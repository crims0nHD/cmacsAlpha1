#include "display_ncurses.h"
#include "types/linkedlist.h"
#include "types/null.h"
#include <ncurses.h>
#include <stdlib.h>

static char *screenbuffer;
static int width, height;

static LLnode *l_renderFunctions = NULL;

int r_setupPipeline() { return 0; }

int r_resetScreenbuffer() {
  int width, height;
  getmaxyx(stdscr, height, width);
  if (screenbuffer == NULL) {
    screenbuffer = malloc(sizeof(char) * width * height);
  } else {
    screenbuffer = realloc(screenbuffer, sizeof(char) * width * height);
  }
  return 0;
}

int r_addToPipeline() { return 0; }

char *getScreenbuffer() { return screenbuffer; }

int render() {
  // Clear screen
  for (int i = 0; i < width * height; i++)
    screenbuffer[i] = ' ';

  // Render bottom bar
  for (int i = 0; i < width; i++)
    screenbuffer[(height - 1) * width + i] = '#';

  return 0;
}
