#include <spiegel9.h>

complex* solveQuadraticEquation(double a, double b, double c)
{
    static double complex roots[2];
    double D = b*b - 4*a*c;
    roots[0] = (-b + csqrt(D))/(2*a);
    roots[1] = (-b - csqrt(D))/(2*a);
    return roots;
}

complex* solveCubicEquation(double a, double b, double c)
{
    static double complex roots[3];
}