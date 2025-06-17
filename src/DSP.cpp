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

noteInfo convertToNote(float frequency){
    noteInfo note;
    if(frequency<=20 || frequency >= 5000){
        note.noteName = "error";
        note.octave = -1;
        note.deviationCents = 0;
        note.midiNote = -1;
        return note; //return empty note if frequency is invalid
    }
    //calculate MIDI number
    int midiNote = round(69 + 12 * log2(frequency / 440.0));
    note.midiNote = midiNote;

    //note name array
    const char* noteNames[] = {"C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "A#", "B"};

    //calculating octave and note name
    note.octave = (midiNote / 12) - 1; //-1 because octave starts at 0
    note.noteName = noteNames[midiNote % 12]; //get the note name

    //calculate deviation
    float notefreq =  440.0 * pow(2.0, (midiNote - 69) / 12.0); //calculate the frequency of the note
    note.deviationCents = round(1200*log2(frequency / notefreq)); //calculate the deviation in cents
    if(note.deviationCents < -50) note.deviationCents = -50;
    else if(note.deviationCents > 50) note.deviationCents = 50; //limit the deviation to -50 to 50 cents
    return note; //return the note info
}
