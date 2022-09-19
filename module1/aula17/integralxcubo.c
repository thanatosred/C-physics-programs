#include <stdio.h>
#include <math.h>
//Mais algumas informações sobre integração
void main(){
  double x,dx,r1,r2;
  double y =0.;
  dx = 0.005;
  for(x = -1.;x <=1.;x+=dx){
    y += (pow(x,3)+pow(x+dx,3))*dx*0.5;
  }
  printf("Integral po trapézio: %13.8le \n Integral esperada: %13.8f \n",y,0.);
}