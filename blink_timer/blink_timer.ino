const int ledPin =  13;    // the number of the LED pin

int ledState = LOW;        // ledState used to set the LED
long nextEvent = 0;        // next time to reverse LED
 
long intervaluit = 500;
long intervalaan = 2000;

void setup() {
  pinMode(ledPin, OUTPUT); // set the digital pin as output    
}

void loop()
{ 
  if (millis() > nextEvent) {
    if (ledState == LOW) {
      nextEvent = millis() + intervaluit;  // next time to reverse LED
    } else {
      nextEvent = millis() + intervalaan;  // next time to reverse LED
    }
 
    if (ledState == LOW)  // reverse ledState
      ledState = HIGH;
    else
      ledState = LOW;

    digitalWrite(ledPin, ledState); // set the LED 
  }
}
