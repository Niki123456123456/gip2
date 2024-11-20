#include "array.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>

int max_v(int a, int b)
{
    return a > b ? a : b;
}

Array construct(int value_size, int capacity)
{
    Array array;
    array.length = 0;
    array.capacity = max_v(capacity, 1);
    array.value_size = value_size;
    array.values = malloc(array.capacity * value_size);
    return array;
}

void destruct(Array *array)
{
    free(array->values);
    array->values = NULL;
}

void extend_for_more_values(Array *array)
{
    if (array->length >= array->capacity)
    {
        array->capacity *= 2;
        array->values = realloc(array->values, array->capacity * array->value_size);
    }
}

void push(Array *array, void *anomaly)
{
    extend_for_more_values(array);
    memcpy(array->values + array->length * array->value_size, anomaly, array->value_size);
    array->length += 1;
}

void loop(Array *array, void (*operation)(void *))
{
    for (size_t i = 0; i < array->length; i++)
    {
        operation(array->values + i * array->value_size);
    }
}

void *get(Array *array, unsigned int i)
{
    return array->values + i * array->value_size;
}

unsigned int find(Array *array, void *year, bool (*operation)(void *, void *))
{
    for (unsigned int i = 0; i < array->length; i++)
    {
        if (operation(array->values + i * array->value_size, year))
        {
            return i;
        }
    }
    return -1;
}

void remove_at(Array *array, unsigned int index)
{
    for (unsigned int i = index; i < (array->length - 1); i++)
    {
        memcpy(array->values + (i)*array->value_size, array->values + (i + 1) * array->value_size, array->value_size);
    }
    array->length -= 1;
}

void insert(Array *array, unsigned int index, void *anomaly)
{
    extend_for_more_values(array);
    unsigned int i = array->length -1;
    while (true)
    {
        if(i >= index){
            memcpy(array->values + (i + 1) * array->value_size, array->values + (i)*array->value_size, array->value_size);
        } else {
            break;
        }
        if (i > 0){
            i--;
        } else {
            break;
        }
    }
    memcpy(array->values + index * array->value_size, anomaly, array->value_size);
    array->length += 1;
}

void set(Array *array, unsigned int index, void *anomaly)
{
    memcpy(array->values + index * array->value_size, anomaly, array->value_size);
}

void swap(Array *array, unsigned int a, unsigned int b)
{
    if (a != b)
    {
        unsigned int i0 = a <= b ? a : b;
        unsigned int i1 = a > b ? a : b;

        push(array, get(array, i0));
        set(array, i0, get(array, i1));
        set(array, i1, get(array, array->length - 1));
        array->length -= 1;
    }
}

void move(Array *array, unsigned int old_index, unsigned int new_index){
    insert(array, new_index, get(array, old_index));
    remove_at(array, old_index);
}