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
void buscarConsecutivosExecutiva(int numeroAssentos, int lugares[6][29]);
void buscarConsecutivosEconomica(int numeroAssentos, int lugares[6][29]);
void buscarConsecutivosSaidaEmergencia(int numeroAssentos, int lugares[6][29]);
void buscarConsecutivosSemReclinagem(int numeroAssentos, int lugares[6][29]);
void imprimirGraficos(int lugares[6][29], float precoBase);
void imprimirGraficoAlocacao(int lugares[6][29], float precoBase);
void imprimirGraficoPercentual(float porcentagem);
void imprimirGraficoReservas(int lugares[6][29]);
void imprimirGraficoIdades(int lugares[6][29]);
void imprimirGraficoValorArrecadado(int lugares[6][29], float precoBase);
float calcularPreco(int indiceFileira, int indiceColuna, int idade, float precoBase);

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
            consultarDisponibilidadeAssentosConsecutivos(lugares);
            break;
        case 6:
            imprimirGraficos(lugares, precoBase);
            break;
        case 7:
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

void consultarDisponibilidadeAssentosConsecutivos(int lugares[6][29])
{
    int numeroAssentos;
    printf("\n Digite o número de assentos consecutivos que deseja encontrar");
    scanf("%d", &numeroAssentos);

    buscarConsecutivosExecutiva(numeroAssentos, lugares);
    buscarConsecutivosEconomica(numeroAssentos, lugares);
    buscarConsecutivosSemReclinagem(numeroAssentos, lugares);
    buscarConsecutivosSaidaEmergencia(numeroAssentos, lugares);

}

void buscarConsecutivosExecutiva(int numeroAssentos, int lugares[6][29])
{
    int numeroFileira = 999;
    int numeroColuna = 999;
    int numeroLivresSequencia;

    for(int i = 0; i < 6; i++)
    {
        numeroLivresSequencia = 0;
        for(int j = 0; j < 3; j++)
        {
            if(lugares[j][i] == 0)
            {
                if(numeroLivresSequencia == 0)
                {
                    numeroFileira = j;
                    numeroColuna = i;
                }
                numeroLivresSequencia++;
            }
            else
            {
                numeroFileira = 999;
                numeroColuna = 999;
                numeroLivresSequencia = 0;
            }

            if(numeroLivresSequencia == numeroAssentos)
            {
                printf("\n Primeira sequencia EXECUTIVA encontrada: %c %d", escolherLetraAssento(numeroFileira), numeroColuna + 1);
                return;
            }
        }

        numeroLivresSequencia = 0;

        for(int j = 3; j < 6; j++)
        {
            if(lugares[j][i] == 0)
            {
                if(numeroLivresSequencia == 0)
                {
                    numeroFileira = j;
                    numeroColuna = i;
                }
                numeroLivresSequencia++;
            }
            else
            {
                numeroFileira = 999;
                numeroColuna = 999;
                numeroLivresSequencia = 0;
            }

            if(numeroLivresSequencia == numeroAssentos)
            {
                printf("\n Primeira sequencia EXECUTIVA encontrada: %c %d", escolherLetraAssento(numeroFileira), numeroColuna + 1);
                return;
            }
        }
    }

    printf("\n Nenhuma sequencia EXECUTIVA encontrada.");
}


void buscarConsecutivosEconomica(int numeroAssentos, int lugares[6][29])
{
    int numeroFileira = 999;
    int numeroColuna = 999;
    int numeroLivresSequencia;

    for(int i = 6; i < 10; i++)
    {
        numeroLivresSequencia = 0;
        for(int j = 0; j < 3; j++)
        {
            if(lugares[j][i] == 0)
            {
                if(numeroLivresSequencia == 0)
                {
                    numeroFileira = j;
                    void buscarConsecutivosEconomica(int numeroAssentos, int lugares[6][29])
                    {
                        int numeroFileira = 999;
                        int numeroColuna = 999;
                        int numeroLivresSequencia;

                        for(int i = 6; i < 10; i++)
                        {
                            numeroLivresSequencia = 0;
                            for(int j = 0; j < 3; j++)
                            {
                                if(lugares[j][i] == 0)
                                {
                                    if(numeroLivresSequencia == 0)
                                    {
                                        numeroFileira = j;
                                        numeroColuna = i;
                                    }
                                    numeroLivresSequencia++;
                                }
                                else
                                {
                                    numeroFileira = 999;
                                    numeroColuna = 999;
                                    numeroLivresSequencia = 0;
                                }

                                if(numeroLivresSequencia == numeroAssentos)
                                {
                                    printf("\n Primeira sequencia ECONOMICA encontrada: %c %d", escolherLetraAssento(numeroFileira), numeroColuna + 1);
                                    return;
                                }
                            }

                            numeroLivresSequencia = 0;

                            for(int j = 3; j < 6; j++)
                            {
                                if(lugares[j][i] == 0)
                                {
                                    if(numeroLivresSequencia == 0)
                                    {
                                        numeroFileira = j;
                                        numeroColuna = i;
                                    }
                                    numeroLivresSequencia++;
                                }
                                else
                                {
                                    numeroFileira = 999;
                                    numeroColuna = 999;
                                    numeroLivresSequencia = 0;
                                }

                                if(numeroLivresSequencia == numeroAssentos)
                                {
                                    printf("\n Primeira sequencia ECONOMICA encontrada: %c %d", escolherLetraAssento(numeroFileira), numeroColuna + 1);
                                    return;
                                }
                            }
                        }

                        numeroFileira = 999;
                        numeroColuna = 999;

                        for(int i = 13; i < 27; i++)
                        {
                            numeroLivresSequencia = 0;
                            for(int j = 0; j < 3; j++)
                            {
                                if(lugares[j][i] == 0)
                                {
                                    if(numeroLivresSequencia == 0)
                                    {
                                        numeroFileira = j;
                                        numeroColuna = i;
                                    }
                                    numeroLivresSequencia++;
                                }
                                else
                                {
                                    numeroFileira = 999;
                                    numeroColuna = 999;
                                    numeroLivresSequencia = 0;
                                }

                                if(numeroLivresSequencia == numeroAssentos)
                                {
                                    printf("\n Primeira sequencia ECONOMICA encontrada: %c %d", escolherLetraAssento(numeroFileira), numeroColuna + 1);
                                    return;
                                }
                            }

                            numeroLivresSequencia = 0;

                            for(int j = 3; j < 6; j++)
                            {
                                if(lugares[j][i] == 0)
                                {
                                    if(numeroLivresSequencia == 0)
                                    {
                                        numeroFileira = j;
                                        numeroColuna = i;
                                    }
                                    numeroLivresSequencia++;
                                }
                                else
                                {
                                    numeroFileira = 999;
                                    numeroColuna = 999;
                                    numeroLivresSequencia = 0;
                                }

                                if(numeroLivresSequencia == numeroAssentos)
                                {
                                    printf("\n Primeira sequencia ECONOMICA encontrada: %c %d", escolherLetraAssento(numeroFileira), numeroColuna + 1);
                                    return;
                                }
                            }
                        }

                        printf("\n Nenhuma sequencia ECONOMICA encontrada.");
                    }
                    numeroColuna = i;
                }
                numeroLivresSequencia++;
            }
            else
            {
                numeroFileira = 999;
                numeroColuna = 999;
                numeroLivresSequencia = 0;
            }

            if(numeroLivresSequencia == numeroAssentos)
            {
                printf("\n Primeira sequencia ECONOMICA encontrada: %c %d", escolherLetraAssento(numeroFileira), numeroColuna + 1);
                return;
            }
        }

        numeroLivresSequencia = 0;

        for(int j = 3; j < 6; j++)
        {
            if(lugares[j][i] == 0)
            {
                if(numeroLivresSequencia == 0)
                {
                    numeroFileira = j;
                    numeroColuna = i;
                }
                numeroLivresSequencia++;
            }
            else
            {
                numeroFileira = 999;
                numeroColuna = 999;
                numeroLivresSequencia = 0;
            }

            if(numeroLivresSequencia == numeroAssentos)
            {
                printf("\n Primeira sequencia ECONOMICA encontrada: %c %d", escolherLetraAssento(numeroFileira), numeroColuna + 1);
                return;
            }
        }
    }

    numeroFileira = 999;
    numeroColuna = 999;

    for(int i = 13; i < 27; i++)
    {
        numeroLivresSequencia = 0;
        for(int j = 0; j < 3; j++)
        {
            if(lugares[j][i] == 0)
            {
                if(numeroLivresSequencia == 0)
                {
                    numeroFileira = j;
                    numeroColuna = i;
                }
                numeroLivresSequencia++;
            }
            else
            {
                numeroFileira = 999;
                numeroColuna = 999;
                numeroLivresSequencia = 0;
            }

            if(numeroLivresSequencia == numeroAssentos)
            {
                printf("\n Primeira sequencia ECONOMICA encontrada: %c %d", escolherLetraAssento(numeroFileira), numeroColuna + 1);
                return;
            }
        }

        numeroLivresSequencia = 0;

        for(int j = 3; j < 6; j++)
        {
            if(lugares[j][i] == 0)
            {
                if(numeroLivresSequencia == 0)
                {
                    numeroFileira = j;
                    numeroColuna = i;
                }
                numeroLivresSequencia++;
            }
            else
            {
                numeroFileira = 999;
                numeroColuna = 999;
                numeroLivresSequencia = 0;
            }

            if(numeroLivresSequencia == numeroAssentos)
            {
                printf("\n Primeira sequencia ECONOMICA encontrada: %c %d", escolherLetraAssento(numeroFileira), numeroColuna + 1);
                return;
            }
        }
    }

    printf("\n Nenhuma sequencia ECONOMICA encontrada.");
}

void buscarConsecutivosSemReclinagem(int numeroAssentos, int lugares[6][29])
{
    int numeroFileira = 999;
    int numeroColuna = 999;
    int numeroLivresSequencia;

    for(int i = 10; i < 11; i++)
    {
        numeroLivresSequencia = 0;
        for(int j = 0; j < 3; j++)
        {
            if(lugares[j][i] == 0)
            {
                if(numeroLivresSequencia == 0)
                {
                    numeroFileira = j;
                    numeroColuna = i;
                }
                numeroLivresSequencia++;
            }
            else
            {
                numeroFileira = 999;
                numeroColuna = 999;
                numeroLivresSequencia = 0;
            }

            if(numeroLivresSequencia == numeroAssentos)
            {
                printf("\n Primeira sequencia SEM RECLINAGEM encontrada: %c %d", escolherLetraAssento(numeroFileira), numeroColuna + 1);
                return;
            }
        }

        numeroLivresSequencia = 0;

        for(int j = 3; j < 6; j++)
        {
            if(lugares[j][i] == 0)
            {
                if(numeroLivresSequencia == 0)
                {
                    numeroFileira = j;
                    numeroColuna = i;
                }
                numeroLivresSequencia++;
            }
            else
            {
                numeroFileira = 999;
                numeroColuna = 999;
                numeroLivresSequencia = 0;
            }

            if(numeroLivresSequencia == numeroAssentos)
            {
                printf("\n Primeira sequencia SEM RECLINAGEM encontrada: %c %d", escolherLetraAssento(numeroFileira), numeroColuna + 1);
                return;
            }
        }
    }

    numeroFileira = 999;
    numeroColuna = 999;

    for(int i = 28; i < 29; i++)
    {
        numeroLivresSequencia = 0;
        for(int j = 0; j < 3; j++)
        {
            if(lugares[j][i] == 0)
            {
                if(numeroLivresSequencia == 0)
                {
                    numeroFileira = j;
                    numeroColuna = i;
                }
                numeroLivresSequencia++;
            }
            else
            {
                numeroFileira = 999;
                numeroColuna = 999;
                numeroLivresSequencia = 0;
            }

            if(numeroLivresSequencia == numeroAssentos)
            {
                printf("\n Primeira sequencia SEM RECLINAGEM encontrada: %c %d", escolherLetraAssento(numeroFileira), numeroColuna + 1);
                return;
            }
        }

        numeroLivresSequencia = 0;

        for(int j = 3; j < 6; j++)
        {
            if(lugares[j][i] == 0)
            {
                if(numeroLivresSequencia == 0)
                {
                    numeroFileira = j;
                    numeroColuna = i;
                }
                numeroLivresSequencia++;
            }
            else
            {
                numeroFileira = 999;
                numeroColuna = 999;
                numeroLivresSequencia = 0;
            }

            if(numeroLivresSequencia == numeroAssentos)
            {
                printf("\n Primeira sequencia SEM RECLINAGEM encontrada: %c %d", escolherLetraAssento(numeroFileira), numeroColuna + 1);
                return;
            }
        }
    }

    printf("\n Nenhuma sequencia SEM RECLINAGEM encontrada.");
}

void buscarConsecutivosSaidaEmergencia(int numeroAssentos, int lugares[6][29])
{

    int numeroFileira = 999;
    int numeroColuna = 999;
    int numeroLivresSequencia;

    for(int i = 11; i < 13; i++)
    {
        numeroLivresSequencia = 0;
        for(int j = 0; j < 3; j++)
        {
            if(lugares[j][i] == 0)
            {
                if(numeroLivresSequencia == 0)
                {
                    numeroFileira = j;
                    numeroColuna = i;
                }
                numeroLivresSequencia++;
            }
            else
            {
                numeroFileira = 999;
                numeroColuna = 999;
                numeroLivresSequencia = 0;
            }

            if(numeroLivresSequencia == numeroAssentos)
            {
                printf("\n Primeira sequencia SAIDA DE EMERGENCIA encontrada: %c %d", escolherLetraAssento(numeroFileira), numeroColuna + 1);
                return;
            }
        }

        numeroLivresSequencia = 0;

        for(int j = 3; j < 6; j++)
        {
            if(lugares[j][i] == 0)
            {
                if(numeroLivresSequencia == 0)
                {
                    numeroFileira = j;
                    numeroColuna = i;
                }
                numeroLivresSequencia++;
            }
            else
            {
                numeroFileira = 999;
                numeroColuna = 999;
                numeroLivresSequencia = 0;
            }

            if(numeroLivresSequencia == numeroAssentos)
            {
                printf("\n Primeira sequencia SAIDA DE EMERGENCIA encontrada: %c %d", escolherLetraAssento(numeroFileira), numeroColuna + 1);
                return;
            }
        }
    }

    printf("\n Nenhuma sequencia SAIDA DE EMERGENCIA encontrada.");
}

void imprimirGraficos(int lugares[6][29], float precoBase)
{

    imprimirGraficoAlocacao(lugares, precoBase);
    imprimirGraficoReservas(lugares);
    imprimirGraficoIdades(lugares);
    imprimirGraficoValorArrecadado(lugares, precoBase);

}

void imprimirGraficoAlocacao(int lugares[6][29], float precoBase)
{
    printf("\n Grafico de alocação: \n");

    float total = 6 * 29.0;

    int livres = 0;

    int ocupados = 0;

    for(int i = 0; i < 6; i++)
    {
        for(int  j = 0; j < 29; j++)
        {
            if(lugares[i][j] == 0)
            {
                livres++;
            }
            else
            {
                ocupados++;
            }
        }
    }

    printf("\n Reservados: %d - %.1f %%", ocupados, ocupados * 1.0 / total * 100.0);
    imprimirGraficoPercentual(ocupados * 1.0 / total * 100.0);
    printf("\n Liberados: %d - %.1f %%", livres, livres * 1.0/total * 100.0);
    imprimirGraficoPercentual(livres * 1.0 / total * 100.0);
    printf("\n Total: %.0f %.1f %%", total, 100.0);
    imprimirGraficoPercentual(100.0);
}

void imprimirGraficoPercentual(float porcentagem)
{
    printf("|");
    for(int i = 0; i < 20; i++)
    {
        if(porcentagem / 5.0 >= i * 1.0)
        {
            printf(" = ");
        }
        else
        {
            printf(" . ");
        }
    }
    printf("|");
}

void imprimirGraficoReservas(int lugares[6][29])
{
    printf("\n Grafico de reservas: \n");

    int total = 29;
    int livres, ocupados;

    for(int i = 5; i >= 0; i--)
    {
        livres = 0;
        ocupados = 0;
        for(int  j = 0; j < 29; j++)
        {
            if(lugares[i][j] == 0)
            {
                livres++;
            }
            else
            {
                ocupados++;
            }
        }
        printf("\n %c: - %d - %.1f %%", escolherLetraAssento(i), ocupados, ocupados * 1.0 / total * 100.0);
        imprimirGraficoPercentual(ocupados * 1.0 / total * 100.0);
    }
}

void imprimirGraficoIdades(int lugares[6][29])
{
    printf("\n Grafico de reservas: \n");

    int totalReservas = 0;

    int totalZeroAdois = 0;

    int totalDoisAdoze = 0;

    int totalDozeAvinte = 0;

    int totalVinteASessenta = 0;

    int totalSessentaNoventaeNove = 0;

    for(int i = 0; i < 6; i++)
    {
        for(int  j = 0; j < 29; j++)
        {
            if(lugares[i][j] != 0)
            {
                totalReservas++;
                int idade = lugares[i][j];
                if(idade < 2)
                {
                    totalZeroAdois++;
                }
                else if(idade >= 2 && idade < 12)
                {
                    totalDoisAdoze++;
                }
                else if(idade >= 12 && idade < 20)
                {
                    totalDozeAvinte++;
                }
                else if(idade >= 20 && idade < 60)
                {
                    totalVinteASessenta++;
                }
                else if(idade >= 60 && idade < 99)
                {
                    totalSessentaNoventaeNove++;
                }
            }
        }
    }

    printf("\n 00-02: %d - %.1f %%", totalZeroAdois, totalZeroAdois * 1.0 / totalReservas * 100.0);
    imprimirGraficoPercentual(totalZeroAdois * 1.0 / totalReservas * 100.0);

    printf("\n 02-12: %d - %.1f %%", totalDoisAdoze, totalDoisAdoze * 1.0 / totalReservas * 100.0);
    imprimirGraficoPercentual(totalDoisAdoze * 1.0 / totalReservas * 100.0);

    printf("\n 12-20: %d - %.1f %%", totalDozeAvinte, totalDozeAvinte * 1.0 / totalReservas * 100.0);
    imprimirGraficoPercentual(totalDozeAvinte * 1.0 / totalReservas * 100.0);

    printf("\n 20-60: %d - %.1f %%", totalVinteASessenta, totalVinteASessenta * 1.0 / totalReservas * 100.0);
    imprimirGraficoPercentual(totalVinteASessenta * 1.0 / totalReservas * 100.0);

    printf("\n 60-99: %d - %.1f %%", totalSessentaNoventaeNove, totalSessentaNoventaeNove * 1.0 / totalReservas * 100.0);
    imprimirGraficoPercentual(totalSessentaNoventaeNove * 1.0 / totalReservas * 100.0);
}


void imprimirGraficoValorArrecadado(int lugares[6][29], float precoBase)
{
    printf("\n Grafico de reservas: \n");

    float totalArrecadado = 0.0;

    float totalExecutiva = 0.0;

    float totalEconomica = 0.0;

    float totalSaidaEmergencia = 0.0;

    float totalSemReclinagem = 0.0;

    for(int i = 0; i < 6; i++)
    {
        for(int  j = 0; j < 29; j++)
        {
            if(lugares[i][j] != 0)
            {
                float precoCalculado = calcularPreco(i, j, lugares[i][j], precoBase);
                totalArrecadado += precoCalculado;
                if(j < 6)
                {
                    totalExecutiva += precoCalculado;
                }
                else if(j > 6 && j < 10 || j > 12 && j < 27)
                {
                    totalEconomica += precoCalculado;
                }
                else if(j == 12 || j == 11)
                {
                    totalSaidaEmergencia += precoCalculado;
                }
                else if(j == 10 || j == 28)
                {
                    totalSemReclinagem += precoCalculado;
                }
            }
        }
    }

    printf("\n Executiva : %.2f - %.1f %%", totalExecutiva, totalExecutiva / totalArrecadado * 100.0);
    imprimirGraficoPercentual(totalExecutiva / totalArrecadado * 100.0);

    printf("\n Economica : %.2f - %.1f %%", totalEconomica, totalEconomica / totalArrecadado * 100.0);
    imprimirGraficoPercentual(totalEconomica / totalArrecadado * 100.0);

    printf("\n Saida de emergencia : %.2f - %.1f %%", totalSaidaEmergencia, totalSaidaEmergencia / totalArrecadado * 100.0);
    imprimirGraficoPercentual(totalSaidaEmergencia / totalArrecadado * 100.0);

    printf("\n Sem reclinagem : %.2f - %.1f %%", totalSemReclinagem, totalSemReclinagem / totalArrecadado * 100.0);
    imprimirGraficoPercentual(totalSemReclinagem / totalArrecadado * 100.0);


    printf("\n Total : %.2f - %.1f %%", totalArrecadado, 100.0);
    imprimirGraficoPercentual( 100.0);

}

float calcularPreco(int indiceFileira, int indiceColuna, int idade, float precoBase)
{

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


