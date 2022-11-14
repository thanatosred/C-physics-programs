//Método de Euler Modificado para lançamento oblíquo com resistência do ar.
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <complex.h>
#define PI M_PI

int lanc(double gama){
    FILE *file;
    char filename[100];
    sprintf(filename,"lancamentoeuler%f.dat",gama);

    file = fopen(filename,"w");

    int i,n0;
    double r1,r2,r3,r4;
    double x,x0,y,y0,vx,vx0,vy,vy0,gg;
    double v0,theta,t,tm,dt;

    tm = 20.;
    dt = 0.00005;
    theta = PI/4;
    gg= 10.;
    v0 = 10.;
    vx0 = v0*cos(theta);
    vy0 = v0*sin(theta);
    x0 = 0.;
    y0 = 0.;
    x = y = 0.;
    for(t=dt;t<=tm;t+=dt){
        vx = vx0+dt*(-gama*vx0);
        vy = vy0+dt*(-gama*vy0 -gg);
        x = x0+dt*vx0;
        y = y0+dt*vy0;
        x0 =x;
        y0 = y;
        vx0 = vx;
        vy0 = vy;

        if(y>0.){
            fprintf(file, "%20.8g %20.8g \n",x,y);
        }
    }
    return 0;
}
int main(){
    lanc(0.);
    lanc(1.);
    lanc(2.);

    return 0;
}