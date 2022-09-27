#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#define pi 3.14159 
#define RAN()((double)rand()/(double)(RAND_MAX))
//V14 - funcao de correlacao
void main (){
  FILE *file1,*file2;
  char filename1[100] = "numAleaGAU.dat";
  char filename2[100] = "autocorrelacao.dat";
  file1 = fopen(filename1,"w");
  file2 = fopen(filename2,"w");

  srand(time(NULL));
  //
  double xx[810000];
  double ngau[810000];
  double histo[810000];
  
  int  i,cr;
  int k = 800000;
  double r1,r2,r3,r4,r5,r6;

  for(i=1;i<=k;i++){
    r1 = RAN();
    r2 = RAN();
    r3 = sqrt(-2.*log(r1));
    r4 = cos(2.*pi*r2);
    r5 =r3*r4;
    ngau[i]=r5;
    fprintf(file1,"%20.8g \n",r5);
  } 
  for(cr=0;cr<=10;cr+=1){
    r1 =0.;
    r2 = 0.;
    for(i=1;i<=(k-cr);i++){
      r1+=ngau[i]*ngau[i+cr];
    }
    for(i=1;i<=k;i++){
      r2+=ngau[i];
    }
    r1=r1/(double)(k-cr);
    r2 = r2/(double)(k);
    fprintf(file2,"%20.8g %20.8g \n",((double)cr),r1-r2*r2);
  }
}