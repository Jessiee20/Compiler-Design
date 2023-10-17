#include <stdio.h>
#include <stdlib.h>
typedef struct {
    char op;
    char arg1;
    char arg2;
    char result;
} Triple;
Triple triples[100]; 
int tripleCount = 0; void generateTriple(char op, char arg1, char arg2, char result) {
    triples[tripleCount].op = op;
    triples[tripleCount].arg1 = arg1;
    triples[tripleCount].arg2 = arg2;
    triples[tripleCount].result = result;
    tripleCount++;
}
int main() {
	char expression[] = "a = b + c * d";
    char resultVar = expression[0];
    char op = '\0';
    for (int i = 4; expression[i] != '\0'; i++) {
        if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/') {
            op = expression[i];
        } else if (expression[i] != ' ') {
            if (op == '\0') {
                generateTriple('=', expression[i], '\0', resultVar);
            } else {
                char tempVar = 't';  
                generateTriple(op, expression[i], expression[i + 2], tempVar);
                generateTriple('=', tempVar, '\0', resultVar);
                op = '\0';
                i += 2;  
            }
        }
    }
    printf("Generated Triples:\n");
    for (int i = 0; i < tripleCount; i++) {
        printf("(%c, %c, %c, %c)\n", triples[i].op, triples[i].arg1, triples[i].arg2, triples[i].result);
    }
	return 0;
}
