#include <stdio.h>
int main()
{
int a, *p;

a = 10;
p = &a;
*p = 11;

printf(" %d\n %p\n %p\n %p\n",a ,&a, p, &p);




return 0;
}
