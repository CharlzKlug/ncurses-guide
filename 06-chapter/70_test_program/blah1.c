#include <ncurses.h>

int main(void) {
  int c, y, x, cmax;

  initscr();

  getmaxyx(stdscr, y, x);
  cmax = (x * y) / 5;
  for (c=0; c < cmax; c++) addstr("blah ");
  refresh();

  getch();

  endwin();
  return 0;
}
