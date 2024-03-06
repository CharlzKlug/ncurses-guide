#include <ncurses.h>

int kbhit(void) {
  int ch, r;

  /* turn off getch() blocking and echo  */
  nodelay(stdscr, TRUE);
  noecho();

  /* check for input */
  ch = getch();
  if (ch == ERR)
    r = FALSE;
  else {
    r = TRUE;
    ungetch(ch);
  }

  /* restore block and echo */
  echo();
  nodelay(stdscr, FALSE);
  return (r);
}

int main(void) {
  initscr();

  addstr("Press any key to end this program:");
  while (!kbhit());

  endwin();
  return 0;
}
