//Física computacional 1 - Atividade de avaliação !
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
# define RAND()((double)rand()/(double)(RAND_MAX))

int main(){
  int N = 300;
  int i,j;
  printf("valor: %i \n",N);
  //malha no presente
  int grade[N][N];
  //malha no futuro
  int fgrade[N][N];

  int inf0 = N/2;
  double prob,time;
  prob = 0.5;
  time = (double)N*0.1;
  printf("valor: %lf \n",time);
  
  for(i=1; i<=N;i++){
    for(j=1; i<=N; j++){
      grade[i][j] = 0;
      fgrade[i][j] = 0;
    }
  }
  //elemento infectado
  grade[inf0][inf0] = fgrade[inf0][inf0] = 1;
  printf("valor: %lf \n",fgrade[inf0][inf0]);
  for(double t = 0.; t<time;t+=0.1){
    for(i=1;i<=N;i++){
      for(j=1;j<=N;j++){
        if(grade[i][j] == 1){
          for(int k = i-1;k<=i+1;k++){
            for(int m = j-1;m<=j+1;m++){
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
    for(i=1;i<=N;i++){
      for(j=1;j<=N;j++){
        grade[i][j] = fgrade[i][j];
      }
    }
    printf("valor: %i \n",grade[N][N]);
  }
  return 0;
}