#include <GraphicWindow.h>

GraphicWindow::GraphicWindow()
{
    screen = initCDKScreen(stdscr);
}

GraphicWindow::~GraphicWindow()
{
    destroyCDKScreen(screen);
}