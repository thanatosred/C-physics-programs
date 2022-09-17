#include <stdio.h>
#include <math.h>
//Física Computacional 1 - Introdução geral parte 6 - Calculando a curva média de tabela de dados
void curvaMediaArit(int n){
// n é o número de intervalos computados
FILE *partivideo06,*file;
partivideo06 = fopen("partivideo6.dat","rb");
file = fopen("curvaMediaArti.dat","w");
double x[] = { };
double y[] = { };
double a,b,xs,ys,dx = 0.;
dx = 0.1;
//leitura dos arquivos
int c =0;
for (int i =0; fscanf(partivideo06,"%lf %lf",&a,&b)!=EOF;i++){//a condição ler o arquivo até não encontrar mais linhas para leitura (EOF = -1)
    x[i]=i*0.1;
    y[i]=i*0.1;
    printf("i:%d\n",i);
}
/*for (x = -2.6; x <=2.5; x +=dx){
}*/
fclose(partivideo06);
}
void main(){
    curvaMediaArit(10);
/*double x[]={ };
for (int i = 0; i < 20.; i++)
{
    x[i] = i*0.1;
    printf("x: %lf \n",x[i]);
}*/

}