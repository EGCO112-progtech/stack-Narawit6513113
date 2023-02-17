
#ifndef stack_h
#define stack_h
#include "node.h"
#include <stdlib.h>
typedef struct {
  NodePtr top;
  int size;
} Stack;

typedef Stack *StackPtr;
void push_stack(StackPtr s, char value) {
  Node *new_node = (NodePtr)malloc(sizeof(Node));
  if (new_node) {
    new_node->data = value;
    new_node->nextPtr = s->top;
    s->top = new_node;
    s->size++;
  }
}
char pop_stack(StackPtr s) {
  NodePtr t = s->top;
  char value;
  if (t) {
    t = s->top;
    value = t->data;
    s->top = t->nextPtr;
    s->size--;
    free(t);
    return value;
  }
  // printf("Empty stack\n");
  return 0;
}

void pop_all(StackPtr s) {
  while (s->size > 0) {
    // printf("%d", pop_stack(s));
    pop_stack(s);
    // s->size--;
  }
}
#endif
