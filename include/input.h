#ifndef __INPUT_H_
#define __INPUT_H_

enum {
  IMOD_SHIFT = 1 << 0,
  IMOD_META = 1 << 1,
  IMOD_CTRL = 1 << 2,
  IMOD_SUPER = 1 << 3
};

extern int input_map_key(int (*fun)(void), unsigned int key, unsigned int mods);

extern int input_umap_key(unsigned int key, unsigned int mods);

extern int input_do_key(unsigned int key, unsigned int mods);

#endif // __INPUT_H_
