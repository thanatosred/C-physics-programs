//Física computacional 2 (V4)- usando "diferença finita" para resolver numericamente E. diferenciais
#include <stdio.h>
#include <math.h>

int main(){
    FILE *file;
    

    char filename[100] = "cposicao2.dat";
    file = fopen(filename,"w");

    double x0,m,k,dt,t,tm,t0;
    double x2,x1;

    t0 = 0.;
    x0=0.1;
    x1=0.1;
    dt=0.1;
    tm=20.0;
    k=1.;
    m=1.;

    for(t=t0+dt;t<=tm;t+=dt){
        x2 = 2.*x1-x0-dt*(k/m)*x1;
        x0=x1;
        x1=x2;

        fprintf(file,"%13.8f %13.8f \n",t,x1);
    }
    return 0;
}