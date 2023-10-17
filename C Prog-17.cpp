#include <stdio.h>
int main() {
    int x = 5;
    int y = 10;

    if (x < 10) {
        printf("x is less than 10\n");
    } else {
        printf("x is greater than or equal to 10\n");
    }
    if (y < 10) {
        printf("This code will never be executed\n");
    }

    return 0;
}
