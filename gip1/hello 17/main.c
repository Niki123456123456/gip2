#include <stdio.h>
#include <stdbool.h>

int main(){
	int number = 0;
	int sum = 0;

	int count = 0;
	int min = 0;
	int max = 0;

	while(true) {
		int scan_result = scanf("%d", &number);
		if (scan_result == EOF) {
			break;
		}
		if (count == 0 || min > number) {
			min = number;
		}
		if (count == 0 || max < number) {
			max = number;
		}
		count++;
		sum += number;
		
		//printf("your number is: %d\n", number);	
	}
	printf("sum: %d\n", sum);
	printf("max: %d\n", max);
	printf("min: %d\n", min);
	return 0;
}