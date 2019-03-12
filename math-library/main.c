#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    float raio;
    printf("Digite o raio de um circulo: \n");
    scanf("%f", &raio);
    printf("\nDiametro: %.2f\nCircunferencia: %.2f\nArea: %.2f\n", raio * 2.0, raio * M_PI * 2.0, M_PI * pow(raio, 2.0));


    float h_retangulo, l_retangulo;

    printf("Digite a altura de um retangulo: \n");
    scanf("%f", &h_retangulo);
    printf("Digite a largura de um retangulo: \n");
    scanf("%f", &l_retangulo);

    printf("Perimetro: %.2f\nArea: %.2f\n", (h_retangulo + l_retangulo) * 2.0, h_retangulo * l_retangulo);

    float h_triangulo, b_triangulo;

    printf("Digite a base do triangulo: \n");
    scanf("%f", &b_triangulo);
    printf("Digite a altura do triangulo: \n");
    scanf("%f", &h_triangulo);

    printf("Area: %.2f\n", (b_triangulo * h_triangulo) / 2.0);

    float primeira_pot, segunda_pot;
    printf("Digite o primeiro numero: \n");
    scanf("%f", &primeira_pot);
    printf("Digite o segundo numero: \n");
    scanf("%f", &segunda_pot);

    printf("%.2f elevado a %.2f eh %.2f\n", primeira_pot, segunda_pot, pow(primeira_pot, segunda_pot));

    float primeiro_cat, segundo_cat;

    printf("Digite o primeiro cateto: \n");
    scanf("%f", &primeiro_cat);

    printf("Digite o segundo cateto: \n");
    scanf("%f", &segundo_cat);

    printf("Hipotenusa: %.2f\n", sqrt(pow(primeiro_cat, 2.0) + pow(segundo_cat, 2.0)));
    printf("Area: %.2f\n", (primeiro_cat * segundo_cat) / 2);
    printf("Perimetro: %.2f\n", primeiro_cat + segundo_cat + sqrt(pow(primeiro_cat, 2.0) + pow(segundo_cat, 2.0)));
    printf("Seno: %.2f\n", primeiro_cat / sqrt(pow(primeiro_cat, 2.0) + pow(segundo_cat, 2.0)));
    printf("Cosseno: %.2f\n", segundo_cat / sqrt(pow(primeiro_cat, 2.0) + pow(segundo_cat, 2.0)));
    printf("Tangente: %.2f\n", primeiro_cat / segundo_cat);

}
