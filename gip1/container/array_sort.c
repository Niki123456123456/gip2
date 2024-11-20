#include "array.h"
#include "array_sort.h"
#include <stdbool.h>

bool is_greater(Array *array, unsigned int a, unsigned int b, compare_fn *compare_fn){
    return compare_fn(get(array, a), get(array, b)) == GREATER;
}

unsigned int min(Array *array, unsigned int start, compare_fn *compare_fn){
    unsigned int min = start;
    
    
    
    return min;
}

void sort_bubble(Array *array, compare_fn *compare_fn)
{
    for (unsigned int j = 0; j < array->length; j++)
    {
        bool return_early = true;
        for (unsigned int i = 0; i < (array->length - 1-j); i++)
        {
            if (is_greater(array, i, i+1, compare_fn))
            {
                swap(array, i, i + 1);
                return_early = false;
            }
        }
        if(return_early){
            return;
        }
    }
}
void sort_selection(Array *array, compare_fn *compare_fn)
{
    for (unsigned int j = 0; j < array->length; j++)
    {
        swap(array, j, min(array, j, compare_fn));
    }
}

void sort_insertion(Array *array, compare_fn *compare_fn)
{
    for (unsigned int j = 1; j < array->length; j++)
    {
        for (unsigned int i = 0; i < j; i++)
        {
            if (is_greater(array, i, j, compare_fn))
            {
                move(array, j+1, i);
                break;
            }
        }
    }
}

void sort_merge_core(Array *array, int start, int length, compare_fn *compare_fn)
{
    if (length > 1){
        int half = length / 2;
        int i = start;
        int j = start+half;
        sort_merge_core(array, i, half, compare_fn);
        sort_merge_core(array, j, length-half, compare_fn);
        while (i < j && j < start+length)
        {
            if (j < start+length && is_greater(array, i, j, compare_fn))
            {
                j++;
                move(array, j, i);
            } 
            i++; 
        }
    }
}

void sort_merge(Array *array, compare_fn *compare_fn)
{
    sort_merge_core(array, 0, array->length, compare_fn);
}

void sort_quick_core(Array *array, int start, int length, compare_fn *compare_fn)
{
    if (length > 1){
        int pivot = start+ length - 1;
        for (unsigned int j = start; j < pivot;){
            if(is_greater(array, j, pivot, compare_fn)){
                move(array, j, pivot+1);
                pivot--;
            } else {
                j++;
            }
        }
        sort_quick_core(array, start, pivot-start, compare_fn);
        sort_quick_core(array, pivot, length-pivot+start, compare_fn);
    }
}

void sort_quick(Array *array, compare_fn *compare_fn)
{
    sort_quick_core(array, 0, array->length, compare_fn);
}

