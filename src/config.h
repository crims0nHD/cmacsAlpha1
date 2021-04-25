#ifndef __CONFIG_H_
#define __CONFIG_H_

/* File description: Portable user configuration */

#include <stdbool.h>

/* Terminal user interface setup */
/* ----------------------------- */
#define TUI_NCURSES true

/* Debug settings */
/* -------------- */
#define DEBUG_CREATE_FILE_STRUCTURE true
const char* DEBUG_LOG_PATH = "/tmp/cmacsLog.txt";

#endif // __CONFIG_H_
