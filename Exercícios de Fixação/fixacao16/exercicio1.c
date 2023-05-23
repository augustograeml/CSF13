#include <stdio.h>
#include <stdlib.h>
#define N 10

int main()
{
float* vetor;
int i;

   vetor = (float*) malloc ( N * sizeof (float));

   for(i = 0; i < N; i++)
   {
       scanf("%f", &vetor[i]);
   }
   for(i = 0; i < N ; i++)
   {
       printf("%f\n", vetor[i]);
   }

   free(vetor);



return 0;
}
