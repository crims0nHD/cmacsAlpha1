#include "display_ncurses.h"
#include "input.h"
#include "logger.h"
#include <ncurses.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

int display_ncurses_start() {
  void *wind = initscr();
  if (wind == NULL)
    return -1;
  raw();
  keypad(stdscr, true);
  noecho();
  nodelay(stdscr, true);
  nl();
  clear();
  refresh();
  return 0;
}

int display_ncurses_stop() {
  endwin();
  return 0;
}

typedef struct {
  bool isControl;
  bool isMeta;
  bool isShift;
  char key;
} keycode;

static keycode decode_input(int c) {
  keycode kc;
  kc.isControl = false;
  kc.isShift = false;
  kc.isMeta = false;
  char *n = keyname(c);
  int nlen = strlen(n);

  for (int i = 0; i < nlen; i++) {
    if (n[i] == '^')
      kc.isControl = true;
    if (n[i] == 'M')
      if (i + 1 < nlen)
        if (n[i + 1] == '-')
          kc.isMeta = true;
  }

  if (c == 3) // CTRL + c
    kc.key = 'c';
  else
    kc.key = n[nlen - 1];

  return kc;
}

int display_ncurses_routine_input() {
  int c = getch();
  if (c != ERR) {
    keycode kc = decode_input(c);

    unsigned int mods = 0;
    if (kc.isControl)
      mods |= IMOD_CTRL;
    if (kc.isMeta)
      mods |= IMOD_META;
    if (kc.isShift)
      mods |= IMOD_SHIFT;

    input_do_key(kc.key, mods);
  }

  return 0;
}

int display_ncurses_routine_output() { return 0; }
