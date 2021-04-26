#include "config.h"
#include "core.h"
#include "display_ncurses.h"
#include "logger.h"
#include "modulemanager.h"

#include <stdbool.h>

extern int OnStartup();

static int cleanup_resources() {
  log_exit();
  mmanager_module_cleanup();
  mmanager_cleanup();
  mmanager_exit();
  return 0;
}

static void loop() {
  volatile bool isRunning = true;
  while (isRunning) {
    display_ncurses_routine_output();
    if (display_ncurses_routine_input()) {
      // If function returns something other than 0:

      isRunning = false;
    }
  }
}

int main(int argc, char **argv) {
  log_init(NULL);
  mmanager_init();
  logwarning("Started Application...");

  OnStartup();

  if (TUI_NCURSES) {
    display_ncurses_start();
    logmessage("Started Ncurses...");
  }

  loop();

  if (TUI_NCURSES) {
    display_ncurses_stop();
    logmessage("Stopped Ncurses");
  }

  logmessage("Stopped Application");
  cleanup_resources();
  return 0;
}
