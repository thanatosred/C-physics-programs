#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#define pi M_PI
#define RAN()((double)rand()/(double)(RAND_MAX))
//V14 - funcao de correlacao
double xx[1000000];
double ngau[1000000];
double histo[1000000];
void main (){

  FILE *file1,*file2;
  char filename1[100] = "numAleaGAU.dat";
  char filename2[100] = "autocorrelacao.dat";
  file1 = fopen(filename1,"w");
  file2 = fopen(filename2,"w");

  srand(time(NULL));
  
  int  i,cr;
  int k = 800000;
  double r1,r2,r3,r4,r5,r6;

  for(i=1;i<k;i++){
    r1 = RAN();
    r2 = RAN();
    r3 = sqrt(-2.*log(r1));
    r4 = cos(2.*pi*r2);
    r5 =r3*r4;
    ngau[i]=r5;
    fprintf(file1,"%20.8g \n",r5);
  }

  for(cr=1;cr<= 20;cr++){
    r1 = 0.;
    r2 = 0.;
    for(i=1;i<(k-cr);i++){
      r1+=ngau[i]*ngau[i+cr];
    }
    for(i=1;i<=k;i++){
      r2+=ngau[i];
      //printf("%20.8g %20.8g \n",r1,r2);
    }
    r1=r1/(double)(k-cr);
    r2 = r2/(double)(k);
    //printf("%20.8f %20.8f \n",r1,r2);
    fprintf(file2,"%20.8g %20.8g \n",((double)cr),(r1-r2*r2));
  }
}