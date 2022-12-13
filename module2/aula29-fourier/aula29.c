//Física Computacional 2 (V 16) - Introdução a transformada de Fourier numérica!
# include <stdio.h>
# include <math.h>
# include <stdlib.h>
# include <complex.h>

int main(){

    FILE *file;
    char filname[100]="fourierxfreq.dat";
    file= fopen(filname,"w");

    double _Complex cc1,cc2,cc3,cc4,ic;
    double r1,r2,r3,r4,f,t,dt,df,ff,pi;

    pi=2.*asin(1.0);
    ff=2.5;
    ic= 0.+1*I;

    dt=0.01;
    df=0.1;

    for (f=0.;f<=5.;f+=df){
        cc1=0.+0.*I;

        for (t=-200.;t<=200.;t+=dt){
            r1=cos(2*pi*ff*t); //F(t)
            cc1=cc1+r1*cexp(2.*pi*f*t*ic)*dt; // Cálculo da integral
        }

        fprintf(file,"%20.8g %20.8g \n",f,cabs(cc1));
    }
    return 0;
}