#include <stdio.h>
#include <math.h>
//Integração numérica de X^2
int main(){
  //metodo do retangulo
  double x,y,dx;
  //integra x^2 de 0 a 1
  dx = 0.001;
  y = 0.;
  for(x = 0; x<=1.;x+=dx){
    y+= (x*x)*dx;
  }
  printf("Solucao numerica: %13.8f \n Solucao exata: %13.8f \n",y,1./3.);
  return 0;
}