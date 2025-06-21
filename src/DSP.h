#ifndef DSP_H
#define DSP_H
//declaring used libraries
#include <Arduino.h>
#include "arduinoFFT.h"
//declaring FFT variables
#define SAMPLES 1024
#define SAMPLING_FREQUENCY 20000 // Hz

struct noteInfo{
    String noteName; //simple note letter eg. "C", "D#", "F"
    int octave; // octave number, 0-8
    float deviation; //deviation in hertz
    int deviationCents; // deviation in cents, -50 to 50
    int midiNote; // MIDI note number, 0-127
};

//function for setting up the FFT from the arduinoFFT library
void setupFrequencyDetector();
//function for reading the ADC and performing the FFT
float getFrequency();
//function for converting the frequency to a note
noteInfo convertToNote(float frequency);

#endif