// Example 4: Neopixel LEDs and libraries (adapted from Neopixel example, strandtest)
// Last Updated: 5/13/2023
// Ryan J. Priore (ryan.priore@gmail.com)

// LIBRARIES (List any dependent libraries for your code)
#include <Adafruit_NeoPixel.h>

// DEFINITIONS (Define constants or variables)
#define RGB_LED_PIN    6 // The RGB LED is connected to pin 6
#define RGB_LED_COUNT  5 // There is a total of 5 RGB LEDs

// Declare the Neopixel strip object
Adafruit_NeoPixel strip(RGB_LED_COUNT, RGB_LED_PIN, NEO_GRB + NEO_KHZ800);

// SETUP FUNCTION (This loop only runs once at startup)
void setup() {
  // Initialize the serial port
  Serial.begin(9600);

  // Setup the Neopixel strip
  strip.begin();           // Initialize the NeoPixel strip object
  strip.show();            // Turn off all pixels ASAP
  strip.setBrightness(50); // Set brightness to about 1/5 (max = 255)
}

// LOOP FUNCTION (Runs repeatedly as long as board is on) 
void loop() {
  // Fill along the length of the strip in various colors...
  
  // Red LED wipe
  Serial.println("Red LED wipe.");            // Update serial monitor
  colorWipe(strip.Color(255,   0,   0), 100); // Wipe with red and pause for 50 milliseconds

  // Green LED wipe
  Serial.println("Green LED wipe.");          // Update serial monitor  
  colorWipe(strip.Color(  0, 255,   0), 100); // Wipe with green and pause for 50 milliseconds

  // Blue LED wipe
  Serial.println("Blue LED wipe.");           // Update serial monitor 
  colorWipe(strip.Color(  0,   0, 255), 100); // Wipe with blue and pause for 50 milliseconds
}

// Fill strip pixels one after another with a color. Strip is NOT cleared
// first; anything there will be covered pixel by pixel. Pass in color
// (as a single 'packed' 32-bit value, which you can get by calling
// strip.Color(red, green, blue) as shown in the loop() function above),
// and a delay time (in milliseconds) between pixels.
void colorWipe(uint32_t color, int wait) {
  for(int i=0; i<strip.numPixels(); i++) { // For each pixel in strip...
    strip.setPixelColor(i, color);         //  Set pixel's color (in RAM)
    strip.show();                          //  Update strip to match
    delay(wait);                           //  Pause for a moment
  }
}