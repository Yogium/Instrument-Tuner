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

    //creating if note is empty
    if(note.noteName == "-"){
       for(int i=0; i<11; i++){
            tft.fillRect(rects[i].x, rects[i].y, rects[i].w, rects[i].h, TFT_BLACK); // Clear the rectangles
        }
        tft.fillRect(152, 75, 173, 38, TFT_WHITE);
    }

    //if there is note information
    else{
        //draw initial display
        for(int i=0; i<11; i++){
            tft.fillRect(rects[i].x, rects[i].y, rects[i].w, rects[i].h, rects[i].color);
        }
        //write the note
        tft.setCursor(173, 51);
        tft.setTextSize(2);
        tft.setTextColor(TFT_WHITE, TFT_BLACK);
        //creating note+octave string
        String noteStr = note.noteName + String(note.octave);
        tft.printf("Note: %s", noteStr.c_str()); // Print the note and octave
        //changing rectangle color based on deviation
        //clamping deviation to -50 to 50
        int deviation = note.deviationCents;
        if(deviation < -50) deviation = -50;
        else if(deviation > 50) deviation = 50;
        //calculating which rectangle to change
        int rectIndex = (deviation + 50) / 10; // -50 to +50 maps to 0 to 10
        //change rectangle color
        tft.fillRect(rects[rectIndex].x, rects[rectIndex].y, rects[rectIndex].w, rects[rectIndex].h, TFT_WHITE); // Change the rectangle color to white
    }           
}