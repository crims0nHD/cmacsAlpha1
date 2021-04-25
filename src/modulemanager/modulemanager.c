#include "modulemanager.h"
#include "types/linkedlist.h"
#include <stdlib.h>
#include <string.h>

typedef struct n_module {
  unsigned int id;
  char *name;
} n_module;

static LLnode *module_nodes_start, *module_nodes_end;

static int m_addNode(char *name) {
  n_module *m = malloc(sizeof(n_module));
  LLnode *nextn = LL_addNode(module_nodes_end, m);

  m->id = ((n_module *)module_nodes_end->content)->id++;
  m->name = malloc(sizeof(char) * strlen(name));
  strcpy(m->name, name);

  module_nodes_end = nextn;
  return 0;
}

static int m_remNode(LLnode *n) {
  n_module *m = n->content;
  /*Free the allocated Dogs*/
  free(m->name);
  free(m);
  n->content = NULL;

  if (LL_nextNode(n) == NULL)
    module_nodes_end = LL_prevNode(n);

  if (LL_prevNode(n) == NULL) {
    module_nodes_start = LL_nextNode(n);
  }

  LL_remNode(n);

  return 0;
}

int mmanager_init() {
  /*Setup node list*/
  n_module *m = malloc(sizeof(n_module));
  m->id = 0;
  char *mmname = "ModuleManager";
  m->name = malloc(sizeof(char) * strlen(mmname));
  strcpy(m->name, mmname);

  module_nodes_start = LL_addNode(NULL, m);
  module_nodes_end = module_nodes_start;

  return 0;
}

int mmanager_cleanup() {
  while (module_nodes_end != NULL) {
    m_remNode(module_nodes_end);
  }

  return 0;
}

int mmanager_module_cleanup() { return 0; }

int mmanager_exit() { return 0; }
