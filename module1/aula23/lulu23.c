#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

void main()
{   

    FILE *file3, *file4;
    // Declarando as funcoes que vou utilizar lkk

    double RAN();

    // Declarando variaveis utilizadas para gerar os dados
    double num_rand, num_rand_mult, a, b;
    int contador, interacao;

    printf("Quer gerar os dados? Digite 1 para sim e qualquer outro numero para nao: \n");
    scanf("%d", &interacao);
    if(interacao == 1)
    {   
        FILE *file1 = fopen("teste1.dat", "w"), *file2 = fopen("teste2.dat", "w");
        for(contador = 1; contador <= 180000; contador = contador + 1)
        {
            num_rand = RAN();
            a = RAN();
            b = RAN();
            num_rand_mult = a*b;

            fprintf(file1, "%20.8g\n", num_rand);
            fprintf(file2, "%20.8g\n", num_rand_mult);

        }
        fclose(file1);
        fclose(file2);
    }


    // Declarando variaveis utilizadas para gerar o histograma
    int n_max = 200000, i, j, k, cont;
    double data[n_max], data_linha, contador_r;
    double r1, r2, x, r_min, r_max, dx, num_caixas;
    char filename_in[50], filename_out[50];

    // declaracao dos arrays para normalizar os histogramas
    double hist_norm[200], xx[200];

    printf("Digite o nome do arquivo de entrada: \n");
    scanf("%s", &filename_in);
    file3 = fopen(filename_in, "r");

    printf("Digite o nome do arquivo de saida \n");
    scanf("%s", &filename_out);
    file4 = fopen(filename_out, "w");

    printf("Digite o numero de caixas do histograma \n");
    scanf("%lf", &num_caixas);

    /*
        Lendo os arquivos sem saber o numero de linhas
    */
    
    for(cont = 1; fscanf(file3, "%lf", &data_linha) != EOF; cont = cont + 1)
    {
        data[cont] = data_linha;
    }
    
    /*
        Aqui o arquivo ja foi lido e salvo em data, agora vamos para a estrategia abaixo:
        temos que encontrar o valor minimo e maximo da tabela, para poder definir o nosso
        dx, entao vou definir r_max e o r_min como numeros bem grandes e a partir dai
        vem outra logica
    */
    r_max = -100.;
    r_min = 100.;

    /*
        esse for serve para determinar o r_min e r_max
    */

    for(contador = 1; contador <= cont; contador ++)
    {   
        if(data[contador] < r_min)
        {
            r_min = data[contador];
            
        }
        if(data[contador] > r_max)
        {
            r_max = data[contador];
        }
    }

    
    dx = (r_max - r_min)/num_caixas;

    /*
        explicacao do pq comecamos em dx e terminamos em r_max - dx no time
        aproximado https://youtu.be/NMZgWHF4oS0?t=720
    */

    // valor inicial do j
    j = 1;
    for(contador_r = dx; contador_r <= r_max - dx; contador_r = contador_r + dx)
    {
        r1 = 0.;
        for(i = 1; i<= cont; i ++)
        {
            if(fabs(data[i]-contador_r)<0.5*dx)
            {
                r1 = r1 + 1.;
            }
        }

        xx[j] = contador_r;
        hist_norm[j] = r1;
        // indexador
        j = j + 1;
    
    }

    // integracao e definicao do r2 = 0
    r2 = 0;
    for(i = 1; i <= j-1; i ++)
    {
        r2 = r2 + (hist_norm[i+1] + hist_norm[i])*dx/2;
    }

    // loop para normalizar e escrever
    for(i = 1; i <= j-1; i ++)
    {
        hist_norm[i] = hist_norm[i]/r2;
        fprintf(file4, "%20.8g %20.8g \n", xx[i], hist_norm[i]);
    }

    
}


/* 
    aqui eu defino a funcao RAN() como sendo a conversao do numero aleatorio e dividindo
    pelo seu valor maximo, gera um numero aleatorio entre 0 e 1.
*/
double RAN()
{   
    return ((double)rand()/((double)RAND_MAX));
} 