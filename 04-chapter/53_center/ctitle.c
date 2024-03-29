#include <ncurses.h>
#include <string.h>

void center(int row, char *title);

int main(void) {
  initscr();

  center(1, "Penguin Soccer Finals");
  center(5, "Cattle Dung Samples from Temecula");
  center(7, "Catatonic Theater");
  center(9, "Why Do Ions Hate Each Other?");
  getch();

  endwin();
  return 0;
}

void center(int row, char *title) {
  int len, indent, width;

  width= getmaxx(stdscr);

  len= strlen(title);
  indent= width - len;
  indent /= 2;

  mvaddstr(row, indent, title);
  refresh();
}
