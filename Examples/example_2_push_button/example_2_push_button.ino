// Example 2: Push button & the internal LED
// Last Updated: 5/13/2023
// Ryan J. Priore (ryan.priore@gmail.com)

// LIBRARIES (List any dependent libraries for your code)

// DEFINITIONS (Define constants or variables)
#define BUTTON         2 // The button is connected to pin 2
#define internal_LED  13 // The internal LED is connected to pin 13

// SETUP FUNCTION (This loop only runs once at startup)
void setup() {
  // Initialize the serial port
  Serial.begin(9600);

  // Set the mode for each pin
  pinMode(BUTTON, INPUT_PULLUP); // Button is an input w/ pullup resistor
  pinMode(internal_LED, OUTPUT); // Internal LED is an output 
}

// LOOP FUNCTION (Runs repeatedly as long as board is on) 
void loop() {
  // Read the pushbutton value into a variable
  int buttonVal = digitalRead(BUTTON);

  // Take action if button is pressed
  if (buttonVal == HIGH) {
    digitalWrite(internal_LED, LOW);   // Button not pressed, so LED is off
    delay(100);                        // Delay for 100 milliseconds (0.1 seconds)
    }
  else {
    digitalWrite(internal_LED, HIGH);  // Button pressed, so LED is on
    Serial.println("Button Pressed!"); // Update serial monitor
    delay(100);                        // Delay for 100 milliseconds (0.1 seconds)
    }
}