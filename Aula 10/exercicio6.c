#include <stdio.h>

int testaTipoChar (char c);
int main ()
{
 char c = 'A';

 printf("%d",testaTipoChar(c));



return 0;
}
int testaTipoChar (char c)
{
    if (c >= 'A' && c <= 'Z')
    {
        if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
            return 1;
        else
            return 3;
    }

    if (c >= 'a' && c <= 'z')
    {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
            return 2;
        else
            return 4;
    }


     //se retornar 1
   if (c >= 0 && c <= 9)
        return 5;

    else
        return 0;

}
