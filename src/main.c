#include "core.h"
#include "logger.h"
#include "modulemanager.h"

static int cleanup_resources() {
  log_exit();
  mmanager_module_cleanup();
  mmanager_cleanup();
  return 0;
}

int main(int argc, char **argv) {
  // Parse arguments

  log_init(NULL);
  mmanager_init();
  logmessage("Started Application...");

  cleanup_resources();
  logmessage("Stopped Application");
  return 0;
}
