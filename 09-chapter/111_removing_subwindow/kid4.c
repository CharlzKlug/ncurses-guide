#include <ncurses.h>

int main(void) {
  WINDOW *grandpa, *father, *boy;
  int maxx, maxy;

  initscr();
  refresh();
  
  start_color();
  init_pair(1, COLOR_WHITE, COLOR_BLUE);
  init_pair(2, COLOR_RED, COLOR_YELLOW);
  init_pair(3, COLOR_CYAN, COLOR_GREEN);

  getmaxyx(stdscr, maxy, maxx);

  grandpa= newwin(maxy-4, maxx-10, 2, 5);
  father= subwin(grandpa, maxy-8, maxx-20, 4, 10);
  boy= subwin(father, maxy-16, maxx-40, 8, 20);

  wbkgd(grandpa, COLOR_PAIR(1));
  waddstr(grandpa, "Grandpa\n");
  wbkgd(father, COLOR_PAIR(2));
  waddstr(father, "Father\n");
  wbkgd(boy, COLOR_PAIR(3));
  waddstr(boy, "Boy\n");
  wrefresh(grandpa);
  getch();

  delwin(boy);
  wclear(father);
  waddstr(father, "Bye, son!\n");
  wrefresh(father);
  getch();

  endwin();
  return 0;
}
