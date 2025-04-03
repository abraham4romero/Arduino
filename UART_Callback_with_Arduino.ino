const int ledPin = 13; // Onboard LED pin
bool blink = false;    // global variable that the Callback function changes

// Code that runs once
void setup() {
  pinMode(ledPin, OUTPUT); // make the LED pin an output pin
  Serial.begin(9600); // start a UART connection at 9600 baud (9600 bits per second)
}

// Code that executes over and over again
void loop() {

  // If the "blink" variable is set to true, toggle the LED
  if (blink){
    digitalWrite(ledPin, !digitalRead(ledPin)); // Toggle the LED
    delay(200); // wait 200 ms
  }
}

// Callback code that executes when a Serial message is received.
void serialEvent(){
  String message = Serial.readStringUntil('\n'); // stop reading when new line '\n' ("Enter") received
  blink = false;

  // Determine what to do based on the message
  if (message == "LED_ON") {

    digitalWrite(ledPin, HIGH); // Turn on the LED
    Serial.write("Message received - LED turned on.\n");  // Send a confirmation message back to the laptop

  } else if (message == "LED_OFF"){

    digitalWrite(ledPin, LOW);  // Turn off the LED
    Serial.write("Message received - LED turned off.\n"); // Send a confirmation message back to the laptop;

  } else if (message == "LED_BLINK"){

    blink = true; // set the "blink" variable true
    Serial.write("Message received - LED blinking.\n");   // Send a confirmation message back to the laptop;
    
  } else {
    Serial.write("Unrecognized command.\n");              // Send an error message back to the laptop
  } 
}

