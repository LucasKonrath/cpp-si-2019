#include <stdio.h>
#include <stdlib.h>


  float somar(float a, float b);
  float subtrair(float a, float b);
  float dividir(float a, float b);
  float multiplicar(float a, float b);

int main()
{
  int option;
  float _1, _2;

  while(1){
printf("\nDigite 1 para soma \n 2 para subtracao \n 3 para multiplicacao \n 4 para divisao \n");
scanf("%d", &option);

printf("\nDigite o primeiro numero \n");
scanf("%f", &_1);
fflush(stdin);
printf("Digite o segundo numero \n");
scanf("%f", &_2);

float resultado;

switch(option){
case 1:
    resultado = somar(_1, _2);
    break;
case 2:
    resultado = subtrair(_1, _2);
    break;
case 3:
    resultado = multiplicar(_1, _2);
    break;
case 4:
    resultado = dividir(_1, _2);
    break;
default:
    return 0;
}

printf("\nResultado: %.2f", resultado);
}
}

float somar(float a, float b){
return a + b;
}

float subtrair(float a, float b){
return a - b;
}

float dividir(float a, float b){
return a / b;
}

float multiplicar(float a, float b){
return a * b;

}
