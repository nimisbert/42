#include <math.h>
#include <spiegel4.h>

double rectangleArea(double a, double b)
{
    return a*b;
}
double rectanglePerimeter(double a, double b)
{
    return 2*a + 2*b;
}

double parallelogramArea(double h, double b)
{
    return h*b;
}
double parallelogramPerimeter(double a, double b)
{

    return 2*a + 2*b; 
}

double triangleAreaHB(double h, double b)
{
    return (h*b)*0.5;
}

double triangleAreaABC(double a, double b, double c)
{
    double s = (a+b+c)*0.5;
    return sqrt(s*(s-a)*(s-b)*(s-c));
}

double trianglePerimeter(double a, double b, double c)
{
    return a+b+c;
}


double trapezoidArea(double a, double b, double h)
{
    return 0.5*h*(a+b);
}

double trapezoidPerimeter(double a, double b, double h, double theta, double phi)
{
    return a + b + h*(1.0/sin(theta) + 1.0/sin(phi)); 
}

double regularPolygonArea(double b, unsigned int n)
{
    return 0.25 * n * pow(b,2) * (cos(M_PI/n)/sin(M_PI/n));
}

double regularPolygonPerimeter(double b, unsigned int n)
{
    return b*n;
}