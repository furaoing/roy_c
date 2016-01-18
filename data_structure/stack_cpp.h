//
// Created by rao on 15-12-26.
//

#ifndef ROY_C_STACK_CPP_H
#define ROY_C_STACK_CPP_H

#endif //ROY_C_STACK_CPP_H

class Stack {
    int MaxStack;
    int EmptyStack;
    int top;
    char* items;

public:
    Stack(int size) {
        MaxStack = size;
        EmptyStack = -1;
        top = EmptyStack;
        items = new char[MaxStack];
    }

    ~Stack() {
        delete[] items;
    }

    void push(char x){
        items[++top] = x;
    }

    char pop(){
        return items[top--];
    }

    int empty(){
        return top == EmptyStack;
    }

    int full(){
        return top + 1 == MaxStack;
    }
};


