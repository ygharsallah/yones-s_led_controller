#pragma once

#include <WString.h>
#include "animation/animation.h"

namespace AnimationParser {
    bool parse(const String& json, Animation& result);
}
