#include <stdio.h>
#include <math.h>
// Fisica Computacional - (V2)-Introdução geral (p2)
void cExponential(double a, int n){
    FILE *file;
    char filename[] = "cexponencial";
    sprintf(filename,"%s%d%s","cexponencial", n,".dat");
    file = fopen(filename,"w");

    double y,t,dt,C;
    C = 1.;
    dt = 0.1;

    for (t = 0; t < 20.; t = t+dt){
        y = C*(1.-exp(-a*t));
        fprintf(file,"%13.8f %13.8f\n",t,y);
    }
}
void cParabola(){
    FILE *file;
    char filename[] = "cparabola.dat";
    file = fopen(filename,"w");

    double y,x,a,b,c,dx;
    a = 1.;
    b =0.1;
    c = -1.;
    dx = 0.2;

    for (x = -2.0;x<=2.0;x=x+dx){
        y = a*(x*x)+b*x+c;
        fprintf(file,"%13.8f %13.8f\n",x,y);
    }
    
}
void main(){
    cExponential(0.5,1);
    cExponential(0.1,2);
    cParabola();
}