#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
int E();
int T();
int F();
void error();

char input[100];
int position = 0;

int main() {
    printf("Enter an arithmetic expression: ");
    fgets(input, sizeof(input), stdin);

    if (E() && position == strlen(input) - 1) {
        printf("Valid expression!\n");
    } else {
        error();
    }

    return 0;
}

int E() {
    int result = T();
    while (input[position] == '+' || input[position] == '-') {
        char op = input[position];
        position++;
        int right = T();
        if (op == '+') {
            result += right;
        } else {
            result -= right;
        }
    }
    return result;
}

int T() {
    int result = F();
    while (input[position] == '*' || input[position] == '/') {
        char op = input[position];
        position++;
        int right = F();
        if (op == '*') {
            result *= right;
        } else {
            if (right == 0) {
                error();
                return 0;
            }
            result /= right;
        }
    }
    return result;
}

int F() {
    if (isdigit(input[position])) {
        int num = 0;
        while (isdigit(input[position])) {
            num = num * 10 + (input[position] - '0');
            position++;
        }
        return num;
    } else if (input[position] == '(') {
        position++;
        int result = E();
        if (input[position] == ')') {
            position++;
            return result;
        } else {
            error();
            return 0;
        }
    } else {
        error();
        return 0;
    }
}

void error() {
    printf("Invalid expression!\n");
    exit(1);
}
