#include <ncurses.h>

int main(void) {
  initscr();
  int maxy, y;

  maxy= getmaxy(stdscr);
  scrollok(stdscr, TRUE);

  for (y= 0; y <= maxy; y++)
    mvprintw(y, 0, "This is boring text written to line %d.", y);
  refresh();
  getch();

  scrl(3);
  refresh();
  getch();

  endwin();
  printf("maxy: %d", maxy);
  return(0);
}
