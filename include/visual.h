#ifndef __VISUAL_H_
#define __VISUAL_H_

#include "buffer.h"
#include "core.h"
#include <stdbool.h>

typedef struct cursor {
  unsigned int pos_x;
  unsigned int pos_y;
} cursor_t;

typedef struct workspace {
  char *name;
} workspace_t;

typedef struct window {
  bool focused;
  buffer_t *buffer;
  cursor_t *cursor;
  workspace_t *workspace;
  unsigned int scrolled_lines_x; // naming?
  unsigned int scrolled_lines_y;
  unsigned int size_x;
  unsigned int size_y;
  unsigned int pos_x;
  unsigned int pos_y;
} window_t;

extern int w_queryByWorkspace(char *ws_name, window_t **out_windows,
                              int *out_length);

#endif // __VISUAL_H_
