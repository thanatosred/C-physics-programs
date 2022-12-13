//Física computacional 2 - Método de Verlet - potencial de Lennard-Jones

# include <stdio.h>
# include <math.h>
# include <stdlib.h>
# include <time.h>
# define PI M_PI

int main(){

    FILE *file;
    char filename[100]="verletdoisocorpos2.txt";
    file=fopen(filename,"w");

    int c10,i,n0;
    double r1,r2,r3,r4;
    double x,x0,y,y0,vx,vx0,vy,vy0,sig,sig6,sig12,e1;
    double t,tm,dt,t2;
    double rr1,rr2,LL;
    double rx0,ry0,mf,fx,fy,ax0,ay0,ax,ay;
    double EE1,EE2,EE3,EE4, EE0,EET;

    c10=0;
    

    tm=30.;
    dt=0.001;

    t2=0.1;

    r2=t2/dt;

    x0=6.;
    y0=6.;
    vx0=-1.;
    vy0=-1.;

    e1=100.;
    sig=3.3;

    sig12=12.*log(sig);
    sig12=exp(sig12);

    sig6=6.*log(sig);
    sig6=exp(sig6);

    //inicial
    r1=x0*x0+y0*y0;

    r1=sqrt(r1);
    rr1=12.*log(r1);
    rr1=exp(rr1);

    rr2=6.*log(r1);
    rr2=exp(rr2);

    EE1=4.*e1*(sig12/rr1-sig6/rr2);

    EE2=(vx0*vx0+vy0*vy0)*0.5;
    EE0=EE1+EE2;

    for(t=dt;t<=tm;t+=dt){
        r1=x0*x0+y0*y0;

        r1=sqrt(r1);
        rr1=13.*log(r1);
        rr1=exp(rr1);

        rr2=7.*log(r1);
        rr2=exp(rr2);

        mf=4.*e1*(12.*(sig12/rr1)-6.*(sig6/rr2));


        rx0=x0/(r1);
        ry0=y0/(r1);

        fx=mf*rx0;
        fy=mf*ry0;

        ax0=fx/mf;
        ay0=fy/mf;

        x=x0+vx0*dt+0.5*ax0*(dt*dt);

        y=y0+vy0*dt+0.5*ay0*(dt*dt);

        r1=x*x+y*y;
        r1=sqrt(r1);

        rr1=13.*log(r1);
        rr1=exp(rr1);

        rr2=7.*log(r1);
        rr2=exp(rr2);

        mf=4.*e1*(12.*(sig12/rr1)-6.*(sig6/rr2));

        rx0=x/(r1);
        ry0=y/(r1);

        fx=mf*rx0;
        fy=mf*ry0;

        ax=fx/mf;
        ay=fy/mf;

        vx=vx0+0.5*dt*(ax+ax0);
        vy=vy0+0.5*dt*(ay+ay0);

        x0=x;
        y0=y;
        vx0=vx;
        vy0=vy;

        //energia atual
        r1=x0*x0+y0*y0;

        r1=sqrt(r1);
        rr1=12.*log(r1);
        rr1=exp(rr1);

        rr2=6.*log(r1);
        rr2=exp(rr2);

        EE3=4.*e1*(sig12/rr1-sig6/rr2);

        EE4=(vx0*vx0+vy0*vy0)*0.5;
        EET=EE3+EE4;

        r3=r3+1.;
        if(r3>r2){
            fprintf(file,"%20.8g %20.8g %20.8g %20.8g\n",x,y,t,fabs(1.-EET/EE0));
            r3=0.;
        }

    }
    return 0;
}