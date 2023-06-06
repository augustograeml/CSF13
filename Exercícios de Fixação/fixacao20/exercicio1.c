#include <stdio.h>
typedef struct
{
    int a;
    float b;
} FooStruct;
FooStruct fooFunction (FooStruct s1, FooStruct* s2)
{
    s1.a *= 2;
    s1.b /= 2;
    s2->a *= 2;
    s2->b /=2;
    return (s1);
}
int main ()
{
    FooStruct s1, s2, s3;
    s1.a = 10;
    s1.b = 20.4;
    s2.a = 30;
    s2.b = 14.4;
    s3 = fooFunction (s2, &s1);
    printf ("%d %.2f\n%d %.2f\n%d %.2f\n",
            s1.a, s1.b, s2.a, s2.b, s3.a, s3.b);
    return (0);
}
