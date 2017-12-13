#include <stdlib.h>
#include <unistd.h>

#define TMP 1 /*Change for the timer between messages*/

int credits (int row, int col)
{
  clear();
  printw("Text output: Inigo\n");
  refresh();
  sleep(TMP);
  printw("Blood and gore: Inigo\n");
  refresh();
  sleep(TMP);
  printw("Graphics: Inigo\n");
  refresh();
  sleep(TMP);
  printw("3D Engine: Inigo\n");
  refresh();
  sleep(TMP);
  mvprintw((row-1),1,"Created in 2017: Press any key to return to the main menu ;)");
  refresh();
  getch();
  return (0);
}
