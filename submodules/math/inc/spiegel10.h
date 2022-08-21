#ifndef SPIEGEL_SECTION_10
#define SPIEGEL_SECTION_10
/** 
 * Formulas from Plane 
 * Analytic Geometry
 */

#include <math.h>
#include <stdio.h>

typedef struct p{
    double x;
    double y;
    double r;
    double theta;
}point;

typedef struct l{
    double b;
    double m;
}line;

double distanceBetweenPoints(double x1, double y1, double x2, double y2);
double slopeBetweenPoints(double x1, double y1, double x2, double y2);

line lineBetweenPoints(double x1, double y1, double x2, double y2);

double angleBetweenLines(line line1, line line2);

double triangleAreaFromVertices(point v1, point v2, point v3);

point pointTransformPureTranslation(point p, double x0, double y0);

point pointTransformPureRotation(point p, double alpha);

point pointTransform(point p, double x0, double y0, double alpha);

point toPolar(point p);

unsigned char pIsOnCirclePlanar(point p, double x0, double y0, double R);
unsigned char pIsOnCirclePolar(point p, double R, double alpha);
unsigned char pIsOnConics(point p, double epsilon, double theta, double d);

#endif