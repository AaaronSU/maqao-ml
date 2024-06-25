#include <stdio.h> // printf
#include <math.h>  // sqrtf
#include <omp.h>

int sum(int rept, int n)
{
   unsigned r;
   int sum = 0;

#pragma omp parallel for
   for (r = 0; r < rept; r++)
   {
      unsigned i;
      sum = 0;
      for (i = 0; i < n; i++)
         sum += sqrtf(i);
      printf("sum=%d\n", sum);
   }

   return sum;
}
