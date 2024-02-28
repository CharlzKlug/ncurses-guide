/* How to build: gcc -Wall -Werror -Wextra main.c -lncurses */
#include <ncurses.h>

int main(void) {
  initscr();

  box(stdscr, '*', '*');
  refresh();
  getch();

  endwin();
  return 0;
}
