#include <stdio.h>
#include <stdlib.h>

int main()
{
    int A[6];

    for(int i = 0; i < 6; i++){
        A[i] = i * 2  + 2;
    }

    for(int i = 0; i < 6; i++){
        printf("%d\n", A[i]);
    }
}
