//Método de Euler Continuação
#include <stdio.h>
#include <math.h>
int main(){
    FILE *file1,*file2;
    char filename[100] = "cposicao1.dat";
    char filename2[100] = "cvelocidade1.dat";
    file1 = fopen(filename,"w");
    file2 = fopen(filename2,"w");

    double v2,v1,m,k,dt,t,tm,t0;
    double x2,x1,x0;

    t0 = 0.;
    x0 = 0.1;
    x1 = x0;
    dt = 0.005; //determina a convergencia da curva
    tm = 20.;
    v1 = 0.;
    k = 1.;
    m = 1.;

    for(t=(t0+dt); t<=tm; t+=dt){
        v2 = v1-dt*(k/m)*x1;
        x2 = x1+dt*v1;

        v1=v2;
        x1=x2;

        fprintf(file1,"%13.8f %13.8f \n",t,x1); //Solucao Numerica
        fprintf(file2,"%13.8f %13.8f \n",t,v1);
    }
    return 0;
}