#include "config.h"
#include "input.h"
#include "logger.h"
#include "userspace.h"

int keybindings() {
  input_map_key(&Stop, 'c', IMOD_CTRL);
  input_map_key(&ForceStop, 'x', IMOD_CTRL);
  return 0;
}

int OnStartup() {
  keybindings();

  logwarning("OnStartup called!");
  return 0;
}
