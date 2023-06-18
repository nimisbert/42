-- Quadratic Formula 
module Exe12 () where 
import Polynomials

-- Q1 : Solve 
q1a :: Float -> Float 
q1a x = x^2 - 4*x + 2 
a1a :: Maybe (Float, Float)
a1a = computeRoots (Quadratic 1 (-4) 2)

q1b :: Float -> Float 
q1b x = x^2 - 2*x - 44
a1b :: Maybe (Float, Float)
a1b = computeRoots (Quadratic 1 (-2) (-44))

q1c :: Float -> Float 
q1c x = x^2 + 3*x - 12
a1c :: Maybe (Float, Float)
a1c = computeRoots (Quadratic 1 3 (-12))

q1d :: Float -> Float
q1d x = x^2 - 14*x + 42
a1d :: Maybe (Float, Float)
a1d = computeRoots (Quadratic 1 (-14) 42)

q1e :: Float -> Float 
q1e x = 4*x^2 + 4*x - 1
a1e :: Maybe (Float, Float)
a1e = computeRoots (Quadratic 4 4 (-1))

q1f :: Float -> Float 
q1f x = -x^2 + 4*x - 3
a1f :: Maybe (Float, Float)
a1f = computeRoots (Quadratic (-1) 4 (-3))

q1g :: Float -> Float 
q1g x = x^2 - (5/6)*x + (1/6)
a1g :: Maybe (Float, Float)
a1g = computeRoots (Quadratic 1 (-5/6) (1/6))

q1h :: Float -> Float 
q1h x = x^2 - x - 35/2
a1h :: Maybe (Float, Float)
a1h = computeRoots (Quadratic 1 (-1) (-35/2))

q1i :: Float -> Float
q1i x = x^2 - 2*sqrt(11)*x + 11
a1i :: Maybe (Float, Float)
a1i = computeRoots (Quadratic 1 (-2*sqrt 11) 11)

-- Q2 : 
q2a :: Float -> Float 
q2a x = (x - 2 + sqrt 5)*(x - 2 - sqrt 5)

a2a :: Float -> Float 
a2a x = x^2  - 4*x - 1

a2b :: Maybe (Float, Float)
a2b = computeRoots (Quadratic 1 (-4) (-1))

a2c :: Maybe (Float, Float)
a2c = a2b

-- Q3 : Solution a +/- sqrt(b), a, b integers, find a b
q3a :: Float -> Float 
q3a x = x^2 + 8*x + 13

a3a :: (Int, Int)
a3a = (-4, 3) -- (a, b)

-- Q4 : Solve 
q4a :: Float -> Float
q4a x = x^2 + x + (1/4)
a4a :: Maybe (Float, Float)
a4a = computeRoots (Quadratic 1 1 (1/4))

q4b :: Float -> Float 
q4b x = x^2 - (7/4)*x + (2/3)
a4b :: Maybe (Float, Float)
a4b = computeRoots (Quadratic 1 (-7/4) (2/3))

q4c :: Float -> Float
q4c x = 25*x^2 - 30*x + 7
a4c :: Maybe (Float, Float)
a4c = computeRoots (Quadratic 25 (-30) 7)

q4d :: Float -> Float
q4d x = 100*x^2 + 60*x - 2
a4d :: Maybe (Float, Float)
a4d = computeRoots (Quadratic 100 60 (-2))

q4e :: Float -> Float
q4e x = 2*x^2 - 5*x - 7
a4e :: Maybe (Float, Float)
a4e = computeRoots (Quadratic 2 (-5) (-7))

q4f :: Float -> Float
q4f x = 3*x^2 - 2*x - 8
a4f :: Maybe (Float, Float)
a4f = computeRoots (Quadratic 3 (-2) (-8))