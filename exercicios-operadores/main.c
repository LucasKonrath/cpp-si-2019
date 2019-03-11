#include <stdio.h>
#include <stdlib.h>

int main()
{

/*
Implementar um programa que solicite dois números ao
usuário e exiba na tela a soma destes dois números

int _1, _2;

printf("Digite o primeiro numero \n");
scanf("%d", &_1);
fflush(stdin);
printf("Digite o segundo numero \n");
scanf("%d", &_2);

printf("Soma: %d", _1 + _2);


 Implementar um programa que solicite dois números ao
usuário e exiba na tela a subtração destes dois números


int _1, _2;

printf("Digite o primeiro numero \n");
scanf("%d", &_1);
fflush(stdin);
printf("Digite o segundo numero \n");
scanf("%d", &_2);

printf("Subtracao: %d", _1 - _2);

 Implementar um programa que solicite dois números ao
usuário e exiba na tela a divisão destes dois números

Implementar um programa que solicite um número ao
usuário. Sendo este número uma temperatura em graus
Celsius, faça um programa para converter esta
temperatura em graus Fahrenheit e exiba o resultado na
tela. F = C * 1.8 + 32
6. Implementar um programa que solicite um número ao
usuário. Sendo este número uma temperatura em graus
Fahrenheit, faça um programa para converter esta
temperatura em graus Celsius e exiba o resultado na tela.
C = (F - 32) / 1.8

Implementar um programa que solicite um número ao
usuário. Sendo este número uma velocidade em km/h,
faça um programa para converter esta velocidade em m/s
e exiba o resultado na tela

8. Implemente um programa que solicite ao usuário o valor
de um calçado e o percentual de desconto. Em seguida,
calcule o valor do desconto e o valor final a ser pago pelo
calçado.
*/


int _1, _2;

printf("Digite o primeiro numero \n");
scanf("%d", &_1);
fflush(stdin);
printf("Digite o segundo numero \n");
scanf("%d", &_2);

printf("Soma: %d \n", _1 + _2);
printf("Subtracao: %d \n", _1 - _2);
printf("Multiplicacao: %d \n", _1 * _2);
printf("Divisao: %d \n", _1 / _2);
printf("Fahrenheit: %.2fF \n", _1 * 1.8 + 32);
printf("Celsius: %.2fC \n", (_1 - 32) * 1.8);
printf("Metros/s: %.2fm/s \n", _1 * 1000 / 3600.00);
printf("Desconto: R$%.2f \nValor Final: R$%.2f \n", _1 * (_2 / 100.00), _1 - _1 * (_2 / 100.00));
}
