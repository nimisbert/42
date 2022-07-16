#include <spiegel10.h>

double distanceBetweenPoints(double x1, double y1, double x2, double y2)
{
    return sqrt(pow(x2-x1,2) + pow(y2-y1,2));
}

double slopeBetweenPoints(double x1, double y1, double x2, double y2)
{
    return (y2 - y1)/(x2 - x1);
}

double* lineBetweenPoints(double x1, double y1, double x2, double y2)
{
    static double s[2]; //s[0] == b ; s[1] == m
    s[1] = slopeBetweenPoints(x1,y1,x2,y2);
    s[0] = y1 - s[1]*x1;
    return s;
}

