//Física Computacional 2 - método de Verlet - 2 partículas com potencial tipo Lennard-Jones

# include <stdio.h>
# include <math.h>
# include <stdlib.h>
# include <time.h>
# define PI M_PI

int main(){

    FILE *file;
    char filename[100]="verletLJ2particulas.dat";
    file=fopen(filename,"w");
    // Declaração de variáveis
    int c10,i,n0;
    double r1,r2,r3,r4;
    double x,x0,y,y0,vx,vx0,vy,vy0,sig,sig6,sig12,e1;
    double x1,x10,y1,y10,v1x,v1x0,v1y,v1y0,f1x,f1y,r1x,r1y;
    double a1x,a1y,a1x0,a1y0;
    double t,tm,dt,t2;
    double rr1,rr2,LL;
    double rx0,ry0,mf,fx,fy,ax0,ay0,ax,ay;
    double EE1,EE2,EE3,EE4,EE0,EET;
    double xm,ym;

    c10=0;   
    tm=30.;
    dt=0.001;
    t2=0.1;
    r2=t2/dt;
    x0=6.;
    y0=6.;
    vx0=0.0;
    vy0=0.0;
    e1=100.;
    
    sig=3.3;
    sig12=12.*log(sig);
    sig12=exp(sig12);
    sig6=6.*log(sig);
    sig6=exp(sig6);

    //Calcule a energia inicial
    r1=(x0-x10)*(x0-x10)+(y0-y10)*(y0-y10);
    r1=sqrt(r1);
    rr1=12.*log(r1);
    rr1=exp(rr1);
    rr2=6.*log(r1);
    rr2=exp(rr2);

    EE1=4.*e1*(sig12/rr1-sig6/rr2);
    EE2=(vx0*vx0+vy0*vy0+v1x0*v1x0+v1y0*v1y0)*0.5;
    EE0=EE1+EE2;

    for(t=dt;t<=tm;t+=dt){
        r1=(x0-x10)*(x0-x10)+(y0-y10)*(y0-y10);

        r1=sqrt(r1);
        rr1=13.*log(r1);
        rr1=exp(rr1);

        rr2=7.*log(r1);
        rr2=exp(rr2);

        mf=4.*e1*(12.*(sig12/rr1)-6.*(sig6/rr2));


        rx0=(x0-x10)/(r1);
        ry0=(y0-x10)/(r1);

        fx=mf*rx0;
        fy=mf*ry0;

        ax0=fx;
        ay0=fy;

        x=x0+vx0*dt+0.5*ax0*(dt*dt);

        y=y0+vy0*dt+0.5*ay0*(dt*dt);

        a1x0=-ax0;
        a1y0=-ay0;

        x1=x10+v1x0*dt+0.5*a1x0*(dt*dt);

        y1=y10+v1y0*dt+0.5*a1y0*(dt*dt);

        r1=(x-x1)*(x-x1)+(y-y1)*(y-y1);

        r1=x*x+y*y;
        r1=sqrt(r1);

        rr1=13.*log(r1);
        rr1=exp(rr1);

        rr2=7.*log(r1);
        rr2=exp(rr2);

        mf=4.*e1*(12.*(sig12/rr1)-6.*(sig6/rr2));

        rx0=(x-x1)/(r1);
        ry0=(y-y1)/(r1);

        fx=mf*rx0;
        fy=mf*ry0;

        ax=fx;
        ay=fy;

        a1x=-ax;
        a1y=-ay;

        vx=vx0+0.5*dt*(ax+ax0);
        vy=vy0+0.5*dt*(ay+ay0);

        v1x=v1x0+0.5*dt*(a1x+a1x0);
        vy=v1y0+0.5*dt*(a1y+a1y0);


        x0=x;
        y0=y;

        vx0=vx;
        vy0=vy;

        x10=x1;
        y10=y1;

        v1x0=v1x;
        v1y0=v1y;

        // energia atual
        r1=(x0-x10)*(x0-x10)+(y0-y10)*(y0-y10);

        r1=sqrt(r1);
        rr1=12.*log(r1);
        rr1=exp(rr1);

        rr2=6.*log(r1);
        rr2=exp(rr2);

        EE3=4.*e1*(sig12/rr1-sig6/rr2);

        EE4=(vx0*vx0+vy0*vy0+v1x0*v1x0+v1y0*v1y0)*0.5;
        EET=EE3+EE4;

        r3=r3+1.;
        if(r3>r2){
            r4=(x0-x10)*(x0-x10)+(y0-y10)*(y0-y10);
            xm=(x0+x10)*0.5;
            ym=(y0+y10)*0.5;
            r4=sqrt(r4);
            fprintf(file,"%18.6g %18.6g %18.6g %18.6g %18.6g %18.6g %18.6g %18.6g %18.6g \n",t,r4,x,x1,y,y1,xm,ym,fabs(1.-EET/EE0));
            r3=0.;
        }

    }
    return 0;
}