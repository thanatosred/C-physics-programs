# include <stdio.h>
# include <math.h>
# include <stdlib.h>
# include <complex.h>
# define RAND()((double)rand()/(double)(RAND_MAX))
# define NN 30000

//Computacional (1 e 2)- Números aleatórios com correlações de Longo Alcance

int main(){
    FILE *file;
    char filename[100] = "numerosaleatoriosocorre.dat";
    file = fopen(filename, "w");

    int i, k, N;
    double m1, m2, NR, pi, alpha, ir, kr;
    double r1, r2;
    double epsi[NN + 1], phi[NN + 1];

    N = 10000;
    NR = (double)N;

    pi = 2.*asin(1.);

    alpha = 3.;

    for (i = 1; i <= N; i++){
        phi[i] = 2.*pi*RAND();
    }
    printf("E_n's calculados");

    for (i = 1; i <= N; i++){
        ir = (double)i;
        epsi[i] = 0.;

        for (k = 1; k <= (N/2); k++){
            kr = (double)k;
            r1 = pow(kr, alpha*0.5);
            r1 = 1./r1;
            r2 = cos(2.*pi*ir*kr/(NR+phi[k]));
            epsi[i] += r1*r2;
        }
      
        m1 += epsi[i];
        m2 += epsi[i]*epsi[i];
    }
    m1 = m1/(double)NR;
    m2 = m2/(double)NR;
    printf("Valores médios calculados: \n m1: %lf \n m2:  %lf \n",m1,m2);
    
    for (i = 1; i <= NR; i++){
        epsi[i] = (epsi[i]-m1)/sqrt(m2-(m1*m1));

        fprintf(file, "%20.8g \n", epsi[i]);
    }
    printf("Valores normalizados \n");
    return 0;
}