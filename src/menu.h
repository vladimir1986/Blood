#include <string.h>/* Required for strlen */
#include <ctype.h> /* Required for toupper */

#define VERSI "0.1-ALPHA"
#define menu1 "New game"
#define menu2 "Credits"
#define menu3 "Exit"

int menu(int row, int col)
{

  /***************************************************************************/
  /*        Assign the strings to print the same values as the DEFINES       */
  /***************************************************************************/
  
  char ver[] = VERSI;
  char mesg[] = menu1;
  char mesg2[]= menu2;
  char mesg3[] = menu3;

/* mvprintw(x,y,<message>);
   mvchgat(x,y, num_of_characters, Acction_in_char, colour_index, NULL); */
  init_pair(1,COLOR_GREEN,COLOR_BLACK);
  clear();
  attrset(COLOR_PAIR(1));

  mvprintw(0, (col/2) - strlen(ver), "BLOOD version %s", ver);
  mvprintw(row/2, (col - strlen(mesg))/2, "%s",mesg);
  mvprintw((row/2)+1, (col - strlen(mesg))/2, "%s",mesg2);
  mvprintw((row/2)+2, (col - strlen(mesg))/2, "%s",mesg3);

  mvchgat(row/2, (col-strlen(mesg))/2, 1, A_BOLD | A_UNDERLINE, 0, NULL);
  mvchgat((row/2)+1, (col-strlen(mesg))/2, 1, A_BOLD | A_UNDERLINE, 0, NULL);
  mvchgat((row/2)+2, (col-strlen(mesg))/2, 1, A_BOLD | A_UNDERLINE, 0, NULL);
  refresh();
  return(0);
}
