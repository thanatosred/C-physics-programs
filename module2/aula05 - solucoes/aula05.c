//Física computacional 2 - Solução da equação de movimento de uma bola de tênis com efeito Magnus
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define pi M_PI

int main(){
    FILE *file;
    char filename[100];

    double vx0,vx,m,k,dt,t,tm,t0;
    double x1,x0,y0,y1;
    double vy0,vy,theta,g,v0,ww,vt;
    double AA,BB,rho,Area,RR;
    double CA,CM;
    double c100,c200;

    printf("Digite o valor de Omega \n");
    scanf("%lf",&ww);
    
    sprintf(filename,"trajetoriabolaw%1.8f.dat",ww);
    file = fopen(filename,"w");

    t0 = 0.;
    x0=0.;
    y0 = 1.5;
    dt = 0.00001;
    g = 9.8;
    tm = 1.656;

    v0=35.;
    theta = (10./180.)*pi;
    vx0 = v0*cos(theta);
    vy0 = v0*sin(theta);

    //ww = 210.;
    RR = 3.25/100.;//raio da bola
    Area = pi*(RR*RR);

    CA = 0.67; //coef de arraste
    rho = 1.18; // densidade do ar

    AA = 0.5*rho*Area*CA;// A*

    m = 58./1000;//massa da bola

    c200 = 0.02/dt;

    for(t = dt; t<=tm;t+=dt){
        vt = sqrt(vx0*vx0+vy0*vy0);
        CM = RR*ww/vt;

        BB = 0.5*rho*Area*CM;

        vx = vx0+dt*(-AA*vt*vx0+BB*vt*vy0)/m;
        vy = vy0+dt*(-m*g-AA*vt*vy0-BB*vt*vx0)/m;

        x1 = x0+dt*vx0;
        y1 = y0+dt*vy0;

        vx0 = vx;
        vy0 = vy;
        x0 = x1;
        y0 = y1;
        c100 +=1.;
        if(c100>=c200 && y0>0 ){
            fprintf(file,"%13.8f %13.8f \n",x0,y0);
            c100 = 0.;
        }
    }
    return 0;
}