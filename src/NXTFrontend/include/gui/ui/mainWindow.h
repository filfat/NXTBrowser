#pragma once
#include <stdio.h>

#include <libui/ui.h>

class MainWindow {
    public:
        MainWindow();
        ~MainWindow();

        static void BrowserAreaOnDraw(uiAreaHandler* handler, uiArea* area, uiAreaDrawParams* params);
        static void BrowserAreaMouseEvent(uiAreaHandler *, uiArea *, uiAreaMouseEvent *);
        static void BrowserAreaMouseCrossed(uiAreaHandler *, uiArea *, int left);
    private:
        uiWindow *window;

        uiEntry *address_bar_entry;
        uiForm *address_bar_group;

        uiArea *browser_area;
        uiAreaHandler *browser_area_handler = new uiAreaHandler;
};