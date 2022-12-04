//Física computacional 2 (V8)-Aplicação de Runge-Kutta 2a Ordem no sistema de dois níveis
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <complex.h>

int main(){
    FILE *file,*file2;
    char filename[100] = "r12niveisEULER.dat";//rk2
    char filename2[100] = "r12niveisrk2.dat";//rk2
    file = fopen(filename,"w");
    file2 = fopen(filename2,"w");

    double r1,r2,r3,r4,eg,ef,tt,t,dt;
    double _Complex f1,f2,g1,g2,k1f,k2f,k1g,k2g;
    double _Complex ff1,ff2,gg1,gg2,ic;

    ic = 0.-1.*I;//-i
    ef = eg=1.;
    tt = 0.1;
    dt = 0.01;
    //condicao inicial
    f1 = 1.+0.*I;
    g1 = 0.+0.*I;
    
    ff1 = f1;
    gg1 = g1;
    for(t=dt;t<=100.;t+=dt){
        //RK2 k1
        k1f = ic*(ef*f1+tt*g1);
        k1g = ic*(eg*g1+tt*f1);
        //k2
        k2f = ic*(ef*(f1+0.5*dt*k1f)+tt*(g1+0.5*dt*k1g));
        k2g = ic*(eg*(g1+0.5*dt*k1g)+tt*(f1+0.5*dt*k1f));

        f2=f1+dt*k2f;
        g2 = g1+dt*k2g;

        f1=f2;
        g1=g2;
        //fim do rk2

        //EULER
        ff2 = ff1+dt*ic*(ef*ff1+tt*gg1);
        gg2 = gg1+dt*ic*(eg*gg1+tt*ff1);

        ff1 = ff2;
        gg1 = gg2;
        //fim

        r1 = cabs(ff1);
        r2 = cabs(gg1);
        r3 = r1*r1+r2*r2;
        fprintf(file,"%13.8f %13.8f \n",t,r1);//solucao numerica de euler

        r1 = cabs(f1);
        r2 = cabs(g1);
        r3 = r1*r1+r2*r2;
        fprintf(file2,"%13.8f %13.8f \n",t,r1);//solucao numerica rk2
    }
    return 0;
}