#include <Arduino.h> // Include the Arduino core library for ESP32
#include <TFT_eSPI.h> // Include the TFT_eSPI library
#include <unity.h> // Include the Unity testing framework for Arduino


// Create a TFT_eSPI object.
// The pin definitions and display type are configured in the User_Setup.h file
TFT_eSPI tft = TFT_eSPI();

void test_display(){
    Serial.begin(115200);
  Serial.println("Starting TFT_eSPI LCD Test...");

  // Initialize the TFT display
  tft.init();

  // Set the rotation of the display (0 to 3)
  // Experiment with this until your display shows text in the desired orientation.
  // For a 320x480 display, 0 or 2 might be portrait, 1 or 3 might be landscape.
  tft.setRotation(1); // Try 0, 1, 2, or 3

  // Clear the entire screen with black
  tft.fillScreen(TFT_BLACK);
  Serial.println("Screen cleared to black.");

  delay(500); // Give a moment to see the black screen

  // --- Test Text ---
  tft.setTextColor(TFT_WHITE); // Set text color to white
  tft.setTextSize(2);          // Set text size (1 is smallest)
  tft.setCursor(10, 10);       // Set cursor position (x, y)
  tft.println("Hello, ILI9488!"); // Print text

  tft.setTextSize(1);
  tft.setTextColor(TFT_YELLOW);
  tft.setCursor(10, 40);
  tft.printf("Resolution: %dx%d", tft.width(), tft.height()); // Display detected resolution

  delay(1000);

  // --- Test Colors and Shapes ---
  tft.fillScreen(TFT_RED); // Fill screen with red
  Serial.println("Screen filled with red.");
  delay(1000);

  tft.fillScreen(TFT_BLUE); // Fill screen with blue
  Serial.println("Screen filled with blue.");
  delay(1000);

  tft.fillScreen(TFT_GREEN); // Fill screen with green
  Serial.println("Screen filled with green.");
  delay(1000);

  // Test drawing a rectangle
  tft.fillScreen(TFT_BLACK);
  tft.drawRect(20, 20, 100, 50, TFT_CYAN); // (x, y, width, height, color)
  tft.fillRect(140, 20, 100, 50, TFT_MAGENTA); // Filled rectangle
  Serial.println("Rectangles drawn.");
  delay(1000);

  // Test drawing circles
  tft.fillCircle(tft.width() / 2, tft.height() / 2, 50, TFT_ORANGE); // (x_center, y_center, radius, color)
  tft.drawCircle(tft.width() / 2, tft.height() / 2, 60, TFT_WHITE); // Outline circle
  Serial.println("Circles drawn.");
  delay(1000);

  // Test drawing lines
  tft.drawLine(0, 0, tft.width() - 1, tft.height() - 1, TFT_WHITE); // Diagonal line
  tft.drawLine(0, tft.height() - 1, tft.width() - 1, 0, TFT_WHITE); // Other diagonal
  Serial.println("Lines drawn.");
  delay(1000);

  // Final message
  tft.fillScreen(TFT_BLACK);
  tft.setCursor(10, 10);
  tft.setTextColor(TFT_GREEN, TFT_BLACK); // Text color, background color
  tft.setTextSize(3);
  tft.println("Test Complete!");
  tft.setTextSize(1);
  tft.setCursor(10, 60);
  tft.setTextColor(TFT_WHITE);
  tft.println("If you see this, your LCD is working!");
}

void setup() {
  Serial.begin(115200);
  delay(1000);
  UNITY_BEGIN();
  RUN_TEST(test_display); // Run the test function
  UNITY_END();
}

void loop() {
  // You can add animations or continuous updates here if you wish.
  // For a simple test, we just do everything once in setup().
}