//Física Computacional 2 (V7) -método de Adams-Bashforth de 2a ordem
#include<stdio.h>
#include<math.h>
#include <stdlib.h>

int main(){

FILE *file,*file2;
char filename[100]="caproximadoadams.dat";
char filename2[100]="csolucao.dat";
file=fopen(filename,"w");
file2=fopen(filename2,"w");

double f0,f1,f2,g0,g1,dx,x0,x,xm,c;
//resolver dy/dx = cy

//usando o metodo de euler
x0=0.;
dx=0.1;
xm=20.;
f0=1.; //y_{k-1} = 1
c=0.2;

//inicando em ordem 1
//tempo 1dx
g0=c*f0; //f_{k-1}
f1=f0+dx*g0; //y_k

//tempo 2dx
g1=c*f1;//f_{k-2} 
f2=f1+dx*g1; //f_{k+1}
f1=f2;
//tempo 3dx
for (x=3.*dx;x<=xm;x+=dx){
    f2=f1+0.5*dx*(3.*g1-g0);//y_{k+1}=y_{k}+h/2*(3f_{k}-f_{k-1})
    g0=g1;
    g1=c*f2;
    f1=f2;

    fprintf(file,"%13.8f %13.8f\n",x,f1);
    fprintf(file2,"%13.8f %13.8f\n",x,exp(c*x)); //solucao exata
    }   
return 0;
}