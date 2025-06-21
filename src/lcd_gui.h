#ifndef LCD_GUI_H
#define LCD_GUI_H
#include <TFT_eSPI.h>
#include "DSP.h"
#include <string>

//GUI rectangle elements
struct Rect{
    int x, y, w, h; // x, y coordinates and width, height
    uint16_t color; // color of the rectangle
};

//array of rectangles for the deviation in cents
const Rect rects[11] = {
    {45, 266, 54, 30, TFT_RED},   // -50
    {82, 241, 79, 29, TFT_RED},   // -40
    {117, 216, 103, 29, TFT_ORANGE}, // -30
    {153, 194, 126, 29, TFT_ORANGE}, // -20
    {189, 166, 154, 30, TFT_ORANGE}, // -10
    {225, 152, 168, 29, TFT_GREEN}, // +0
    {260, 166, 154, 30, TFT_ORANGE}, // +10
    {297, 194, 126, 29, TFT_ORANGE}, // +20
    {333, 216, 104, 29, TFT_ORANGE}, // +30
    {369, 241, 79, 29, TFT_RED},   // +40
    {404, 266, 54, 30, TFT_RED}    // +50
};

//function to initialize the TFT display
void initDisplay();
void testDisplay();
void displayNote(noteInfo note);

#endif // LCD_GUI_H