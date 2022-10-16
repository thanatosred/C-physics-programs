# include <stdio.h>
# include <math.h>
# include <stdlib.h>
# include <complex.h>
# define RAND()((double)rand()/(double)(RAND_MAX))
//Física Computacional 1 (V15) - Interpolação linear e quadrática
/*Algoritmo para criar uma curva que interpole os pontos*/
/*int criarTabela(int N){
    FILE *tab;
    char filename[100] = "tabela.dat";
    tab = fopen(filename,"w");
    double y;
    for(int i = 1; i<=N; i++){
        y = (double)i+pow(-1,i)*RAND();
        fprintf("%i %lf \n",2*i,y);
    }
    return 0;
}*/
int main(){
    FILE *file,*file2;
    char filename[100] = "tabela.dat";
    char filename2[100] = "interpolin.dat";
    file = fopen(filename,"w");
    file2 = fopen(filename2,"w");
    double x [1000],y[1000];
    double r1,r2,r3,b0,b1,b2;
    double A0,A1,A2,A3;
    double xx,fxx;
    int i;

    x[1] = 1.;
    x[2] = 2.;
    x[3] = 3.;
    
    y[1] = 0.95;
    y[2] = 3.4;
    y[3] = 8.;

    for(i = 1; i<=3; i++){
        fprintf(file,"%lf %lf \n",x[i],y[i]);
    }
    b0= y[1];
    b1 = (y[2]-y[1])/(x[2]-x[1]);
    r1 = (y[3]-y[2])/(x[3]-x[2]);
    r2 = (y[2]-y[1])/(x[2]-x[1]);
    r3 = (r1-r2)/(x[3]-x[1]);

    b2 = r3;
    A0  = b0-b1*x[1]+b2*x[1]*x[2];
    A1 = b1-b2*x[1]-b2*x[2];
    A2 = b2;

    for (xx = 0.5;xx<=3.5;xx+=0.1){
        fxx = A0+A1*xx+A2*xx*xx;
        fprintf(file2,"%20.8f %20.8f \n",xx,fxx);

    }
    return 0;
}
