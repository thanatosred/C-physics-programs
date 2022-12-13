//Física computacional 2 - Método de Newton-Raphson (Parte 2)

# include <stdio.h>
# include <math.h>
# include <stdlib.h>

int main(){

    FILE *file;
    char filname[100]="Newton.txt";
    file= fopen(filname,"w");

    double f1,f2,x1,x2,x3,x4;

    x1=2.;
    x3=1.;

    while(x3>1e-8){
        f1=pow(x1,5.)-3.*pow(x1,3.)-2*x1+1;;//f(x_1)
        f2=5.*pow(x1,4.)-9.*pow(x1,2)-2.;//f'(x_1)

        x2=x1-f1/f2;//x2=x1-f(x_1)/f'(x_1)
        x3=fabs(x2-x1);//|x_2-x_1|
        x1=x2;


        fprintf(file,"%s %20.11g \n","raiz",x1);
    }
    f1=pow(x1,2.)-100.;

    fprintf(file,"%s %20.11g\n","precisao=",f1);

    return 0;
}