#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
//Física Computacional 1 (V17)- Desordem correlacionada e o cálculo da função de autocorrelação C(r)
#define IA 16807
#define IM 2147483647
#define AM (1.0/IM)
#define IQ 127773
#define IR 2836
#define NTAB 32
#define NDIV (1+(IM-1)/NTAB)
#define EPS 1.2e-7
#define RNMX (1.0-EPS)
#define pi M_PI
#define N5 200000
#define RAND()((double)rand()/(double)RAND_MAX)

double xx[N5];//E_n
double yy[N5];// numeros aleatorios

int gerador(double zeta){
    FILE *file,*file2;
    int i,j,NR,cr;
    double r1,r2,r3,r4,r5,r6,m1,m2;
    char filename[150],filename2[150];
    long int SEED;

    NR = 15000;

    sprintf(filename,"numerosaleatoriosN%izeta%1.1lf.dat",NR,zeta);
    sprintf(filename2,"autocorrelacaoN%izeta%1.1lf.dat",NR,zeta);
    
    file = fopen(filename,"w");
    file2 = fopen(filename2,"w");

    SEED = -1;

    for(i=1;i<=NR;i++){
        yy[i] = (RAND()-0.5);
    }
    printf("Eta_m gerados \n");

    m1=m2=0.;
    for(i=1;i<=NR;i++){
        xx[i] =0.;
        for(j=1;j<=NR;j++){
            r1 = fabs((double)(i-j));
            r1 =r1/zeta;
            r1 = exp(-r1);
            xx[i] = xx[i]+yy[j]*r1;
        }
        m1+=xx[i];
        m2+=xx[i]*xx[i];
    }
    m1=m1/(double)NR;
    m2 = m2/(double)NR;
    printf("Valores calculados: \n  E_n: %20.8g \n (E_n)^2: %20.8g \n",m1,m2);

    for(i=1;i<=NR;i++){
        xx[i] = (xx[i]-m1)/sqrt(m2-(m1*m1));//epsilon
        fprintf(file,"%20.8g \n",xx[i]);
    }
    printf(" Calculos dos epsilon\n");

    //calculo do C(r)
    for(cr =0;cr<=50;cr++){
        r1 =0.;
        r2 =0.;
        for(i=1;i<=(NR-cr);i++){
            r1+=xx[i]*xx[i+cr];
        }
        for(i=1;i<=(NR);i++){
            r2+=xx[i];
        }
        r1= r1/(double)(NR-cr);
        r2 = r2/(double)(NR);
        fprintf(file2,"%20.8g %20.8g \n",(double)cr,r1-(r2*r2));
    }
    return 0;
}
int main(){
    for(double i = 2.; i<=16.;i=i*2){
        gerador(i);
        printf("zeta: %lf",i);
    }
    return 0;
}