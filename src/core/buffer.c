#include "buffer.h"
#include <stdbool.h>

bool b_checkflag(buffer_t *buffer, unsigned int flag) {
  return buffer->flags & flag;
}
