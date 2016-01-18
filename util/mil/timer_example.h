#include <time.h>

float timer()
{
    clock_t start_time = clock();
    /* Code Here */
    clock_t end_time = clock();
    float time_c = 1000*(((float)(end_time - start_time))/CLOCKS_PER_SEC);
    // time_c in milliseconds
    return time_c;
}
