#include <stdio.h>
#include "stack.h"

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
    return 0;
}