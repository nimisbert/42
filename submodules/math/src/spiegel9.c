#include <spiegel9.h>

complex* quadraticEquation(double a, double b, double c)
{
    static double complex roots[2];
    double D = b*b - 4*a*c;
    if(D>0.0)
    {
        // roots[0] = (-b + sqrt(D))/(2*a);
        // roots[1].real = (-b - sqrt(D))/(2*a);
    }
    else if(D==0.0)
    {
        // roots[0].real = -b/(2*a);
    }
    else if(D<0.0)
    {
        // csqrt(D);
    }
    return roots;
}