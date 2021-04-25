#include "types/linkedlist.h"
#include "logger.h"
#include <stdlib.h>

LLnode *LL_addNode(LLnode *prevnode, void *content) {
  if (prevnode == NULL) {
    LLnode *n = malloc(sizeof(LLnode));
    n->prev = NULL;
    n->next = NULL;
    n->content = content;

    return n;
  } else {
    LLnode *n = malloc(sizeof(LLnode));
    n->prev = prevnode;
    n->next = prevnode->next;
    n->content = content;

    prevnode->next = n;
    if (n->next != NULL) /* if prevnode is the last */
      n->next->prev = n;

    return n;
  }
}

int LL_remNode(LLnode *node) {
  LLnode *p, *n;
  p = node->prev;
  n = node->next;

  /* if node is not the first */
  if (p != NULL) {
    p->next = n;
  }

  /* if node is not the last */
  if (n != NULL) {
    n->prev = p;
  }

  if (node->content != NULL) {
    logwarning("Memory at pointer was not freed");
  }

  free(node);

  return 0;
}

LLnode *LL_nextNode(LLnode *node) { return node->next; }
LLnode *LL_prevNode(LLnode *node) { return node->prev; }
