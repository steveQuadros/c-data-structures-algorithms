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

struct Node *Pop(struct Stack* s) {
    struct Node *tmp = s->top;
    free(s->top);
    s->top = tmp->next;
    return s->top;
}

struct Node *Push(struct Stack *s, int data) {
    struct Node *top = malloc(sizeof(struct Node));
    top->data = data;
    struct Node *tmp = s->top;
    s->top = top;
    top->next = tmp;
    return s->top;
}

struct Stack *Stack_Create() {
    struct Stack *s = malloc(sizeof(struct Stack));
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