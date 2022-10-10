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
int linearFunction(){
    FILE *file;
    char filename[100] = "funcaoAfim.dat";
    file = fopen(filename,"w");
    int x,y = 0.;
    for (x = 0.; x < 20.; x = x+1.){
        y = x+1.;
        fprintf(file,"%d %d\n",x,y);
        printf("\n%d %d\n",x,y);
    } 
    return 0;
}
int main(){
    int a,b = 0;
    printf("Digite um numero inteiro: \n");
    scanf("%d", &a);
    printf("Digite outro numero inteiro: \n");
    scanf("%d",&b);
    printf("\n A media aritmetica eh: \n %.2f", media(a,b));
    printf("\n A soma de todos os termos eh: \n %d", soma(a,b));
    printf("\n A raiz da soma dos quadrados eh: \n %.2f", r2soma(a,b));
    linearFunction();
    return 0;
}

