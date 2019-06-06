#include "input/input.h"

namespace browser {
    INPUT::INPUT() { }
    INPUT::~INPUT() { }

    void INPUT::prepareTick() {
        #ifdef __SWITCH__
            hidScanInput();
        #endif
    }

    bool INPUT::doTick(browser::STACK *STACK, browser::DOM *DOM, browser::GUI *GUI) {
        #ifdef __SWITCH__
            u64 kDown   = hidKeysDown(CONTROLLER_P1_AUTO);
            u64 kHeld   = hidKeysHeld(CONTROLLER_P1_AUTO);
            u64 kUp     = hidKeysUp(CONTROLLER_P1_AUTO);

            if ((kDown & KEY_LSTICK) && (kDown & KEY_RSTICK)) console.toggleConsole();
            if (kHeld & KEY_DUP)    GUI->scroll(0, 1);
            if (kHeld & KEY_DDOWN)  GUI->scroll(0, -1);

        #endif
        return true;
    }
}