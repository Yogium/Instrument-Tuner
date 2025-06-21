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

// Array of example notes for testing
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

void setup(void) {
  initDisplay();
 
}

void loop() {
  for(int i = 0; i < 7; i++) {
    noteInfo note = exampleNotes[i];
    displayNote(note);
    delay(2000); // Wait for 2 seconds before displaying the next note
    cleanDisplay();
  }
}




