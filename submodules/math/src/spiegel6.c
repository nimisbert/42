#include <spiegel6.h>

unsigned char complexEqual(complex c0, complex c1)
{
    if(c0.real == c1.real && c0.imag == c1.imag)
        return 1;
    return 0;
}

complex complexAdd(complex c0, complex c1)
{
    complex r = {c0.real+c1.real, c0.imag+c1.imag};
    return r;
}

complex complexSub(complex c0, complex c1)
{
    complex r = {c0.real-c1.real, c0.imag-c1.imag};
    return r;
}

complex complexMul(complex c0, complex c1)
{
    complex r = {c0.real*c1.real - c0.imag*c1.imag, c0.real*c1.imag + c0.imag*c1.real};
    return r;
}

complex complexDiv(complex c0, complex c1)
{
    complex r;
    r.real = (c0.real*c1.real + c0.imag*c1.imag)/(c1.real*c1.real + c1.imag*c1.imag);
    r.imag = (c0.imag*c1.real - c0.real*c1.imag)/(c1.real*c1.real + c1.imag*c1.imag);
    return r;
}

complex toPolar(complex c0)
{
    complex r = {c0.real, c0.imag, sqrt(c0.real*c0.real + c0.imag*c0.imag), atan((c0.imag/c0.real))};
    return r;
}

complex toPlane(complex c0)
{
    complex r = {c0.r*cos(c0.theta),c0.r*sin(c0.theta),c0.r,c0.theta};
    return r;
}

complex complexPolarMul(complex c0, complex c1)
{
    complex r;
    r.real = c0.r * c1.r * cos((c0.theta + c1.theta));
    r.imag = c0.r * c1.r * sin((c0.theta + c1.theta));
    r = toPolar(r);
    return r;
}

complex complexPolarDiv(complex c0, complex c1)
{
    complex r;
    r.real = (c0.r/c1.r) * cos(c0.theta - c1.theta);
    r.imag = (c0.r/c1.r) * sin(c0.theta - c1.theta);
    r = toPolar(r);
    return r;
}

complex deMoivre(complex c, double p)
{
    complex r;
    r.real = pow(c.r,p) * cos(p*c.theta);
    r.imag = pow(c.r,p) * sin(p*c.theta);
    r = toPolar(r);
    return r;
}

complex roots(complex c, unsigned int k, unsigned int n)
{
    complex r;
    r.real = pow(c.r,1.0/n) * cos((c.theta + 2*k*M_PI)/n);
    r.imag = pow(c.r,1.0/n) * sin((c.theta + 2*k*M_PI)/n);
    r = toPolar(r);
    return r;
}