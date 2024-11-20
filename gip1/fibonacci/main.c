#include <stdio.h>

int main() {
    for (int i = 0; i < 20; i++) {
        printf("%d: %d %d\n",i, get_fibonacci_rekursiv(i), get_fibonacci_iterativ(i));
    }
    return 0;
}

// index:     0 1 2 3 4 5 6
// fibonacci: 0 1 1 2 3 5 8 

int get_fibonacci_rekursiv(int index){
    if(index < 2){
        return index;
    }
    return get_fibonacci_rekursiv(index - 1) + get_fibonacci_rekursiv(index - 2);
}

int get_fibonacci_iterativ(int index){
    int fibonaccis [] = {0,1};
    for (int i = 0; i < index; i++) {
        fibonaccis[i % 2] = fibonaccis[0] + fibonaccis[1];
    }
    return fibonaccis[index % 2];
}