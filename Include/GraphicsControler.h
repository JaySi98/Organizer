/*
 *
 */

#pragma once

#include <stdint.h>
#include <cdk.h>
#include <cdk/cdk_test.h>
#include <ncurses.h>

#include <GraphicWindow.h>

#define INPUT_INIT_VALUE ' '

class GraphicsControler
{
private:
    CDK_PARAMS params;

    uint8_t isOpened;
    GraphicWindow* currentWindow;

public:
    GraphicsControler(int argc, char* argv[]);
    ~GraphicsControler();

    uint8_t IsOpened();
    void    RefreshScreen();
    void    AnalyzeUserInput();
};







// MainWindow::MainWindow()
// {
//     // cdk screen init
//     cdkscreen = initCDKScreen (NULL);

//     /* Start CDK Colors. */
//     initCDKColor ();

//     /* Draw the CDK screen. */
//     refreshCDKScreen (cdkscreen);

// }

// MainWindow::~MainWindow()
// {
//     destroyCDKScreen (cdkscreen);
//     endCDK ();
//     ExitProgram (EXIT_SUCCESS);
// }
