#ifndef __BUFFER_H_
#define __BUFFER_H_
#include <stdbool.h>

enum {
  B_FLAG_READONLY = 1 << 0,  // denies editing
  B_FLAG_PROTECTED = 1 << 1, // denies messing arround with name or deletion
  B_FLAG_IS_FILE = 1 << 2,   // makes sure delete also closes stream or whatever
};

// TODO
typedef void buffercontent_t;

typedef struct buffer {
  char *name;
  unsigned int flags;
  buffercontent_t *content;
} buffer_t;

// Check if a flag is set on a buffer
extern bool b_checkflag(buffer_t *buffer, unsigned int flag);

// Create new buffer; return -1 if unsuccessful
extern buffer_t *b_create(char *name, bool readonly, bool protected);

// Delete the buffer; returns -1 if fallback buffer
extern int b_delete(buffer_t *b);

#endif // __BUFFER_H_
