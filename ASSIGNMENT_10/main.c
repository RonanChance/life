#include <stdio.h>

char *ga = "abcdefghijklmnopqrstuvwxyz";

void one(char ca[]){
    printf("Function 1:\n");
    printf("&val      = %p\n", &ca);
    printf("&(val[0]) = %p\n", &(ca[0]));
    printf("&(val[1]) = %p\n", &(ca[1]));
}

void two(char *pa){
    printf("Function 2:\n");
    printf("&val      = %p\n", &pa);
    printf("&(val[0]) = %p\n", &(pa[0]));
    printf("&(val[1]) = %p\n", &(pa[1]));
    printf("++val     = %p\n", ++pa);
}

int main() {
    char ca[] = "HelloLBPca!";
    char *pa = "HelloLBPpa!";
    printf("Running func 1 with ca\n");
    one(ca);
    printf("Running func 2 with pa\n");
    two(pa);
    printf("Now running one() and two() with global alphabet\n");
    one(ga);
    two(ga);
    printf("Now printing in main global alphabet:\n");
    printf("&val      = %p\n", &ga);
    printf("&(val[0]) = %p\n", &(ga[0]));
    printf("&(val[1]) = %p\n", &(ga[1]));
    return 0;
}

