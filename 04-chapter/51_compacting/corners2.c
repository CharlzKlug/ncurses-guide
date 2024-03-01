#include <ncurses.h>

int main(void) {
  int rows, cols;

  initscr();
  getmaxyx(stdscr, rows, cols);
  rows--;
  cols--;

  mvaddch(0, 0, '*');
  refresh();
  napms(500);

  mvaddch(0, cols, '*');
  refresh();
  napms(500);

  mvaddch(rows, 0, '*');
  refresh();
  napms(500);

  mvaddch(rows, cols, '*');
  refresh();

  getch();

  endwin();
  return 0;
}
