#include <stdio.h>
#include <math.h>
//Física Computacional 1 - Introdução Geral (p5)
void cParabola(){
    FILE *file;
    char filename[100] = "tabela.dat";
    file = fopen(filename,"w");

    double a,b,c,delta,y,x,r1,r2,xl,xr;

    printf("Digite o valor de a:\n");
    scanf("%lf",&a);
    printf("Digite o valor de b:\n");
    scanf("%lf",&b);
    printf("Digite o valor de c:\n");
    scanf("%lf",&c);

    delta = b*b -4.*a*c;

    if (delta>=0){   
        r1 = (-b+sqrt(delta))/(2*a);
        r2 = (-b-sqrt(delta))/(2*a);
        
        printf("r1: %lf r2: %lf \n",r1,r2);

        if(r1>=r2){
            xr = r1+1.;
            xl = r2-1.;
        }else{
            xr = r2+1.;
            xl = r1-1.;
        }
        for (x = xl; x <=xr; x = x + 0.1){
            y = a*(x*x)+b*x+c;
            fprintf(file,"%lf %lf\n", x,y);
        }
        
    }else{
        printf("A equacao nao tem solucao real\n");
    }
}
void main(){  
    cParabola();
}