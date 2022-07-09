#include <math.h>
#include <stdarg.h>
#include <spiegel3.h>

double factorial(unsigned int n)
{
    double r = 1;
    for(int i=1; i<n+1; i++)
    {
        r *= i;
    }
    return r;
}

double binomial(double x, double y, unsigned int n)
{
    return pow(x+y,n);
}

double binomialCoeficient(double k, double n)
{
    double r = n;
    for(int i = 1; i<k; i++)
    {
        r *= (n-i)/(i+1);
    }
    return r;
}

double multinomial(unsigned int n, unsigned int p, ...)
{
    double r = 0;
    va_list ptr;
    va_start(ptr,p);
    for(int i = 0; i<p; i++)
        r += va_arg(ptr, double);
    va_end(ptr);
    return pow(r,n);
}