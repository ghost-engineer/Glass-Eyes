#include <IRremote.h>

// Define the pin connected to the IR LED (via the transistor)
const int irLedPin = 3;

IRsend irsend;

void setup() {
  // Initialize the random number generator with a floating analog pin
  randomSeed(analogRead(A0));
}

void loop() {
  // Generate a random 32-bit number to send as the IR data
  uint32_t randomData = 0;
  for (int i = 0; i < 32; i++) {
    if (random(2) == 1) {
      randomData |= (1UL << i);
    }
  }

  // Create a random pulse pattern. We will use a simple on/off pattern
  // within the 3ms window.
  unsigned int rawData[6]; // An array to hold our raw pulse data
  int pulseLength = 50; // A base pulse length in microseconds

  // Create a few random on/off pulses
  for(int i = 0; i < 6; i += 2) {
    rawData[i] = random(pulseLength / 2, pulseLength * 2); // Random ON time
    rawData[i+1] = random(pulseLength / 2, pulseLength * 2); // Random OFF time
  }


  // Send the raw IR data at 38kHz for approximately 3ms
  // The total time will be the sum of the rawData array elements.
  // We can adjust the loop and pulse lengths to get closer to 3ms.
  unsigned long startTime = micros();
  while(micros() - startTime < 3000) {
    irsend.sendRaw(rawData, sizeof(rawData) / sizeof(rawData[0]), 38);
  }


  // A short, random delay to make the pattern less predictable
  delay(random(5, 20));
}