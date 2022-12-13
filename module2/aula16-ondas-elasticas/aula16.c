//Física Computacional 2 (V12) - Solução numérica da equação de ondas elásticas 1d .

# include <stdio.h>
# include <math.h>
# include <stdlib.h>
# include <complex.h>

int main(){

    FILE *file;
    char filename[100]="equacaodeonda.dat";
    file=fopen(filename,"w");

    int N,i,j;
    double phipresente[10000],phipassado[10000],phifuturo[10000];
    double t,dt,A,ww;

    N=200;


    for (i=0;i<=(N);i++){
        phipresente[i]=phipassado[i]=phifuturo[i];
    }

    // inicial phi(x=0,t)=Acos(wt)

    dt=0.001; 
    A=0.1;    // amplitude
    ww=1.;    // frequencia
    phipresente[0]=A;
    phipassado[0]=A;

    for (t=(dt);t<=150.;t+=dt){
        for (i=0;i<=(N);i++){
            phifuturo[i]=2.*phipresente[i]-phipassado[i]+(dt*dt)*(phipresente[i+1]-2.*phipresente[i]+phipresente[i-1]);
        }

        // atualizando condicoes
        for (i=0;i<=(N);i++){
            phipassado[i]=phipresente[i];
            phipresente[i]=phifuturo[i];
        }

        phipassado[0]=phipresente[0];
        phipresente[0]=A*cos(ww*t);

        j++;
        if (j>10){
            fprintf(file,"%20.8g %20.8g \n",t,phifuturo[50]);

            j=0.;
        }
    }   
    return 0;
}