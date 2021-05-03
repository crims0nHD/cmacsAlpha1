#include "logger.h"
#include "config.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static FILE *file;
static bool initialized = false;

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

int log_echo(char *filepath) {
  if (initialized)
    return -1;

  char cmdBuffer[2048];

  if (strlen(filepath) >= 2048 - 100) {
    return -2;
  }

  strcpy(cmdBuffer, "/bin/sh -c \"cat ");
  strcat(cmdBuffer, filepath);
  strcat(cmdBuffer, "\"");

  FILE *fp;
  char path[1035];

  /* Open the command for reading. */
  fp = popen(cmdBuffer, "r");
  if (fp == NULL) {
    logerror("Failed to run command\n");
    return -3;
  }

  /* Read the output a line at a time - output it. */
  while (fgets(path, sizeof(path), fp) != NULL) {
    printf("%s", path);
  }

  /* close */
  pclose(fp);

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
