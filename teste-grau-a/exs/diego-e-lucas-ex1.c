#include <stdio.h>
#include <stdlib.h>

// Diego Britto e Lucas Damaceno
int main()
{
    int numeros[] = {132, 34, 82, 121, 17, 24, 77, 65, 987, 93, 62, 29};

    int maior = numeros[0];
    int menor = numeros[0];

    int somasPares = 0;
    int somasImpares = 0;

    for(int i = 0; i < sizeof(numeros) / sizeof(numeros[0]); i++)
    {

        int numero = numeros[i];

        if(i % 2 == 0)
        {
            somasPares += numero;
        }
        else
        {
            somasImpares += numero;
        }

        if(numero < menor)
        {
            menor = numero;
        }

        if(numero > maior)
        {
            maior = numero;
        }
    }

    printf("\nMaior valor: %d", maior);
    printf("\nMenor valor: %d", menor);
    printf("\nSomatorio dos indices pares: %d", somasPares);
    printf("\nSomatorio dos indices impares: %d", somasImpares);
}
