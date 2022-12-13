//Física computacional 2 - Resolvendo o Oscilador Harmônico simples usando o método de Verlet
# include <stdio.h>
# include <math.h>
# include <stdlib.h>
# include <time.h>
# define PI M_PI

int main(){

    FILE *file;
    char filename[100]="verletOH.dat";
    file=fopen(filename,"w");

    int c10,i,n0;
    double r1,r2,r3,r4;
    double x,x0,y,y0,vx,vx0,kk,m1,mf;
    double t,tm,dt,fx,ax0,ax;

    m1=1.;
    c10=0;
    

    tm=20.;
    dt=0.001;

    r2=0.1/dt;
    x0=1.;
    vx0=0.;

    kk=1.;

    for(t=dt;t<=tm;t+=dt){

        mf=-kk*x0;

        r1=sqrt(r1);

        ax0=mf/m1;

        x=x0+vx0*dt+0.5*ax0*(dt*dt);

        mf=-kk*x;
        ax=mf/m1;


        vx=vx0+0.5*dt*(ax+ax0);

        x0=x;
        vx0=vx;

        r3+=1.;
        if(r3>r2){
            fprintf(file,"%20.8g %20.8g %20.8g\n",t,x,vx);
            r3=0.;
        }

    }
    return 0;
}