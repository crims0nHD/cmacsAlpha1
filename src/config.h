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
#define DEBUG_LOG_PATH "/tmp/cmacsLog.txt"
#define DEBUG_LOG_ECHO_AFTER_CLOSE true

/* On Startup */
/* ---------- */
extern int OnStartup();

#endif // __CONFIG_H_
