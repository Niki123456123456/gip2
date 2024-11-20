#ifndef array_h
#define array_h

#include <stdbool.h>

typedef struct {
    int length;
    int capacity;
    void* values;
    int value_size;
} Array;

Array construct(int value_size, int capacity);

void destruct(Array* array);

void push(Array* array, void* anomaly);

void loop(Array* array, void(*operation)(void*));

unsigned int find(Array *array, void* year, bool (*operation)(void *, void *));

void remove_at(Array* array, unsigned int index);

void insert(Array* array, unsigned int index, void* anomaly);
void set(Array* array, unsigned int index, void* anomaly);
void* get(Array *array, unsigned int i);
void swap(Array* array, unsigned int a, unsigned int b);
void move(Array *array, unsigned int old_index, unsigned int new_index);

#endif