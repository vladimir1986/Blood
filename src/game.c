#include "enemy.h"

int game (int row,int col)
{
  row=1;
  col=1;
  int ch;
  int x,y;

  getmaxyx(stdscr,x,y);
  ch=0;

  int enemyx = rand() % (x+1);
  int enemyy = rand() % (y+1);

  /***************************************************************************/
  /*                              Define colours                             */
  /***************************************************************************/

  init_pair(1,COLOR_RED,COLOR_BLACK);
  init_pair(2,COLOR_BLUE,COLOR_BLACK);
  
  clear();
  attron(COLOR_PAIR(1));
  box(stdscr, '|','-');
  keypad(stdscr,TRUE);
  //  mvaddch(row,col,ACS_DIAMOND);
  
  do
    {
      attron(COLOR_PAIR(2));
      enemy(enemyx,enemyy);
      attroff(COLOR_PAIR(2));
      attron(COLOR_PAIR(1));      
      ch=getch();
      ch=toupper(ch);
      mvaddch(row,col,ACS_DIAMOND);
      switch (ch)
	{

	case KEY_DOWN:
	  mvaddch(row,col,' ');
	    row=row+1;
	    mvaddch(enemyx,enemyy,' ');
	    enemyx=enemyx-1;
	    if (enemyx==0) enemyx=enemyx+1;
		enemy(enemyx,enemyy);
	    if (row==x-1) row=row-1;
		mvaddch(row,col,ACS_DIAMOND);
	  break;

	case KEY_UP:
	  mvaddch(row,col,' ');
	  row=row-1;
	  mvaddch(enemyx,enemyy,' ');
	  enemyx=enemyx+1;
	  if (enemyx==x-1) enemyx=enemyx-1;
	      enemy(enemyx,enemyy);
	  if (row==0) row=row+1;
	      mvaddch(row,col,ACS_DIAMOND);
	  break;

	case KEY_RIGHT:
	  mvaddch(row,col,' ');
	  col=col+1;
	  mvaddch(enemyx,enemyy,' ');
	  enemyy=enemyy-1;
	  if (enemyy==0) enemyy=enemyy+1;
	      enemy(enemyx,enemyy);
 
	  if (col==y-1) col=col-1;
	      mvaddch(row,col,ACS_DIAMOND);
	  break;

	case KEY_LEFT:
	  mvaddch(row,col,' ');
	  col=col-1;
	  mvaddch(enemyx,enemyy,' ');
	  enemyy=enemyy+1;
	  if (enemyy==y-1) enemyy=enemyy-1;
	      enemy(enemyx,enemyy);
	  if (col==0) col=col+1;
	      mvaddch(row,col,ACS_DIAMOND);
	  break;
	  refresh();
	default:
	  return(0);
	}
    } while (ch || 'Q');
  attroff(COLOR_PAIR(1));
  return(0);
}
