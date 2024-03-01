#include <ncurses.h>

int main(void) {
  int rows, cols;

  initscr();
  getmaxyx(stdscr, rows, cols);
  rows--;
  cols--;

  move(0, 0);
  addch('*');
  refresh();
  napms(500);

  move(0, cols);
  addch('*');
  refresh();
  napms(500);

  move(rows, 0);
  addch('*');
  refresh();
  napms(500);

  move(rows, cols);
  addch('*');
  refresh();
  getch();

  endwin();
  return 0;
}
