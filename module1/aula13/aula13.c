#include <stdio.h>
#include <math.h>
//Física Computacional 1 (V8) - Integração numérica!
void integrais(double dx){

double I1,I2,I3,I4,r1,r2,r3;
I1 =0.;
I2 =0.;
I3 = 0.;
for(double x=0.;x<1.;x=x+dx){
    //retangulo
    r1 = dx*(exp((x+x+dx)/2.));
    I1+=r1;
    //trapezio
    r2 = ((exp(x)+exp(x+dx))/2.)*dx;
    I2+=r2;
    //Simpson
    r3 =(exp(x)+4.*(exp((x+x+dx)*0.5))+exp(x+dx))*dx/6.;
    I3+=r3;
}
I4 = exp(1.)-1.;
printf("I1:%13.8f I2:%13.8f I3:%13.8f I4:%13.8f\n",I1,I2,I3,I4);
}
void main(){
//integrais();
integrais(0.05);
integrais(0.01);
integrais(0.005);
}