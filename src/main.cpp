/*  
 Test the tft.print() viz. the libraries embedded write() function

 This sketch used font 2, 4, 7
 
 Make sure all the required fonts are loaded by editing the
 User_Setup.h file in the TFT_eSPI library folder.

  #########################################################################
  ###### DON'T FORGET TO UPDATE THE User_Setup.h FILE IN THE LIBRARY ######
  #########################################################################
 */
#include <Arduino.h>
#include "DSP.h"
#include "lcd_gui.h"

// // Array of example notes for testing
noteInfo exampleNotes[7] = {
    // Perfect Middle C
    {
        .noteName = "C",
        .octave = 4,
        .deviation = 0.0f,
        .deviationCents = 0,
        .midiNote = 60
    },
    
    // A440 reference
    {
        .noteName = "A",
        .octave = 4,
        .deviation = 0.0f,
        .deviationCents = 0,
        .midiNote = 69
    },
    
    // Slightly flat E (guitar)
    {
        .noteName = "E",
        .octave = 2,
        .deviation = -1.5f,
        .deviationCents = -15,
        .midiNote = 40
    },
    
    // Slightly sharp G
    {
        .noteName = "G",
        .octave = 3,
        .deviation = 0.8f,
        .deviationCents = 8,
        .midiNote = 55
    },
    
    // Very sharp D#
    {
        .noteName = "D#",
        .octave = 3,
        .deviation = 3.2f,
        .deviationCents = 45,
        .midiNote = 51
    },
    
    // Very flat F#
    {
        .noteName = "F#",
        .octave = 5,
        .deviation = -4.1f,
        .deviationCents = -40,
        .midiNote = 78
    },
    
    // No note detected
    {
        .noteName = "-",
        .octave = -1,
        .deviation = 0.0f,
        .deviationCents = 0,
        .midiNote = -1
    }
};

// Number of example notes in the array
const int NUM_EXAMPLE_NOTES = 7;

//# define BIAS_PIN 35 //pin for biasing analog circuit

void setup(void) {
    initDisplay(); // Initialize the display
    pinMode(34, INPUT); // Set pin 34 as input for ADC
    analogSetPinAttenuation(32, ADC_11db);
    setupFrequencyDetector(); // Initialize the frequency detector
    //pinMode(BIAS_PIN, OUTPUT); // Set the bias pin as output
    //digitalWrite(BIAS_PIN, HIGH); // Set the bias pin to HIGH 
    // Serial.begin(115200); // Start serial communication for debugging
}

void loop() {
    float freq = getFrequency(); // Get the frequency from the ADC
    // int rawVolt = analogRead(34); // Read the raw voltage from the ADC
    // float volt = (rawVolt / 4095.0) * 3.3; // Convert the raw value to voltage (assuming 12-bit ADC and 3.3V reference)
    // Serial.printf("Raw ADC Value: %d, Voltage: %.2f V\n", rawVolt, volt); // Print the raw ADC value and voltage to the serial monitor for debugging
    // Serial.printf("Frequency: %.2f Hz\n", freq); // Print the frequency to the serial monitor for debugging
    noteInfo note = convertToNote(freq); // Convert the frequency to a note

    //display note to LCD
    displayNote(note);
    delay(1000); // Wait for 1 second before the next reading
    cleanDisplay(); // Clear the display for the next note

    
    //display examples for testing LCD
    // for (int i = 0; i < NUM_EXAMPLE_NOTES; i++) {
    //     displayNote(exampleNotes[i]);
    //     delay(2000); // Wait for 2 seconds before displaying the next note
    //     cleanDisplay(); // Clear the display before the next note
    // }
}




