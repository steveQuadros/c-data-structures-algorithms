#ifndef STACK_H_   /* Include guard */
#define STACK_H_

typedef struct Stack {
    struct Node* top;
} Stack;

typedef struct Node {
    int data;
    struct Node *next;
} Node;

void Pop(struct Stack* s);
void Push(struct Stack *s, int data);
int Stack_Empty(struct Stack *s);
Stack *Stack_Create();
void Print_Stack(struct Stack *s);

#endif //STACK_H_