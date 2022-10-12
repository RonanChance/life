// compute sum of consecutive integers 1 to n inclusive
// git will track everything else
#include <stdio.h>
long cumulative_sum(int N);

int main(int argc, char *argv[])
{
int N;
long result;
// ask for a number
printf("Enter a number:\n");
scanf("%d", &N);

// compute result
result = cumulative_sum(N);
// display result
printf("The sum from 1 to %d (inclusive) is %ld\n", N, result);
return 0;
}

long cumulative_sum(int N){
long accumulator = 0;

for (int n=1; n <= N; n++){
accumulator += n;

}
return accumulator;
}
