#include <iostream>
#include <Include/Config.h>
#include <boost/regex.hpp>

#include <GraphicsControler.h>
#include <GraphicWindow.h>

// int main(int argc, char* argv[])
// {
//     // inicjalizacja
//     GraphicsControler *graphicsControler = new GraphicsControler(argc, argv);

//     // pierwsze narysowanie wszystkiego
//     graphicsControler->RefreshScreen();
    
//     // dopóki user nie zamknął programu
//     while(graphicsControler->IsOpened())
//     {
//         // zebranie inputu od usera
//         graphicsControler->AnalyzeUserInput();

//         // odswiezenie grafiki     
//         graphicsControler->RefreshScreen();
//     }

//     // zwolnienie pamięci itp
//     delete graphicsControler;

//     return EXIT_SUCCESS;

// wymiary okna 65, 80
// }


/*
 * This demo displays the ability to put widgets within a curses subwindow.
 */
// int main (int argc, char **argv)
// {
//    CDKSCREEN *cdkscreen;
//    CDKSCROLL *dowList;
//    CDKLABEL *title;
//    WINDOW *subWindow;
//    const char *dow[] =
//    {
//       "Monday",
//       "Tuesday",
//       "Wednesday",
//       "Thursday",
//       "Friday",
//       "Saturday",
//       "Sunday"
//    };
//    const char *mesg[5];
//    int pick;

//    CDK_PARAMS params;

//    CDKparseParams (argc, argv, &params, "s:" CDK_CLI_PARAMS);

//    /* Start curses. */
//    (void) initCDKScreen (NULL);
//    curs_set (0);

//    /* Create a basic window. */
//    subWindow = newwin (LINES, COLS , 0, 0);

//    /* Start Cdk. */
//    cdkscreen = initCDKScreen (subWindow);

//    /* Box our window. */
//    box (subWindow, ACS_VLINE, ACS_HLINE);
//    wrefresh (subWindow);

//    /* Create a basic scrolling list inside the window. */
//    dowList = newCDKScroll (cdkscreen,
// 			   CDKparamValue (&params, 'X', CENTER),
// 			   CDKparamValue (&params, 'Y', CENTER),
// 			   CDKparsePosition (CDKparamString2 (&params,
// 							      's',
// 							      "RIGHT")),
// 			   CDKparamValue (&params, 'H', 10),
// 			   CDKparamValue (&params, 'W', 15),
// 			   "<C></U>Pick a Day",
// 			   (CDK_CSTRING2) dow, 7,
// 			   NONUMBERS,
// 			   A_REVERSE,
// 			   CDKparamValue (&params, 'N', TRUE),
// 			   CDKparamValue (&params, 'S', FALSE));

//    /* Put a title within the window. */
//    mesg[0] = "<C><#HL(30)>";
//    mesg[1] = "<C>This is a Cdk scrolling list";
//    mesg[2] = "<C>inside a curses window.";
//    mesg[3] = "<C><#HL(30)>";
//    title = newCDKLabel (cdkscreen, CENTER, 0,
// 			(CDK_CSTRING2) mesg, 4,
// 			FALSE, FALSE);

//    /* Refresh the screen. */
//    refreshCDKScreen (cdkscreen);

//    /* Let the user play. */
//    pick = activateCDKScroll (dowList, 0);

//    /* Clean up. */
//    destroyCDKScroll (dowList);
//    destroyCDKLabel (title);
//    eraseCursesWindow (subWindow);
//    destroyCDKScreen (cdkscreen);
//    endCDK ();

//    /* Tell them what they picked. */
//    printf ("You picked %s\n", dow[pick]);
//    ExitProgram (EXIT_SUCCESS);
// }


WINDOW *create_newwin(int height, int width, int starty, int startx);
void destroy_win(WINDOW *local_win);

int main(int argc, char *argv[])
{	WINDOW *my_win;
	int startx, starty, width, height;
	int ch;

	initscr();			/* Start curses mode 		*/
	cbreak();			/* Line buffering disabled, Pass on
					 * everty thing to me 		*/
	keypad(stdscr, TRUE);		/* I need that nifty F1 	*/

	height = 3;
	width = 10;
	starty = (LINES - height) / 2;	/* Calculating for a center placement */
	startx = (COLS - width) / 2;	/* of the window		*/
	printw("Press F1 to exit");
	refresh();
	my_win = create_newwin(height, width, starty, startx);

	while((ch = getch()) != KEY_F(1))
	{	switch(ch)
		{	case KEY_LEFT:
				destroy_win(my_win);
				my_win = create_newwin(height, width, starty,--startx);
				break;
			case KEY_RIGHT:
				destroy_win(my_win);
				my_win = create_newwin(height, width, starty,++startx);
				break;
			case KEY_UP:
				destroy_win(my_win);
				my_win = create_newwin(height, width, --starty,startx);
				break;
			case KEY_DOWN:
				destroy_win(my_win);
				my_win = create_newwin(height, width, ++starty,startx);
				break;	
		}
	}
		
	endwin();			/* End curses mode		  */
	return 0;
}

WINDOW *create_newwin(int height, int width, int starty, int startx)
{	WINDOW *local_win;

	local_win = newwin(height, width, starty, startx);
	box(local_win, 0 , 0);		/* 0, 0 gives default characters 
					 * for the vertical and horizontal
					 * lines			*/
	wrefresh(local_win);		/* Show that box 		*/

	return local_win;
}

void destroy_win(WINDOW *local_win)
{	
	/* box(local_win, ' ', ' '); : This won't produce the desired
	 * result of erasing the window. It will leave it's four corners 
	 * and so an ugly remnant of window. 
	 */
	wborder(local_win, ' ', ' ', ' ',' ',' ',' ',' ',' ');
	/* The parameters taken are 
	 * 1. win: the window on which to operate
	 * 2. ls: character to be used for the left side of the window 
	 * 3. rs: character to be used for the right side of the window 
	 * 4. ts: character to be used for the top side of the window 
	 * 5. bs: character to be used for the bottom side of the window 
	 * 6. tl: character to be used for the top left corner of the window 
	 * 7. tr: character to be used for the top right corner of the window 
	 * 8. bl: character to be used for the bottom left corner of the window 
	 * 9. br: character to be used for the bottom right corner of the window
	 */
	wrefresh(local_win);
	delwin(local_win);
}