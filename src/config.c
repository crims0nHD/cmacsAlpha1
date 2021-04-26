#include "config.h"
#include "input.h"
#include "logger.h"
#include "userspace.h"

int keybindings() {
  input_map_key(&ForceStop, 'c', IMOD_CTRL);
  return 0;
}

int OnStartup() {
  keybindings();

  logwarning("OnStartup called!");
  return 0;
}
