#include <ncurses.h>

#define FILENAME "gettysburg.txt"

int main(void) {
  FILE *text;
  WINDOW *lister;
  int maxy, maxx, ch;

  initscr();
  refresh();
  getmaxyx(stdscr, maxy, maxx);

  lister = newwin(maxy, maxx/2, 0, maxx/4);
  if (lister == NULL) {
    addstr("unable to create window\n");
    refresh(); getch();
    endwin();
    return(1);
  }

  scrollok(lister, true);
  
  text= fopen(FILENAME,  "r");
  if (text == NULL) {
    addstr("unable to open file\n");
    refresh(); getch();
    endwin();
    return(2);
  }

  do {
    ch = fgetc(text);
    waddch(lister, ch);
    wrefresh(lister);
  } while (ch != EOF);
  fclose(text);
  getch();

  endwin();
  return (0);
}
