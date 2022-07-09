#include <complex.h>

cmplx::cmplx (double reel, double imag)
{
    x = reel;
    y = imag;
}

double cmplx::getR(void)
{
    return cmplx::x;
}

void cmplx::setR(double a)
{
    cmplx::x = a;
}
