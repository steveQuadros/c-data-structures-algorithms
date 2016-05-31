/**
 * Stack implementation using singly linked list
 */

#include <stdio.h>
#include <stdlib.h>

#include "stack.h"

void Pop(struct Stack* s) {
    struct Node *tmp = s->top;
    if (tmp == NULL) return;
    free(s->top);
    s->top = tmp->next;
}

void Push(struct Stack *s, int data) {
    struct Node *top = (struct Node*)malloc(sizeof(struct Node));
    top->data = data;

    struct Node *tmp = s->top;
    s->top = top;
    top->next = tmp;
}

struct Stack *Stack_Create() {
    struct Stack *s = (struct Stack*)malloc(sizeof(struct Stack));
    s->top = NULL;
    return s;
}

int Stack_Empty(struct Stack *s) {
    return s->top == NULL ? 1 : 0;
}

void Print_Stack(struct Stack *s) {
    struct Node *node = s->top;
    printf("%d ", node->data);
    while(node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}