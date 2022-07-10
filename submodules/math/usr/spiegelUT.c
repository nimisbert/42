#include <math.h>
#include <stdio.h>
#include <spiegel3.h>
#include <spiegel4.h>

double fooUT(double x)
{
    return x*x;
}

int main(int argc, char* argv[])
{
    printf("factorial %d! = 1 : %lf\r\n",0,factorial(0));
    printf("factorial %d! = 6 : %lf\r\n",3,factorial(3));
    printf("factorial %d! = 6 : %lf\r\n",6,factorial(6));
    printf("binomial (%lf + %lf)^%d = %lf\r\n",1.0,2.0,3,binomial(1,2,3));
    printf("binomial (%lf + %lf)^%d = %lf\r\n",1.0,2.0,0.0,binomial(1,2,0));
    printf("binomial (%lf + %lf)^%d = %lf\r\n",-1.0,-2.0,5,binomial(-1,-2,5));
    printf("binCoef (%d %d)t = %lf\r\n",9,10,binomialCoeficient(9,10));
    printf("multinomial (%lf + %lf + %lf + %lf)^%d = %lf\r\n",1.0,2.0,3.0,4.0,5,multinomial(5,4,1.0,2.0,3.0,4.0));
    printf("multinomial (%lf + %lf + %lf + %lf)^%d = %lf\r\n",-1.0,2.0,-3.0,-4.0,2,multinomial(2,4,-1.0,2.0,-3.0,-4.0));
    printf("Rect Area a = %lf, b = %lf : A = %lf\r\n",2.0,8.0,rectangleArea(2.0,8.0));
    printf("Rect Perimeter a = %lf, b = %lf : P = %lf\r\n",2.0,8.0,rectanglePerimeter(2.0,8.0));
    printf("Parallelo Area h = %lf, b = %lf : A = %lf\r\n",2.0,8.0,parallelogramArea(2.0,8.0));
    printf("Parallelo Perimeter a = %lf, b = %lf : P = %lf\r\n",2.0,8.0,parallelogramPerimeter(2.0,8.0));
    printf("Triangle Area h = %lf , b = %lf : A = %lf\r\n",6.062,7.0,triangleArea(6.062,7.0));
    printf("Triangle Area a = %lf , b = %lf, c = %lf : A = %lf\r\n",7.0,7.0,7.0,triangleArea(7.0,7.0,7.0));
    printf("Triangle Perimeter a = %lf, b = %lf, c = %lf : P = %lf\r\n",2.0,2.0,2.0,trianglePerimeter(2.0,2.0,2.0));
    printf("Trapezoid Area a = %lf, b = %lf, h = %lf : A = %lf\r\n",3.0,2.0,1.0,trapezoidArea(3.0,2.0,1.0));
    printf("Trapezoid Perimeter a = %lf, b = %lf, h = %lf, theta = %lf, phi = %lf : P = %lf\r\n",3.0,2.0,1.0,0.5236,0.5236,trapezoidPerimeter(3.0,2.0,1.0,0.5236,0.5236));
    printf("Regular Polygon Area b = %lf, n = %d : A = %lf\r\n",2.0, 5, regularPolygonArea(2.0,5));
    printf("Regular Polygon Perimeter b = %lf, n = %d : P = %lf\r\n",2.0, 5, regularPolygonPerimeter(2.0,5));
    printf("Circle Area r = %lf : A = %lf \r\n",2.0,circleArea(2.0));
    printf("Circle Perimeter r = %lf : P = %lf \r\n",2.0,circlePerimeter(2.0));
    printf("Sector Area r = %lf, theta = %lf : A = %lf \r\n",2.0, 6.28,sectorArea(2.0,6.28318531));
    printf("Sector Arc r = %lf, theta = %lf : P = %lf \r\n",2.0,6.28,sectorArc(2.0,6.28318531));
    printf("Circle Radius Inscribed in Triangle a = %lf, b = %lf, c = %lf : r = %lf \r\n",2.0,2.0,2.0,circleRadiusInscribedInTriangle(2.0,2.0,2.0));
    printf("Circle Radius Circumscribed of Triangle a = %lf, b = %lf, c = %lf : r = %lf \r\n",2.0,2.0,2.0,circleRadiusCircumscribingTriangle(2.0,2.0,2.0));
    printf("Regular polygon area Inscribed in circle r = %lf, n = %d : A = %lf\r\n",2.0,5,regularPolygonAreaInscribedInCircle(2.0,5));
    printf("Regular polygon perimeter Inscribed in circle r = %lf, n = %d : P = %lf\r\n",2.0,5,regularPolygonPerimeterInscibedInCircle(2.0,5));
    printf("Regular polygon area Circumscribing a circle r = %lf, n = %d : A = %lf\r\n",2.0,5,regularPolygonAreaCircumscribingCircle(2.0,5));
    printf("Regular polygon perimter Circumscribing a circle r = %lf, n = %d : P = %lf\r\n",2.0,5,regularPolygonPerimeterCircumscribingCircle(2.0,5));
    printf("Segment Area between two radiuses r = %lf, theta = %lf : A = %lf\r\n",2.0,M_PI/5,segmentOuterAreaOfCircle(2.0,M_PI/5));
    printf("Ellipse Area a = %lf, b = %lf : A = %lf\r\n",2.0,1.0,ellipseArea(2.0,1.0));
    printf("Ellipse Perimeter raw approx a = %lf, b = %lf : P = %lf\r\n",2.0,1.0,ellipsePerimeterRawApproximation(2.0,1.0));
    printf("Integral numerical approximation of x^2 by composite rule %lf \r\n",integralComposite(0.0, 2.0, fooUT, 1000));
    printf("Integral of x^2 analytical result (1/3 * x^3) for reference = %lf \r\n",(1.0/3)*2.0*2.0*2.0);
    printf("Ellipse Perimeter raw approx a = %lf, b = %lf, s = %d : P = %lf\r\n",2.0,1.0,1000,ellipsePerimeterIntegralApproximation(2.0,1.0,10000));
    printf("Parabola Area a = %lf, b = %lf : A = %lf\r\n",2.0,4.0,parabolaArea(2.0,4.0));
    printf("Parabola Arc length a = %lf, b = %lf : P = %lf\r\n",2.0,4.0,parabolaArcLength(2.0,4.0));
    printf("Rectangular parallelepiped volume a = %lf, b = %lf, c = %lf : V = %lf \r\n",2.0,2.0,2.0,rectangularParallelepipedVolume(2.0,2.0,2.0));
    printf("Rectangular parallelepiped surface area a = %lf, b = %lf, c = %lf : SA = %lf \r\n",2.0,2.0,2.0,rectangularParallelepipedSurfaceArea(2.0,2.0,2.0));
    printf("Parallelepiped volume a = %lf, b = %lf, c = %lf, theta = %lf : V = %lf \r\n",2.0,2.0,2.0,M_PI/3,parallelepipedVolumeABCT(2.0,2.0,2.0,M_PI/3));
    printf("Parallelepiped volume A = %lf, h = %lf : V = %lf \r\n",4.0,2.0*sin(M_PI/3),parallelepipedVolumeAh(4.0,2.0*sin(M_PI/3)));
    printf("Sphere volume r = %lf : V = %lf\r\n",2.0,sphereVolume(2.0));
    printf("Sphere surface area r = %lf : SA = %lf\r\n",2.0,sphereSurfaceArea(2.0));
    printf("Cylinder volume r = %lf, h = %lf : V = %lf\r\n",2.0,2.0,cylinderVolume(2.0,4.0));
    printf("Cylinder lateral surface area r = %lf, h = %lf : LSA = %lf\r\n",2.0,2.0,cylinderLateralSurfaceArea(2.0,4.0));
    return 0;
}