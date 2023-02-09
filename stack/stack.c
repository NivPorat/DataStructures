#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

struct stack {
    size_t elementSize;/*size of each element in stack*/
    size_t capacity;/*amount of space left in stack*/
    size_t size;/*size of the stack*/
    char* buffer;/*stack data*/
};


void main()
{
    Stack_tests();
    return 0;
}

myStack create(size_t capacity, size_t elemSize)
{
    /*allocate memory for a stack pointer */
    myStack stackPtr = (myStack*)malloc(sizeof(myStack));
    if (NULL == stackPtr)
    {
        return NULL;
    }
   
    /*allocate memory for char* buffer*/
    stackPtr->buffer = (char*)malloc(sizeof(char*));
    if (NULL == stackPtr->buffer)
    {
        free(stackPtr);
        return NULL;
    }
    /*init other stack data*/
    stackPtr->capacity = capacity;
    stackPtr->elementSize = elemSize;
    stackPtr->size = 0;

    return stackPtr;
}

void destroy(myStack stack)
{
    free(stack);
}

bool push(myStack stack, void* elem)
{
    if (stack->size >= stack->capacity)
    {
        return false;
    }
    stack->buffer[stack->size++] = (char*)elem;
    return true;
}

void pop(myStack stack)
{
    if (true == isEmpty(stack))
    {
        return;
    }
    stack->size--;
}

char* peek(myStack stack)
{
    if (false == isEmpty(stack))
    {
        return stack->buffer[stack->size];
    }
    return NULL;
}

bool isEmpty(myStack stack)
{
	return (stack->size == 0);
}

bool isFull(myStack stack)
{
	return (stack->size == stack->capacity);
}

size_t stackCapacity(myStack stack)
{
    return stack->capacity;
}

size_t stackSize(myStack stack)
{
    return stack->size;
}


void Stack_tests()
{
    int i = 0;
    char c = 'c';
    myStack stack_test5 = NULL;


    /***************** 5 size stack test. all functions tested ********************/
    stack_test5 = create(5, sizeof(size_t));
    printf("\nTEST FOR 5 SIZE STACK\nstack pointer is: %p\n", (void*)stack_test5);
    printf("capacity of stack is (expected 5): %lu\n", stackCapacity(stack_test5));
    printf("size of stack is (expected 0): %lu\n", stackSize(stack_test5));
    printf("value of top stack is (expected NULL): %p\n\n", peek(stack_test5));

    for (i = 0; i < 4; ++i)
    {
        printf("push element number %d/5 (expected 1): %d\n",
            i + 1, push(stack_test5, &c));
    }

    printf("push element number 5/5 (expected 1): %d\n", push(stack_test5, &i));
    printf("push element number 6/5 (expected 0): %d\n\n", push(stack_test5, &i));
    printf("size of stack is (expected 5): %lu\n", stackSize(stack_test5));
    printf("value of top stack is: %p\n", peek(stack_test5));
    pop(stack_test5);
    printf("value of top stack after one pop is (expected diffrent from above):\
	 %p\n", peek(stack_test5));
    printf("size of stack is (expected 4): %lu\n", stackSize(stack_test5));
    pop(stack_test5);
    pop(stack_test5);
    pop(stack_test5);
    printf("value of IsEmpty for 0 size stack is: %d\n", isEmpty(stack_test5));
    pop(stack_test5);
    printf("value of IsEmpty for 1 size stack is: %d\n\n", isEmpty(stack_test5));

    destroy(stack_test5);

}