//Método de Euler
#include <stdio.h>
#include <math.h>

int main(){
  FILE *file,*file2;
  char filename[100] = "cteste.dat";
  char filename2[100] = "cteste4.dat";
  file = fopen(filename, "w");
  file2 = fopen(filename2,"w");

  double f1,f2,g,dx,x0,x,xm;
  x0 =0.;
  dx = 0.01;
  xm = 10.;
  f1 = 1.;
  for(x=x0+dx;x<=xm;x+=dx){
    g = exp(x-dx);
    f2 = f1+dx*g;
    f1 = f2;
    fprintf(file, "%13.8f %13.8f \n",x,f1);
    fprintf(file2,"%13.8f %13.8f \n",x,exp(x));
  }
  return 0;
}