#ifndef SPIEGEL_SECTION_6
#define SPIEGEL_SECTION_6
/** 
 * COMPLEX
 * NUMBERS
 */

#include <math.h>
#include <stdio.h>

typedef struct tcmplx{
    //Plane
    double real;
    double imag;
    //Polar
    double r;
    double theta;
}complex;

unsigned char complexEqual(complex c0, complex c1);

complex complexAdd(complex c0, complex c1);
complex complexSub(complex c0, complex c1);

complex complexMul(complex c0, complex c1);
complex complexDiv(complex c0, complex c1);

complex toPolar(complex c0);
complex toPlane(complex c0);

complex complexPolarMul(complex c0, complex c1);
complex complexPolarDiv(complex c0, complex c1);

complex deMoivre(complex c, double p);
complex roots(complex c, unsigned int k, unsigned int n);

#endif