#include <stdio.h>
#include <string.h>

#define MAX_RULES 10
#define MAX_PROD_LEN 50

char grammar[MAX_RULES][MAX_PROD_LEN];
char newGrammar[MAX_RULES * 2][MAX_PROD_LEN];
int newCount = 0;
void eliminateLeftRecursion(int ruleIndex) {
    int i, j;
    char nonTerminal = grammar[ruleIndex][0];
    int count = 0;
	for (i = 0; i < ruleIndex; i++) {
        if (grammar[i][0] != nonTerminal) {
            char newProd[MAX_PROD_LEN] = {0};
            int pos = 0;
            for (j = 0; grammar[i][j] != '\0'; j++) {
                if (grammar[i][j] != nonTerminal) {
                    newProd[pos] = grammar[i][j];
                    pos++;
                }
            }
            strcat(newProd, nonTerminal);
            strcat(newGrammar[newCount], newProd);
            newCount++;
        } else {
            char alpha[MAX_PROD_LEN] = {0};
            int pos = 0;
            for (j = 3; grammar[i][j] != '\0'; j++) {
                alpha[pos] = grammar[i][j];
                pos++;
            }
            strcat(alpha, nonTerminal);
            strcat(newGrammar[ruleIndex], alpha);
        }
    }
}
int main() {
    int numRules;
    printf("Enter the number of production rules: ");
    scanf("%d", &numRules);
	printf("Enter the production rules:\n");
    for (int i = 0; i < numRules; i++) {
        scanf("%s", grammar[i]);
    }
	for (int i = 0; i < numRules; i++) {
        if (grammar[i][0] == grammar[i][3]) {
            eliminateLeftRecursion(i);
        }
    }
	 for (int i = 0; i < numRules; i++) {
        if (grammar[i][0] != grammar[i][3]) {
            strcat(newGrammar[newCount], grammar[i]);
            newCount++;
        }
    }
	printf("Grammar without left recursion:\n");
    for (int i = 0; i < newCount; i++) {
        printf("%s\n", newGrammar[i]);
    }
	return 0;
}
