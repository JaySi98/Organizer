#include <GraphicWindow.h>

GraphicWindow::GraphicWindow()
{
    screen = initCDKScreen(stdscr);
    isOpened = 0;

    drawCDKScreen (screen);
}

GraphicWindow::~GraphicWindow()
{ 
    destroyCDKScreen(screen);
}

void GraphicWindow::Refresh()
{
    refreshCDKScreen(screen);
}

void GraphicWindow::Routine()
{

}

WindowResponseType GraphicWindow::AnalyzeInput(char input)
{
    if(input == 'q')
    {
        return WINDOW_RESPONSE_CLOSE;
    }

    return WINDOW_RESPONSE_CANCEL;
}

uint8_t GraphicWindow::IsOpened()
{
    return isOpened;
}