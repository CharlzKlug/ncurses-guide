#include <ncurses.h>

int main(void) {
  MEVENT mort;
  int ch;
  initscr();
  noecho();
  keypad(stdscr, TRUE);

  mousemask(ALL_MOUSE_EVENTS, NULL);

  while(1) {
    ch= getch();
    if(ch == KEY_MOUSE) {
      getmouse(&mort);
      clrtoeol();
      mvaddch(mort.y, mort.x, '*');
      move(0, 0);
      printw("%d\t%d", mort.y, mort.x);
      refresh();
      continue;
    }
    if(ch == '\n')
      break;
  }

  endwin();
  return 0;
}
