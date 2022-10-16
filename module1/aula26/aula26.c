# include <stdio.h>
# include <math.h>
# include <stdlib.h>
# include <complex.h>
//Física computacional 1 (V 16) - Regressão linear (introdução)
int main(){
    FILE *file,*file2;
    char filename[100] = "2.dat";
    char filename2[100] = "regressao.dat";
    file = fopen(filename,"r");
    file2 = fopen(filename2,"w");

    double x[1000],y[1000];
    double r1,r2,r3,r4,r5;
    double xm,ym,NR;
    double a0,a1;
    int i,N;

    double readX,readY;
    int lin;
    scanf("Se os dados forem lineares aperte 1, caso contrário aperte qualquer número \n",&lin);
    if(lin==1){
        for (i=1; fscanf(file,"%lf %lf",&readX, &readY)!=EOF;i++){
            x[i] = readX;
            y[i] = readY;
        }
    }else{
        for (i=1; fscanf(file,"%lf %lf",&readX, &readY)!=EOF;i++){
            x[i] = log(readX);
            y[i] = log(readY);
        }
    }
    fclose(file);

    N = i;
    NR = (double) N;
    r1 = r2 = r3 = r4 = xm = ym = 0.;

    for(i=1;i<=N;i++){
        xm+=x[i]/NR;
        ym+=y[i]/NR;
        r1+=x[i];
        r2+=y[i];
        r3 += r1*r2;
        r4 +=r1*r1;
    }

    a1 = (NR*r3-r1*r2)/(NR*r4-r1*r1);
    a0 = ym-a1*xm;
    
    r1 = x[1];
    r2 = x[N];

    for(r3=r1;r3<=r2;r3+=0.1){
        fprintf(file2,"%20.8f %20.8f \n",r3,(a0+a1*r3));
    }

    return 0;
}