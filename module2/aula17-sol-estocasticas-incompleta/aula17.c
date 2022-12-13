//Física Computacional 2 (V13)- Solução numérica de Equações estocásticas
# include <stdio.h>
# include <math.h>
# include <stdlib.h>
# include <time.h>
# define RAN() ((double)rand()/(double)(RAND_MAX))
# define pi M_PI
# define NMAX 13000005


int main(){

    FILE *file;
    char filename[100]="precosrandom.dat";
    file=fopen(filename,"w");
    
    int i,NN,c100;
    double r1,r2,r3,r4,r5,r6;
    double nm,n2m,m2,x0,x1;
    double t,dt,r7,r8,tr,AA,BB;
    double WW[NMAX];

    NN=30000; 

    nm=n2m=r6=0.;
    for (i=1;i<=NN;i++){
        r1=RAN();
        r2=RAN();
        r3=sqrt(-2.*log(r1));
        r4=cos(2.*pi*r2);
        r5=r3*r4;
        WW[i]=r5;
        r6=r6+1.;
        nm+=WW[i];
        n2m+=WW[i]*WW[i];
    }

    nm=nm/r6;
    n2m=n2m/r6;
    m2=n2m-nm*nm;
    m2=sqrt(m2);

    for (i=1;i<=NN;i++){
        WW[i]=(WW[i]-nm)/m2;
    }

    dt=1./200.;
    x0=10000.; // P(t=0) e  x1= P(t=Delta t)
    i=0;
    AA=0.001;
    BB=0.001;
    tr=sqrt(dt);

    for (t=dt;t<=100.;t++){
        i=i+1;
        x1=x0+AA*x0*dt+BB*x0*WW[i]*tr;

        x0=x1;

        c100=c100+1;
        if (c100>199){
            fprintf(file,"%20.8g %20.8g \n",t,x0);
            c100=0;
        }
    }
    return 0;
}