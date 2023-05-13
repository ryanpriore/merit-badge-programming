// Example 3: Three LEDs
// Last Updated: 5/13/2023
// Ryan J. Priore (ryan.priore@gmail.com)

// LIBRARIES (List any dependent libraries for your code)

// DEFINITIONS (Define constants or variables)
#define R_LED_PIN      5 // The red LED is connected to pin 3
#define G_LED_PIN      4 // The green LED is connected to pin 4
#define B_LED_PIN      3 // The blue LED is connected to pin 5

// SETUP FUNCTION (This loop only runs once at startup)
void setup() {
  // Initialize the serial port
  Serial.begin(9600);

  // Set the mode for each pin
  pinMode(R_LED_PIN, OUTPUT);    // Red LED is an output
  pinMode(G_LED_PIN, OUTPUT);    // Green LED is an output
  pinMode(B_LED_PIN, OUTPUT);    // Blue LED is an output
}

// LOOP FUNCTION (Runs repeatedly as long as board is on) 
void loop() {
  // Cycle through each of the LEDs
  
  // Red LED on/off
  Serial.println("Red LED is On!");    // Update serial monitor
  ledOnOff(R_LED_PIN, 500);            // Turn on Red LED for 500 milliseconds
  Serial.println("Red LED is Off!");   // Update serial monitor

  // Green LED on/off
  Serial.println("Green LED is On!");  // Update serial monitor
  ledOnOff(G_LED_PIN, 500);            // Turn on Green LED for 500 milliseconds
  Serial.println("Green LED is Off!"); // Update serial monitor

  // Blue LED on/off
  Serial.println("Blue LED is On!");   // Update serial monitor
  ledOnOff(B_LED_PIN, 500);            // Turn on Blue LED for 500 milliseconds
  Serial.println("Blue LED is Off!");  // Update serial monitor  
}

// ledOnOff function to turn an LED on, wait for a defined time period, then turn LED off
void ledOnOff(int led_pin, int wait) {
  digitalWrite(led_pin, HIGH); // Turn on LED
  delay(wait);                 // Delay
  digitalWrite(led_pin, LOW);  // Turn off LED  
}