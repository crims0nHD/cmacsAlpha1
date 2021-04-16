#include "logger.h"
#include <stdbool.h>
#include <stdio.h>

static FILE *file;
static bool initialized = 0;

int log_init(char *filepath) {
  if (initialized) {
    logerror("Log is already initialized");
    return 1;
  }

  if (file != NULL)
    file = fopen(filepath, "a");
  return 0;
}

int log_exit() {
  if (!initialized) {
    logerror("Log is not initialized");
    return 1;
  }

  fclose(file);
  return 0;
}

int logerror(char *error) {
  if (!initialized) {
    logerror("Log is not initialized");
    return 1;
  }

  fprintf(stderr, "%s", error);
  if (file != NULL)
    fprintf(file, "ERROR: %s", error);
  return 0;
}

int logwarning(char *warning) {
  if (!initialized) {
    logerror("Log is not initialized");
    return 1;
  }

  fprintf(stdout, "%s", warning);
  if (file != NULL)
    fprintf(file, "WARNING: %s", warning);
  return 0;
}

int logmessage(char *message) {
  if (!initialized) {
    logerror("Log is not initialized");
    return 1;
  }

  fprintf(stdout, "%s", message);
  if (file != NULL)
    fprintf(file, "MESSAGE: %s", message);
  return 0;
}
