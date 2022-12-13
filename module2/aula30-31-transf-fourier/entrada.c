////Física Computacional 2 (V17) Transformada de Fourier no problema de um elétron em um campo elétrico

# include <stdio.h>
# include <math.h>
# include <stdlib.h>
# include <complex.h>

int main(){

    FILE *file,*file2;
    char filename[100]="2niveisrk4.dat";//rk2
    char filename1[100]="saida.dat";
    file=fopen(filename,"r");
    file2=fopen(filename1,"w");
    
    double r1,r2,r3,r4,f,df;
    double _Complex cc1,cc2,ic;
    double x[300000],y[300000];
    int i,j,N,i10,i20;

    ic = 0. + I;
    i = 1;

    while ((fscanf(file, "%lf %lf %lf %lf\n", &x[i], &y[i], &r1, &r2)) != EOF){

        i ++;
    }
    i++;
    N = i;

    df = 0.025;
    for (f = 0.05; f <= 2.0; f +=df){
        cc1 = 0. + I * 0.;
        for (i = 1; i <= N; i ++){
            cc1 += y[i] * cexp(-ic * x[i] * f);
        }
        r1 = cabs(cc1);
        fprintf(file2, "%20.8lf %20.8lf \n", f, r1);
    }
    return 0;
}