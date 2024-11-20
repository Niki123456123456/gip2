#include <stdio.h>
#include <stdbool.h>

int main(){
    int number = 0;
    float floatNumber = 0.0;
    int count = 0;

    int first_number = 0;
    int last_number = 0;
    float min = 0;
    float max = 0;
    float sum = 0;

    while (true) {
        int scan_result = scanf("%d, %f", &number, &floatNumber);
        if(scan_result == EOF) {
            break;
        }
        if (scan_result == 2) {
            if (count == 0){
                first_number = number;
            }
            last_number = number;

            if (count == 0 || min > floatNumber) {
			    min = floatNumber;
            }
            if (count == 0 || max < floatNumber) {
                max = floatNumber;
            }
            sum += floatNumber;
            count++;
    } else {
            printf("Invalid input.\n");
        }
    }
    
    printf("first_number: %d\n", first_number);
    printf("last_number: %d\n", last_number);
    printf("avg: %f\n", sum / count);
	printf("max: %f\n", max);
	printf("min: %f\n", min);
    return 0;
}
// main.exe < global-annual.txt