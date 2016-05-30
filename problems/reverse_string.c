#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *reverse_string(char *string) {
    char *c = string;
    int i, j, length = strlen(c);

    printf("%c is %d long\n", c[0], length);
    for (i = 0, j = length - 1; i < length && j > i; i++, j--) { //
            char tmp = c[i];
            c[i] = c[j];
            c[j] = tmp;
    }
    return c;
}

int string_length_get(char *c) {
    int i = 0;
    while( *(c + i) != '\0') {
        i++;
    }
    return i;
}

int main(int argc, char *argv[]) {
    char string[] = "hello\0";
    char *rev;
    int string_length;

    printf("Please enter a string:\n");
    printf("You entered %s\n", string);

    rev = reverse_string(string);
    printf("final: %s\n", rev);

    string_length = string_length_get(string);
    printf("Strlgnth by ptr: %d\n", string_length);

    return 0;
}