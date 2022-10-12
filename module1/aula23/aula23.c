#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define RAND()((double)rand()/(double)(RAND_MAX))
//Física computacional 1 - histograma normalizado de séries de números aleatórios
int gerar(){
    double r1,r2,cn;
    int i;

    FILE *file,*file2;
    char filename[100] = "teste.dat";
    char filename2[100] = "teste2.dat";

    file = fopen(filename,"w");
    file2 = fopen(filename2,"w");

    srand(time(NULL));

    for(i=1;i<=180000;i++){
        r1 = RAND();
        fprintf(file,"%20.8f \n",r1);
    }
    for(i=1;i<=180000;i++){
        r1 = RAND();
        r2 = RAND();
        cn = r1*r2;
        fprintf(file2,"%20.8f \n",cn);
    }
    return 0;
}

int histograma(){
    FILE *file,*file2,*file3;
    char filename[100];
    char filename2[100];
    char filename3[100] = "histograma_nor.dat";


    printf("Digite o nome do arquivo de leitura \n");
    scanf("%s",&filename);
    printf("Digite o nome do arquivo de saida \n");
    scanf("%s",&filename2);

    file = fopen(filename,"r");
    file2 = fopen(filename2,"w");
    file3 = fopen(filename3,"w");

    int i,j,k,cont,Nmax;
    Nmax = 200000;
    double data[Nmax];
    double r1,r2,x,rmin,rmax,dx;

    double norma[200],xc [200];
    //leitura do arquivo
    double leit;
    for(cont=1; fscanf(file,"%lf",&leit)!=EOF;cont++){
        data[cont] = leit;
    }
    printf("lido: %lf \n",data[1]);

    rmax = -100.;
    rmin = 100.;
    //encontrar maximo e minimo
    for(i = 1; i <= cont; i++){   
        if(data[i] < rmin){
            rmin = data[i];
        }
        if(data[i] > rmax){
            rmax = data[i];
        }
    }
    dx = (rmax-rmin)/100.;
    
    printf("rmax: %lf \n rmin: %lf \n dx: %lf \n",rmax,rmin,dx);

    j = 1;
    for(x=dx;x<=(rmax-dx);x+=dx){
        r1=0.;
        for(i=1;i<=cont;i++){
            if(fabs(data[i]-x)<0.5*dx){
                r1+=1.;
            }
        }
        xc[j] = x;
        norma[j] = r1;
        fprintf(file2,"%20.8g \n",r1);
        j++;
    }
    printf("Histograma gerado \n x: %lf \n r1: %lf \n",x,r1);
    //integracao e histograma
    r2 = 0.;
    for(i = 1; i < j; i ++){
        r2 += (norma[i+1] + norma[i])*dx/2;
    }
    for(i = 1; i < j; i ++){
        norma[i] = norma[i]/r2;
        fprintf(file3, "%20.8g %20.8g \n", xc[i], norma[i]);
    }
    printf("Histograma normalizado \n");

    return 0;
}
int main(){
    //gerar();
    histograma();
    return 0;
}