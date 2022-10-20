//Física computacional 1 - Atividade de avaliação !
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
# define RAND()((double)rand()/(double)(RAND_MAX))

int main(){
  FILE *file;
  char filename[100] = "grate.dat";
  file = fopen(filename,"w"); 
  int N = 300;
  int i,j;
  printf("valor: %i \n",N);
  //malha no presente
  int grade[N][N];
  //malha no futuro
  int fgrade[N][N];

  int inf0 = N/2;
  double prob;
  int time;
  prob = 0.5;
  time = N;
  printf("valor: %i \n",time);
  
  for(i=1; i<N;i++){
    for(j=1; i<N; j++){
      grade[i][j] = 0;
      fgrade[i][j] = 0;
    }
  }
  //elemento infectado
  grade[inf0][inf0] = fgrade[inf0][inf0] = 1;
  printf("valor: %i \n",fgrade[inf0][inf0]);
  for(int t = 0; t<time;t++){
    for(i=1;i<N;i++){
      for(j=1;j<N;j++){
        if(grade[i][j] == 1){
          for(int k = i-1;k<i+1;k++){
            for(int m = j-1;m<j+1;m++){
              if(RAND()>prob){
                if(grade[k][m]!=1 && j!=N && i!=N){
                  fgrade[k][m] = 1;
                }
              }
            }
          }
        }
      }
    }
    //substituindo a grade
    for(i=1;i<N;i++){
      for(j=1;j<N;j++){       
        grade[i][j] = fgrade[i][j];
        fprintf(file,"%i \n",grade[i][j]);
      }
    }
  }
  return 0;
}