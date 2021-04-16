#include "module.h"
#include "logger.h"

int module_load() {
  logmessage("Module template loaded!");
  return 0;
}

int module_cleanup() {
  logmessage("All resources are cleaned up :)");
  return 0;
}

int module_unload() {
  logmessage("Module template unloaded!");
  return 0;
}
