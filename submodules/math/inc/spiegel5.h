#ifndef SPIEGEL_SECTION_5
#define SPIEGEL_SECTION_5
/** 
 * TRIGONOMETRIC
 * FUNCTIONS
 */

double toRad(double deg);
double toDeg(double rad);

double cot(double rad);
double sec(double rad);
double csc(double rad);

unsigned char planeLawOfSines(double a, double b, double c, double A, double B, double C);
unsigned char planeLawOfCosines(double a, double b, double c, double C);
unsigned char planeLawOfTangentsABab(double a, double b, double A, double B);
unsigned char planeLawOfTangentsAabc(double A, double a, double b, double c);

#endif