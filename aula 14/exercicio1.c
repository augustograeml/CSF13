#include <stdio.h>
#define N 81

int main()
{
int num_questoes,acertos = 0, i;
char gabarito[N], respostas[N];

scanf("%d", &num_questoes);

scanf("%s", gabarito);

scanf("%s", respostas);

    for(i = 0; i < num_questoes; i++)
    {
        if (gabarito[i] == respostas [i])
            acertos++;
    }
printf("%d", acertos);

return 0;
}
