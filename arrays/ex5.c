#include <stdio.h>
#include <stdlib.h>

int main()
{
    int ado[10];

    for(int i = 0; i < 10; i++){
        printf("\nDigite um valor\n");
        scanf("%d", &ado[i]);
    }

    for(int i = 9; i >= 0; i--){
        printf("\n Valores \n")
        printf("%d\n", ado[i]);
    }
}
