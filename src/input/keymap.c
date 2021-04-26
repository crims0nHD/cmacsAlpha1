#include "input.h"
#include "types/linkedlist.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// TODO: use hash maps

struct km_binding {
  int (*fun)(void);
  unsigned int key;
  unsigned int mods;
};
typedef struct km_binding km_binding;

static LLnode *llbindings_start = NULL, *llbindings_end = NULL;

static LLnode *km_get(unsigned int key, unsigned int mods) {
  LLnode *search = llbindings_start;

  while (true) {
    if (search == NULL)
      return NULL;
    if ((((km_binding *)search->content)->key) == key &&
        ((km_binding *)search->content)->mods == mods)
      return search;
    search = LL_nextNode(search);
  }
}

static int km_set(int (*fun)(void), unsigned int key, unsigned int mods) {
  LLnode *k = km_get(key, mods);
  if (k) {
    ((km_binding *)k->content)->fun = fun;
  } else {
    km_binding *bind = malloc(sizeof(km_binding));
    bind->key = key;
    bind->mods = mods;
    bind->fun = fun;

    LLnode *n = LL_addNode(llbindings_end, bind);
    if (llbindings_start == NULL) {
      llbindings_start = n;
    }
  }

  return 0;
}

static int km_reset(unsigned int key, unsigned int mods) {
  LLnode *n = km_get(key, mods);
  if (n != NULL)
    LL_remNode(n);
  return 0;
}

int input_map_key(int (*fun)(void), unsigned int key, unsigned int mods) {
  km_set(fun, key, mods);
  return 0;
}

int input_do_key(unsigned int key, unsigned int mods) {
  LLnode *n = km_get(key, mods);
  if (n != NULL) {
    return (*((km_binding *)n->content)->fun)();
  }
  return -1;
}
