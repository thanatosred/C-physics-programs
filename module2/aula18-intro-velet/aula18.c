//Física Computacional 2 - introdução ao método de Verlet
# include <stdio.h>
# include <math.h>
# include <stdlib.h>
# include <time.h>

# define PI M_PI

int main(){

    FILE *file;
    char filename[100]="verletdoisocorpos2.dat";
    file=fopen(filename,"w");

    int c10,i,n0;
    double r1,r2,r3,r4;
    double x,x0,y,y0,vx,vx0,vy,vy0,gg,m1,m2;
    double v0,theta,t,tm,dt,tdia;
    double rx0,ry0,mf,fx,fy,ax0,ay0,ax,ay;

    m1=7.36e+22;
    m2=5.97e+24;
    c10=0;

    tm=27.*24.*3600.;
    dt=0.0025;
    tdia=24.*3600;
    r2=tdia/dt;
    x0=384000000;
    y0=0.;
    vx0=0.;
    vy0=-1000.;

    gg=6.67e-11;

    for(t=dt;t<=tm;t+=dt){
        r1=x0*x0+y0*y0;

        mf=gg*m1*m2/r1;

        r1=sqrt(r1);

        rx0=-x0/(r1);
        ry0=-y0/(r1);

        fx=mf*rx0;
        fy=mf*ry0;

        ax0=fx/m1;
        ay0=fy/m1;

        x=x0+vx0*dt+0.5*ax0*(dt*dt);

        y=y0+vy0*dt+0.5*ay0*(dt*dt);

        r1=x*x+y*y;

        mf=gg*m1*m2/r1;
        r1=sqrt(r1);
        rx0=-x/(r1);
        ry0=-y/(r1);

        fx=mf*rx0;
        fy=mf*ry0;

        ax=fx/m1;
        ay=fy/m1;

        vx=vx0+0.5*dt*(ax+ax0);
        vy=vy0+0.5*dt*(ay+ay0);

        x0=x;
        y0=y;
        vx0=vx;
        vy0=vy;

        r3=r3+1.;
        if(r3>0.25*r2){
            fprintf(file,"%20.8g %20.8g %20.8g \n",x,y,t/tdia);
            r3=0.;
        }

    }
    return 0;
}