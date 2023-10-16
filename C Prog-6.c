#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RULES 10
#define MAX_FIRST_SET_SIZE 10

char grammar[MAX_RULES][MAX_FIRST_SET_SIZE];
int numRules;

int isTerminal(char symbol) {
    return (symbol >= 'a' && symbol <= 'z');
}

int isNonTerminal(char symbol) {
    return (symbol >= 'A' && symbol <= 'Z');
}

int hasEpsilon(char rule[]) {
    return (rule[0] == '@');
}

void calculateFirstSet(char nonTerminal) {
    int i, j;
    for (i = 0; i < numRules; i++) {
        if (grammar[i][0] == nonTerminal) {
            int ruleLength = strlen(grammar[i]);
            for (j = 1; j < ruleLength; j++) {
                char symbol = grammar[i][j];
                if (isTerminal(symbol)) {
                    printf("FIRST(%c) = {%c}\n", nonTerminal, symbol);
                    break;
                } else if (isNonTerminal(symbol)) {
                    calculateFirstSet(symbol);
                }
            }
        }
    }
}

int main() {
    printf("Enter the number of rules: ");
    scanf("%d", &numRules);

    printf("Enter the grammar rules:\n");
    for (int i = 0; i < numRules; i++) {
        scanf("%s", grammar[i]);
    }

    printf("Calculating FIRST sets:\n");
	for (int i = 0; i < numRules; i++) {
	char nonTerminal = grammar[i][0];
	if (isNonTerminal(nonTerminal)) {
	calculateFirstSet(nonTerminal);
        }
    }

    return 0;
}
