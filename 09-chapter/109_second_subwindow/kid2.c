#include <ncurses.h>

int main(void) {
  WINDOW *sonny, *babygirl;

  initscr();
  start_color();
  init_pair(1, COLOR_WHITE, COLOR_BLUE);
  init_pair(2, COLOR_RED, COLOR_YELLOW);
  init_pair(3, COLOR_CYAN, COLOR_WHITE);

  sonny = subwin(stdscr, 5, 20, 10, 30);
  babygirl = derwin(stdscr, 5, 20, 1, 50);

  bkgd(COLOR_PAIR(1));
  addstr("Hello, son, hello baby girl.");
  wbkgd(sonny, COLOR_PAIR(2));
  waddstr(sonny, "Hello, Dad.");
  wbkgd(babygirl, COLOR_PAIR(3));
  waddstr(babygirl, "Hello, Papa.");
  refresh();
  getch();

  endwin();
  return 0;
}
