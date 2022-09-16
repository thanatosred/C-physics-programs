#include <stdio.h>
#include <math.h>
// Fisica Computacional - (V2)-Introdução geral (p2)
void main(){

    FILE *file;
    char filename[] = "cexponencial.dat";
    file = fopen(filename,"w");

    double y,t,dt,C,A;
    C = 1.;
    A =0.5;
    dt = 0.1;

    for (t = 0; t < 20.; t = t+dt)
    {
        y = C*(1.-exp(-A*t))
    }
      
}