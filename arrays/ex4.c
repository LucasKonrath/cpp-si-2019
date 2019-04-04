#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numeros[];

    for(int i = 0; i < 10; i++){

        printf("\nDigite um valor\n");
        scanf("%f", &B[i]);
    }

    float maior, menor = 0.0;
    int maiorIndice, menorIndice = 0;

    for(int i = 0; i < 10; i++){

        if(B[i] <= menor){
            menor = B[i];
            menorIndice = i;
        }

        if(B[i] >= maior){
            maior = B[i];
            maiorIndice = i;
        }

        printf("\nMaior %f maior indice %d\n", maior, maiorIndice);
        printf("\nMenor %f menor indice %d\n", menor, menorIndice);
        printf("\nDiferença: %.2f\n", maior - menor);
    }
}
