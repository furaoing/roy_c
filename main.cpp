#include <iostream>
#include <stdio.h>
#include "util/mil/quick_sort.h"
#include <stdlib.h>
#include "nlp/vocabulary_miner.h"
#include "IO/FileIO.h"
#include "data_structure/stack.h"
#include "data_structure/stack_cpp.h"

int main()
{
    /*
    stackT st1,st2;
    StackInit(&st1, 500);
    StackPush(&st1, 'a');
    printf("%c", StackPop(&st1));
    */
    Stack my_s(10);
    my_s.push('a');
    std::cout << my_s.pop();

}