#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void raizes();
void calcularRaizes(int a, int b, int c);
int ehPositivo(float a);

int main()
{
  raizes();
}

void raizes(){
int a,b,c;

printf("\n Digite o valor a");
scanf("%d", &a);

printf("\n Digite o valor de b");
scanf("%d", &b);

printf("\n Digite o valor de c");
scanf("%d", &c);

calcularRaizes(a, b, c);
}


void calcularRaizes(int a, int b, int c){
    float delta = sqrt(pow(b, 2.0) - 4*a*c);

    if(ehPositivo(delta)){
        printf("\n Raiz 1: %.2f", (-1 * b + delta) / 2 * a);
        printf("\n Raiz 2: %.2f", (-1 * b - delta) / 2 * a);
    }else{
        printf("\n DELTA NEGATIVO!!!! NON ECSISTEM RAIZES REAIS");
    }
}

int ehPositivo(float a){
return a >= 0.0;
}

