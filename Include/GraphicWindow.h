#pragma once

#include <cdk.h>
#include <cdk/cdk_test.h>
#include <ncurses.h>

typedef enum
{
    WINDOW_RESPONSE_CLOSE  = 0x01,
    WINDOW_RESPONSE_CANCEL = 0x02,
} WindowResponseType;

class GraphicWindow
{
private:
    CDKSCREEN *screen;
    uint8_t    isOpened;

public:
    GraphicWindow();
    ~GraphicWindow();

    void    Routine();
    void    Refresh();
    uint8_t IsOpened();
    WindowResponseType AnalyzeInput(char input);
};

