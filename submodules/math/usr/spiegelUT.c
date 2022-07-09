#include <stdio.h>
#include <spiegel3.h>
#include <spiegel4.h>

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
    
    return 0;
}