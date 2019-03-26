#include <stdio.h>
#include <stdlib.h>

int main()
{
    int ado[10];

    for(int i = 0; i < 10; i++){
        printf("\nDigite um valor\n");
        scanf("%d", &ado[i]);
    }

    for(int i = 0; i < 5; i++){
        int um, dois;

        um = ado[i];
        dois = ado[9 - i];

        ado[i] = dois;
        ado[9 - i] =  um;
    }

    printf("\nVetor invertido\n");

    for(int i = 0; i < 10; i++){
        printf("%d", ado[i]);
    }
}
