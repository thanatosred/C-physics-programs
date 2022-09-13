#include <stdio.h>
#include <math.h>
/*a biblioteca include possibilita a utilizacao das funcoes printf() e Scanf()
em C devemps criar um bloco de instrucao principal para compilar o codigo.
*/
float media(int a, int b){
    float c = (a+b)/2.;
    return c;
}
int soma(int a,int b){
    int c = 0;
    for (int i= 0; i <= (b-a); i++)
    {
        c +=a+i;
    }
    return c;
}
float r2soma(int a, int b){
    float c = sqrt((a*a+b*b));
    return c;
}
void plot(){
    FILE *fp=NULL;
    fp=fopen("circle.dat","w");
    int x [] = {0};
    int y [] = {0};
    for (int i = 0; i < 20; i++)
    {
        x[i] = i;
        y[i] = x[i]+1;
    } 
    int p[20][2] = {x,y};
    //fprintf(fp,"%lf\t %lf\n",x,y);
}
void main(){
    int a,b = 0;
    printf("Digite um numero inteiro: \n");
    scanf("%d", &a);
    printf("Digite outro numero inteiro: \n");
    scanf("%d",&b);
    printf("\n A media aritmetica eh: \n %.2f", media(a,b));
    printf("\n A soma de todos os termos eh: \n %d", soma(a,b));
    printf("\n A raiz da soma dos quadrados eh: \n %.2f", r2soma(a,b));
    plot();
}

