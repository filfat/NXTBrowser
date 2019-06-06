#include <string.h>
#include <fstream>
#include <stdio.h>
#include <iostream>
#include <functional>

#ifdef __SWITCH__
    #include <switch.h>
#elif __MACOS__
    #include <sys/time.h>
    #include <sys/resource.h>
#elif __LINUX__
#elif __WIN32__
#endif

#include "main.h"
#include "html/html.h"
#include "gui/gui.h"
#include "input/input.h"
#include "net/net.h"
#include "stack/stack.h"
#include "dom/dom.h"

#ifdef __NATIVE_GUI__
    #include "gui/ui/mainWindow.h"
#endif

unsigned int currentTick = 0, lastTick = 0, delta = 0;

browser::INPUT *INPUT;
browser::NET *NET;
browser::STACK *STACK;
browser::DOM *DOM;
browser::GUI *GUI;

device_aspect DEVICE;

long getMemoryUsage() {
    #ifdef __MACOS__
        struct rusage usage;
        if(0 == getrusage(RUSAGE_SELF, &usage))
            return usage.ru_maxrss/1000/1000;
    #endif

    return 0;
}

int render(void*) {
    INPUT->prepareTick();
    NET->prepareTick();
    STACK->prepareTick();
    DOM->prepareTick();
    GUI->prepareTick();

    // TODO: ?

    INPUT->doTick(STACK, DOM, GUI);
    NET->doTick(STACK, DOM);
    STACK->doTick();
    DOM->doTick(STACK, GUI);
    GUI->doTick();

    #ifndef __NATIVE_GUI__
        return 1;
    #endif

    #ifndef __SWITCH__
        SDL_PumpEvents();
    #endif

    return 0;
}

bool running = true;
int main(int argc, char* argv[]) {
    printf("APP->Init\n");
    INPUT = new browser::INPUT();
    NET = new browser::NET();
    STACK = new browser::STACK();
    DOM = new browser::DOM();
    GUI = new browser::GUI();
    printf("APP->Init done\n");

    #ifdef __NATIVE_GUI__
        MainWindow *window = new MainWindow();
    #endif

    if (argc > 1)
        STACK->setSource(argv[1], true);
    
    #ifndef __NATIVE_GUI__
        #ifdef __SWITCH__
            while(appletMainLoop() && running) {
        #else
            while(running) {
        #endif
                currentTick = SDL_GetTicks();
                delta = currentTick - lastTick;
                    
                render(NULL);

                SDL_Delay(10);
                lastTick = currentTick;
            };
    #else
        uiTimer(1000, &render, NULL);
        uiMain();
    #endif

    delete GUI, DOM, STACK, NET, INPUT;
    return 0;
}