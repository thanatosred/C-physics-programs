#include <stdio.h>
#include <math.h>

void derivadaExe01(){
//Física Computacional 1 (V6)-Derivada numérica
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
void derivadaExe02(double h){
//Física Computacional 1 (V7)-Derivada numérica (continuação).
double f0,f1,f2,x;
double d1,d2,d3;

x=2.;
f2 = log(x+2.*h);
f1 =log(x+h);
f0 = log(x);
d1 =(-3.*f0+4.*f1-f2)/(2.*h);

f2 = log(x-2.*h);
f1=log(x-h);
f0 = log(x);
d2 = (f2-4.*f1+3*f0)/(2.*h);
d3 = 1./x;

printf("for h: %lf \n d1: %13.8f d2: %13.8f d3: %13.8f\n",h,d1,d2,d3);
printf("fabs1: %13.8f fabs2: %13.8f\n",fabs(d1-d3),fabs(d2-d3));
}
void main(){
    //derivadaExe01();
    derivadaExe02(0.1);
    derivadaExe02(0.05);
    derivadaExe02(0.005);

}