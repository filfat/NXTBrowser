#pragma once
#include <iostream>

#include "../main.h"
#ifdef __NATIVE_GUI__
    #include "ui/mainWindow.h"
#endif

namespace browser {
    class GUI {
        public:
            GUI();
            ~GUI();

            void prepareTick();
            bool doTick();
    };
}