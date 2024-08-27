#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "Ansi/Ansi.h"

#define rows 150
#define cols 150
#define avg 0
#define stddev rows/6.0
#define totpart 50000

#define PI 3.14159265358979323846200

double rand0_1(){
    double r=(double)rand();
    return r/(double)RAND_MAX;
}

double square(double x){
    return x*x;
}

double gaussian(double x, double deviation, double average) {
    double exponent = -square(x - average) / (2 * square(deviation));
    double numerator = exp(exponent);
    return numerator / (deviation * sqrt(2 * PI));
}

void printgausstemp(double n, double deviation, double average, int totparticles){
    double maxavg=square(gaussian(average, deviation, average))*totparticles;
    double sector=maxavg/6.0;
    //i know its horrible, but does the job
    if(n>0.5 && n<1){
        printf("{}");
        return;
    }
    terminal_set_background_color(ANSI_BLACK_COLOR);
    if(n>=1 && n<sector)terminal_set_background_color(ANSI_CYAN_COLOR);
    if(n>=sector && n<sector * 2)terminal_set_background_color(ANSI_BLUE_COLOR);
    if(n>= sector * 2 && n<sector * 3)terminal_set_background_color(ANSI_GREEN_COLOR);
    if(n>=sector * 3 && n<sector * 4)terminal_set_background_color(ANSI_YELLOW_COLOR);
    if(n>=sector* 4 && n<sector * 5 + sector/2) terminal_set_background_color(ANSI_RED_COLOR);
    if(n>=sector * 5 + sector/2) terminal_set_background_color(ANSI_WHYTE_COLOR);
    printf("  ");
    terminal_reset_color();
}

void fill_matrix2D_gaussian_particles_noisy(int r, int c, double matrix[][c] , double standard_dev, double mean, int n_particles, double noisepercent){
    srand(time(0)*time(0));
    double sum=0.0;
    double gaussx, gaussy, gaussprob;
    double x, y;
    int centery=r/2, centerx=c/2; 
    
    //i start filling the matrix with the probability of normalized gaussian distribution
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            x=j-centerx;
            y=i-centery;
            gaussx=gaussian(x, standard_dev, mean);
            gaussy=gaussian(y, standard_dev, mean);
            matrix[i][j]=gaussx*gaussy;
        }
    }
    //then take every cell(that contains the probability for a particle to exist there)
    //and multiply it by te number of particles
    //then i add noise accordingly to <noisepercent>
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            matrix[i][j]*=n_particles;
            if(rand0_1()<=noisepercent/100 && noisepercent) matrix[i][j]+=(rand0_1()-0.5)*2.2;
        }
    }
}

int main() {
    clear_terminal();
    double matr[rows][cols];
    fill_matrix2D_gaussian_particles_noisy(rows, cols, matr,stddev, avg, totpart, 30);
    for(int i=0; i<rows; i++){
        for (int j=0; j<cols; j++){
            printgausstemp(matr[i][j], stddev, avg, totpart);
        }
        printf("\n");
    }
    return 0;
}
