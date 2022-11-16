//Física Computacional 2 (V6)-Método de Runge-Kutta 2 Ordem (Aplicação ao Modelo SIR)
#include <stdio.h>
#include <math.h>

int main(){
    FILE *file,*file2;

    char filename[100] = "crk2SIRINF.dat";//runge kutta 2
    char filename2[100] = "crk2SIRREC.dat";

    file = fopen(filename,"w");
    file2 = fopen(filename2,"w");

    double S0,I0,R0,S,I,R;
    double K1S,k2S,k1I,k2I,K1R,k2R;
    double beta, gama;
    double N0,NT;
    double t,dt;

    dt = 0.01;
    N0=100.; // inical de infectados
    NT = 2e+8; // populacao total
    I0 = N0/NT; // fracao de infectados
    R0 = I0; // pessoas recuperadas, sua hipotese
    S0 = 1.-2.*I0;
    gama = 1./12.;//inverso do numero de dias q uma pessoa leva para se recuperar
    beta = 0.25; // coeficiente de propagacao
    for (t=dt;t<=100.;t+=dt){
        //k1
        K1S = -beta*I0*S0;
        K1R = gama*I0;
        k1I = -1.*K1S - K1R;

        //k2
        k2S = -beta*(I0+dt*0.5*k1I)*(S0+dt*0.5*K1S);
        k2R = gama*(I0+dt*0.5*k1I);
        k2I = -1.*k2S-k2R;
       
       //o futuro
       S = S0+dt*k2S;
       I = I0+dt*k2I;
       R = R0 + dt*k2R;
       I0 = I;
       S0 = S;
       R0 = R;

       fprintf(file,"%13.8f %13.8f %13.8f \n",t,I*100.,I+R+S);//fracao de infectados
       fprintf(file2,"%13.8f %13.8f %13.8f \n",t,R*100.,I+R+S); // fracao de recuperados
    }
    return 0;
}