#include <stdio.h>
#include <stdlib.h>

#include <stdio.h>
#include <math.h>
int main()
{
//float notaFinal = 8.6;
//
//if(notaFinal >= 8.5){
//    printf("Parabens! Voce passou direto.");
//}
//else if(notaFinal >= 6.0)
//{
//printf("Grau C para aumentar a nota");
//}
//else
//{
//printf("Grau C para poder passar");
//}

//int a;
//printf("Digite o numero: \n");
//scanf("%d", &a);
//
//if(a % 2 == 0){
//    printf("Par!");
//}else{
//    printf("Impar!");
//}

//int a,b;
//
//printf("Digite o primeiro numero: \n");
//scanf("%d", &a);
//
//printf("Digite o segundo numero: \n");
//scanf("%d", &b);
//
//if(a % b == 0){
//    printf("%d eh divisivel por %d", a, b);
//}else{
//    printf("%d nao eh divisivel por %d", a, b);
//}
//
//int a,b;
//
//printf("Digite o primeiro numero: \n");
//scanf("%d", &a);
//
//printf("Digite o segundo numero: \n");
//scanf("%d", &b);
//
//if(a - b < 0){
//    printf("Negativo");
//}else{
//    printf("Positivo");
//}


//float a;
//
//printf("Digite a temperatura da agua em graus celsius: \n");
//scanf("%f", &a);
//
//if(a <= 0){
//    printf("Solido");
//}else if(a >= 100){
//    printf("Gasoso");
//}else{
//    printf("Liquido");
//}

//char letra;
//printf("Digite uma letra: \n");
//scanf("%c", &letra);
//
//if(letra >= 65 && letra <= 90){
//    printf("Maiusculo");
//}else if(letra >= 97 && letra <=122){
//    printf("minusculo");
//}else{
//    printf("pfvr digite uma letra");
//}

//char letra_1, letra_2;
//printf("Digite uma letra: \n");
//scanf("%c", &letra_1);
//
//fflush(stdin);
//
//printf("Digite outra letra: \n");
//scanf("%c", &letra_2);
//
//if(letra_1 == letra_2){
//    printf("letras iguais");
//}else if( letra_1 > letra_2){
//    printf("sucessora");
//}else{
//    printf("antecessora");
//}

//float distancia, velocidade, tempo;
//
//printf("Informe a distancia. caso seja o que deve ser calculado infome como 0.\n");
//scanf("%f", &distancia);
//
//printf("Informe a velocidade. caso seja o que deve ser calculado infome como 0.\n");
//scanf("%f", &velocidade);
//
//printf("Informe o tempo. caso seja o que deve ser calculado infome como 0.\n");
//scanf("%f", &tempo);
//
//if(tempo == 0){
//    printf("Tempo: %.2f", distancia / velocidade);
//}else if(velocidade == 0){
//    printf("Velocidade: %.2f", distancia / tempo);
//}else if(distancia == 0){
//    printf("Distancia: %.2f", tempo * velocidade);
//}else{
//    printf("parametros invalidos");
//}

//float x1, y1, x2, y2;
//
//printf("Digite x1: \n");
//scanf("%f", &x1);
//fflush(stdin);
//printf("Digite y1: \n");
//scanf("%f", &y1);
//fflush(stdin);
//printf("Digite x2: \n");
//scanf("%f", &x2);
//fflush(stdin);
//printf("Digite y2: \n");
//scanf("%f", &y2);
//fflush(stdin);
//printf("Distancia: %.2f", sqrt(pow(x2 - x1, 2.0) + pow(y2 - y1, 2.0)));

float altura_m;
char sexo;
float pesoIdeal, pesoInformado;

printf("Digite a altura em m ex: 1.70\n");

scanf("%f", &altura_m);

fflush(stdin);

printf("Digite seu sexo, M para masculino e F para feminino.\n");
scanf("%c", &sexo);

fflush(stdin);

if(sexo == 'M'){
    pesoIdeal = (72.7 * altura_m) - 58.0;
}else {
    pesoIdeal = (62.1 * altura_m) - 44.7;
}

printf("Peso ideal: %.2f\n", pesoIdeal);

printf("Informe seu peso: \n");
scanf("%f", &pesoInformado);

if(pesoInformado <= pesoIdeal * 1.05 && pesoInformado >= pesoIdeal * 0.95){
    printf("VOCE ESTA NO PESO IDEAL!!!!!!!  ");
}else{
    printf("vc n esta no peso ideal");
}
}
