#include <stdio.h>
#include <math.h>
#include <spiegel5.h>

double toRad(double deg)
{
    return (M_PI/180)*deg;
}
double toDeg(double rad)
{
    return (180/M_PI)*rad;
}

double cot(double rad)
{
    return 1/tan(rad);
}
double sec(double rad)
{
    return 1/cos(rad);
}
double csc(double rad)
{
    return 1/sin(rad);
}

unsigned char planeLawOfSines(double a, double b, double c, double A, double B, double C)
{
    if(a/sin(A) == b/sin(B))
        if(b/sin(B) == c/sin(C))
            return 1;
    return 0;
}

unsigned char planeLawOfCosines(double a, double b, double c, double C)
{
    double le = c*c;
    double re = a*a + b*b - 2*a*b*cos(C);
    if(abs(re-le) == 0.0)
        return 1;
    return 0;
}

unsigned char planeLawOfTangentsABab(double a, double b, double A, double B)
{
    if(a-b != 0.0)
    {
        double leftM = (a+b)/(a-b);
        double rightM= tan(0.5*(A+B))/tan(0.5*(A+B));
        printf("left %lf\r\n",leftM);
        printf("right %lf\r\n",rightM);
        if(leftM-rightM == 0.0)
            return 1;
        return 0;
    }
    return 2; //unconclusive if a == b, use Aabc formula
}

unsigned char planeLawOfTangentsAabc(double A, double a, double b, double c)
{
    double s = 0.5*(a+b+c);
    if((2/(b*c))*sqrt(s*(s-a)*(s-b)*(s-c)) - sin(A) == 0.0)
        return 1;
    return 0;
}