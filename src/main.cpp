#include <Arduino.h>
#include <WiFi.h>

#include "animation/animation_player.h"
#include "config.h"
#include "graphics/neopixel_renderer.h"
#include "web/animation_web_server.h"

NeoPixelRenderer renderer;
AnimationPlayer animationPlayer(renderer);
AnimationWebServer webServer(animationPlayer);

void setup() {
    Serial.begin(115200);

    renderer.setup();

    WiFi.mode(WIFI_AP);
    if (!WiFi.softAP(Config::AP_SSID, Config::AP_PASSWORD)) {
        Serial.println("Wi-Fi setup failed");
        return;
    }

    webServer.setup();
}

void loop() {
    webServer.update();
    animationPlayer.update();
}
