//Física Computacional 2 (V17) Transformada de Fourier no problema de um elétron em um campo elétrico

# include <stdio.h>
# include <math.h>
# include <stdlib.h>
# include <complex.h>

int main(){

    FILE *file,*file2;
    char filename1[100]="Niveisk4v2campoeletrico.dat";
    file2= fopen(filename1,"w");

    double r1,r2,r3,r4;
    double _Complex cn[2000],cc1,cc2,cc3;
    double _Complex ic,k1[2000],k2[2000],k3[2000],k4[2000];
    double en[2000],eg,ef;
    double t,dt,tt,FT;
    double nm,n2m,m2;
    int i,j,N,i10,i20;

    N=500;


    // equacoes "sistema de dois niveis"
    FT=1.;

    // dg/dt=(1/i)*(eg*g+tt*f)

    for (i=1;i<=N;i+=1){
        cn[i]=0.+0.*I;
        en[i]=0.;
    }
    ic=0.-1.*I;    //(1/i)=-i

    tt=1;
    dt=0.008;
    i20=(int)(0.025/dt);
    i20=0;

    //inicial
    cn[N/2]=1./sqrt(2.)+0.*I;
    cn[N/2+1]=1./sqrt(2.)+0.*I;

    //|f1|^2+|g1|^2=1 (Para todos os tempos)

    for(t=(dt);t<=300.;t+=1){
        //k1
        for(i=1;i<=N;i=i+1){
            r1=en[i]+FT*(double)(i-N/2);
            k1[i]=dt*ic*(r1*cn[i]+tt*(cn[i+1]+cn[i-1]));
        }
    //k2
        for(i=1;i<=N;i+=1){
            cc1=cn[i]+0.5*k1[i];
            cc2=cn[i+1]+0.5*k1[i+1];
            cc3=cn[i-1]+0.5*k1[i-1];
            r1=en[i]+FT*(double)(i-N/2);
            k2[i]=dt*ic*(r1*cc1*tt*(cc2+cc3));
        }
        //kk3
        for(i=1;i<=N;i+=1){
            cc1=cn[i]+0.5*k2[i];
            cc2=cn[i+1]+0.5*k2[i+1];
            cc3=cn[i-1]+0.5*k2[i-1];
            r1=en[i]+FT*(double)(i-N/2);
            k3[i]=dt*ic*(r1*cc1+tt*(cc2+cc3));
        }
        m2=n2m-nm*nm;


        fprintf(file2,"%20.8g %20.8g %20.8g %20.8g\n",t,nm,nm,fabs(1.-r1));
        i10=0;
    }


    return 0;
}