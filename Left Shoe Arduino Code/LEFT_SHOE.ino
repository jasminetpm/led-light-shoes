#include <Adafruit_NeoPixel.h>

const int analogInPin = A9;  // Analog input pin that the potentiometer is attached to
Adafruit_NeoPixel strip = Adafruit_NeoPixel(33, 6, NEO_GRB + NEO_KHZ800);
int sensorValue = 0;        // value read from the pot

const int numReadings = 20;

int readings[numReadings];      // the readings from the analog input
int readIndex = 0;              // the index of the current reading
int total = 0;                  // the running total
int average = 0;                // the average

void setup() {
  // initialize serial communications at 9600 bps:
  Serial.begin(9600);
  pinMode(9, INPUT_PULLUP);
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'

  for (int thisReading = 0; thisReading < numReadings; thisReading++) {
    readings[thisReading] = 0;
  }

}

void loop() {
  // read the analog in value:
  sensorValue = analogRead(analogInPin);
  // print the results to the serial monitor:
  Serial.print("sensor = " );
  Serial.println(sensorValue);

  // subtract the last reading:
  total = total - readings[readIndex];
  // read from the sensor:
  readings[readIndex] = sensorValue;
  // add the reading to the total:
  total = total + readings[readIndex];  
  // advance to the next position in the array:
  readIndex = readIndex + 1;

  // if we're at the end of the array...
  if (readIndex >= numReadings) {
    // ...wrap around to the beginning:
    readIndex = 0;
  }

  // calculate the average:
  average = total / numReadings;
  /*Serial.print("average = " );
  Serial.println(average);
  int redValue = map(average,127,40,0,255);
  Serial.print("scaled = " );
  Serial.println(redValue);
  
  for (uint16_t i = 0; i < strip.numPixels(); i++) {
    strip.setPixelColor(i, strip.Color(0,0,0));
    strip.show();
  }
  delay(10);*/
  if (sensorValue < 230 && sensorValue > 200) {
    Serial.println("leds triggered");
    colorWipe(strip.Color(255, 200, 50), 5);
    colorWipe(strip.Color(0, 0, 0), 3);
    } 
    else if (sensorValue < 200 && sensorValue > 190) {
    Serial.println("leds triggered");
    colorWipe(strip.Color(0, 255, 0), 5);
    colorWipe(strip.Color(0, 0, 0), 3);
    }
    else if (sensorValue < 190 && sensorValue > 180) {
    Serial.println("leds triggered");
    colorWipe(strip.Color(0, 255, 40), 5);
    colorWipe(strip.Color(0, 0, 0), 3);
    }
    else if (sensorValue < 180 && sensorValue > 170) {
    Serial.println("leds triggered");
    colorWipe(strip.Color(204, 204, 255), 5);
    colorWipe(strip.Color(0, 0, 0), 3);
    }
    else if (sensorValue < 170 && sensorValue > 160) {
    Serial.println("leds triggered");
    colorWipe(strip.Color(50, 0, 13), 5);
    colorWipe(strip.Color(0, 0, 0), 3);
    }
    else if (sensorValue < 160 && sensorValue > 150) {
    Serial.println("leds triggered");
    colorWipe(strip.Color(0, 255, 30), 5);
    colorWipe(strip.Color(0, 0, 0), 3);
    }
    else if (sensorValue < 150 && sensorValue > 140) {
    Serial.println("leds triggered");
    colorWipe(strip.Color(255, 0, 255), 5);
    colorWipe(strip.Color(0, 0, 0), 3);
    }
    else if (sensorValue < 140 && sensorValue > 130) {
    Serial.println("leds triggered");
    colorWipe(strip.Color(0, 102, 102), 5);
    colorWipe(strip.Color(0, 0, 0), 3);
    }
    else if (sensorValue < 130 && sensorValue > 120) {
    Serial.println("leds triggered");
    colorWipe(strip.Color(51, 255, 255), 5);
    colorWipe(strip.Color(0, 0, 0), 3);
    }
    else if (sensorValue < 120) {
    Serial.println("leds triggered");
    colorWipe(strip.Color(0, 0, 255), 5);
    colorWipe(strip.Color(0, 0, 0), 3);
    }
}

void colorWipe(uint32_t c, uint8_t wait) {
  for (uint16_t i = 0; i < strip.numPixels(); i++) {
    strip.setPixelColor(i, c);
    strip.show();
    delay(wait);
  }
}
