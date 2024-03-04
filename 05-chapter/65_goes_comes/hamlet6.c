#include <ncurses.h>
#include <string.h>

int main(void) {
  char Ham1[]= "To be, or not to be: that is the question:\n";
  char Ham2[]= "Whether 'tis nobler in the mind to suffer\n";
  char Ham3[]= "The slings and arrows of outrageous fortune,\n";
  char Ham4[]= "Or to take arms against a sea of troubles,\n";
  char Ham5[]= "And by opposing end them?\n";
  int c;
  char some_word[]= "obnoxious";
  
  initscr();

  addstr(Ham1);
  addstr(Ham2);
  addstr(Ham3);
  addstr(Ham4);
  addstr(Ham5);
  refresh();
  getch();

  move(2, 25);
  for(c=0; c<10; c++) {
    delch();
    napms(100);
    refresh();
  }
  getch();

  /* Print "obnoxious" */
  move(2, 25);

  size_t i= strlen(some_word);
  do {
    i--;
    insch(some_word[i]);
    refresh();
    napms(100);
  } while (i != 0);

  getch();
  
  endwin();
  return 0;
}
