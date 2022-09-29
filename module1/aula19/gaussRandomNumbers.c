#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#define pi M_PI
#define RAN()((double)rand()/(double)(RAND_MAX))
//Física Computacional 1 (V12) - Número aleatórios com distribuição Gaussiana
void main(){
  FILE *file;
  char filename[100] = "numerosaleatoriosGAU.dat";
  file = fopen(filename,"w");
  double r1,r2,r3,r4,r5,r6;
  srand(time(NULL));
  //gerei o gráfico com 20000 loops pois o meu grace estava travando
  for(int i=1; i<=200000;i++){
    r1 = RAN();
    r2 = RAN();
    r3 = sqrt(-2.*log(r1));
    r4 = cos(2.*pi*r2);
    r5 = r3*r4;
    fprintf(file,"%20.8g \n",r5);
  }
}  