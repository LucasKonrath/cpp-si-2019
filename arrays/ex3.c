#include <stdio.h>
#include <stdlib.h>

int main()
{
    int ado[10];

    for(int i = 0; i < 5; i++){
        ado[i] = i;
    }

    for(int i = 0; i < 10; i++){
        printf("%d\n", ado[i]);
    }
}
