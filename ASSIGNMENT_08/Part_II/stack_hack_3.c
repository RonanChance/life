#include <stdio.h>
#include <stdlib.h>

void grow_stack(){
    int my_array[100000] = {1};
    int my_array2[100000] = {1};
    int j;
    printf("Growing stack, now top is near: %p\n", &j);
}

int main()
{
    int i;
    printf("The top of stack is near:       %p\n", &i);
    grow_stack();
    return 0;
}