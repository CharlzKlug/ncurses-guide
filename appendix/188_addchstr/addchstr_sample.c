#include <ncurses.h>

int main(void) {
  chtype text[6]= {'H' | A_BOLD | A_UNDERLINE, 'e', 'l', 'l', 'o', '\0'};

  initscr();

  addchstr(text);
  refresh();
  getch();

  endwin();
  return 0;
}
