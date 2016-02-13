#include <stdlib.h>
#include <stdio.h>

//
// Created by rao on 15-11-24.
//
typedef char stackElementT;

typedef struct {
    stackElementT *contents;
    int top;
    int maxSize;
} stackT;
/* A struct functions as a stack for char elements */

void StackInit(stackT *stackP, int maxSize)
{
    stackElementT *newContents;

    newContents = (stackElementT*) malloc(maxSize*sizeof(stackElementT));
    if(newContents==NULL) {
        fprintf(stderr, "Insufficient memory to initialize stack.\n");
        exit(1); /* Exit, returning error code */
    }

    stackP->contents = newContents;
    stackP->maxSize = maxSize;
    stackP->top = -1;
}

void StackDestory(stackT *stackP)
{
    free(stackP->contents);
    stackP->contents = NULL;
    stackP->maxSize = 0;
    stackP->top = -1;
}

int StackIsEmpty(stackT* stackP)
{
    return stackP->top < 0;
}

int StackIsFull(stackT* stackP)
{
    return stackP->top >= stackP->maxSize - 1;
}

void StackPush(stackT* stackP, stackElementT element)
{
    if(StackIsFull(stackP)) {
        fprintf(stdout, "Can't push element on stack: stack is full.\n");
        exit(1);
    }

    stackP->contents[++stackP->top] = element;
}

stackElementT StackPop(stackT* stackP)
{
    if(StackIsEmpty(stackP)) {
        fprintf(stdout, "Can't pop element from stack: stack is empty.\n");
        exit(1);
    }

    return stackP->contents[(stackP->top)--];
}

