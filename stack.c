#include <stdio.h>
#include <stdlib.h>

/**
 * Stack implementation using singly linked list
 */

struct Stack {
    struct Node* top;
};

struct Node {
    int data;
    struct Node *next;
};

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

void Print(struct Stack *s) {
    struct Node *node = s->top;
    while(node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

int main(int argc, char *argv[]) {
    struct Stack *s = Stack_Create();

    Pop(s);

    Push(s, 5);
    Print(s);
    Push(s, 12);
    Print(s);
    Push(s, 23);
    Print(s);
    Push(s, 1);
    Print(s);

    Pop(s);
    Print(s);
    Pop(s);
    Print(s);

    Push(s, 4895);
    Print(s);
}