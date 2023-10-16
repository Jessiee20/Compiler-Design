#include <stdio.h>
#include <string.h>
char productions[][10] = {
    "A->aB",
    "B->bC",
    "C->cA",
    "C->d"
};
int n = 4;
int isNonTerminal(char c) {
    return (c >= 'A' && c <= 'Z');
}
void computeFollow(char nonTerminal) {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 3; j < strlen(productions[i]); j++) {
            if (productions[i][j] == nonTerminal) {
                if (j == strlen(productions[i]) - 1) {
                    computeFollow(productions[i][0]);
                } else {
                    while (j < strlen(productions[i]) - 1) {
                        if (isNonTerminal(productions[i][j + 1])) {
                            computeFollow(productions[i][j + 1]);
                            break;
                        } else {
                            printf("FOLLOW(%c) = %c\n", nonTerminal, productions[i][j + 1]);
                            break;
                        }
                        j++;
                    }
                }
            }
        }
    }
}

int main() {
    char nonTerminal = 'A'; 
    printf("FOLLOW(%c):\n", nonTerminal);
    computeFollow(nonTerminal);
    return 0;
}
