//Física Computacional 2 - (V14) - Introdução ao método de Monte Carlo (integração)
# include <stdio.h>
# include <math.h>
# include <stdlib.h>
# include <complex.h>

/*# define RAN() ((double)rand()/(double)(RAND_MAX))
# define IA 16807
# define IM 2147483647
# define AM (1.0/IM)
# define IQ 127773
# define IR 2836
# define NTAB 32
# define NDIV (1+(IM-1)/NTAB)
# define EPS 1.2e-7
# define RNMX (1.0-EPS)


int main(){

    FILE *file;
    char filname[100]="montecarlo.dat";
    file=fopen(filname,"w");

    int i,n0;
    double r1,r2,r3,r4;
    long int SEED;

    SEED = -1;
    for (n0=100000;n0<=22100000;n0+=100000){
        r4=0.;
        for (i=1;i<=n0;i++){
            r1=RAN(); // recebe a posicao x
            r2=RAN(); // recebe a posicao y
            r3=r1*r1+r2*r2; // x^2 +y^2
            r3=sqrt(r3);

            // no primeiro quadrante:
            // se r=sqrt{x^2+y^2}<1
            if (r3<1.){
               r4+=1.;
            }

        }

        r4=r4/(double)n0;
        r4=4.*r4;

        fprintf(file,"%20.8g %20.8g \n",(double)n0,r4);
    }
    return 0;
}
double ran1(long int *idum){
    int j;
    long k;
    static long iy =0;
    static long iv[NTAB];
    double temp;
    if(*idum <= 0 || !iy){
        if(- *idum <1){
            *idum = 1;
        }else{
            *idum = -*idum;
            for(j=NTAB+7;j>=0;j--){
                k=*idum/IQ;
                *idum = IA*(*idum-k*IQ)-IR*k;
                if(*idum<0){
                    *idum +=IM;
                }
                if(j<NTAB){
                    iv[j] = *idum;
                }
            }
            iy = iv[0];
        }
        k = *idum/IQ;
        *idum = IA*(*idum-k*IQ)-IR*k;
        if(*idum<0) *idum +=IM;
        j = iy/NDIV;
        iy = iv[j];
        iv[j]= *idum;
        if((temp=AM*iy)>RNMX) return RNMX;
        else return temp;
    }
}
*/
# include <stdio.h>
# include <math.h>
# include <stdlib.h>
# include <complex.h>

# define RAN() ((double)rand()/(double)(RAND_MAX))

int main(){

    FILE *file;
    char filname[100]="montecarlo.dat";
    file=fopen(filname,"w");

    int i,n0;
    double r1,r2,r3,r4;
 
    //n0 = numero do lancamento
    

    for (n0=100000;n0<=22100000;n0+=100000){
        r4=0.;
        for (i=1;i<=n0;i++){
            r1=RAN(); // recebe posiucao x
            r2=RAN(); // recebe posicao y
            r3=r1*r1+r2*r2; // x^2 +y^2
            r3=sqrt(r3);

            if (r3<1.){
               r4=r4+1.;
            }

        }

        r4=r4/(double)n0;
        r4=4.*r4;

        fprintf(file,"%20.8g %20.8g\n",(double)n0,r4);
    }
    return 0;
}