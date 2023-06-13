#include <Arduino.h>
#include <FastLED.h>
#define NUM_LEDS 1
#define DATA_PIN 48
CRGB leds[NUM_LEDS];

void BlinkRGB();
void RedLedOn();
void GreenLedOn();
void BlueLedOn();
void LedOff();
void DeviceInfo();
void ConfigLed();

void setup()
{
  ConfigLed();
  DeviceInfo();
}
void loop()
{
}
void BlinkRGB()
{
  leds[0] = CRGB::Red;
  FastLED.show();
  delay(500);
  leds[0] = CRGB::Green;
  FastLED.show();
  delay(500);
  leds[0] = CRGB::Blue;
  FastLED.show();
  delay(500);
  leds[0] = CRGB::Black;
  FastLED.show();
  delay(1500);
}
void RedLedOn()
{
  leds[0] = CRGB::Red;
  FastLED.show();
}
void GreenLedOn()
{
  leds[0] = CRGB::Green;
  FastLED.show();
}
void BlueLedOn()
{
  leds[0] = CRGB::Blue;
  FastLED.show();
}
void LedOff()
{
  leds[0] = CRGB::Black;
  FastLED.show();
}
void DeviceInfo()
{
  log_d("Chip Model: %s", ESP.getChipModel());
  log_d("CPU Core: %d", ESP.getChipCores());
  log_d("CPU Speed: %d", ESP.getCpuFreqMHz());
  log_d("Total heap: %d", ESP.getHeapSize());
  log_d("Total Flash: %d", ESP.getFlashChipSize());
  log_d("Total PSRAM: %d", ESP.getPsramSize());
  log_d("Free PSRAM: %d", ESP.getFreePsram());
}
void ConfigLed()
{
  FastLED.addLeds<SK6812, DATA_PIN, GRB>(leds, NUM_LEDS);
  pinMode(BUILTIN_LED, OUTPUT);
}