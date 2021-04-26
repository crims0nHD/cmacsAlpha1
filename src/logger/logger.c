#include "logger.h"
#include "config.h"
#include <stdbool.h>
#include <stdio.h>

static FILE *file;
static bool initialized = 0;

int log_init(char *filepath) {
  if (initialized) {
    logerror("Log is already initialized");
    return -1;
  }

  if (file != NULL)
    file = fopen(filepath, "a");

  initialized = true;
  return 0;
}

int log_exit() {
  if (!initialized) {
    logerror("Log is not initialized");
    return -1;
  }

  if (file != NULL)
    fclose(file);

  initialized = false;
  return 0;
}

int logerror(char *error) {
  if (!initialized) {
    return -1;
  }

#ifndef TUI_NCURSES
  fprintf(stderr, "%s\n", error);
#endif

  if (file != NULL)
    fprintf(file, "ERROR: %s\n", error);
  return 0;
}

int logwarning(char *warning) {
  if (!initialized) {
    return -1;
  }

#ifndef TUI_NCURSES
  fprintf(stderr, "%s\n", warning);
#endif

  if (file != NULL)
    fprintf(file, "WARNING: %s\n", warning);
  return 0;
}

int logmessage(char *message) {
  if (!initialized) {
    return -1;
  }

#ifndef TUI_NCURSES
  fprintf(stdout, "%s\n", message);
#endif

  if (file != NULL)
    fprintf(file, "MESSAGE: %s\n", message);
  return 0;
}
