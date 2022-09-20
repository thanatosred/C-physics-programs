#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
//Física computacional 1 (V11)-Introdução aos números aleatórios(em C e Fortran)
//valor inteiro gerado
void randomInt(){
  FILE *file;
  char filename[100] = "numerosAleatoriosInteiros.dat";
  file = fopen(filename,"w");
  int i,r1,r2;
  srand(time(NULL));
  for(i = 1; i<=10000;i++){
    r1=rand();
    r2 = rand()%1000000;
    fprintf(file," %i \n",r1);
  }
}
void randomReal(){
  //nao é a melhor estrategia
  FILE *file;
  char filename[100] = "numerosAleatoriosReais.dat";
  file = fopen(filename,"w");
  int i,rd;
  double r1,r2,r3;
  srand(time(NULL));
  for(i = 1; i<=10000;i++){
    rd=rand();
    r1 = (double)rd;
    r2 =(double)(RAND_MAX);
    r3 = r1/r2;
    r3 =r3-0.5;
    fprintf(file,"%20.8f \n",r3);
  }
}
void main(){
  randomInt();
  randomReal();
}