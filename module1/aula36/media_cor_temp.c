//Física computacional (1 e 2) - médias de tabelas de dados de correlação temporal e participação
#include <dirent.h>
#include <stdio.h>
/*
Cálculo da média de diversas tabelas de dados (Fis. Comp. 1, 2 e métodos numéricos da PPG)
Nao entendi muito bom qual tabela seria lida, se seria uma tabela com as médias já prontas ou n
*/
int main(){
    DIR *dc;
    struct dirent *dir[20];
    dc = opendir(".");//abrir diretorio atual
    double x[100][1000],y[100][1000];
    double a[100][1000],xm,ym,rr;
    double rr1,rr2,rr3,rr4;
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
                for(i =1; fscanf(file,"%lf %lf %lf",&xm,&ym)!=EOF;i++){
                   // printf("%Lf \n",xm);
                    x[count][i] = xm;
                    a[count][i] = ym;
                }
                fclose(file);
            }
            count++;
        }
    }
    rr2 = 0.1;
    for(rr1=0.1;rr1<=350.;rr1+=rr2){
      rr3 = 0.;
      rr4 = 0.;
      for(int j=1;j<=count;j++){
        for(int k = 1; k<=i;k++){
          if(fabs(x[j][k]-rr1)<rr2*0.5){
            rr3+=a[j][k];
            rr4+=1.;
            printf("rr3: %lf rr4: %lf \n",rr3,rr4);
          }
        }
      }
      printf("MEDIAS CORRELATAS: \n");
      if(rr4>=0){            
        printf("rr1: %lf rr4: %lf \n",rr1,rr3/rr4);
      }
    }   
    return 0;
}