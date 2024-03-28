#include <ncurses.h>

#define TSIZE 18

int main(void) {
  WINDOW *b;
  int maxy, maxx, y, x;

  initscr();
  refresh();
  
  getmaxyx(stdscr, maxy, maxx);
  x= (maxx - TSIZE) >> 1;
  bkgd('.');
  refresh();
  
  b= newwin(1, TSIZE, 0, x);
  waddstr(b, "I'm getting sick!");
  wrefresh(b);
  
  for (y= 1; y < maxy; y++) {
    mvwin(b, y, x);
    /* touchwin(stdscr); */
    touchline(stdscr, y-1, 1);
    refresh();
    wrefresh(b);
    getch();
  }

  endwin();
  return (0);
}
