#include <spiegel9.h>

complex* solveQuadraticEquation(double a, double b, double c)
{
    static complex roots[2];
    double D = b*b - 4*a*c;
    roots[0] = (-b + csqrt(D))/(2*a);
    roots[1] = (-b - csqrt(D))/(2*a);
    return roots;
}

complex* solveCubicEquation(double a1, double a2, double a3)
{
    static double complex roots[3];
    double Q = (3*a2 - pow(a1,2)) / 9.;
    //printf("Q = %lf\r\n",Q);
    double R = (9*a1*a2 - 27*a3 - 2*pow(a1,3)) / 54.;
    //printf("R = %lf\r\n",R);
    complex double S = csqrt(R + csqrt(pow(Q,3) + pow(R,2)));
    //printf("S = %lf + %lf i\r\n",creal(S),cimag(S));
    complex double T = csqrt(R - csqrt(pow(Q,3) + pow(R,2)));
    //printf("T = %lf + %lf i\r\n",creal(T),cimag(T));
    double D = pow(Q,3) + pow(R,2);
    //printf("D = %lf \r\n",D);
    if(D >= 0)
    {
        roots[0] = S + T - (1.0/3)*a1;
        roots[1] = -0.5*(S+T) - (1.0/3)*a1 + 0.5*sqrt(3)*I*(S-T);
        roots[2] = -0.5*(S+T) - (1.0/3)*a1 - 0.5*sqrt(3)*I*(S-T);
    }
    else if(D<0)
    {
        double theta = (-R / csqrt(-pow(Q,3)))*M_PI/180;
        roots[0] = 2*csqrt(-Q)*cos((1.0/3)*theta );
        roots[1] = 2*csqrt(-Q)*cos((1.0/3)*theta + (2*M_PI)/3);
        roots[2] = 2*csqrt(-Q)*cos((1.0/3)*theta + (4*M_PI)/3);
    }
    return roots;
}

complex* solveQuarticEquation(double a1, double a2, double a3, double a4)
{
    //Use cubic equation... which DOES NOT WORK 
}