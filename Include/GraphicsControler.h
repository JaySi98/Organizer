#pragma once

#include <stdint.h>

class GraphicsControler
{
private:
    uint8_t opened;

public:
    GraphicsControler();
    ~GraphicsControler();

    void MainLoopRoutine();
    uint8_t IsOpened();
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
