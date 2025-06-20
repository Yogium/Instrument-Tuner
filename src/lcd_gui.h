#ifndef LCD_GUI_H
#define LCD_GUI_H
#include <TFT_eSPI.h>
#include "DSP.h"
#include <string>

//function to initialize the TFT display
void initDisplay();
void testDisplay();
void displayNote(noteInfo note);

#endif // LCD_GUI_H