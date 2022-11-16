//Física computacional 2 (V5)- Runge-kutta de 2 ordem
#include <stdio.h>
#include <math.h>

int main(){
    FILE *file,*file2,*file3;
    char filename[100] = "crk2.dat";//runge kutta
    char filename2[100] = "ceuler.dat";//s via euler
    char filename3[100] = "csolucao.dat";//s exata

    file = fopen(filename,"w");
    file2 = fopen(filename2,"w");
    file3 = fopen(filename3,"w");

    double c,f1,f2,g,dx,x0,x,xm;
    double k1,k2;
    double f11,f22;

    x0=0.;
    dx =0.2;
    xm =10.;
    f1 = 1.;
    f11 = f1;
    c=0.1;
    for(x=x0+dx;x<=xm;x+=dx){
        //Runge Kutta
        k1=c*f1;
        k2 = c*(f1+0.5*dx*k1);
        f2 = f1+dx*k2;
        f1=f2;

        //Euler
        f22 = f11+dx*c*f11;
        f11 = f22;

        fprintf(file,"%13.8f %13.8f \n",x,f1);
        fprintf(file2,"%13.8f %13.8f \n",x,f22);
        fprintf(file3,"%13.8f %13.8f \n",x,exp(c*x));
    }

    return 0;
}