#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main()
{
    int ado[10];

    for(int i = 0; i < 10; i++){
        printf("\nDigite um valor\n");
        scanf("%d", &ado[i]);
    }

    int procurar;
    printf("\n Digite o numero pra procurar \n");
    scanf("%d", &procurar);

    printf("Numero lido: %d", procurar);

    bool encontrado = false;
    for(int i = 0; i < 10; i++){
        if(procurar == ado[i]){
            encontrado = true;
            printf("\nPosicao %d\n", i);
        }
    }

    if(!encontrado){
        printf("\nNAO ENCONTRADO\n");
    }
}
