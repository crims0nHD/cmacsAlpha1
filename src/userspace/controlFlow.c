#include "logger.h"
#include "userspace.h"
#include <stdlib.h>

int ForceStop() {
  logerror("I don't know what happened but imma stop now!");
  exit(69);
}
