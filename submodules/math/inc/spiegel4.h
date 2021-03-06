#ifndef SPIEGEL_SECTION_4
#define SPIEGEL_SECTION_4
/** 
 * GEOMETRIC
 * FORMULAS
 */ 
#define GET_MACRO(_1,_2,_3,NAME,...) NAME

/**
 * @brief Rectangle Area formula 
 * f(a,b) = a*b
 * @param a 
 * @param b 
 * @return double 
 */
double rectangleArea(double a, double b);

/**
 * @brief Rectangle Perimeter formula 
 * f(a,b) = 2*a + 2*b
 * @param a 
 * @param b 
 * @return double 
 */
double rectanglePerimeter(double a, double b);

/**
 * @brief Parallelogram Area formula
 * f(h,b) = h*b
 * @param h 
 * @param b 
 * @return double 
 */
double parallelogramArea(double h, double b);
/**
 * @brief Parallelogram Perimeter formula
 * f(h,b) = 2*h + 2*b
 * @param a 
 * @param b 
 * @return double 
 */
double parallelogramPerimeter(double a, double b);

double triangleAreaHB(double h, double b); //height, base triangle area function
double triangleAreaABC(double a, double b, double c);
#define triangleAreaHb(a,b) triangleAreaHB(a,b) //height, base triangle area MACRO to be selected
#define triangleAreaAbc(a,b,c) triangleAreaABC(a,b,c)
/**
 * @brief Triangle Area formula
 * Function-like Macro using Selector Macro GET_MACRO
 * given (h,b)   : A = h*b*0.5
 * given (a,b,c) : A = sqrt( s * (s-a) * (s-b) * (s-c))
 * s = 0.5*(a+b+c)
 */
#define triangleArea(...) GET_MACRO(__VA_ARGS__, triangleAreaAbc, triangleAreaHb)(__VA_ARGS__)

/**
 * @brief Triangle Perimeter formula
 * f(a,b,c) = a+b+c
 * @param a 
 * @param b 
 * @param c 
 * @return double 
 */
double trianglePerimeter(double a, double b, double c);

/**
 * @brief Trapezoid Area formula 
 * f(a,b,c) = (a+b) * h/2
 * @param a 
 * @param b 
 * @param h 
 * @return double 
 */
double trapezoidArea(double a, double b, double h);
/**
 * @brief Trapezoid Perimeter formula
 * f(a,b,h,theta,phi) = a + b + h(1/sin(theta) + 1/sin(phi))
 * a is lower base, b is upper base
 * @param a 
 * @param b 
 * @param h 
 * @param theta 
 * @param phi 
 * @return double 
 */
double trapezoidPerimeter(double a, double b, double h, double theta, double phi);

/**
 * @brief Regular Polygon Area formula, of n sides each of length b
 * f(b,n) = (1/4) * n * b^2 * cos(pi/n)/sin(pi/n)
 * @param b 
 * @param n 
 * @return double 
 */
double regularPolygonArea(double b, unsigned int n);

/**
 * @brief Regular Polygon Perimter formula
 * f(b,n) = n*b
 * @param b 
 * @param n 
 * @return double 
 */
double regularPolygonPerimeter(double b, unsigned int n);

double circleArea(double r); //
double circlePerimeter(double r); //

double sectorArea(double r, double theta); //
double sectorArc(double r, double theta); //

double circleRadiusInscribedInTriangle(double a, double b, double c); //
double circleRadiusCircumscribingTriangle(double a, double b, double c); //

double regularPolygonAreaInscribedInCircle(double r, unsigned int n); //
double regularPolygonPerimeterInscibedInCircle(double r, unsigned int n); //

double regularPolygonAreaCircumscribingCircle(double r, unsigned int n);
double regularPolygonPerimeterCircumscribingCircle(double r, unsigned int n);

double segmentOuterAreaOfCircle(double r, double theta);

//a major, b minor
double ellipseArea(double a, double b);
double ellipsePerimeterRawApproximation(double a, double b);
double ellipsePerimeterIntegralApproximation(double a, double b, unsigned int nstep);

double parabolaArea(double a, double b);
double parabolaArcLength(double a, double b);

double rectangularParallelepipedVolume(double a, double b, double c);
double rectangularParallelepipedSurfaceArea(double a, double b, double c);

//to do abstraction
double parallelepipedVolumeABCT(double a, double b, double c, double theta);
double parallelepipedVolumeAh(double A, double h);

double sphereVolume(double r);
double sphereSurfaceArea(double r);

double cylinderVolume(double r, double h);
double cylinderLateralSurfaceArea(double r, double h);

double slantCylinderVolumeRL(double r, double l);
double slantCylinderVolumeRHT(double r, double h, double theta);
double slantCylinderLateralSurfaceAreaRL(double r, double l);
double slantCylinderLateralSurfaceAreaRHT(double r, double h, double theta);

double slantTubeVolumeAL(double A, double l);
double slantTubeVolumeAHT(double A, double h, double theta);
double slantTubeLateralSurfaceAreaPL(double p, double l);
double slantTubeLateralSurfaceAreaPHT(double p, double h, double theta);

double coneVolume(double r, double h);
double coneLateralSurfaceArea(double r, double l);

double pyramidVolume(double A, double h);

double sphericalCapVolume(double r, double h);
double sphericalCapSurfaceArea(double r, double h);

double frustrumVolume(double a, double b, double h);
double frustrumLateralSurfaceArea(double a, double b, double h);

double sphericalTriangleArea(double A, double B, double C, double r);

double torusVolume(double a, double b);
double torusSurfaceArea(double a, double b);

double ellipsoidVolume(double a, double b, double c);
double parapoloidVolume(double a, double b);

typedef double (*fptr) (double x); // f(x)
double integralComposite(double a, double b, fptr f, unsigned int n);
#endif