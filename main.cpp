#include <iostream>
#include <stdio.h>
#include "quick_sort.h"
#include <stdlib.h>
#include "new_word_digger.h"
#include "FileIO.h"
#include <time.h>
int main()
{

    char pth[] = "/home/rao/C++/algorithm/test/test";
    char* my_arr = read(pth);
    char* p = &my_arr[0];
    int len = strlen(p);
    // excluding the /0 char from the len passed in as argument
    clock_t start_time = clock();
    struct tf* my_tf = get_tf(p, len);
    clock_t end_time = clock();
    read_clean(my_arr);
    float time_c = 1000*(((float)(end_time - start_time))/CLOCKS_PER_SEC);

    printf("The amout of millseconds consumed: %f", time_c);
    free_list(my_tf);


    /*
    char apth[] = "/home/rao/C++/algorithm/test/pku_test.utf8";

    char* str = read(apth);
    int len = strlen(str);
    time_t result = time(NULL);
    printf("%d", len);
    read_clean(str);
*/
}