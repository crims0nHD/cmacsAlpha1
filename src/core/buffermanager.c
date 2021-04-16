#include "core.h"
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef struct lln_buffer {
  buffer_t *this;
  struct lln_buffer *next;
  struct lln_buffer *prev;
} lln_buffer_t;

static lln_buffer_t *ll_start;
static lln_buffer_t *ll_end;

static int lln_remove(lln_buffer_t)

    int bman_init() {
  // setup the list
  ll_start = malloc(sizeof(lln_buffer_t));
  ll_end = ll_start;

  // setup first node
  ll_start->this = malloc(sizeof(buffer_t));
  ll_start->next = NULL;
  ll_start->prev = NULL;

  // setup first buffer
  char *fallback_name = "fallbackbuffer";
  ll_start->this->name = malloc(sizeof(char) * strlen(fallback_name));
  strcpy(ll_start->this->name, fallback_name);
  ll_start->this->flags = (0 | B_FLAG_PROTECTED | B_FLAG_READONLY);
  ll_start->this->content = NULL;

  return 0;
}

int bman_exit() {
  lln_buffer_t *purge = ll_start->next;
  while (purge != NULL) {
    b_delete(purge->this);
    purge = purge->next;

    if (purge->prev != ll_start)
  }
}
