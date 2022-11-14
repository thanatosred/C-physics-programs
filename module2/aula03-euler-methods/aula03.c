//Método de Euler Modificado
#include <stdio.h>
#include <math.h>

int main(){
    FILE *file,*file2,*file3;
    char filename[100] = "caproximado1ordem.dat";
    char filename2[100] = "caproximado2ordem.dat";
    char filename3[100] = "caproximado3ordem.dat";
    file = fopen(filename,"w");
    file2 = fopen(filename2,"w");
    file3 = fopen(filename3,"w");
    double f0,f1,f2,g0,g1,dx,x0,x,xm,c;
    
    x = 0.;
    x0 = 0.;
    dx = 0.1;
    xm = 120.;
    f0 = 1.;
    c = 0.2;

    for(x = x0+dx; x<=xm; x+=dx){
        //1ºa ordem
        g0 = c*f0;
        f1 = f0+dx*g0;
        fprintf(file,"%13.8f %13.8f \n",x,f1);

        //2ºa ordem
        g1 = c*f1;
        f2 = f0+0.5*dx*(g0+g1);
        fprintf(file2,"%13.8f %13.8f \n",x,f2);

        f0=f2;

        //solucao exata
        fprintf(file3,"%13.8f %13.8f \n",x,exp(c*x));

    }
    return 0;
}