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
    {45, 266, 30, 54, TFT_RED},   // -50
    {82, 241, 29, 79, TFT_RED},   // -40
    {117, 216, 29, 103, TFT_ORANGE}, // -30
    {153, 194, 29, 126, TFT_ORANGE}, // -20
    {189, 166, 30, 154, TFT_ORANGE}, // -10
    {225, 152, 29, 168, TFT_GREEN}, // +0
    {260, 166, 30, 154, TFT_ORANGE}, // +10
    {297, 194, 29, 126, TFT_ORANGE}, // +20
    {333, 216, 29, 104, TFT_ORANGE}, // +30
    {369, 241, 29, 79, TFT_RED},   // +40
    {404, 266, 30, 54, TFT_RED}    // +50
};

//function to initialize the TFT display
void initDisplay();
void testDisplay();
void displayNote(noteInfo note);
void cleanDisplay();

#endif // LCD_GUI_H