-- Factorising Quadratics 
module Exe11 () where

-- Q1 : Factorise
q1a :: Float -> Float 
q1a x = x^2 - 6*x + 5 
a1a :: Float -> Float 
a1a x = (x - 5)*(x - 1)

q1b :: Float -> Float 
q1b x = x^2 - 3*x - 18
a1b :: Float -> Float 
a1b x = (x - 6)*(x + 3)

q1c :: Float -> Float 
q1c x = x^2 + 22*x + 121
a1c :: Float -> Float 
a1c x = (x + 11)*(x + 11)

q1d :: Float -> Float 
q1d x = x^2 - 12*x
a1d :: Float -> Float 
a1d x = x * (x - 12)

q1e :: Float -> Float 
q1e y = y^2 - 13*y + 42
a1e :: Float -> Float 
a1e y = (y - 7)*(y - 6)

q1f :: Float -> Float 
q1f x = x^2 + 51*x + 144
a1f :: Float -> Float 
a1f x = (x + 3)*(x + 48)

q1g :: Float -> Float 
q1g x = x^2 - 121
a1g :: Float -> Float 
a1g x = (x - 11)*(x + 11)

q1h :: Float -> Float 
q1h x = x^2 - 35*x + 66
a1h :: Float -> Float 
a1h x = (x - 2)*(x - 33)

-- Q2 : Factorise
q2a :: Float -> Float 
q2a x = 4*x^2 - 4*x - 3
a2a :: Float -> Float 
a2a x = (2*x + 1)*(2*x - 3)

q2b :: Float -> Float 
q2b x = 2*x^2 + 23*x + 11
a2b :: Float -> Float 
a2b x = (2*x + 1)*(2*x + 11)

q2c :: Float -> Float 
q2c x = 7*x^2 - 19*x -6
a2c :: Float -> Float 
a2c x = (7*x + 2)*(x - 3)

q2d :: Float -> Float 
q2d x = -x^2 - 5*x + 36
a2d :: Float -> Float 
a2d x = (-x + 4)*(x + 9)

q2e :: Float -> Float 
q2e x = 6*x^2 - 7*x - 3
a2e :: Float -> Float 
a2e x = (3*x + 1)*(2*x - 3)

q2f :: Float -> Float 
q2f x = 2*x^2 - 2
a2f :: Float -> Float 
a2f x = (2*x - 2)*(x + 1)

q2g :: Float -> Float 
q2g x = 3*x^2 - 3
a2g :: Float -> Float 
a2g x = (3*x - 3)*(x + 1)

q2h :: Float -> Float 
q2h x = -x^2 + 9*x - 14
a2h :: Float -> Float 
a2h x = (-x + 7)*(x - 2)

-- Q3 : Solve Equation 
q3a :: Float -> Float 
q3a x = x^2 - 2*x - 8
a3a :: (Float, Float)
a3a = (-2, 4)

q3b :: Float -> Float 
q3b x = 2*x^2 + 2*x - 40
a3b :: (Float, Float)
a3b = (-5, 4)

q3c :: Float -> Float 
q3c p = p^2 + 21*p + 38
a3c :: (Float, Float)
a3c = (-2, -19)

q3d :: Float -> Float 
q3d x = x^2 - 15*x + 54
a3d :: (Float, Float)
a3d = (6, 9)

q3e :: Float -> Float 
q3e x = x^2 + 18*x + 65
a3e :: (Float, Float)
a3e = (-13, -5)

q3f :: Float -> Float 
q3f x = x^2 - x - 42
a3f :: (Float, Float)
a3f = (-6, 7)

q3g :: Float -> Float 
q3g x = x^2 + 1100*x + 100000
a3g :: (Float, Float)
a3g = (-100, -1000)

q3h :: Float -> Float
q3h x = 3*x^2 - 3*x - 6
a3h :: (Float, Float)
a3h = (-1, 2)

q3i :: Float -> Float 
q3i x = 5*x^2 - 21*x + 4
a3i :: (Float, Float)
a3i = (1/5, 4)

-- Q4 : Solve Equation
q4a :: Float -> Float
q4a x = -5*x^2 - 22*x + 15
a4a :: (Float, Float)
a4a = (3/5, -5)

q4b :: Float -> Float 
q4b x = 32*x^2 + 60*x + 13
a4b :: (Float, Float)
a4b = (-1/4, -13/8)

q4c :: Float -> Float
q4c a = 5*a^2 + 12*a - 9
a4c :: (Float, Float)
a4c = (3/5, -3) 

q4d :: Float -> Float 
q4d x = 8*x^2 + 22*x + 15
a4d :: (Float, Float)
a4d = (-4/5, -2/3)

q4e :: Float -> Float 
q4e q = 4*q^2 - 11*q + 6
a4e :: (Float, Float)
a4e = (-3/4, -2)

q4f :: Float -> Float
q4f y = 24*y^2 + 23*y - 12
a4f :: (Float, Float)
a4f = (3/8, 3/4)

-- Q5 : Solve (x - 1)(x - 2) = 37 - x
q5a :: Float -> Float 
q5a x = x^2 - 2*x - 35
a5a :: (Float, Float)
a5a = (-5, 7)

-- Q6 : find x such that f(x) meets x-axis : f(x) = -x^2 + 7x + 30
q6a :: Float -> Float 
q6a x = -x^2 + 7*x + 30 
a6a :: (Float, Float)
a6a = (-10, 3)

-- Q7 : Solve 
q7a :: Float -> Float 
q7a h = -2*h^2 + 13*h - 20
a7a :: (Float, Float)
a7a = (5/2, 4)

-- Q8 : Factorise 
q8a :: Float -> Float -> Float 
q8a x y = x^2 + 6*x*y + 8*y^2
a8a :: Float -> Float -> Float 
a8a x y = (x + 2*y) * (x + 4*y)
