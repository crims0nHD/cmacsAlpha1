#include "display_ncurses.h"

#include <curses.h>

int display_ncurses_start() {
  void *wind = initscr();
  if (wind == NULL)
    return -1;
  raw();
  noecho();
  return 0;
}

int display_ncurses_stop() {
  endwin();
  return 0;
}

int display_ncurses_routine_input() { return 0; }

int display_ncurses_routine_output() { return 0; }
