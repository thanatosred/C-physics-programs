#include <stdio.h>
#include <math.h>
//Física Computacional 1 (V4)- Introdução geral (p4)

int main(){

    FILE *file;
    char filename[100] = "mapaLogistico.dat";
    file = fopen(filename,"w");

    double x2,x1,x0,r;
    int n;
    
    for (r=2.75;r<=3.99;r=r+0.001){
        for(x0 = 0.01; x0<=0.99;x0 =x0+0.02){
            x1=x0;
            for(n=1.;n<=10000;n=n+1){
                x2 = r*x1*(1.-x1);
                x1 =x2;
            }
            fprintf(file,"%13.8f %13.8f\n",r,x1);
        }
    }
    return 0;
}