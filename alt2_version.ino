// Arduino IR Jammer - Randomized Stutter Pattern
// This sketch rapidly pulses an IR LED with random ON/OFF durations to overwhelm IR sensors.
// Requirements:
// 1. IR LED on digital pin 9
// 2. Randomized ON/OFF durations (50-500 microseconds)
// 3. Continuous operation, no modulation
// 4. Random seed from analogRead(0)

const int irLedPin = 9; // Pin connected to IR LED
const int minPulse = 50;   // Minimum pulse duration in microseconds
const int maxPulse = 500;  // Maximum pulse duration in microseconds

void setup() {
  pinMode(irLedPin, OUTPUT); // Set IR LED pin as output
  // Initialize random seed using floating analog pin for more entropy
  randomSeed(analogRead(0));
}

void loop() {
  // Generate random ON and OFF durations
  int onTime = random(minPulse, maxPulse + 1);   // ON duration (us)
  int offTime = random(minPulse, maxPulse + 1);  // OFF duration (us)

  // Turn IR LED ON for random duration
  digitalWrite(irLedPin, HIGH);
  delayMicroseconds(onTime);

  // Turn IR LED OFF for random duration
  digitalWrite(irLedPin, LOW);
  delayMicroseconds(offTime);
  // Repeat forever
}
