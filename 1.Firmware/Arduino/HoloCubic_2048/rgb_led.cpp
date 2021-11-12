#include "rgb_led.h"


void Pixel::init()
{
	FastLED.addLeds<WS2812, RGB_LED_PIN, GRB>(color_buffers, RGB_LED_NUM);
	FastLED.setBrightness(200);
}

Pixel& Pixel::setRGB(int r, int g, int b)
{
	color_buffers[0] = CRGB(r, g, b);
	FastLED.show();

	return *this;
}

Pixel& Pixel::setBrightness(float duty)
{
	FastLED.setBrightness((int)duty);
	FastLED.show();

	return *this;
}
