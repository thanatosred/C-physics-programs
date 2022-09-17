#include <stdio.h>
#include <math.h>

//Física Computacional 1 (V6)-Derivada numérica
void main(){
    double f0,f1,f2,h,x;
    double d1,d2,d3;
    x =2.;
    h = 0.1;
    f2 = log(x+h);
    f1 = log(x);
    f0 = log(x-h);
    d1 = (f2-f0)/(2.*h);
    d2 = (f2-f1)/h;
    d3 = 1./x;
    printf("D1: %13.8f D2: %13.8f D3: %13.8f\n",d1,d2,d3);
    printf("fabs1: %13.8f fabs2: %13.8f\n",fabs(d1-d3),fabs(d2-d3));
}