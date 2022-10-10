#include <stdio.h>
#include <math.h>
// V10 -Integração numérica de uma tabela de dados
int criarGauss(){
  FILE *file;
  char filename[] = "dados.dat";
  file = fopen(filename,"w");
  double x,y,dx;
  dx = 0.01;
  for(x = -3.; x < 3.;x+=dx){
    y = exp(-x*x);
    fprintf(file,"%13.8f %13.8f \n",x,y);
  }
  return 0;
}
int integral(){
  FILE *file2,*file3;
  char filename2[100] = "dados.dat";
  char filename3[100] = "dadosNormalizados.dat";

  file2 = fopen(filename2,"r");
  file3 = fopen(filename3,"w");

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
  //probabilidade
  for (j = 0; j<i;j++){
    y[j] = y[j]/I1;
    fprintf(file3,"%20.8f %20.8f \n",x[j],y[j]);
  }
  return 0;
}
int main(){
  criarGauss();
  integral();
  return 0;
}