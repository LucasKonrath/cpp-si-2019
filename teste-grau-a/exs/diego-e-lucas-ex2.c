#include <stdio.h>
#include <stdlib.h>

// Diego Britto e Lucas Damaceno

void imprime(int n1, int n2);

int main()
{
    int n1, n2;

    printf("\nDigite o valor de n1 \n");
    scanf("%d", &n1);

    printf("\nDigite o valor de n2 \n");
    scanf("%d", &n2);

    if(n1 >= n2)
    {
        printf("\n n1 deve ser menor que n2");
        return 0;
    }

    imprime(n1, n2);

}

void imprime(int n1, int n2)
{
    for(int i = n1; i <n2; i++)
    {
        if(i % 7 == 4 || i % 11 ==4)
        {
            printf("\n %d gera resto 4 \n", i);
        }
    }
}
