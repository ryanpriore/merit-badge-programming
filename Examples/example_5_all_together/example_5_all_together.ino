// Example 5: All Together (button & LEDs)
// Last Updated on 5/13/2023
// Ryan J. Priore (ryan.priore@gmail.com)

// LIBRARIES (List any dependent libraries for your code)
#include <Adafruit_NeoPixel.h>

// DEFINITIONS (Define constants or variables)
#define BUTTON         2 // The button is connected to pin 2
#define R_LED_PIN      5 // The red LED is connected to pin 3
#define G_LED_PIN      4 // The yellow LED is connected to pin 4
#define B_LED_PIN      3 // The green LED is connected to pin 5
#define RGB_LED_PIN    6 // The RGB LED is connected to pin 6
#define RGB_LED_COUNT  5 // There is a total of 1 RGB LED

// Declare the Neopixel strip object
Adafruit_NeoPixel strip(RGB_LED_COUNT, RGB_LED_PIN, NEO_GRB + NEO_KHZ800);

// SETUP FUNCTION (This loop only runs once at startup)
void setup() {
  // Initialize the serial port
  Serial.begin(9600);
  
  // Set the mode for each pin
  pinMode(BUTTON, INPUT_PULLUP); // Button is an input w/ pullup resistor
  pinMode(R_LED_PIN, OUTPUT);    // Red LED is an output
  pinMode(G_LED_PIN, OUTPUT);    // Green LED is an output
  pinMode(B_LED_PIN, OUTPUT);    // Blue LED is an output
  pinMode(RGB_LED_PIN, OUTPUT);  // RGB LED is an output

  // Setup the Neopixel strip
  strip.begin();           // Initialize the NeoPixel strip object
  strip.show();            // Turn off all pixels ASAP
  strip.setBrightness(50); // Set brightness to about 1/5 (max = 255)
}

// LOOP FUNCTION (Runs repeatedly as long as board is on) 
void loop() {
  // Red LED
  colorWipe(strip.Color(255, 0, 0), 50); // Red Neopixel wipe
  ledOnOff(BUTTON, R_LED_PIN, 50);       // If button pressed, turn on red LED

  // Green LED
  colorWipe(strip.Color(0, 255, 0), 50); // Green Neopixel wipe
  ledOnOff(BUTTON, G_LED_PIN, 50);       // If button pressed, turn on green LED

  // Blue LED
  colorWipe(strip.Color(0, 0, 255), 50); // Blue Neopixel wipe
  ledOnOff(BUTTON, B_LED_PIN, 50);       // If button pressed, turn on blue LED
}

// ledOnOff function to turn an LED on, wait for a defined time period, then turn LED off
void ledOnOff(int button_pin, int led_pin, int wait) {
  // Read the pushbutton value into a variable
  int buttonVal = digitalRead(button_pin);

  // Take action if button is pressed
  if (buttonVal == HIGH) {
    digitalWrite(led_pin, LOW);       // Button not pressed
    }
  else {
    digitalWrite(led_pin, HIGH);       // Button pressed
    Serial.println("Button Pressed!");
    digitalWrite(led_pin, HIGH);       // Turn on LED
    delay(wait);                       // Delay
    digitalWrite(led_pin, LOW);        // Turn off LED 
    }   
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