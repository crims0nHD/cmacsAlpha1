#include "input.h"

// TODO: use hash maps

static int km_set(int *fun, unsigned int key, unsigned int mods) {}

static int km_get(unsigned int key, unsigned int mods) {}

static int km_reset(unsigned int key, unsigned int mods) {}

int input_map_key(int *fun, unsigned int key, unsigned int mods) {
  km_set(fun, key, mods);
  return 0;
}
