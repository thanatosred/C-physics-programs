//Física computacional 2- método de Newton-Raphson (Parte 1)
# include <stdio.h>
# include <math.h>
# include <stdlib.h>

int main(){

    FILE *file;
    char filname[100]="Newton.dat";
    file= fopen(filname,"w");

    int k,i,j,n0;
    double f1,f2,x1,x2,x3,x4;

    x1=5.;  
    x3=1.;

    while(x3>1e-8){
        f1=pow(x1,2.)-100.;//f(x_1)
        f2=2.*pow(x1,1.);//f'(x_1)

        x2=x1-f1/f2;//x2=x1-f(x_1)/f'(x_1)
        x3=fabs(x2-x1);//|x_2-x_1|
        x1=x2;


        fprintf(file,"%s %20.11g \n","raiz",x1);
    }
    f1=pow(x1,2.)-100.;

    fprintf(file,"%s %20.11g \n","precisoo=",f1);

    return 0;
}