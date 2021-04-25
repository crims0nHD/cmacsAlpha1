#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

struct LLnode {
  struct LLnode *prev;
  struct LLnode *next;

  void *content;
};

typedef struct LLnode LLnode;

extern LLnode *LL_addNode(LLnode *prevnode, void *content);
extern int LL_remNode(LLnode *node);

extern LLnode *LL_nextNode(LLnode *node);
extern LLnode *LL_prevNode(LLnode *node);

#endif // LINKEDLIST_H_
