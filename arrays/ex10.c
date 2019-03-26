#include <stdio.h>
#include <stdlib.h>

void imprimirHistograma(float valorInicial, float valorFinal, int numeroNotas);

int main()
{
    int tamanhoTurma;

    printf("Qual o tamanho da turma? \n");
    scanf(" %d", &tamanhoTurma);

    float notas[tamanhoTurma];

    for(int i = 0; i < tamanhoTurma; i++){
        printf("\nDigite a %d nota\n", i + 1);
        scanf(" %f", &notas[i]);
    }

    float menorNota = notas[0];
    float maiorNota = notas[0];
    float mediaTurma = 0;

    int qtdEntreZeroTres = 0, qtdEntreTresUmQuatro = 0, qtdQuatroCinco = 0, qtdCincoSeis = 0, qtdSeisSete = 0, qtdSeteOito = 0, qtdOitoNove = 0, qtdNoveDez = 0;

    for(int i = 0; i < tamanhoTurma; i++){
        if(notas[i] <= menorNota){
            menorNota = notas[i];
        }

        if(notas[i] >= maiorNota){
            maiorNota = notas[i];
        }

        mediaTurma += notas[i] / tamanhoTurma * 1.0;

        float nota = notas[i];

        if(nota >= 0.0 && nota < 3.1){
            qtdEntreZeroTres++;
        }else if(nota >= 3.1 && nota < 4.1){
            qtdEntreTresUmQuatro++;
        }else if(nota >= 4.1 && nota < 5.1){
            qtdQuatroCinco++;
        }else if(nota >= 5.1 && nota < 6.1){
            qtdCincoSeis++;
        }else if(nota >= 6.1 && nota < 7.1){
            qtdSeisSete++;
        }else if(nota >= 7.1 && nota < 8.1){
            qtdSeteOito++;
        }else if(nota >= 8.1 && nota < 9.1){
            qtdOitoNove++;
        }else if(nota >= 9.1 && nota <= 10){
            qtdNoveDez++;
        }
    }

    printf("\nResultado da avaliacao da turma: \n");

    printf("\n Menor nota: %f \n", menorNota);
    printf("\n Maior nota: %f \n", maiorNota);
    printf("\n Média da turma: %f \n", mediaTurma);

    imprimirHistograma(0.0, 3.0, qtdEntreZeroTres);
    imprimirHistograma(3.1, 4.0, qtdEntreTresUmQuatro);
    imprimirHistograma(4.1, 5.0, qtdQuatroCinco);
    imprimirHistograma(5.1, 6.0, qtdCincoSeis);
    imprimirHistograma(6.1, 7.0, qtdSeisSete);
    imprimirHistograma(7.1, 8.0, qtdSeteOito);
    imprimirHistograma(8.1, 9.0, qtdOitoNove);
    imprimirHistograma(9.1, 10.0, qtdNoveDez);


}

void imprimirHistograma(float valorInicial, float valorFinal, int numeroNotas){
printf("\n%.1f ~ %.1f  ", valorInicial, valorFinal);
for(int i = 0; i < numeroNotas; i++){
    printf("*");
}
}
