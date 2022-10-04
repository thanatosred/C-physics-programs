#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

double A[305][400005];
double RAN()
{
    return ((double)rand()/((double)RAND_MAX));
}
void main()
{
    FILE *file1, *file2;
    double RAN();
    int i, j, m;
    int n1 = 300, n2 = 400000;
    double pp = 0.5;
    double r1, r2, r3, r4, cc;

    char filename1[100] = "sigmacaminhante.dat";
    char filename2[100] = "histograma.dat";

    file1 = fopen(filename1, "w");
    file2 = fopen(filename2, "w");

    srand(time(NULL));

    for(m = 1; m <= n2; m++){
        A[1][m] = 0.;

        for(j=2; j<= n1; j++){
            r1 = RAN();
            if(r1 > pp){
                r2 = 1.;
            }
            if(r1 < pp){
                r2 = -1.;
            }
            A[j][m] = A[j-1][m] + r2;
        }
    }

    for(j=2;j<= n1; j++){
        r1 = 0.;
        r2 = 0.;
        r3 = 0.;

        for(m=1; m<=n2;m++){
                r1 += A[j][m]; //media <x>
                r2 += pow(A[j][m], 2.); //media quad<x²>
                r3 += 1.;
            }
            r1 = r1/r3;
            r2 = r2/r3;
            fprintf(file1, "%i %20.8g \n", j, sqrt(r2 - r1*r1));
    }

    j = n1;

    for(cc = -200.; cc <= 200.; cc = cc + 4.)
    {
        r4 = 0.;

        for(m=1; m<=n2;m=m+1){
            if((fabs(A[j][m]-cc)) <= 2.)
            {
                r4 = r4 + 1.;
            }

        }
        fprintf(file2, "%f %f \n", cc, r4);
    }

}