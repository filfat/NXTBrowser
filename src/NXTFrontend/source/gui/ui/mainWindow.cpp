#include "gui/ui/mainWindow.h"
#define _DEFAULT_WIDTH 1024

MainWindow::MainWindow() {
    printf("GUI->UI->MainWindow->Init\n");

	window = uiNewWindow("NXTBrowser", _DEFAULT_WIDTH, 620, 1);

    uiBox *container = uiNewVerticalBox();

    // AddressBar

    #ifndef __DARWIN__
        address_bar_entry = uiNewEntry();
        uiEntrySetText(address_bar_entry, "http://lite.cnn.io/en");

        address_bar_group = uiNewForm();
        uiFormSetPadded(address_bar_group, 0);
        uiFormAppend(address_bar_group,
            NULL,
            uiControl(address_bar_entry),
            0);
        
        uiBoxAppend(container,
            uiControl(address_bar_group),
            0);
    #endif

    // BrowserArea
    browser_area_handler->Draw = BrowserAreaOnDraw;
    browser_area_handler->MouseEvent = BrowserAreaMouseEvent;
    browser_area_handler->MouseCrossed = BrowserAreaMouseCrossed;
    browser_area = uiNewScrollingArea(browser_area_handler, _DEFAULT_WIDTH, 1000);

    uiBoxAppend(container,
        uiControl(browser_area),
        1);

    uiWindowSetChild(window, uiControl(container));
    uiControlShow(uiControl(window));

    printf("GUI->UI->MainWindow->Init done\n");
}

MainWindow::~MainWindow() {
	
}

void MainWindow::BrowserAreaOnDraw(uiAreaHandler* handler, uiArea* area, uiAreaDrawParams* params) {
    uiDrawBrush *brush = new uiDrawBrush;
    brush->Type = uiDrawBrushTypeSolid;
    brush->A = 255;
    brush->R = 255;
    brush->G = 255;
    brush->B = 255;

    uiDrawPath *path = uiDrawNewPath(uiDrawFillModeWinding);
    uiDrawPathAddRectangle(path, 0, 0, _DEFAULT_WIDTH, 1000);
    uiDrawPathEnd(path);

    uiDrawFill(params->Context, path, brush);
}
void MainWindow::BrowserAreaMouseEvent(uiAreaHandler *, uiArea *, uiAreaMouseEvent *) {}
void MainWindow::BrowserAreaMouseCrossed(uiAreaHandler *, uiArea *, int left) {
    printf("GUI->UI->MainWindow->Mouse->%d\n", !left);
}