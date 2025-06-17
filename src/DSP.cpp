#include "DSP.h"

// declaring fft and ADC variables
arduinoFFT FFT = arduinoFFT();
unsigned int samplingPeriod; //in us
unsigned long microseconds;

double vReal[SAMPLES];
double vImag[SAMPLES];

const int ADC_PIN = 34; //esp32 ADC1 pin

void setupFrequencyDetector() {
    samplingPeriod = round(1000000 * (1.0 / SAMPLING_FREQUENCY)); //in us
    //filling the vReal and vImag arrays with zeros
    for (int i = 0; i < SAMPLES; i++) {
        vReal[i] = 0;
        vImag[i] = 0;
    }
}

float getFrequency(){
    //get sample points from ADC
    for(int i=0; i < SAMPLES; i++) {
        microseconds = micros(); //get the current time in us
        vReal[i] = analogRead(ADC_PIN); //read the ADC value
        vImag[i] = 0; //set the imaginary part to 0
        while (micros() - microseconds < samplingPeriod); //wait for the next sample
    }
    //perform the FFT
    FFT.Windowing(vReal, SAMPLES, FFT_WIN_TYP_HAMMING, FFT_FORWARD); //apply Hamming window
    FFT.Compute(vReal, vImag, SAMPLES, FFT_FORWARD); //perform the FFT
    FFT.ComplexToMagnitude(vReal, vImag, SAMPLES); //convert the complex numbers to magnitude

    //find frequency
    double maxVal = 0;
    int maxIndex = 0;
    for(int i=1; i < (SAMPLES / 2); i++) { //ignores first value (DC component)
        if(vReal[i] > maxVal) {
            maxVal = vReal[i];
            maxIndex = i;
        }
    }
    float frequency = (maxIndex * SAMPLING_FREQUENCY) / SAMPLES; //calculate the frequency
    return frequency; //return the frequency
}

