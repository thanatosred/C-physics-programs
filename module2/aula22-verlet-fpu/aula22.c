# include <stdio.h>
# include <math.h>
# include <stdlib.h>
# include <time.h>
# define PI M_PI

int main(){

    FILE *file, *file2, *file3;
    char filename[100] = "verletFPU.dat";
    char filename2[100] = "cenergiaverletFPU.dat";
    file = fopen(filename, "w");
    file2 = fopen(filename2, "w");
    char filenameC[200];

    int j, c10, i, n0, n00, c300, c1200, c500;
    double r1, r2, r3, r4, rr3, rr2, UT, U0;
    double kk, m1, mf;
    double kk3, t, tm, dt;
    double v1, v2;
    double xx0[2000], xx1[2000];
    double vx0[2000], vx1[2000];
    double ax0[2000], ax1[2000];
    double energia[2000];

    m1 = 1.;
    c10 = 0;
    c500 = 0.;

    tm = 60.;
    dt = 0.0805;
    n0 = 100;

    r1 = (double)n0;
    r1 = r1 * 0.5;
    n00 = (int)r1;

    for (i = 0; i <= (n0 + 1); i++){
        xx1[i] = xx0[i] = (double)i;
        vx0[i] = ax0[i] = ax1[i] = vx1[i] = 0.;
    }
    vx0[n00 + 25] = 1.;
    vx0[n00 - 25] = -1.;

    rr2 = 0.05 / dt;
    c1200 = 3;
    kk = 1.;
    kk3 = 1.;

    U0 = 0.;
    for (i = 1; i <= (n0); i++){
        v1 = fabs(xx0[i] - xx0[i - 1]);
        v2 = fabs(xx0[i] - xx0[i + 1]);

        r1 = v1 - 1.;

        r2 = v2 - 1.;

        r3 = 0.25 * kk * (r1 * r1 + r2 * r2);
        r4 = (1. / 6.) * kk3 * (r1 * r1 * r1 + r2 * r2 * r2);
        U0 = U0 + r3 + r4 + 0.5 * vx0[i] * vx0[i];
    }
    for (t = dt; t <= tm; t += dt){
        for (i = 1; i <= (n0); i = i + 1){
            v1 = fabs(xx0[i] - xx0[i - 1]);
            v2 = fabs(xx0[i] - xx0[i + 1]);

            r1 = v1 - 1.;
            r2 = v2 - 1.;

            ax0[i] = -kk * r1 - kk3 * (r1 * r1) + kk * r2 + kk3 * (r2 * r2);
            xx1[i] = xx0[i] + dt * vx0[i] + dt * dt * ax0[i] * 0.5;
        }
        for (i = 1; i <= (n0); i = i + 1){
            v1 = fabs(xx1[i] - xx1[i - 1]);
            v2 = fabs(xx1[i] - xx1[i + 1]);

            r1 = v1 - 1.;
            r2 = v2 - 1.;

            ax1[i] = -kk * r1 - kk3 * (r1 * r1) + kk * r2 + kk3 * (r2 * r2);
            vx1[i] = vx0[i] + 0.5 * dt * (ax0[i] + ax1[i]);
        }

        for (i = 1; i <= (n0); i = i + 1){
            xx0[i] = xx1[i];
            vx0[i] = vx1[i];
        }
        rr3 = rr3 + 1;
        if (rr3 > rr2){
            UT = 0.;
            for (i = 1; i <= (n0); i = i + 1){
                v1 = fabs(xx0[i] - xx0[i - 1]);
                v2 = fabs(xx0[i] - xx0[i + 1]);

                r1 = v1 - 1.;
                r2 = v2 - 1.;
                r3 = 0.25 * kk * (r1 * r1 + r2 * r2);
                r4 = (1. / 6.) * kk3 * (r1 * r1 + r2 * r2);
                UT = UT + r3 + r4 + 0.5 * vx0[i] * vx0[i];
                energia[i] = (r3 + r4 + 0.5 * vx0[i] * vx0[i]) / U0;
                fprintf(file, "%20.8g %20.8g %20.8g\n", t, (double)i, energia[i]);
            }
            fprintf(file2, "%20.8g %20.8g\n", t, fabs(1. - UT / U0));
            rr3 = 0.;
            c300 = c300 + 1;
            if (t > 1){
                c1200 = 11;
                }
            if (c300 > c1200){

                c300 = 0.;
                c500 = c500 + 1;
                sprintf(filenameC, "FUNCAOespacial%i.dat", c500);
                file3 = fopen(filenameC, "w");

                for (i = 1; i <= n0; i = i + 1){
                    fprintf(file3, "%20.8g %20.8g %20.8g \n", t, (double)i, energia[i]);
                }
                fclose(file3);
            }
        }
    }
    return 0;
}