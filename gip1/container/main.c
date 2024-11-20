#include <stdio.h>
#include <stdbool.h>
#include "array.h"
#include "array_sort.h"
// gcc -o main main.c array.c array_sort.c

typedef struct
{
    int year;
    float value;
} Anomaly;

void print_anomaly(Anomaly *anomaly)
{
    printf("year: %d anomaly: %0.2f \n", anomaly->year, anomaly->value);
}

int compare_numbers(int *a, int* b)
{
    if (*a > *b){
        return GREATER;
    }
    if (*a < *b){
        return LESS;
    }
    return EQUALS;
}

int compare_anomalys(Anomaly *a, Anomaly* b)
{
    if (a->year > b->year){
        return GREATER;
    }
    if (a->year < b->year){
        return LESS;
    }
    return EQUALS;
}

void print_number(int *number)
{
    printf("%d, ", *number);
}

void print_anomalies(Array *array, char *header)
{
    printf("%s:\n", header);
    loop(array, print_anomaly);
    printf("\n");
}

bool years_equals(Anomaly *a1, Anomaly *a2)
{
    return a1->year == a2->year;
}

int main()
{
    Array array2 = construct(sizeof(Anomaly), 0);
    Anomaly anomalys[] = {{2042, 0.9f},{2039, 0.9f},{2012, 0.9f},{2089, 0.9f},{2017, 0.9f},{2065, 0.9f}, {2052, 0.9f}, {2016, 0.9f},{2018, 0.9f},{2013, 0.9f}};
    for (unsigned int i = 0; i < 10; i++)
    { 
        Anomaly* address = &anomalys[i];
        push(&array2, address);
    }
    print_anomalies(&array2, "initial");
    //sort_bubble(&array2, compare_anomalys);
    //sort_selection(&array2, compare_anomalys);
    //sort_insertion(&array2, compare_anomalys);
    sort_merge(&array2, compare_anomalys);
    //sort_quick(&array2, compare_anomalys);
    print_anomalies(&array2, "quick_sort");

    Array array = construct(sizeof(Anomaly), 0);

    Anomaly anomaly = {2042, 0.9f};
    Anomaly anomaly2 = {2039, 0.21f};
    Anomaly anomaly3 = {2041, 0.81f};

    push(&array, &anomaly);
    push(&array, &anomaly);
    push(&array, &anomaly2);
    print_anomalies(&array, "test3");

    push(&array, &anomaly);
    print_anomalies(&array, "test4");

    push(&array, &anomaly);
    print_anomalies(&array, "test5");

    printf("index: %d\n", find(&array, &anomaly, years_equals));
    printf("index: %d\n", find(&array, &anomaly2, years_equals));
    printf("index: %d\n", find(&array, &anomaly3, years_equals));
    printf("\n");

    remove_at(&array, 2);
    print_anomalies(&array, "test4");

    insert(&array, 3, &anomaly2);
    print_anomalies(&array, "test5");

    swap(&array, 1, 3);
    print_anomalies(&array, "test5");

    destruct(&array);
    return 0;
}
