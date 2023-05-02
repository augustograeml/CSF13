#include <stdio.h>
#define N 10000

void segundosParaHMS (int total_segundos, int *h, int *m, int *s);

int main()
{
    int total = N, horas, minutos, segundos;

    segundosParaHMS (total, &horas, &minutos, &segundos);

    printf(" %d\n %d\n %d\n %d\n", total, horas, minutos, segundos);

return 0;
}

void segundosParaHMS (int total_segundos, int *h, int *m, int *s)
{
    *h = total_segundos / 3600;
    *m = (total_segundos%3600)/60;
    *s = (total_segundos%3600)%60;


}
