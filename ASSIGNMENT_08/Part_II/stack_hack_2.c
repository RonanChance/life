#include <stdio.h>
#include <stdlib.h>

int main()
{
    // external, global, static, and const variables initialized at variable declaration are stored in data segment
    static int j;
    printf("The data & text segment are near %p\n", &j);
    // the heap is where dynamic memory allocation takes place
    char *p = (char *)malloc(sizeof(char));
    printf("The heap is near %p\n", p);
    return 0;
}