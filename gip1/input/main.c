#include <stdio.h>

int main(int argc, char* argv[]) {
    printf("%s\n", argv[0]);
    printf("Hi!\n");
    int number = 0;
    int num_parsed = scanf("%d", &number);
    if (num_parsed != 1) {
        return 0;
    }
    printf("The 1st number was %d\n", number);
    scanf("%d", &number);
    printf("The 2nd number was %d\n", number);
    return 0;
}