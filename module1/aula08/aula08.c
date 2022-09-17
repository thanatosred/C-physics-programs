#include <stdio.h>
#include <math.h>
#include <complex.h>

void introComplex(){
    //Física Computacional 1 (V5)- Números complexos em C (introdução geral)
    double r1,r2,r3,r4;
    double _Complex c1,c2,c3;

    c1 = 1.+1.*I;
    r1 = creal(c1);
    r2 = cimag(c1);
    printf("1- A parte real: %lf A parte complexa: %lf\n",r1,r2);

    c1 = conj(c1);
    r1 = creal(c1);
    r2 = cimag(c1);
    printf("2- A parte real: %lf A parte complexa: %lf\n",r1,r2);
    
    c2 = 2. + 2.*I;
    c3 = c1*c2;
    r1 = creal(c3);
    r2 = cimag(c3);
    printf("2- A parte real: %lf A parte complexa: %lf\n",r1,r2);

    r3 = r1*r2+r2*r1;
    r4 = cabs(c3);
    r4 = r4*r4;
    printf("4-modulo de c3\n r3: %lf A parte r4: %lf\n",r3,r4);

    c3 = cexp(c3);
    r1 = creal(c3);
    r2 = cimag(c3);
    printf("5-exponencial de c3 \n A parte real: %lf A parte complexa: %lf\n",r1,r2);

}
void exercComplex(){
    //Física Computacional 1 - Números complexos em Fortran (P2)
    double _Complex c[11] ={};
    double r1,r2;
    double _Complex cs =0.+0.*I;
    for(int i = 0; i<=10;i++){
        c[i] = i*1.+i*1.*I;
        cs +=c[i];
        r1 = creal(c[i]);
        r2 = cimag(c[i]);
       // cs = cs+c[i];
        printf("2- A parte real: %lf A parte complexa: %lf\n",r1,r2);
    }
    r1 = creal(cs);
    r2 = cimag(cs);
    printf("2- A parte real: %lf A parte complexa: %lf\n",r1,r2);

}
void main(){
    introComplex();
    exercComplex();
}