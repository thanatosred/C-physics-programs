#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#define pi M_PI 
#define RAN()((double)rand()/(double)(RAND_MAX))
int main(){
    FILE *file,*file2;
    char filename1[100] = "numerosaleatoriosGAU.dat";
    char filename2[100] = "histograma.dat";
    file = fopen(filename1,"w");
    file2 = fopen(filename2,"w");
    double ngau[500000];
    double r1,r2,r3,r4,r5,r6;
    
    srand(time(NULL));

    for(int i=0; i<200000;i++){
        r1 = RAN();
        r2 = RAN();
        r3 = sqrt(-2.*log(r1));
        r4 = cos(2.*pi*r2);
        r5 = r3*r4;
        ngau[i] = r5;
        fprintf(file,"%20.8g \n",r5);
    }
    for(r1 =-5.;r1<=5.0;r1+=0.1){
        r2 = 0.;
        for(int i=0;i<200000; i+=1){
            if(fabs(ngau[i]-r1)<0.05){
                r2+=1.;
            }
        }
        fprintf(file2,"%20.8g %20.8g \n",r1,r2);
    }
    return 0;
}