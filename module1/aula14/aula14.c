#include <stdio.h>
#include <math.h>
//Física Computacional 1 (V9) - derivada numérica de uma tabela dados (ATENÇÃO: olhar descrição)
void criarTabela(){
    FILE *file;
    char filename[] = "dados.dat";
    file = fopen(filename,"w");
    double y;
    for (double x=0.;x <2.1;x+=0.1){
        y = x*x;
        fprintf(file,"%13.8f %13.8f\n",x,y);
    }
    printf("Dados gerados \n");
}
void lerTabela(){
    FILE *file1,*file2;
    char filename1[100] = "derivada.dat";
    char filename2[100] = "dados.dat";
    file1 = fopen(filename1,"w");
    file2 = fopen(filename2,"r");

    double h;
    double d1,d2;
    double x[1000],y[1000];
    int i,j;
    for(i=0; fscanf(file2,"%lf %lf ",&x[i],&y[i])!=EOF;i++){
        printf("%13.8f %14.8f \n",x[i],y[i]);
    }
    printf("Dados lidos \n");
    
    h = x[1]-x[0];
    //colocando ponto inicial
    //fprintf(file1,"%20.8lf %20.8lf \n",x[0],y[0]);
    //adicionando pontos da derivada
    for(j=1; j<(i-1);j++){
        d1 = (y[j+1]-y[j-1])/(2.*h);
        fprintf(file1,"%20.8lf %20.8lf \n",x[j],d1);
        printf("%20.8lf %20.8lf \n",x[j],d1);
    }
    //colocando ponto final
    //fprintf(file1,"%20.8lf %20.8lf \n",x[i-1],y[i-1]);
    fclose(file2);
    printf("Derivadas geradas \n");
}
void main(){
    criarTabela();
    lerTabela();
}