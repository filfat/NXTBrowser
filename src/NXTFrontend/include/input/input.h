#pragma once
#include <iostream>
#ifdef __SWITCH__
    #include <switch.h>
#endif

#include "../main.h"

#include "../gui/gui.h"
#include "../stack/stack.h"
#include "../dom/dom.h"

extern device_aspect DEVICE;

namespace browser {
    class INPUT {
        private:
        public:
            INPUT();
            ~INPUT();

            void prepareTick();
            bool doTick(browser::STACK *STACK, browser::DOM *DOM, browser::GUI *GUI);
    };
}