#include "gui/gui.h"

namespace browser {
    GUI::GUI() {
        #ifndef __NATIVE_GUI__
            // sdl_helper::init();
        #else
            uiInitOptions options;
            memset(&options, 0, sizeof (uiInitOptions));
            uiInit(&options);
        #endif
    }
    GUI::~GUI() {
        #ifndef __NATIVE_GUI__
            // sdl_helper::exit();
        #else
            uiUninit();
        #endif
    }

    void GUI::prepareTick() { }

    bool GUI::doTick() {
        return true;
    }
}