#include <Adafruit_NeoPixel.h>
 
#define PIN 6

// These constants won't change. They're used to give names to the pins used:
const int analogInPin = A0;  // Analog input pin that the potentiometer is attached to
const int analogOutPin = 13; // Analog output pin that the LED is attached to

int sensorValue = 0;        // value read from the pot
int outputValue = 0;        // value output to the PWM (analog out)

 
// Parameter 1 = number of pixels in strip
// Parameter 2 = pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
Adafruit_NeoPixel strip = Adafruit_NeoPixel(24, PIN, NEO_GRB + NEO_KHZ800);
 
void setup() {
  strip.begin();
  Serial.begin(9600);
  strip.setBrightness(5); //adjust brightness here
  strip.show(); // Initialize all pixels to 'off'
}
 
void loop() {
  // Some example procedures showing how to display to the pixels:
  colorWipe(strip.Color(50, 20, 255), 10); // Blue

  sensorValue = analogRead(analogInPin);
  
  // map it to the range of the analog out:
  outputValue = map(sensorValue, 0, 1023, 0, strip.numPixels()+1);
  
  // print the results to the Serial Monitor:
  Serial.print("sensor = ");
  Serial.print(sensorValue);
  Serial.print("\t output = ");
  Serial.println(outputValue);

}
 
// Fill the dots one after the other with a color
void colorWipe(uint32_t c, uint8_t wait) {
  uint16_t i;
  for( i=0; i<strip.numPixels(); i++) {
    if(i<outputValue){
      strip.setPixelColor(i, c);
      }
     else{
        strip.setPixelColor(i, strip.Color(0,0,0));
       
        }
     strip.show();
     //delay(wait);
  }
}

  




