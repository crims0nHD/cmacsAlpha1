#include "core.h"
#include "logger.h"
#include "modulemanager.h"

static int cleanup_resources() {
  log_exit();
  mmanager_module_cleanup();
  mmanager_cleanup();
  mmanager_exit();
  return 0;
}

int main(int argc, char **argv) {
  log_init(NULL);
  mmanager_init();
  logwarning("Started Application...");

  logmessage("Stopped Application");
  cleanup_resources();
  return 0;
}
