#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../stack.h"

int is_balanced(char *str);
int string_length(char *str);
int is_target_char(char c);
int is_opening(char b);
int is_closing(char b);
int same_type(char o, char c);

char items[3][2] = {{'(', ')'}, {'{', '}'}, {'[', ']'}};

int is_balanced(char *str) {
    int i = 0, l = strlen(str);
    struct Stack *s = Stack_Create();

    for (i = 0; i < l; i++) {
        int opening = is_opening(str[i]);
        int closing = is_closing(str[i]);

        if (opening) {
            Push(s, str[i]);
        } else if (closing) {
            if (Stack_Empty(s) || same_type(s->top->data, str[i]) == 0) {
                return 0;
            }
            Pop(s);
        }
    }

    return Stack_Empty(s);
}

int same_type(char o, char c) {
    int i;
    for(i = 0; i < 3; i++) {
        if (items[i][0] == o) {
            return c == items[i][1];
        }
    }
    return 0;
}

int is_opening(char c) {
    int i;
    for(i = 0; i < 3; i++) {
        if(items[i][0] == c) {
            return 1;
        }
    }
    return 0;
}

int is_closing(char c) {
    int i;
    for(i = 0; i < 3; i++) {
        if(items[i][1] == c) {
            return 1;
        }
    }
    return 0;
}

/**
 * Test whether given examples have balanced parentheses, brackets, etc.
 *
 */
int main(int argc, char *argv[]) {
    char ex1[] = "(A+B)";
    char ex2[] = "[{(A+B)+(c+d)}]";
    char ex3[] = "{(x+y) * (z)";
    char ex4[] = "[2*3] + (A)]";
    char ex5[] = "{a+z)";
    int res;

    printf("Testing is_match function()\n");
    printf("{} should be 1 and is %d\n", same_type('{', '}'));
    printf("(} should be 0 and is %d\n", same_type('(', '}'));
    printf("{] should be 0 and is %d\n", same_type('{', ']'));
    printf("[] should be 0 and is %d\n", same_type('[', ']'));

    printf("\n\nBALANCE TEST --------");
    res = is_balanced(ex1);
    printf("ex 1 should be 1, your output %d\n", res);

    res = is_balanced(ex2);
    printf("ex 2 should be 1, your output %d\n", res);

    res = is_balanced(ex3);
    printf("ex 3 should be 0, your output %d\n", res);

    res = is_balanced(ex4);
    printf("ex 4 should be 0, your output %d\n", res);

    res = is_balanced(ex5);
    printf("ex 5 should be 0, your output %d\n", res);
    return 0;
}