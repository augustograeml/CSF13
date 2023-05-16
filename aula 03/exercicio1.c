#include <stdio.h>
int main()
{
float preco_gasolina,
      preco_alcool,
      km_por_litroA,
      km_por_litroG,
      precoA,
      precoG;

      printf("Insira o preço atual da gasolina: ");
      scanf("%f", &preco_gasolina);

      printf("Insira o preço atual do alcool: ");
      scanf("%f", &preco_alcool);

      printf("Quantos Km o carro faz por litro de Gasolina: ");
      scanf("%f", &km_por_litroG);

      printf("Quantos Km o carro faz por litro de Alcool: ");
      scanf("%f", &km_por_litroA);


      precoA = preco_alcool/km_por_litroA;
      precoG = preco_gasolina/km_por_litroG;

      if (precoG <= precoA)
      {
      printf("Os carros devem ser abastecidos com Gasolina.");
      }
      else
      {
      printf("Os carros devem ser abastecidos com Álcool.");
      }


return 0;
}
