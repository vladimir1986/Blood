int game (int row,int col)
{
  row=1;
  col=1;
  int ch;
  int x,y;

  getmaxyx(stdscr,x,y);
  ch=0;

  /***************************************************************************/
  /*                              Define colours                             */
  /***************************************************************************/

  init_pair(1,COLOR_RED,COLOR_BLACK);
  
  clear();
  box(stdscr, '|','-');
  keypad(stdscr,TRUE);
  attrset(COLOR_PAIR(1));
  mvaddch(row,col,ACS_DIAMOND);
  
  do
    {
      ch=getch();
      ch=toupper(ch);
      mvaddch(row,col,ACS_DIAMOND);
      switch (ch)
	{
	case KEY_DOWN:
	  mvaddch(row,col,' ');
	    row=row+1;
	    if (row==(x-1))
	      row=row-1;
	  mvaddch(row,col,ACS_DIAMOND);
	  break;
	case KEY_UP:
	  mvaddch(row,col,' ');
	  row=row-1;
	  if (row==0)
	    row=row+1;
	  mvaddch(row,col,ACS_DIAMOND);
	  break;
	case KEY_RIGHT:
	  mvaddch(row,col,' ');
	  col=col+1;
	  if (col==y-1)
	    col=col-1;
	  mvaddch(row,col,ACS_DIAMOND);
	  break;
	case KEY_LEFT:
	  mvaddch(row,col,' ');
	  col=col-1;
	  if (col==0)
	    col=col+1;
	  mvaddch(row,col,ACS_DIAMOND);
	  break;
	default:
	  return(0);
	}
    } while (ch || 'Q');
    getch();
  return(0);
}
