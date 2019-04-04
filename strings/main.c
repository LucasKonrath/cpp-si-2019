#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void imprimeCapacidadeValor(char lido[]);

void iguaisOuNao(char um[], char dois[]);

void formaFrase(char sujeito[], char verbo[], char predicado[]);

void toUppercase(char minusculo[]);

void isPalindrome(char palavra[]);
int main()
{
    imprimeCapacidadeValor("Teste");


    iguaisOuNao("sim", "sim");
    iguaisOuNao("sim", "nao");
    iguaisOuNao("nao", "sim");

    formaFrase("eu", "gostar", "bepis");

    toUppercase("tocalmo");

    isPalindrome("arara");
    isPalindrome("batata");
}

void imprimeCapacidadeValor(char lido[])
{
    printf("\nTamanho: %.02d Valor: %s", sizeof(lido), lido);
}

void iguaisOuNao(char um[], char dois[])
{
    int comparacao = strcmp(um, dois);

    if(comparacao == 0)
    {
        printf("\n Strings iguais");
    }
    else if(comparacao < 0)
    {
        printf("\n String 1 < String 2");
    }
    else
    {
        printf("\n String 1 > String 2");
    }
}

void formaFrase(char sujeito[], char verbo[], char predicado[])
{
    char fraseFinal[100] = "\n";
    strcat(fraseFinal, sujeito);
    strcat(fraseFinal, " ");
    strcat(fraseFinal, verbo);
    strcat(fraseFinal, " ");
    strcat(fraseFinal, predicado);
    strcat(fraseFinal, ".");
    printf("%s", fraseFinal);
}

void toUppercase(char minusculo[]){
    printf("\n Minusculo: %s", minusculo);

        int tamanhoMinusculo = strlen(minusculo);

     char maiusculo[tamanhoMinusculo];

    for (int a = 0; a < tamanhoMinusculo; a++)
    {
        maiusculo[a] = toupper(minusculo[a]);
    }

    printf("\n Maiusculo: %s", maiusculo);
}

void isPalindrome(char palavra[]){
    int isNotPalindromo = 0;

    int tamanhoPalavra = strlen(palavra);

    int tamanhoIteracao = tamanhoPalavra / 2;

    for(int i = 0; i < tamanhoIteracao; i++){
        if(palavra[i] != palavra[tamanhoPalavra - i - 1]){
            isNotPalindromo++;
        }
    }

    if(isNotPalindromo > 0){
        printf("\n %s nao eh palindromo", palavra);
    }else{
        printf("\n %s eh palindromo", palavra);
    }
}
