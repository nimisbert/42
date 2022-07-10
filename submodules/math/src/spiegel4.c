#include <stdio.h>
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

double circleArea(double r)
{
    return M_PI*r*r;
}

double circlePerimeter(double r)
{
    return 2*M_PI*r;
}

double sectorArea(double r, double theta)
{
    return 0.5*r*r*theta;
}

double sectorArc(double r, double theta)
{
    return r*theta;
}

double circleRadiusInscribedInTriangle(double a, double b, double c)
{
    double s = 0.5*(a+b+c);
    return sqrt(s*(s-a)*(s-b)*(s-c))/s;
}
double circleRadiusCircumscribingTriangle(double a, double b, double c)
{
    double s = 0.5*(a+b+c);
    return a*b*c/(4*sqrt(s*(s-a)*(s-b)*(s-c)));
}

double regularPolygonAreaInscribedInCircle(double r, unsigned int n)
{
    return 0.5*n*r*r*sin(2*M_PI/n);
}

double regularPolygonPerimeterInscibedInCircle(double r, unsigned int n)
{
    return 2*n*r*sin(M_PI/n);
}

double regularPolygonAreaCircumscribingCircle(double r, unsigned int n)
{
    return n*r*r*tan(M_PI/n);
}

double regularPolygonPerimeterCircumscribingCircle(double r, unsigned int n)
{
    return 2*n*r*tan(M_PI/n);
}

double segmentOuterAreaOfCircle(double r, double theta)
{
    return 0.5*r*r*(theta-sin(theta));
}

double ellipseArea(double a, double b)
{
    return M_PI*a*b;
}

double ellipsePerimeterRawApproximation(double a, double b)
{
    return 2*M_PI*sqrt(0.5*(pow(a,2) + pow(b,2)));
}

double ellipsePerimeterIntegralApproximation(double a, double b, unsigned int nstep)
{
    double f(double theta)
    {
        double k = sqrt(a*a - b*b)/a;
        return sqrt(1- k*k*sin(theta)*sin(theta));
    }
    return 4*a*integralComposite(0,M_PI/2,f,nstep);
}

double parabolaArea(double a, double b)
{
    return (2.0/3.0)*a*b;
}

double parabolaArcLength(double a, double b)
{
    return 0.5 * sqrt(b*b + 16*a*a) + (b*b/(8*a)) * log((4*a + sqrt(b*b + 16*a*a))/b);
}

double rectangularParallelepipedVolume(double a, double b, double c)
{
    return a*b*c;
}

double rectangularParallelepipedSurfaceArea(double a, double b, double c)
{
    return 2*(a*b + a*c + b*c);
}

double parallelepipedVolumeABCT(double a, double b, double c, double theta)
{
    return a*b*c*sin(theta);
}

double parallelepipedVolumeAh(double A, double h)
{
    return A*h;
}

double sphereVolume(double r)
{
    return (4.0/3) * M_PI * r*r*r;
}

double sphereSurfaceArea(double r)
{
    return 4 * M_PI * r*r;
}

double cylinderVolume(double r, double h)
{
    return M_PI*r*r*h;
}

double cylinderLateralSurfaceArea(double r, double h)
{
    return 2*M_PI*r*h;
}

double integralComposite(double a, double b, fptr f, unsigned int n)
{
    double sum = 0;
    for(unsigned int k = 1; k < n; k++)
    {
        sum += f(a + k*(((double)(b-a))/n));
    }
    sum += f(a)/n + f(b)/n;
    sum *= (double)(b-a)/n;
    return sum;
}