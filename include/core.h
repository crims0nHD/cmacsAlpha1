#ifndef __CORE_H_
#define __CORE_H_

#include <stdbool.h>

#define B_FLAG_READONLY 1  // denies editing
#define B_FLAG_PROTECTED 2 // denies messing arround with name or deletion
#define B_FLAG_IS_FILE 4   // makes sure delete also closes stream or whatever

// TODO
typedef void buffercontent_t;

typedef struct buffer {
  char *name;
  unsigned int flags;
  buffercontent_t *content;
} buffer_t;

// Initialize buffer manager
extern int bman_init();

// Deinitialize buffer manager
extern int bman_exit();

// Create new buffer; return -1 if unsuccessful
extern buffer_t *b_create(char *name, bool readonly, bool protected);

// Delete the buffer; returns -1 if fallback buffer
extern int b_delete(buffer_t *b);

#endif // __CORE_H_
