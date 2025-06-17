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

