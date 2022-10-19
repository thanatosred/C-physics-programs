//Física computacional (1 e 2 ) - Médias de dados da participação em função de k (mais exemplos)
#include <dirent.h>
#include <stdio.h>
/*
Cálculo da média de diversas tabelas de dados (Fis. Comp. 1, 2 e métodos numéricos da PPG)
*/
int main(){
    DIR *dc;
    struct dirent *dir[20];
    dc = opendir(".");//abrir diretorio atual
    double x[1000],y[1000];
    double a[1000],xm,ym;
    int i, count;
    if(dc!=NULL){
        count = 1;
        while((dir[count] = readdir(dc))!=NULL){
            if ( !strcmp (dir[count]->d_name, "." ) || !strcmp ( dir[count]->d_name, ".." ) || !strstr( ( dir[count]->d_name ), ".dat" ) ){
                continue;
            }
            printf("%s \n",dir[count]->d_name);
            FILE *file;
            file = fopen(dir[count]->d_name,"r");
            if(file!=NULL){
                for(i =1; fscanf(file,"%lf %lf",&xm,&ym)!=EOF;i++){
                   // printf("%Lf \n",xm);
                    x[i] = xm;
                    y[i] += ym;
                }
                fclose(file);
            }
            count++;
        }
    }
    for(int j = 1; j <=i; j++){
        a[j] = y[j]/((double) count);
        printf("%lf %lf \n",x[j],a[j]);
    }
    return 0;
}