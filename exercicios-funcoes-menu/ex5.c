#include <stdio.h>
#include <stdlib.h>

void cadastrarRendimento(float *rendimentoHora);
void cadastrarHorasTrabalhadas(int *horasTrabalhadas);
float calcularSalarioBruto(float rendimentoHora, int horasTrabalhadas);
float calcularContribuicaoInss(float rendimentoHora, int horasTrabalhadas);
float calcularContribuicaoSindicato(float rendimentoHora, int horasTrabalhadas);
float calcularSalarioLiquido(float rendimentoHora, int horasTrabalhadas);

int main()
{

    int escolha;
    printf("Nenhuma opcao escolhida");
    float rendimentoHora;
    int horasTrabalhadas;

    while(1)
    {
        printf("\n----------------------- ");
        printf("\n1 - Cadastrar rendimento por hora");
        printf("\n2 - Cadastrar horas trabalhadas");
        printf("\n3 - Ver salario bruto");
        printf("\n4 - Ver contribuicao INSS");
        printf("\n5 - Ver contribuicao sindicato");
        printf("\n6 - Ver salario liquido");
        printf("\n7 - Fechar programa ");
        printf("\n----------------------- ");
        printf("\nEscolha uma opcao: \n");
        scanf("%d",&escolha);
        fflush(stdin);
        system("cls");

        switch (escolha)
        {
        case 1:
            cadastrarRendimento(&rendimentoHora);
            printf("\nRendimento cadastrado: %f", rendimentoHora);
            break;
        case 2:
            cadastrarHorasTrabalhadas(&horasTrabalhadas);
            break;
        case 3:
            printf("\nSalario bruto: %.2f", calcularSalarioBruto(rendimentoHora, horasTrabalhadas));
            break;
        case 4:
            printf("\nContribuicao INSS: %.2f", calcularContribuicaoInss(rendimentoHora, horasTrabalhadas));
            break;
        case 5:
            printf("\nContribuicao Sindicato: %.2f", calcularContribuicaoSindicato(rendimentoHora, horasTrabalhadas));
            break;
        case 6:
            printf("\nSalario liquido:  %.2f", calcularSalarioLiquido(rendimentoHora, horasTrabalhadas));
            break;
        case 7:
            printf("\nO programa foi fechado\n");
            return 0;
        default:
            printf("\nOpcao invalida");
        }
    }
}

void cadastrarRendimento(float *rendimentoHora){
    printf("\n Informe seu rendimento por hora!");
    scanf("%f", rendimentoHora);
}

void cadastrarHorasTrabalhadas(int *horasTrabalhadas){
    printf("\n Informe seu numero de horas trabalhadas!");
    scanf("%d", horasTrabalhadas);
}

float calcularSalarioBruto(float rendimentoHora, int horasTrabalhadas){
    return rendimentoHora * horasTrabalhadas;
};

float calcularContribuicaoInss(float rendimentoHora, int horasTrabalhadas){
    return rendimentoHora * horasTrabalhadas * 0.11;
};

float calcularContribuicaoSindicato(float rendimentoHora, int horasTrabalhadas){
    return rendimentoHora * horasTrabalhadas * 0.02;
};
float calcularSalarioLiquido(float rendimentoHora, int horasTrabalhadas){
    return calcularSalarioBruto(rendimentoHora, horasTrabalhadas) - calcularContribuicaoInss(rendimentoHora, horasTrabalhadas) - calcularContribuicaoSindicato(rendimentoHora, horasTrabalhadas);
};


