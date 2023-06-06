#include <stdio.h>
#include <string.h>

typedef struct{
  int num;
  char abrev [4]; /* 3 letras + '\0'. */
  int n_dias;
} Mes;

int main ()
{
  int i;
  Mes meses [12];
  int n_mes;
    
  for (i = 0; i < 12; i++)
  {
    meses [i].num = i+1;
    
    if (meses [i].num == 2) /* Fevereriro */
      meses [i].n_dias = 28;
    else if (meses [i].num == 4 || meses [i].num == 6 || meses [i].num == 9 || meses [i].num == 11)
      meses [i].n_dias = 30; /* Abril, Junho, Setembro e Novembro */
    else
    meses [i].n_dias = 31;
}
strcpy (meses [0].abrev, "Jan");
strcpy (meses [1].abrev, "Fev");
strcpy (meses [2].abrev, "Mar");
strcpy (meses [3].abrev, "Abr");
strcpy (meses [4].abrev, "Mai");
strcpy (meses [5].abrev, "Jun");
strcpy (meses [6].abrev, "Jul");
strcpy (meses [7].abrev, "Ago");
strcpy (meses [8].abrev, "Set");
strcpy (meses [9].abrev, "Out");
strcpy (meses [10].abrev, "Nov");
strcpy (meses [11].abrev, "Dez");
printf ("Digite o numero do mes: ");
scanf ("%d", &n_mes);
printf ("%s tem %d dias.\n", meses [n_mes-1].abrev, meses [n_mes-1].n_dias);
return (0);
}
