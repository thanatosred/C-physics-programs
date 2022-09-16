#include <stdio.h>
#include <math.h>
//Física Computacional 1 (V3)-Introdução geral (p3)
void cExpcAprox(int j){
    FILE *file1,*file2;
    char filename1[] ="";
    sprintf(filename1,"%s%d%s","cExpAprox", j,".dat");
    char filename2[] = "cexp.dat";

    file1 =fopen(filename1,"w");
    file2 =fopen(filename2,"w");

    double fat,y,x,dx,ir;
    int i;

    dx = 0.05f;
    
    for (x = 0.;x<=2.;x = x+dx){
        y = 1.;
        fat = 1.;
        for (i =1; i<=j; i=i+1){
            fat = fat*((double)i);
            ir = (double)i;
            y=y+pow(x,ir)/fat;
        }
        fprintf(file1,"%13.8f %13.8f\n",x,y);
        fprintf(file2,"%13.8f %13.8f\n",x,exp(x));
    }
    
}
void main(){
    cExpcAprox(5);
    cExpcAprox(10);
}