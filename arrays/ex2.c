#include <stdio.h>
#include <stdlib.h>

int main()
{
    float B[10];

    for(int i = 0; i < 10; i++){
        B[i] = i / 2.0 - 1.5;
    }

    for(int i = 0; i < 10; i++){
        printf("%.1f\n", B[i]);
    }
}
