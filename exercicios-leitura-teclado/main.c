#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{

    setlocale(LC_ALL, "Portuguese");

    int diaNascimento;
    int mesNascimento;
    int anoNascimento;

    printf("Opa! Qual � o seu dia de nascimento?\n");
    scanf("%d", &diaNascimento);
    printf("Me parece que voc� nasceu no dia %d.\n", diaNascimento);

    fflush(stdin);

    printf("Opa! Qual � o seu m�s de nascimento?\n");
    scanf("%d", &mesNascimento);
    printf("Me parece que voc� nasceu no m�s %d.\n", mesNascimento);

    fflush(stdin);

    printf("Opa! Qual � o seu ano de nascimento?\n");
    scanf("%d", &anoNascimento);
    printf("Me parece que voc� nasceu no ano %d.\n", anoNascimento);


    printf("Voc� nasceu em: %02d/%02d/%04d", diaNascimento, mesNascimento, anoNascimento);

}
