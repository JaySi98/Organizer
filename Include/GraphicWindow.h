#pragma once

#include <cdk.h>
#include <cdk/cdk_test.h>
#include <ncurses.h>

class GraphicWindow
{
private:

    CDKSCREEN *screen;

public:
    GraphicWindow();
    ~GraphicWindow();
};

