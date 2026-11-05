#pragma once

#include <WebServer.h>
#include "animation/animation.h"

class AnimationPlayer;

class AnimationWebServer {
public:
    explicit AnimationWebServer(AnimationPlayer& player);

    void setup();
    void update();

private:
    AnimationPlayer& player_;
    WebServer server_;
    Animation pendingUpload_;

    void sendError(int status, const char* message);
    void handleAnimationUpload();
    void handleStatus();
};
