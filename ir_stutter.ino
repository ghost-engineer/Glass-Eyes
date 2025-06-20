/*
  Surveillance LED Stutter - IR Flooder
  This sketch rapidly pulses IR LEDs with random patterns for 3ms to disrupt nearby IR sensors.
  Connect IR LEDs to pin 9 (with appropriate resistor).
*/

const int irLedPin = 9;
const unsigned long pulseDuration = 3; // milliseconds

void setup() {
  pinMode(irLedPin, OUTPUT);
}

void loop() {
  unsigned long startTime = millis();
  while (millis() - startTime < pulseDuration) {
    // Generate a random pulse width between 100 and 800 microseconds
    int onTime = random(100, 800);
    int offTime = random(100, 800);
    digitalWrite(irLedPin, HIGH);
    delayMicroseconds(onTime);
    digitalWrite(irLedPin, LOW);
    delayMicroseconds(offTime);
  }
  // After 3ms, turn off LED and halt
  digitalWrite(irLedPin, LOW);
  while (1); // Stop further execution
}
