#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#define pi 3.14159
#define RAN()((double)rand()/(double)(RAND_MAX))
//Física Computacional 1 (V12) - Número aleatórios com distribuição Gaussiana
void main(){
  FILE *file;
  char filename[100] = "numerosaleatoriosGAU.dat";
  file = fopen(filename,"w");
  double r1,r2,r3,r4,r5,r6;
  srand(time(NULL));
  for(int i=0; i<200000;i++){
    r1 = RAN();
    r2 = RAN();
    r3 = sqrt(-2.*log(r1));
    r4 = cos(2.*pi*r2);
    r5 = r3*r4;
    fprintf(file,"%20.8g \n",r5);
  }
}  