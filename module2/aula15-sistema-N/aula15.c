//Física computacional 2 (V11) - Sistema com "N" níveis (aplicação de RK4)

# include <stdio.h>
# include <math.h>
# include <stdlib.h>
# include <complex.h>

int main(){

    FILE *file;

    char filename[100]="NniveisRK4.dat";
    file=fopen(filename,"w");

    double r1,r2,r3,r4,eg,ef;
    double t,dt,tt,nm,n2m,m2;

    double en[2000];
    double _Complex cc1,cc2,cc3,cn[2000];
    double _Complex ic,k1[2000],k2[2000],k3[2000],k4[2000];

    int i,j,N;

    N=500;

    
    for (i=1;i<=N;i++){
        cn[i]=0.+0.*I;
        en[i]=0.;     //termo do "potencial de ionização"
    }

    ic=0.-1.*I;
    tt=1.;

    dt=0.01;

    //inicial
    cn[N/2]=1.+0.*I;

    // RK

    for (t=dt;t<=100;t+=dt){
       // K1
       for (i=1;i<=N;i++){
           k1[i]=dt*ic*(en[i]*cn[i]+tt*(cn[i+1]+cn[i-1]));
       }

       // K2
       for (i=1;i<=N;i++){
           cc1=cn[i]+0.5*k1[i];
           cc2=cn[i+1]+0.5*k1[i+1];
           cc3=cn[i-1]+0.5*k1[i-1];

           k2[i]=dt*ic*(en[i]*cc1+tt*(cc2+cc3));
       }

       // K3
       for (i=1;i<=N;i++){
           cc1=cn[i]+0.5*k2[i];
           cc2=cn[i+1]+0.5*k2[i+1];
           cc3=cn[i-1]+0.5*k2[i-1];

           k3[i]=dt*ic*(en[i]*cc1+tt*(cc2+cc3));
       }

       // K4
       for (i=1;i<=N;i++){
           cc1=cn[i]+k3[i];
           cc2=cn[i+1]+k3[i+1];
           cc3=cn[i-1]+k3[i-1];

           k4[i]=dt*ic*(en[i]*cc1+tt*(cc2+cc3));
       }

       r1=0.;
       for (i=1;i<=N;i++){
           cn[i]=cn[i]+(1./6.)*(k1[i]+2.*k2[i]+2.*k3[i]+k4[i]);
           r1=r1+pow(cabs(cn[i]),2.); // soma sum_n |c_n|^2
       }

       nm=n2m=m2=0.;
       for (i=1;i<=N;i++){
           nm=nm+((double)i)*(pow(cabs(cn[i]),2.)); // posicao media

           n2m=n2m+((double)i)*((double)i)*(pow(cabs(cn[i]),2.));
       }

       m2=n2m-nm*nm;
       fprintf(file,"%20.8g %20.8g %20.8g \n",t,m2,fabs(1.-r1));
    }
    return 0;
}