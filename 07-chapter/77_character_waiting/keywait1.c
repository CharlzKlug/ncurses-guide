#include <ncurses.h>

int main(void) {
  int value = 0;

  initscr();

  addstr("Press any key to begin:\n");
  refresh();
  getch();

  nodelay(stdscr, TRUE);
  addstr("Press any key to stop the insane loop!\n");
  while (getch() == ERR) {
    printw("%d\r", value++);
    refresh();
  }

  endwin();
  return 0;
}
