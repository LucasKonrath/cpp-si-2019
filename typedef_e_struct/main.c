#include <stdio.h>
#include <stdlib.h>

int main()
{
    enum Genero {F, M};

    typedef struct PESSOA
    {
        char nome[40];
        enum Genero genero;
        char cidade[40];
        int idade;
        int idadePai;
        int idadeMae;
        int quantidadeFilhos;
        float rendaFamilia;
    } Pessoa;

    int pessoasEntrevistadas = 0;
    int quantidadeMaximaPessoas;

    printf("\n Digite a quantidade máxima de pessoas do senso: \n");
    scanf("%d", &quantidadeMaximaPessoas);

    Pessoa pessoas[quantidadeMaximaPessoas];

    while(1)
    {
        int escolha;
        printf("\n----------------------- ");
        printf("\n1 - Entrevistar uma pessoa ");
        printf("\n2 - Mostrar resultados ");
        printf("\n3 - Fechar programa ");
        printf("\n----------------------- ");
        printf("\nEscolha uma opcao: ");
        scanf("%d",&escolha);
        fflush(stdin);
        system("cls");

        switch (escolha)
        {
        case 1:
            if(pessoasEntrevistadas + 1 > quantidadeMaximaPessoas)
            {
                printf("Maximo de pessoas cadastrados.");
                return 1;
            }
            printf("\n Digite o nome da pessoa: ");
            scanf("%s", pessoas[pessoasEntrevistadas].nome);
            fflush(stdin);
            printf("\n Digite a idade da pessoa: ");
            scanf("%d", &pessoas[pessoasEntrevistadas].idade);
            fflush(stdin);
            printf("\n Digite 0 se for Feminina, 1 se for Masculino");
            scanf("%d", &pessoas[pessoasEntrevistadas].genero);
            fflush(stdin);
            printf("\n Digite a cidade da pessoa: ");
            scanf("%s", pessoas[pessoasEntrevistadas].cidade);
            fflush(stdin);
            printf("\n Digite a idade do pai da pessoa: ");
            scanf("%d", &pessoas[pessoasEntrevistadas].idadePai);
            fflush(stdin);
            printf("\n Digite a idade da mãe da pessoa: ");
            scanf("%d", &pessoas[pessoasEntrevistadas].idadeMae);
            fflush(stdin);
            printf("\n Digite a qtd de filhos da pessoa: ");
            scanf("%d", &pessoas[pessoasEntrevistadas].quantidadeFilhos);
            fflush(stdin);
            printf("\n Digite a renda da familia da pessoa: ");
            scanf("%f", &pessoas[pessoasEntrevistadas].rendaFamilia);
            fflush(stdin);
            pessoasEntrevistadas++;
            break;
        case 2:
            printf("\n Quantidade de pessoas cadastradas: %d", pessoasEntrevistadas);
            break;
        case 3:
            printf("Opcao escolhida: 3 ");
            return 0;
        default:
            printf("Opcao invalida");
        }
    }
}
