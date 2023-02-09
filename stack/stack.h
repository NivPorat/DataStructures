#ifndef STACK_H
#define STACK_H
#pragma once

#include <stdbool.h>
//push, pop, peek, isempty, isfull
typedef struct stack* myStack;

myStack create(size_t capacity, size_t stackSize);
void destroy(myStack stack);
bool push(myStack stack, void* elem);
void pop(myStack stack);
char* peek(myStack stack);
bool isEmpty(myStack stack);
bool isFull(myStack stack);
size_t stackCapacity(myStack stack);
size_t stackSize(myStack stack);
void Stack_tests();

#endif

