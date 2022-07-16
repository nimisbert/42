#ifndef SPIEGEL_SECTION_10
#define SPIEGEL_SECTION_10
/** 
 * Formulas from Plane 
 * Analytic Geometry
 */

#include <math.h>
#include <stdio.h>

double distanceBetweenPoints(double x1, double y1, double x2, double y2);
double slopeBetweenPoints(double x1, double y1, double x2, double y2);

double* lineBetweenPoints(double x1, double y1, double x2, double y2);

double  angleBetweenLines(double* line1, double* line2);


#endif