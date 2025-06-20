#include "lcd_gui.h"

//declare TFT_eSPI object
TFT_eSPI tft = TFT_eSPI(); // Create object "tft"

//function to initialize the TFT display
void initDisplay() {
    tft.init(); // Initialize the TFT display
    tft.setRotation(1); // Set the rotation of the display
    tft.fillScreen(TFT_BLACK); // Fill the screen with black color
    tft.setTextColor(TFT_WHITE, TFT_BLACK); // Set text color to white with black background
    tft.setTextSize(2); // Set text size
    tft.setCursor(0, 0); // Set cursor position to top left corner
}

void testDisplay(){
    tft.println("Hello, world!");
    delay(1000); // Wait for 1 second
    tft.fillScreen(TFT_BLACK); // Clear the screen
    tft.setTextColor(TFT_GREEN); // Change text color to green
    tft.println("Testing display functionality...");
    delay(1000); // Wait for 1 second
    tft.fillScreen(TFT_BLACK); // Clear the screen again
    tft.setTextColor(TFT_RED); // Change text color to red
    tft.println("Display test complete!");
    delay(1000); // Wait for 1 second
    tft.fillScreen(TFT_BLACK); // Clear the screen one last time
    tft.setTextColor(TFT_WHITE); // Reset text color to white
}


void displayNote(noteInfo note){
    //writing the note and octave to display
    tft.setCursor(173, 51);
    tft.setTextSize(2);
    tft.setTextColor(TFT_WHITE, TFT_BLACK);
    //creating note+octave string
    String noteString = note.noteName + String(note.octave);
    tft.printf("Note: %s", noteString.c_str()); // Print the note and octave

    //drawing initial UI
    tft.fillRect(45, 266, 54, 30, TFT_RED); //draw -50 red rectangle
    tft.fillRect(82, 241, 79, 29, TFT_RED); //draw -40  red rectangle
    tft.fillRect(117, 216, 103, 29, TFT_ORANGE); //draw -30 orange rectangle
    tft.fillRect(153, 194, 126, 29, TFT_ORANGE); //draw -20 orange rectangle
    tft.fillRect(189, 166, 154, 30, TFT_ORANGE); //draw -10 yellow rectangle
    tft.fillRect(225, 152, 168, 29, TFT_GREEN); //draw green rectangle
    tft.fillRect(260, 166, 154, 30, TFT_ORANGE); //draw +10 orange rectangle
    tft.fillRect(297, 194, 126, 29, TFT_ORANGE); //draw +20 orange rectangle
    tft.fillRect(333, 216, 104, 29, TFT_ORANGE); //draw +30 orange rectangle
    tft.fillRect(369, 241, 79, 29, TFT_RED); //draw +40 red rectangle
    tft.fillRect(404, 266, 54, 30, TFT_RED); //draw +50 red rectangle

    //deviation in cents
    
}