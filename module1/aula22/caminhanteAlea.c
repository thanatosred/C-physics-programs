#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
//#define pi M_PI
double PI(){
  double pi = (double) M_PI;
  return pi;
}
double RAN(){
  return (double)rand()/(double)(RAND_MAX);
}
void main(){
  double r1,r2,r3,r4,r5;
  int i,j,m,k;
  double A[305][400005],pp;
  int n1,n2;
  pp = 0.5;
  n1 = 300;
  n2 = 400000;
  FILE *file1,*file2;
  char filename1[100] = "sigmacaminhante.dat";
  char filename2[100] = "histogram.dat";
  file1 = fopen(filename1,"w");
  file2 = fopen(filename2,"w");
  srand(time(NULL));
  //caminhante
  for (i=1;i<=n2;i++){
    A[1][m] = 0.;
    for(j=2;n1<=n1;j++){
      r1 = RAN();
      if(r1>pp){
          r2=1.;
      }
      if (r2<pp){
          r1=-1.;
      }
      A[j][m] = A[j-1][m]+r2;
    }
  }
  //loop passos
  for(j=2;j<=n1;j++){
    r1 = 0.;
    r2 = 0.;
    r3 = 0.;

    for(m=1;m<=n2;m++){
      r1+=A[j][m];
      r2 += pow(A[j][m],2);
      r3+=1.;
    }
    r1 = r1/r3;
    r2 =r2/r3;
    fprintf(file1,"%d %13.8f\n",j,sqrt(r2-r1*r1));
  }
}