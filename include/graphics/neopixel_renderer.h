#pragma once

#include <Adafruit_NeoPixel.h>

struct AnimationFrame;

class NeoPixelRenderer {
public:
    NeoPixelRenderer();

    void setup();
    void showFrame(const AnimationFrame& frame, uint16_t ledCount);

private:
    Adafruit_NeoPixel strip_;
};
