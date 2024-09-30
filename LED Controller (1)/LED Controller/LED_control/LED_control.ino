int ledPins[] = {2, 3, 4, 5,6};  // LEDs connected to pins 2, 3, 4, 5
int fingerCount = 0;

void setup() {
  // Set LED pins as output
  for (int i = 0; i < 5; i++) {
    pinMode(ledPins[i], OUTPUT);
    digitalWrite(ledPins[i], LOW);  // Turn off all LEDs initially
  }
  
  // Initialize serial communication
  Serial.begin(9600);
}

void loop() {
  // Check if data is available from the serial port
  if (Serial.available() > 0) {
    // Read the incoming byte (number of fingers)
    fingerCount = Serial.read() - '0';  // Convert ASCII to integer

    // Turn off all LEDs
    for (int i = 0; i < 4; i++) {
      digitalWrite(ledPins[i], LOW);
    }

    // Turn on LEDs based on the finger count
    for (int i = 0; i < fingerCount && i < 4; i++) {
      digitalWrite(ledPins[i], HIGH);
    }
  }
}
