#include <stdio.h>

int main() {
    printf("%d\n", ggt(32, 12));
    printf("%d\n", ggt(12, 36));
}

int ggt(int a, int b){
    while(a != b){
        if (a > b){
            a = a % b;
            if (a == 0){
                return b;
            }
        } else {
            b = b % a;
            if (b == 0){
                return a;
            }
        }
    }
    return a;
}