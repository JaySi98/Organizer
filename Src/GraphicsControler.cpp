#include <GraphicsControler.h>

GraphicsControler::GraphicsControler(int argc, char* argv[])
{
    CDKparseParams (argc, argv, &params, CDK_MIN_PARAMS);

    currentWindow = new GraphicWindow();
    isOpened = 1;
}

GraphicsControler::~GraphicsControler()
{
    delete currentWindow;
    endCDK ();
}

/*!
 * @brief Returns signal if user closed the app
 */ 
uint8_t GraphicsControler::IsOpened()
{
    return isOpened;
}

/*!
 * @brief Refreshes screen
 */
void GraphicsControler::RefreshScreen()
{
    currentWindow->Refresh();
}

/*!
 * @brief Waits for users input then analise it based on
 *        currently opened window
 */
void GraphicsControler::AnalyzeUserInput()
{
    char input = INPUT_INIT_VALUE;
    while (input = (char)getch ()) { }

    WindowResponseType response =  currentWindow->AnalyzeInput(input);
    
    // podjecie akcji w zaleznosci od wartosci
    if(response == WINDOW_RESPONSE_CLOSE)
    {
        isOpened = 0;
    }
}