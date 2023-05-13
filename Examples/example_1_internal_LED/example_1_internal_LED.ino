// Example 3: Three LEDs
// Last Updated: 5/13/2023
// Ryan J. Priore (ryan.priore@gmail.com)

// LIBRARIES (List any dependent libraries for your code)

// DEFINITIONS (Define constants or variables)
#define internal_LED  13 // The internal LED is connected to pin 13

// SETUP FUNCTION (This loop only runs once at startup)
void setup() {
  // Initialize the serial port
  Serial.begin(9600);

  // Set the mode for each pin
  pinMode(internal_LED, OUTPUT); // Internal LED is an output 
}

// LOOP FUNCTION (Runs repeatedly as long as board is on) 
void loop() {
  // Turn on the internal LED
  digitalWrite(internal_LED, HIGH);
  Serial.println("Internal LED is ON!");   // Update serial monitor

  // Delay for 1000 milliseconds (1 second)
  delay(1000);

  // Turn off the internal LED
  digitalWrite(internal_LED, LOW);
  Serial.println("Internal LED is OFF!");  // Update serial monitor

  // Delay for 1000 milliseconds (1 second)
  delay(1000);
}