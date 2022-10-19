//Física Computacional 1 - Calculando Curtose e Skewness
#include <stdio.h>
#include <math.h>

int main(){
  FILE *file;
  char filename[100];
  printf("Digite o nome do arquivo \n");
  scanf(&filename); 
  int i,N;
  N = 1000;
  double x[N];
  double m1,m2,m3,m4;
  double xm;
  double a,b;
  for (i = 1; fscanf(file,"%lf",&xm)!=EOF;i++){
    x[i] = xm;   
  }
  //calculando m1
  for(i=1;i<=N;i++){
    m1+=x[i];
  }
  m1 = m1/(double)N;
  for(i=1;i<=N;i++){
    m2+=pow(x[i]-m1,2);
    m3+=pow(x[i]-m1,3);
    m4+=pow(x[i]-m1,4);
  }
  m2 = m2/(double)N;
  m3 = m3/(double)N;
  m4 = m4/(double)N;

  a = m3/(sqrt(pow(m2,3)));
  b = m4/(pow(m2,2));
  printf("Skewness: %lf \n Courtose: %lf",a,b);
  return 0;
}