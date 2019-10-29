#pragma once
#include <iostream>

#include "../main.h"
#include "../gui/gui.h"
#include "../stack/stack.h"

extern device_aspect DEVICE;

namespace browser {
    class DOM {
        public:
            bool SHOULD_UPDATE = true;

            DOM() { }
            ~DOM() { }

            void prepareTick() { }

            bool doTick(browser::STACK *STACK, browser::GUI *GUI);
    };
}