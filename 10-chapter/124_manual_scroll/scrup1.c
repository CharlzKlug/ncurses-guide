#include <ncurses.h>

int main(void) {
  initscr();

  int maxy;
  maxy= getmaxy(stdscr);

  scrollok(stdscr, TRUE);

  for (int y= 0; y <= maxy; y++)
    mvprintw(y, 0, "This is boring text written to line %d.", y);
  refresh();
  getch();

  scroll(stdscr);
  refresh();
  getch();

  endwin();
  return 0;
}
