int ledPin = 13;         // LED connected to digital pin 13
int pirPin = 2;          // PIR sensor input pin
int pirState = LOW;      // Start assuming no motion
int val = 0;             // Variable to read PIR status

void setup() {
  pinMode(ledPin, OUTPUT);  // Set LED as output
  pinMode(pirPin, INPUT);   // Set PIR sensor as input
  Serial.begin(9600);
}

void loop() {
  val = digitalRead(pirPin);  // Read input value from PIR sensor
  if (val == HIGH) {
    digitalWrite(ledPin, HIGH);  // Turn LED ON
    if (pirState == LOW) {
      Serial.println("Motion detected!");
      pirState = HIGH;
    }
    delay(5000);                 // Wait for 5 seconds
  } else {
    digitalWrite(ledPin, LOW);   // Turn LED OFF
    if (pirState == HIGH) {
      Serial.println("Motion ended!");
      pirState = LOW;
    }
  }
}
