#include <Arduino.h>
#include "DSP.h"
#include "lcd_gui.h"
// put function declarations here:

void setup() {
  // put your setup code here, to run once:
  initDisplay();
}

void loop() {
  // put your main code here, to run repeatedly:
  testDisplay(); // Call the function to test the display
  delay(2000); // Wait for 2 seconds before the next test
}