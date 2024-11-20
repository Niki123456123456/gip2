#include <stdio.h>

#define BORDER 0.001

float betrag(float f){
    if (f < 0.0) {
        return -f;
    }
    return f;
}

float sqrt_(float f) {
    float a = f;
    while(1) {
        float a2 = f / a;
        if (betrag(a2 - a) < BORDER) {
            break;
        }
        a = (a + a2) / 2.0;
    }
    return a;
}

int main() {
    printf("%f\n", sqrt_(25.0));
    return 0;
}


