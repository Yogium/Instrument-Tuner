#include "DSP.h"

// declaring fft and ADC variables
float vReal[SAMPLES];
float vImag[SAMPLES];
ArduinoFFT<float> FFT = ArduinoFFT<float>(vReal, vImag, SAMPLES, SAMPLING_FREQUENCY);
unsigned int samplingPeriod; //in us
unsigned long microseconds;


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
    FFT.windowing(FFTWindow::Hamming, FFTDirection::Forward); //apply Hamming window
    FFT.compute(FFTDirection::Forward); //perform the FFT
    FFT.complexToMagnitude(); //convert the complex numbers to magnitude
    float frequency = FFT.majorPeak(); //get the frequency of the major peak
    return frequency; //return the frequency
}

