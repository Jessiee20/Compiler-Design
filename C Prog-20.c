#include <stdio.h>
#include <stdbool.h>
#include <string.h>
bool parse(char *input, int start, int end, nonterminal nt, START_SYMBOL) {
}
int main() {
    char input[100]; 
    printf("Enter a string to check for ambiguity: ");
    scanf("%s", input);
    if (parse(input, 0, strlen(input), START_SYMBOL)) {
        printf("The grammar is ambiguous.\n");
    } else {
        printf("The grammar is not ambiguous.\n");
    }
    return 0;
}
