#include <stdio.h>

void incDec (int *a, int *b);


int main()
{
int a = 0 , b = 0 , *pa, *pb;

pa = &a;
pb = &b;

*pa = 5;
*pb = 6;

void incDec ( *pa, *pb);

printf(" %d\n %d", a, b);




return 0;
}

void incDec (int *a, int *b)
{
    (*a)++;
    (*b)--;
}
