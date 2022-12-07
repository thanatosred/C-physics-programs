//Física Computacional 2 - (V10)- RK4 aplicado na cadeia massa mola!
# include <stdio.h>
# include <stdlib.h>
#include <time.h>
# include <math.h>
# include <complex.h>
# define RAN() ((double) rand()/(double)(RAND_MAX))

int main(){

    FILE *file, *file2;
    char filename[100] = "rk4cadeiamassamola.dat";    
    char filename2[100] = "rk4cadeiamassamola3d.dat"; 

    file = fopen(filename, "w");
    file2 = fopen(filename2, "w");

    int N, i, j;

    double r1, r2, r3, r4;

    double m[10000], kmola[10000];
    double x[10000], v[10000];
    double k1x[10000], k1v[10000];
    double k2x[10000], k2v[10000];
    double k3x[10000], k3v[10000];
    double k4x[10000], k4v[10000];

    double E0, ET;
    double t, dt;
    srand(time(NULL));

    N = 100; //sistema de 100 pontos

//zerar e iniciar vetores
    for (i = 0; i <= N; i +=1) {
        x[i] = v[i] = 0.;
        m[i] = 1. +2.*RAN();
        kmola[i] = 1.;
    }

    // condicao inicial
    x[N / 2] = 1.;

    E0 = 0.;

    for (i = 1; i <= N; i +=1){
        r1 = pow(x[i] - x[i + 1], 2.); // x_i-x_f(i+1)^2

        E0 += 0.5*m[i]*pow(v[i], 2.) + 0.5*kmola[i]*(r1);
    }

    dt = 0.05;
    for (t = dt; t <= 100.; t +=dt){ 

        // k1rk4
        for (i = 1; i <= N; i +=1){
            k1x[i] = dt * v[i];
            k1v[i] = dt * (1. / m[i])*(kmola[i]*x[i + 1] + kmola[i - 1]*x[i - 1] - (kmola[i] + kmola[i - 1])*x[i]);
        }
        // k2rk4
        for (i = 1; i <= N; i +=1){
            k2x[i] = dt * (v[i] + 0.5*k1v[i]);

            r1 = x[i + 1] + 0.5*k1x[i + 1];
            r2 = x[i - 1] + 0.5*k2x[i - 1];
            r3 = x[i] + 0.5*k2x[i];

            k3v[i] = dt*(1. / m[i])*(kmola[i]*r1 + kmola[i - 1]*r2 - (kmola[i] + kmola[i - 1])*r3);
        }
        //k3rk4
        for (i = 1; i <= N; i +=1){
            k4x[i] = dt * (v[i] + k3v[i]);

            r1 = x[i + 1] + k3x[i + 1];
            r2 = x[i - 1] + k3x[i - 1];
            r3 = x[i] + k3x[i];

            k4v[i] = dt*(1. / m[i])*(kmola[i]*r1 + kmola[i - 1]*r2 - (kmola[i] + kmola[i - 1])*r3);
        }
        
        for (i = 1; i <= N; i +=1){

            x[i] += (1./6.)*(k1x[i] + 2.*k2x[i] + 2.*k3x[i] + k4x[i]);

            v[i] += (1./6.)*(k1v[i] + 2.*k2v[i] + 2.*k3v[i] + k4v[i]);
        }
        // fim do rk4
        ET = 0.;
        j +=1;
        if (j > 10){ 
            for (i = 1; i <= N; i +=1){
                r1 = pow(x[i] - x[i + 1], 2.);
                r2 = 0.5*m[i]*pow(v[i], 2.) + 0.5*kmola[i]*(r1);
                ET+= r2;

                fprintf(file2, "%20.8g %20.8g %20.8g \n", t, (double)i, r2); // solução numérica rk2

            } // calcular energia e(t)
            j = 0;
            fprintf(file, "%20.8g %20.8g \n", t, fabs(1. - E0 / ET));

        } 
    } 

    return 0;
}