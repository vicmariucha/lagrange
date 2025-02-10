#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>

int main(void){

	setlocale(LC_ALL, "Portuguese");
  int pontos, grau, cont, i, j;
  float Px, valorCalcular, Li, temp;
  char resp;
		
  printf("Digite o grau da funcao que deseja obter: ");
  scanf("%d", &grau);

  pontos = grau + 1; // obtendo o numero de pontos a partir do grau indicado

  float *valoresX = (float *)malloc(pontos * sizeof(float));
  float *valoresFX = (float *)malloc(pontos * sizeof(float));

  for (cont = 0; cont < pontos; cont++){
    printf("Digite o valor do %d valor de X: ", cont);
    scanf("%f", &valoresX[cont]);
    printf("Digite o valor do %d valor de f(x): ", cont);
    scanf("%f", &valoresFX[cont]);
  }

  do{
    printf("Digite o valor que deseja calcular: ");
    scanf("%f", &valorCalcular);
			
    Px = 0;
    //implementação do calculo do Teorema de Lagrange
    for (i = 0; i < pontos; i++){
      Li = 1;
      for (j = 0; j < pontos; j++){
        if (i != j){
          Li = Li * ((valorCalcular - valoresX[j]) / (valoresX[i] - valoresX[j]));
        }
      }
      Px = Px + Li * valoresFX[i];
      }
      printf("O valor interpolado de f(%.2f) eh %.2f\n", valorCalcular, Px);

      printf("Deseja calcular outro valor (s/n)? ");
      scanf(" %c", &resp);
    }while (resp == 's' || resp == 'S');

    free(valoresX);
    free(valoresFX);

	system("pause");
    return 0;
}
