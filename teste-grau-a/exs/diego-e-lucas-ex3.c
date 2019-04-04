#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

// Diego Britto e Lucas Damaceno

int main()
{
    setlocale(LC_ALL, "Portuguese");

    int matrix[10][10];

    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            matrix[i][j] = 11 * i - 3 * j + 7;
        }
    }

    printf("\n Matriz completa:\n\n");

    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            printf("%2i\t", matrix[i][j]);
        }
        printf("\n");
    }

    printf("\nDiagonal Principal\n");

    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            if(i == j)
            {
                printf("%2i\t", matrix[i][j]);
            }
            else
            {
                printf("\t");
            }
        }
        printf("\n");
    }


    printf("\nDiagonal Secundária\n");

    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            if(i + j == 9)
            {
                printf("%2i\t", matrix[i][j]);
            }
            else
            {
                printf("\t");
            }
        }
        printf("\n");
    }

    int somaPrincipal = 0;

    int somaSecundaria = 0;

    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            if(i + j == 9)
            {
                somaSecundaria += matrix[i][j];
            }
            else if(i == j)
            {
                somaPrincipal += matrix[i][j];
            }
        }
        printf("\n");
    }

    printf("\n Somatório principal = %d", somaPrincipal);
    printf("\n Somatório secundário = %d", somaSecundaria);
    printf("\n Diferença entre principal e secundário = %d", somaPrincipal - somaSecundaria);

}

