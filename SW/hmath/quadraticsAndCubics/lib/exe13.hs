module Exe13() where 
import Polynomials

-- Q1 
q1a :: Float -> Float 
q1a x = computePolynomial (QuadraticSquareComplement 1 4 (-25)) x
a1a :: (Float, Float)
a1a = (1, (-9))

q1b :: Float -> Float 
q1b x = (2*x + 5)^2 - 9
a1b :: (Float, Float)
a1b = (-1, -4) 

q1c :: Float -> Float 
q1c x = (5*x - 3)^2 - 21
a1c :: (Float, Float)
a1c = ((3+sqrt(21))/5, (3-sqrt(21))/5)

q1d :: Float -> Float 
q1d x = (3*x - 1)^2 - 32
a1d :: (Float, Float)
a1d = ((1+4*sqrt(2))/3, (1-4*sqrt(2))/3)

-- Q2 
q2a :: BasicPolynomial
q2a = (Quadratic 1 6 8)
a2a :: BasicPolynomial
a2a = completingTheSquare q2a

q2b :: BasicPolynomial
q2b = (Quadratic 1 8 (-10))
a2b :: BasicPolynomial
a2b = completingTheSquare q2b

q2c :: BasicPolynomial
q2c = (Quadratic 1 (-3) (-10))
a2c :: BasicPolynomial
a2c = completingTheSquare q2c 

q2d :: BasicPolynomial
q2d = (Quadratic 1 (-20) 15)
a2d :: BasicPolynomial
a2d = completingTheSquare q2d 

q2e :: BasicPolynomial
q2e = (Quadratic 1 9 (-2))
a2e :: BasicPolynomial
a2e = completingTheSquare q2e 

q2h :: Float -> Float -> BasicPolynomial
q2h r s = (Quadratic 1 (6*r) s)
a2h :: Float -> Float -> BasicPolynomial
a2h r s = (QuadraticSquareComplement 1 (3*r) (s - 9*r^2))

q2f :: BasicPolynomial
q2f = (Quadratic 1 (-5) 7)
a2f :: BasicPolynomial
a2f = completingTheSquare q2f 

q2g :: Float -> Float -> BasicPolynomial
q2g m n = (Quadratic 1 (-2*m) n)
a2g :: Float -> Float -> BasicPolynomial
a2g m n = (QuadraticSquareComplement 1 (-m) (n-m^2))

-- Q3 
q3a :: BasicPolynomial
q3a = (Quadratic 1 (-6) (-16))
a3a :: Maybe (Float, Float)
a3a = computeRoots q3a 

q3b :: BasicPolynomial
q3b = (Quadratic 1 4 (-8))
a3b :: Maybe (Float, Float)
a3b = computeRoots q3b

q3c :: BasicPolynomial
q3c = (Quadratic 1 (-4) 3)
a3c :: Maybe (Float, Float)
a3c = computeRoots q3c 

q3d :: BasicPolynomial
q3d = (Quadratic 1 (-10) 24)
a3d :: Maybe (Float, Float)
a3d = computeRoots q3d 

q3e :: BasicPolynomial
q3e = (Quadratic 1 (-10) (-200))
a3e :: Maybe (Float, Float)
a3e = computeRoots q3e 

q3f :: Float -> BasicPolynomial
q3f k = (Quadratic 1 2 k)
a3f :: Float -> (Float, Float)
a3f k = (-1-sqrt(k+1), -1+sqrt(k+1))

q3g :: BasicPolynomial
q3g = (Quadratic 1 3 2)
a3g :: Maybe (Float, Float)
a3g = computeRoots q3g 