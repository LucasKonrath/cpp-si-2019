#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

// Diego Britto e Lucas Damaceno

float soma(int n);

int main()
{

    setlocale(LC_ALL, "Portuguese");

    int n;
    printf("\nDigite um número para calcular: \n");
    scanf(" %d", &n);

    if( n < 0)
    {
        printf("\nNumero digitado menor que 0: %d", n);
        return 0;
    }

    printf("Número calculado: %.2f", soma(n));
}

float soma(int n)
{

    float base = 0;

    for(int i = 1; i <= n; i++)
    {
        base += (2.0 / i);
    }

    return base;
}

