#ifndef array_sort_h
#define array_sort_h
#include "array.h"

#define LESS -1
#define EQUALS 0
#define GREATER 1

typedef int compare_fn(void *, void *);

void sort_bubble(Array *array, compare_fn* compare_fn);
void sort_selection(Array *array, compare_fn* compare_fn);
void sort_insertion(Array *array, compare_fn* compare_fn);

void sort_merge(Array *array, compare_fn* compare_fn);
void sort_quick(Array *array, compare_fn* compare_fn);

#endif