#include "buffer.h"
#include "core.h"
#include "types/linkedlist.h"
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

static LLnode *ll_start, *ll_end;

static int bman_b_remove(LLnode *n) {
  if (b_checkflag((buffer_t *)n->content, B_FLAG_PROTECTED)) {
    return -1;
  }

  return 0;
}

static int bman_b_add(buffer_t *buffer) {
  ll_end = LL_addNode(ll_end, buffer);
  return 0;
}

int bman_init() {
  // setup first node
  buffer_t *b = malloc(sizeof(buffer_t));

  // setup first buffer
  char *fallback_name = "fallbackbuffer";
  b->name = malloc(sizeof(char) * strlen(fallback_name));
  strcpy(b->name, fallback_name);
  b->flags = (0 | B_FLAG_PROTECTED | B_FLAG_READONLY);
  b->content = NULL;

  // setup the list
  ll_start = LL_addNode(NULL, b);
  ll_end = ll_start;

  return 0;
}

int bman_exit() {
  LLnode *purge = ll_start->next;
  while (purge != NULL) {
    b_delete(purge->content);
    purge = purge->next;
    bman_b_remove(purge->prev);
  }

  return 0;
}
