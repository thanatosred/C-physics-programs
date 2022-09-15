#include <stdio.h>
#include <math.h>
// Integração numérica de uma tabela de dados
void criarGauss(){
  FILE *file;
  char filename[] = "dados.dat";
  file = fopen(filename,"w");
  double x,y,dx;
  dx = 0.01;
  for(x = -3.; x < 3.;x+=dx){
    y = exp(-x*x);
    fprintf(file,"%13.8f %13.8f \n",x,y);
  }
}
void integral(){
  FILE *file1,*file2;
  char filename1[] = "integralNUM.dat";
  char filename2[] = "dados.dat";
  file1 = fopen(filename1,"w");
  file2 = fopen(filename2,"r");

  double h,I1,x[1000],y[1000];
  int i,j;
  for(i=0; fscanf(file2,"%lf %lf ",&x[i],&y[i])!=EOF;i++){
  }
  h = x[1]-x[0];
  I1 = 0.;
  for(j =0; j<(i-1);j++){
    //integração do trapézio
    I1+= (y[j+1]+y[j])*h*0.5;
  }
  fclose(file2);
  printf("O resultado da integral eh: %13.8f \n",I1);
}
void main(){
  criarGauss();
  integral();
}