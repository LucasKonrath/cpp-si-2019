#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

float solicitarPrecoBase();
void imprimirMapaAviao(int lugares[6][29]);
int escolherOpcao();
char escolherLetraAssento(int indice);
void listarPrecos(float precoBase);
void reservarAssento(int lugares[6][29], float precoBase);
int assentoLivre(char assento[3], int lugares[6][29]);
int obterIndiceFileira(char codigoFileira);
float calcularPrecoAssento(char assento[3], int idade, float precoBase);
void confirmarReserva(char assento[3], int idade, int lugares[6][29]);
void liberarReserva(int lugares[6][29]);
void retirarReserva(char assento[3], int lugares[6][29]);
void consultarAssento(int lugares[6][29], float precoBase);
const char* obterCategoriaAssento(char assento[3]);
int obterIdadeReservada(char assento[3], int lugares[6][29]);
void consultarDisponibilidadeAssentosConsecutivos(int lugares[6][29]);

int main()
{

    setlocale(LC_ALL, "Portuguese");

    int escolha;
    float precoBase = solicitarPrecoBase();

    int lugares [6][29];

    for(int i = 0; i < 6; i++)
    {
        for(int j = 0; j < 29; j++)
        {
            lugares[i][j] = 0;
        }
    }

    while(1)
    {

        imprimirMapaAviao(lugares);
        escolha = escolherOpcao();

        switch (escolha)
        {
        case 1:
            listarPrecos(precoBase);
            break;
        case 2:
            reservarAssento(lugares, precoBase);
            break;
        case 3:
            liberarReserva(lugares);
            break;
        case 4:
            consultarAssento(lugares, precoBase);
            break;
        case 5:
            printf("O programa foi fechado\n");
            return 0;
        default:
            printf("Opcao invalida");
        }
    }

}


float solicitarPrecoBase()
{
    float precoBasePassagem;
    printf("Informe o preço base das passagens.");
    scanf("%f", &precoBasePassagem);
    return precoBasePassagem;
}

void imprimirMapaAviao(int lugares[6][29])
{
    printf("\n                                     /:::::::::::::::::::::|");
    printf("\n                                    /::::::::::::::::::::::|");
    printf("\n                                   /:::::::::::::::::::::::|");
    printf("\n  01 02 03 04 05 06 | 07 08 09 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29");
    printf("\n--------------------------------------------------------------------------------------------");
    for(int i = 5; i >= 0; i--)
    {
        if(i == 2)
        {
            printf("\n");
        }
        printf("\n%c|", escolherLetraAssento(i));
        for(int j = 0; j < 29; j++)
        {
            if(j == 6)
            {
                printf("| ");
            }
            if(lugares[i][j] == 0)
            {
                printf("-- ");
            }
            else
            {
                printf("%.2d", lugares[i][j]);
            }
        }
    }
    printf("\n--------------------------------------------------------------------------------------------");
    printf("\n  01 02 03 04 05 06 | 07 08 09 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29");
    printf("\n                                   \\:::::::::::::::::::::::|");
    printf("\n                                    \\::::::::::::::::::::::|");
    printf("\n                                     \\:::::::::::::::::::::|");
}

int escolherOpcao()
{
    printf("\n\n\n Digite 1 para listar preços conforme idades e categorias.");
    printf("\n Digite 2 para reservar um assento.");
    printf("\n Digite 3 para liberar a reserva de um assento.");
    printf("\n Digite 4 para consultar a situação de um assento.");
    printf("\n Digite 5 para consultar a disponibilidade de assentos consecutivos.");
    printf("\n Digite 6 para imprimir os relatórios.");
    printf("\n Digite 7 para sair");

    int escolha;
    scanf("%d", &escolha);
    return escolha;
}

char escolherLetraAssento(int indice)
{
    switch(indice)
    {
    case 0:
        return 'A';
    case 1:
        return 'B';
    case 2:
        return 'C';
    case 3:
        return 'D';
    case 4:
        return 'E';
    case 5:
        return 'F';
    default:
        break;
    }
}

void listarPrecos(float precoBase)
{
    printf("\n---------------------------------------------------");
    printf("\n|           Executivo (fileiras 0 a 6)            |");
    printf("\n|     Adulto    | 0 a 2 anos    |  2 a 12 anos    |");
    printf("\n|   R$%.2f   |     R$%.2f   |      R$%.2f     |", precoBase * 2.5, precoBase * 2.5 * 0.8, precoBase * 2.5 * 0.9);

    printf("\n---------------------------------------------------");
    printf("\n|     Econômica (fileiras 07 a 10 e 14 a 28)      |");
    printf("\n|     Adulto    | 0 a 2 anos    |  2 a 12 anos    |");
    printf("\n|   R$%.2f   |     R$%.2f   |      R$%.2f     |", precoBase * 0.9, precoBase * 0.9 * 0.5, precoBase * 0.9 * 0.7);

    printf("\n---------------------------------------------------");
    printf("\n|     Saída de Emergência  (fileiras 12 e 13)     |");
    printf("\n|     Adulto    | 0 a 2 anos    |  2 a 12 anos    |");
    printf("\n|   R$%.2f   |     R$%.2f   |      R$%.2f     |", precoBase * 1.1, precoBase * 1.1 * 0.7, precoBase * 1.1 * 0.8);

    printf("\n---------------------------------------------------");
    printf("\n|       Sem Reclinagem  (fileiras 11 e 29)        |");
    printf("\n|     Adulto    | 0 a 2 anos    |  2 a 12 anos    |");
    printf("\n|   R$%.2f   |     R$%.2f   |      R$%.2f     |", precoBase * 0.8, precoBase * 0.8 * 0.3, precoBase * 0.8 * 0.5);

    printf("\n\n\n");
}

void reservarAssento(int lugares[6][29], float precoBase)
{

    char assento[3];

    printf("\nDigite o assento desejado");
    scanf("%s", assento);
    printf("assento escolhido %s", assento);

    if(assentoLivre(assento, lugares) == 0)
    {
        printf("\n Assento informado não está livre.");
        return;
    }

    int idade;

    printf("\n Informe sua idade: ");
    scanf("%d", &idade);

    if(idade < 0 || idade > 99)
    {
        printf("\n Idade inválida, deve ser entre 0 e 99 anos.");
        return;
    }

    printf("\n Preço do assento: R$%.2f", calcularPrecoAssento(assento, idade, precoBase));

    printf("\n Deseja reservar o assento? Digite S ou N.");
    char resposta;

    scanf(" %c", &resposta);

    if('S' == resposta)
    {
        confirmarReserva(assento, idade, lugares);
    }
    else if('N' == resposta)
    {
        printf("\n Abandonando operação.");
        return;
    }
    else
    {
        printf("\n Operação inválida.");
        return;
    }
}

int assentoLivre(char assento[3], int lugares[6][29])
{
    char fileira = assento[0];
    int indiceColuna = ((assento[1] - '0') * 10 + (assento[2] - '0')) - 1;

    int indiceFileira = obterIndiceFileira(fileira);

    if(lugares[indiceFileira][indiceColuna] == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

obterIndiceFileira(char codigoFileira)
{
    switch(codigoFileira)
    {
    case 'A':
        return 0;
    case 'B':
        return 1;
    case 'C':
        return 2;
    case 'D':
        return 3;
    case 'E':
        return 4;
    case 'F':
        return 5;
    }
}

float calcularPrecoAssento(char assento[3], int idade, float precoBase)
{

    char fileira = assento[0];
    int indiceColuna =((assento[1] - '0') * 10 + (assento[2] - '0')) - 1;

    int indiceFileira = obterIndiceFileira(fileira);
    float multiplicador;
    float multiplicadorIdade = 1.0;

    if(indiceColuna < 6)
    {
        multiplicador = 2.5;
        if(idade < 2)
        {
            multiplicadorIdade = 0.8;
        }
        else if(idade < 12)
        {
            multiplicadorIdade = 0.9;
        }
    }
    else if(indiceColuna > 6 && indiceColuna < 10 || indiceColuna > 12 && indiceColuna < 27)
    {
        multiplicador = 0.9;
        if(idade < 2)
        {
            multiplicadorIdade = 0.5;
        }
        else if(idade < 12)
        {
            multiplicadorIdade = 0.7;
        }
    }
    else if(indiceColuna == 12 || indiceColuna == 11)
    {
        multiplicador = 1.1;
        if(idade < 2)
        {
            multiplicadorIdade = 0.7;
        }
        else if(idade < 12)
        {
            multiplicadorIdade = 0.8;
        }
    }
    else if(indiceColuna == 10 || indiceColuna == 28)
    {
        multiplicador = 0.8;
        if(idade < 2)
        {
            multiplicadorIdade = 0.3;
        }
        else if(idade < 12)
        {
            multiplicadorIdade = 0.5;
        }
    }

    return precoBase * multiplicador * multiplicadorIdade;
}

void confirmarReserva(char assento[3], int idade, int lugares[6][29])
{
    char fileira = assento[0];
    int indiceColuna = ((assento[1] - '0') * 10 + (assento[2] - '0')) - 1;

    int indiceFileira = obterIndiceFileira(fileira);

    lugares[indiceFileira][indiceColuna] =  idade;

}

void liberarReserva(int lugares[6][29])
{

    char assento[3];

    printf("\nDigite o assento desejado");
    scanf("%s", assento);
    printf("assento escolhido %s", assento);

    if(assentoLivre(assento, lugares) == 0)
    {
        printf("\n Assento informado não está livre.");
        printf("\n Deseja cancelar sua reserva? S para sim, N para não.");
        char resposta;

        scanf(" %c", &resposta);

        if('S' == resposta)
        {
            retirarReserva(assento, lugares);
        }
        else if('N' == resposta)
        {
            printf("\n Abandonando operação.");
            return;
        }
        else
        {
            printf("\n Operação inválida.");
            return;
        }
    }
    else
    {
        printf("\n Assento informado já está livre.");
        return;
    }
}

void retirarReserva(char assento[3], int lugares[6][29])
{

    char fileira = assento[0];

    int indiceColuna = ((assento[1] - '0') * 10 + (assento[2] - '0')) - 1;

    int indiceFileira = obterIndiceFileira(fileira);

    lugares[indiceFileira][indiceColuna] =  0;
}

void consultarAssento(int lugares[6][29], float precoBase)
{

    char assento[3];

    printf("\nDigite o assento desejado");
    scanf("%s", assento);
    printf("assento escolhido %s", assento);

    int livre = assentoLivre(assento, lugares);

    if(livre == 0)
    {
        printf("\n Assento informado não está livre.");
    }
    else
    {
        printf("\n Assento está livre!");
    }

    printf("\nCategoria: %s", obterCategoriaAssento(assento));

    if(livre == 0)
    {
        printf("\n Idade de quem reservou: %d", obterIdadeReservada(assento, lugares));
    }

    printf("\n Preço base: %f", calcularPrecoAssento(assento, 20, precoBase));
    if(livre == 1)
    {
        printf("\n Preço para menores de 2 anos: %f", calcularPrecoAssento(assento, 1, precoBase));
        printf("\n Preço para menores de 12 anos: %f", calcularPrecoAssento(assento, 11, precoBase));
    }
}

const char* obterCategoriaAssento(char assento[3])
{

    char fileira = assento[0];

    int indiceColuna = ((assento[1] - '0') * 10 + (assento[2] - '0')) - 1;

    int indiceFileira = obterIndiceFileira(fileira);

    if(indiceColuna < 6)
    {
        return "EXECUTIVA";
    }
    else if(indiceColuna > 6 && indiceColuna < 10 || indiceColuna > 12 && indiceColuna < 27)
    {
        return "ECONOMICA";
    }
    else if(indiceColuna == 12 || indiceColuna == 11)
    {
        return "SAÍDA DE EMERGÊNCIA";
    }
    else if(indiceColuna == 10 || indiceColuna == 28)
    {
        return "SEM RECLINAGEM";
    }

    return;
}

int obterIdadeReservada(char assento[3], int lugares[6][29])
{

    char fileira = assento[0];

    int indiceColuna = ((assento[1] - '0') * 10 + (assento[2] - '0')) - 1;

    int indiceFileira = obterIndiceFileira(fileira);

    return lugares[indiceFileira][indiceColuna];
}

