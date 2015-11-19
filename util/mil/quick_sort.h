#include <stdio.h>
//
// Created by rao on 15-11-11.
//

#ifndef ALGORITHM_QUICK_SORT_H
#define ALGORITHM_QUICK_SORT_H

#endif //ALGORITHM_QUICK_SORT_H

int find_bigger(int index, int pivot, int* p_x, int arr_len)
{
    int tmp=-1;
    for(int i=index; i< arr_len;i++)
    {
        int a = p_x[i];
        int b = p_x[pivot];
        if(p_x[i] > p_x[pivot])
        {
            tmp = i;
            break;
        }
    }
    return tmp;
}

int find_smaller(int index, int pivot, int* p_x, int arr_len)
{
    int tmp=-1;
    for(int i=index; i>0;i--)
    {
        int a = p_x[i];
        int b = p_x[pivot];
        if(p_x[i] < p_x[pivot])
        {
            tmp = i;
            break;
        }
    }
    return tmp;
}

int exchange(int* a, int* b)
{
    int tmp = *b;
    *b = *a;
    *a = tmp;
    return 0;
}

int partition(int* p_x, int arr_len)
{
    int pivot = 0;
    int low = pivot + 1;
    int hi = arr_len - 1;
    int index_bigger;
    int index_smaller;
    int final;
    while(1) {
        index_bigger = find_bigger(low, pivot, p_x, arr_len);
        index_smaller = find_smaller(hi, pivot, p_x, arr_len);
        if (index_bigger==index_smaller)
        {
            // in this case, index_bigger = -1 and index_smaller = -1, all nums equal;
            break;
            // break the while loop, array unchanged;
        }
        if (index_bigger==-1)
        {
            exchange((p_x + pivot), (p_x + arr_len - 1));
            break;
        }
            // pivot is the biggest or equal to the biggest num, exchange last element with pivot;
        if (index_smaller==-1)
        {
            break;
            // pivot is the smallest or equal to the biggest num, array unchanged;
        }
        if(index_bigger < index_smaller) {
            exchange((p_x + index_bigger), (p_x + index_smaller));
            low = index_bigger + 1;
            hi = index_smaller - 1;
        }
        else
        {
            exchange((p_x+index_smaller), (p_x+pivot));
            break;
        }
    }
    final = pivot + index_smaller;
    return final;
}

int q_sort(int* my_arr, int len)
{
    if (len > 1)
        // only if the sequence here contains more than 1 member, do we begin sorting
    {
        int sep = partition(my_arr, len);
        int *arr_x = my_arr;
        int *arr_y = my_arr + sep + 1;
        int len_x = sep;
        int len_y = len - sep - 1;
        if (len_x > 1)
            q_sort(arr_x, len_x);
        if (len_y > 1)
            q_sort(arr_y, len_y);
    }

    return 0;
}
