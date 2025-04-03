// Define pin numbers
int buttonPin = 2;  // connect button to pin 2
int ledPin = 13;    // the onboard LED is already connected to pin 13

// Code that runs one time
void setup() {
  pinMode(buttonPin, INPUT_PULLUP);  // Configure the button pin as an input 
  pinMode(ledPin, OUTPUT);    // Configure the LED pin as an output
}

// Code that runs over and over again in a loop
void loop() {

  // Read the button state
  int buttonState = digitalRead(buttonPin);  

  // Check if the button is pressed
  if (buttonState == HIGH) {                 
    digitalWrite(ledPin, HIGH); // Turn on the LED
  } else {
    digitalWrite(ledPin, LOW);  // Turn off the LED
  }
  
}
