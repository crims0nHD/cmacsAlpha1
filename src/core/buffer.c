#include "buffer.h"
#include <stdbool.h>
#include <stdlib.h>

bool b_checkflag(buffer_t *b, unsigned int flag) { return b->flags & flag; }

int b_delete(buffer_t *b) {
  if (b_checkflag(b, B_FLAG_PROTECTED))
    return 1;

  if (b_checkflag(b, B_FLAG_IS_FILE)) {
    // TODO Do fancy close file stream or stuff
  }

  if (b->name != NULL) {
    free(b->name);
  }
  if (b->content != NULL) {
    free(b->content);
  }
  free(b);

  return 0;
}
