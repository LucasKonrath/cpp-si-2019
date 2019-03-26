#include <stdio.h>
#include <stdlib.h>

int main()
{
    float A[5];
    float B[5];

    for(int i = 0; i < 5; i++){
        printf("\nDigite um valor do vetor A\n");
        scanf("%f", &A[i]);
    }

    for(int i = 0; i < 5; i++){
        printf("\nDigite um valor do vetor B\n");
        scanf("%f", &B[i]);
    }

    for(int a = 0; a < 5; a++){
        for(int b = 0; b < 5; b++){
            printf("\nA[%d] + B[%d] = %f\n", a, b, A[a] + B[b]);
            printf("\nA[%d] - B[%d] = %f\n", a, b, A[a] - B[b]);
            printf("\nA[%d] * B[%d] = %f\n", a, b, A[a] * B[b]);
            printf("\nA[%d] / B[%d] = %f\n", a, b, A[a] / B[b]);
        }
    }
}
