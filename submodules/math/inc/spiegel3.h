#ifndef SPIEGEL_SECTION_3
#define SPIEGEL_SECTION_3
/**
 * THE BINOMIAL FORMULA
 * AND BINOMIAL COEFFICIENTS
 */

/**
 * @brief Factorial formula for positive integer n
 * 3.1 : f(n) = n!
 * @param n 
 * @return double 
 */
double factorial(unsigned int n);

/**
 * @brief Binomial formula for positive integer n
 * 3.2 : f(x,y,n) = (x+y)^n
 * @param x 
 * @param y 
 * @param n 
 * @return double 
 */
double binomial(double x, double y, unsigned int n);

/**
 * @brief Binomial coeficient formula for positive integer n
 * 3.5 : f(k,n) = n! / k! * (n-k)!
 * @param k 
 * @param n 
 * @return double 
 */
double binomialCoeficient(double k, double n);

/**
 * @brief Multinomial formula for p
 * f(n, p, x1, x2, x3, ..., xp) = (x1 + x2 + x3 + ... + xp)^n
 * @param n 
 * @param p 
 * @param ... 
 * @return double 
 */
double multinomial(unsigned int n, unsigned int p, ...);

#endif