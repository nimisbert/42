module Polynomials (
    BasicPolynomial(..)
  , computePolynomial
  , computeRoots
  , completingTheSquare
) where

data BasicPolynomial = 
    Quadratic Float Float Float                 -- f(x) = a*x^2 + b*x + c 
  | QuadraticSquareComplement Float Float Float -- f(x) = p*(x + q)^2 + r 
  | Cubic Float Float Float Float               -- f(x) = a*x^3 + b*x^2 + c*x + d
  deriving(Show)

computePolynomial :: BasicPolynomial -> Float -> Float 
computePolynomial (Quadratic a b c) x = a*x^2 + b*x + c
computePolynomial (QuadraticSquareComplement p q r) x = p*(x+q)^2 + r
computePolynomial (Cubic a b c d) x = a*x^3 + b*x^2 + c*x + d 

computeRoots :: BasicPolynomial -> Maybe (Float, Float)
computeRoots (Quadratic a b c) 
  | delta >  0 = return ( x0 , x1 )
  | otherwise  = Nothing
  where 
    delta = b^2 - 4*a*c
    x0 = (-b - sqrt( delta )) / (2*a)
    x1 = (-b + sqrt( delta )) / (2*a)

completingTheSquare :: BasicPolynomial -> BasicPolynomial
completingTheSquare (Quadratic a b c) = 
  let q = b / (2*a) in 
  QuadraticSquareComplement a q (c - q^2)