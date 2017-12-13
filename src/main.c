#include <stdio.h>
#include <ncurses.h>


#include "menu.h"
#include "game.c"
#include "credits.c"

int main(void)
{
  char selector;
  int row,col;

  initscr();
  start_color();
  raw();
  cbreak(); /* Disable line buffering */
  keypad(stdscr,TRUE);
  noecho();
  curs_set(0); /*Don't show cursor*/

  getmaxyx(stdscr,row,col); /*Determine screen size*/

  for (;;)
    {
      /***********************************************************************/
      /*            Call menu and send the number of cols and rows           */
      /***********************************************************************/

      menu(row,col);

      selector = getch();
      selector = toupper(selector);
      switch(selector)
	{
	case 'N' :
	  {
	    game(row,col);
	    break;
	  }
	case 'C' :
	  {

	    credits(row,col);
	    break;
	  }
	case 'E' :
	  {
	    clear();
	    refresh();
	    endwin();
	    return(0);
	  }
	default :
        break;
       
	} /*End switch*/
    } /*End For*/
return(0);
}
