#include <stdio.h>
#include <stdlib.h>

int ehPositivo(int a);

int main()
{
  int numero;
  printf("Digite um numero: ");
  scanf("%d", &numero);

  if(ehPositivo(numero)){
    printf("EH POSITIVO!");
  }else{
    printf("NAO EH POSITIVO");
  }
}

int ehPositivo(int a){
return a >= 0;
}
