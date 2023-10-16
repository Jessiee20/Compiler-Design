#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char stack[100];
int top = -1;
void push(char symbol) {
    stack[++top] = symbol;
}
char pop() {
    return stack[top--];
}
void shift(char input) {
    push(input);
}
void reduce() {
    char reduced[3];
    int i;
    
    for (i = 0; i < 3; i++) {
        reduced[2 - i] = pop();
    }
    if (strcmp(reduced, "E+E") == 0 || strcmp(reduced, "E-E") == 0 || strcmp(reduced, "E*E") == 0 || strcmp(reduced, "(E)") == 0) {
        push('E'); 
    } else {
        printf("Error in parsing.\n");
        exit(1);
    }
}
int main() {
    char input[100];
    printf("Enter an expression: ");
    scanf("%s", input);
    push('$'); 
    int i = 0;
    while (i < strlen(input)) {
        shift(input[i]);
        i++;
        while (stack[top] == 'E') {
            reduce();
        }
    }
    if (stack[0] == 'E' && stack[1] == '$') {
        printf("Parsing successful!\n");
    } else {
        printf("Parsing failed.\n");
    }

    return 0;
}
