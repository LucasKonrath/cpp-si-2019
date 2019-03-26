#include <stdio.h>
#include <stdlib.h>

int main()
{
    int ado[10], adoReverso[10];

    for(int i = 0; i < 10; i++){
        printf("\nDigite um valor\n");
        scanf("%d", &ado[i]);
    }

    for(int i = 0; i < 10; i++){
        adoReverso[i] = ado[9-i];
    }

    for(int i = 0; i < 10; i++){
        printf("\n Valor original | valor reverso \n");
        printf("%d\n             | %d", ado[i], adoReverso[i]);
    }
}
