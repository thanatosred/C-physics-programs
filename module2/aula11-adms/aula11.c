//Física computacional 2 - Método de Adams-Bashforth e Adams-Moulton
#include<stdio.h>
#include<math.h>
#include <stdlib.h>

int main(){

FILE *file,*file2,*file3;
char filename[100]="caproximadoadams.dat";
char filename2[100]="capproxacoplado.dat";
char filename3[100]="csolucao.dat";
file=fopen(filename,"w");
file2=fopen(filename2,"w");
file3=fopen(filename3,"w");

double f0,f1,f2,f3,f4;
double x,x0,x1,x2,x3,x4,dx,xm,c;
double y0,y1,y2,y3,y4;

x0 = 0.;
dx = 0.1;
xm = 30.;
y0 = 1.; // y_{k-1}=1
c = 0.2;

f0 = c*y0;
y1 = y0 + dx*f0; // y_k

f1 = c*y1;

y2 = y1 + dx*f1;
f2 = c*y2;

y3 = y2 + dx*f2;

f3 = c*y3;

for (x = 4.*dx; x <= xm; x += dx){
    //formula de adams-bashford para 4 pontos
    y4 = y3 + (dx/24.)*(55.*f3 - 59.*f2 + 37.*f1 - 9*f0);
    f4 = c * y4;
    fprintf(file, "%13.8f %13.8f \n", x, y3);
    //formula de adams-moulton nova estimativa
    y4 = y3 + (dx/24.)*(9.*f4 + 19.*f3 - 5.*f2 + f1);
    fprintf(file2, "%13.8f %13.8f \n", x, y3);

    f4 = c * y4;

    f0 = f1;
    f1 = f2;
    f2 = f3;
    f3 = f4;

    y3 = y4;

    fprintf(file3, "%13.8f %13.8f \n", x, exp(c*x)); // solucao exata
    
    }
return 0;
}