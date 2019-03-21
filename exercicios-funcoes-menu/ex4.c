#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float horaParaFloat(int horas, int minutos, int segundos);
void floatParaHora(float horaFracionada);

int main()
{
  int horas, minutos, segundos;
  printf("\n Digite uma hora no formato hh:mm:ss \n");
  scanf("%d:%d:%d", &horas, &minutos, &segundos);
  float horaFloat = horaParaFloat(horas, minutos, segundos);
  printf("\n Hora para float: %f", horaFloat);
  floatParaHora(horaFloat);
}

float horaParaFloat(int horas, int minutos, int segundos){
    return horas + minutos/60.0 + segundos/3600.0;
}

void floatParaHora(float horaFracionada){
int horas, minutos,segundos;

horas = horaFracionada / 1;
minutos = ((horaFracionada - horas) * 60.0);
segundos = ((((horaFracionada - horas) * 60) - minutos) * 60);

printf("\n Hora: %d:%d:%d", horas, minutos, segundos);

}
