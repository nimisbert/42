#include <stdio.h>
#include <stdlib.h>

#define NUM_COMMANDS 2
#define NUM_POINTS 5

int main (void)
{
    char *cmdGnuPlot[] = {"set title \"Title\"", "plot 'data.temp'"};
    double xvals[NUM_POINTS] = {1.0, 2.0, 3.0, 4.0, 5.0};
    double yvals[NUM_POINTS] = {1.0, 2.0, 3.0, 4.0, 5.0};
    FILE *temp = fopen("data.temp","w");
    FILE *gnuPlotPipe = popen("gnuplot -persistent","w");
    for ( int i = 0; i < NUM_POINTS; i++ ) {
        fprintf( temp, "%lf %lf \n", xvals[i], yvals[i]);
    }
    for ( int i = 0; i < NUM_COMMANDS; i++ ) {
        fprintf( gnuPlotPipe, "%s \n",  cmdGnuPlot[i]);
    }
}
