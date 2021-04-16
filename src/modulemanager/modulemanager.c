#include "modulemanager.h"
#include <stdlib.h>
#include <string.h>

struct n_module {
  unsigned int id;
  char *name;

  struct n_module *nextnode;
  struct n_module *lastnode;
};
typedef struct n_module n_module_t;

static n_module_t *module_nodes_start;
static n_module_t *module_nodes_end;

static int m_addNode(char *name) {
  n_module_t *newnode = malloc(sizeof(n_module_t));
  newnode->nextnode = NULL;
  newnode->id = module_nodes_end->id++;

  newnode->lastnode = module_nodes_end;
  module_nodes_end->nextnode = newnode;

  module_nodes_end = newnode;

  newnode->name = malloc(sizeof(char) * strlen(name));
  strcpy(newnode->name, name);

  return 0;
}

static int m_remNode(n_module_t *module) {
  /*If the module to be removed is the first in the list*/
  if (module == module_nodes_start) {
    module_nodes_start = module->nextnode;
  } else {
    module->lastnode->nextnode = module->nextnode;
  }

  /*If the module to be removed is the last in the list*/
  if (module == module_nodes_end) {
    module_nodes_end = module->lastnode;
  } else {
    module->nextnode->lastnode = module->lastnode;
  }

  /*Free the allocated Dogs*/
  free(module->name);
  free(module);

  return 0;
}

int mmanager_init() {
  /*Setup node list*/
  module_nodes_start = malloc(sizeof(n_module_t));
  module_nodes_start->id = 0;
  char *mmname = "ModuleManager";
  module_nodes_start->name = malloc(sizeof(char) * strlen(mmname));
  strcpy(module_nodes_start->name, mmname);
  module_nodes_start->lastnode = NULL;
  module_nodes_start->nextnode = NULL;
  module_nodes_end = module_nodes_start;

  return 0;
}

int mmanager_cleanup() {
  while (module_nodes_end != NULL) {
    m_remNode(module_nodes_end);
  }

  return 0;
}

int mmanager_module_cleanup() {}

int mmanager_exit() {}
