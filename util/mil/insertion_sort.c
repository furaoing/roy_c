#include <stdio.h>

int insertion_sort(int *nums, int size)
{
    int n = size;
    int i;
    int key;
    int j;
    for(i = 2; i < n; i++)
    {
        key = *(nums + i);
        j = i - 1;
        while(j > 0 && *(nums + j) > key)
        {
            *(nums + j + 1) = *(nums + j);
                    j = j - 1;
        }
        *(nums + j + 1) = key;
    }

    int head = *nums;
    int k = 1;
    while(*(nums+k) < head)
    {
        *(nums + k - 1) = *(nums + k);
        k = k + 1;
    }
    *(nums + k - 1) = head;

    return 1;
}

int _main()
{
    int my_array[] = {5,3,2,4,1,77,8,33,31,3,4};
    int size = sizeof(my_array)/sizeof(my_array[0]);
    int result = insertion_sort(my_array, size);

    int i;
    for(i = 0; i < sizeof(my_array)/sizeof(int); i++)
    {
        printf("%d ", my_array[i]);
    }

    return 1;
}
