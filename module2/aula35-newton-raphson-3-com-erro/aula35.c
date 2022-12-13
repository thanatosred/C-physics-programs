//Física Computacional 2 - Método de Newton-Raphson para sistemas não-lineares (parte 3)
# include <stdio.h>
# include <math.h>
# include <stdlib.h>

int main(){

    FILE *file;
    char filename[100]="newton.txt";
    file= fopen(filename,"w");

    double f1,f2,x1,x2,x3;
    double h1,h2,y1,y2,y3;
    double v1,v2,rr1,rr2;
    double DD[50][50],bb[50],MM[50][50],JJ[50][50],FF[50],FF1[50];
    double vv[50],vv1[50];
    double IDD[50][50],prod[50],prod1[50],aux1[50];
    int i,j,k,o;

    
    x1=1.;
    y1=1.;

    rr1=1.;

    while(rr1>1e-5){
       JJ[1][1]=6.*(x1*x1);
       JJ[1][2]=2.*(y1);
       JJ[2][1]=pow(y1,3.);
       JJ[2][2]=3.*x1*(y1*y1)-1.;

       //JJv=-F
        FF[1]=2.*pow(x1,3.)-y1*y1-1.;
        FF[2]=x1*(pow(y1,3.))-y1-4.;

        FF1[1]=-FF[1];
        FF1[2]=-FF[2];

       //JJv=F1

       vv[1]=0.;
       vv[2]=0.;
       printf("%s %20.10g %20.10g \n","raiz",x2,y2);

       for(i=1;i<=2;i++){
           for(j=1;j<=2;j++){
                DD[i][j]=IDD[i][j]=0.;
            }
       }
       DD[1][1]=JJ[1][1];
       DD[2][2]=JJ[2][1];

       IDD[1][1]=1./DD[1][1];
       IDD[2][2]=1./DD[2][2];

       MM[1][1]=JJ[1][1]-DD[1][1];
       MM[1][2]=JJ[1][2]-DD[1][2];
       MM[2][1]=JJ[2][1]-DD[2][1];
       MM[2][2]=JJ[2][2]-DD[2][2];

       rr2=1.;
       while(rr2>1e-5){
            for(i=1;i<=2;i++){
                prod[i]=0.;
                for(j=1;j<=2;j++){
                    prod[i]=prod[i]+MM[i][j]*vv[j];
                }
             }
             for(i=1;i<=2;i++){
                aux1[i]=FF1[i]-prod[i];
             }
             for(i=1;i<=2;i++){
                vv1[i]=0.;
                for(j=1;j<=2;j++){
                    vv1[i]=vv1[i]+IDD[i][j]*aux1[j];
                }
             }
             rr2=fabs(vv1[1]-vv[1])+fabs(vv1[2]-vv[2]);

             for(i=1;i<=2;i++){
                vv[i]=vv1[i];
             }
       printf("%s %20.10g %20.10g \n","raiz",x2,y2);
       }
      printf("%s %20.10g %20.10g \n","raiz",vv[1],vv[2]);
       x2=x1+vv[1];
       y2=y1+vv[2];

       rr1=fabs(x1-x2)+fabs(y1-y2);
       printf("%s %20.10g %20.10g \n","raiz",x2,y2);

       fprintf(file,"%s %20.10g %20.10g \n","raiz",x2,y2);

       x1=x2;
       y1=y2;

    }

    f1=2.*pow(x1,3.)-y1*y1-1.;
    f2=x1*(pow(y1,3.))-y1-4.;

    fprintf(file,"%s %20.10g %20.10g \n","precisao=",f1,f2);

    return 0;
}