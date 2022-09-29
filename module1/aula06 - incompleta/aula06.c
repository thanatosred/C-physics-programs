#include <stdio.h>
#include <math.h>
//Física Computacional 1 - Introdução geral parte 6 - Calculando a curva média de tabela de dados
void curvaMediaArit(int n){
// n é o número de intervalos computados
/*FILE *partivideo06,*file;
partivideo06 = fopen("partivideo6.dat","rb");
file = fopen("curvaMediaArti.dat","w");
double x[10010] = { };
double y[10010] = { };
double xx,xs,ys,ym,dx = 0.;
dx = 0.1;
int cont,r1 = 0;
//leitura dos arquivos
for (int i =0; fscanf(partivideo06,"%lf %lf",&x[i],&y[i])!=EOF;i++){//a condição ler o arquivo até não encontrar mais linhas para leitura (EOF = -1)
    cont++;
}
//
for (xx = -2.6; xx <=2.5; xx +=dx){
    for(int i = 0; i<cont;i++){
        if(abs(xx-x[i])<dx){
            r1+=1;
            ys+=y[i];
        }
        if(r1>0){
            ym = ys/r1;
            //fprintf(file,"%lf %lf\n",x[r1],ym);
            printf("xm: %lf ym: %lf i: %d\n",x[i],ym,i);
        }
    }
}
fclose(partivideo06);
*/
}
void main(){
    curvaMediaArit(10);
}