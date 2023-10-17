#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char *productions[] = {
    "E->E+T",
    "E->T",
    "T->T*F",
    "T->F",
    "F->(E)",
    "F->id"
};
int numProductions = 6;
char action[12][6][10] = {
    "S5", "", "", "S4", "", "",
    "", "S6", "", "", "", "accept",
    "", "-1", "S7", "", "-1", "-1",
    "S5", "", "", "S4", "", "",
    "", "R3", "R3", "", "R3", "R3",
    "", "-1", "R5", "", "-1", "-1",
    "S5", "", "", "S4", "", "",
    "S5", "", "", "S4", "", "",
    "", "R6", "R6", "", "R6", "R6",
    "", "R4", "R4", "", "R4", "R4",
};

char goTo[12][3] = {
    "1", "2", "3",
    "", "", "",
    "", "", "",
    "8", "2", "3",
    "", "", "",
    "", "9", "3",
    "", "", "10",
    "", "", "11",
    "", "", "",
    "", "", "",
};

int stack[1000];
char input[1000];
int top = -1;
int getRow(char state) {
    return state - '0';
}
int getCol(char symbol) {
    if (symbol == 'i') return 0;
    else if (symbol == '+') return 1;
    else if (symbol == '*') return 2;
    else if (symbol == '(') return 3;
    else if (symbol == ')') return 4;
    else if (symbol == '$') return 5;
    return -1;
}
void parse(char input[]) {
    stack[++top] = '0';
    int ptr = 0;

    printf("\nParsing Steps:\n");
    printf("Stack\t\tInput\t\tAction\n");

    while (1) {
        int row = getRow(stack[top]);
        int col = getCol(input[ptr]);

        if (action[row][col][0] == 'S') {
            stack[++top] = input[ptr];
            stack[++top] = action[row][col][1];
            ptr++;
            printf("%s\t\t%s\t\tShift %c\n", stack, input + ptr, action[row][col][1]);
        } else if (action[row][col][0] == 'R') {
            int production = action[row][col][1] - '0';
            char *rightHand = productions[production];
            int len = strlen(rightHand) - 3;
            for (int i = 0; i < 2 * len; i++) top--;
            row = getRow(stack[top]);
            col = getCol(rightHand[0]);
            stack[++top] = rightHand[0];
            stack[++top] = goTo[row][col];
            printf("%s\t\t%s\t\tReduce %s\n", stack, input + ptr, rightHand);
        } else if (action[row][col][0] == 'a') {
            printf("%s\t\t%s\t\tAccepted\n", stack, input + ptr);
            break;
        } else {
            printf("Error in input!\n");
            break;
        }
    }
}

int main() {
    char inputStr[100];
    printf("Enter input string: ");
    scanf("%s", inputStr);
    strcat(inputStr, "$");
    parse(inputStr);
    return 0;
}
