-- Exercice 2.3 : Algebraic Fractions 
-- Q1 

q1a :: Fractional a => a -> a
q1a x = (x / 3) + (x / 4)
a1a :: Fractional a => a -> a 
a1a x = (7*x / 12)

q1b :: Fractional a => a -> a 
q1b t = (2 / t) + (13 / t^2)
a1b :: Fractional a => a -> a
a1b t = (2*t + 13) / (t^2)

q1c :: Fractional a => a -> a -> a 
q1c p q = (1 / (2*p)) - (1 / (5*q))
a1c :: Fractional a => a -> a -> a 
a1c p q = (5*q - 2*p) / (10*p*q)

q1d :: Fractional a => a -> a -> a -> a
q1d a b c = (a*b / c) + (b*c / a) + (c*a / b)
a1d :: Fractional a => a -> a -> a -> a 
a1d a b c = ((a^2)*(b^2) + (b^2)*(c^2) + (c^2)*(a^2)) / (a*b*c)

q1e :: Fractional a => a -> a -> a
q1e m n = (2 / (m*n)) - ((3*m)/n) + ((n^2)/m)
a1e :: Fractional a => a -> a -> a
a1e m n = (2*m*n - 3*(m^3)*n + m*(n^4)) / ((m^2)*(n^2))

q1f :: Fractional a => a -> a -> a 
q1f a b = (2 / (a*b^3)) - (9 / ((a^3)*b))
a1f :: Fractional a => a -> a -> a 
a1f a b = (2*(a^3)*b - 9*a*(b^3)) / ((a^4)*(b^4))

q1g :: Fractional a => a -> a -> a
q1g x y = (1 / x) + ((2*x) / y) + (4 / (x^2))
a1g :: Fractional a => a -> a -> a 
a1g x y = (y*(x^2) + 2*(x^4) + 4*x*y) / ((x^3)*y)

q1h :: Fractional a => a -> a -> a 
q1h a b = 2 + (a^2 / b) - ((2*b) / a^2)
a1h :: Fractional a => a -> a -> a 
a1h a b = (2*(a^2)*b + a^4 - 2*b^2) / (a^2 * b)

-- Q2 

q2a :: Fractional a => a -> a
q2a y = (5 / (y-1)) + (3 / (y-2))
a2a :: Fractional a => a -> a 
a2a y = (8*y - 13) / ((y-1)*(y-2))

q2b :: Fractional a => a -> a
q2b r = (7 / (r-5)) - (4 / (r+3))
a2b :: Fractional a => a -> a 
a2b r = (3*r + 41) / ((r-5)*(r+3))

q2c :: Fractional a => a -> a 
q2c p = (8 / p)-(1 / (p-3))
a2c :: Fractional a => a -> a 
a2c p = (7*p - 24) / ((p^2) - 3*p)

q2d :: Fractional a => a -> a 
q2d w = (w / (2*(w-2))) + (3*w / (w-7))
a2d :: Fractional a => a -> a 
a2d w = ((7*w^2) - 19*w) / (2*(w-2)*(w-7))

q2e :: Fractional a => a -> a 
q2e z = ((z+1)/(z+2))-((z+3)/(z+4))
a2e :: Fractional a => a -> a 
a2e z = -2 / ((z+2)*(z+4))

q2f :: Fractional a => a -> a 
q2f q = (1/ (q+1)) + (3 / (q-2))
a2f :: Fractional a => a -> a 
a2f q = (4*q + 1) / ((q+1)*(q-2))

q2g :: Fractional a => a -> a -> a 
q2g x z = (x / (x+z)) + (2*z / (x-z))
a2g :: Fractional a => a -> a -> a
a2g x z = ((x^2) + x*z + 2*(z^2)) / ((x+z)*(x-z))

q2h :: Fractional a => a -> a -> a 
q2h x y = (y / (2*x + 3)) - (2*y / (3-x))
a2h :: Fractional a => a -> a -> a
a2h x y = (-3*y - 5*x*y) / ((2*x+3)*(3-x))

-- Q3 

q3a :: Fractional a => a -> a 
q3a x = (2*x + 10) / 6
a3a :: Fractional a => a -> a
a3a x = (1*x + 5) / 3

q3b :: Fractional a => a -> a -> a -> a
q3b a b c = (6*a - 12*b - 15*c) / 3
a3b :: Fractional a => a -> a -> a -> a 
a3b a b c = 2*a - 4*b - 5*c  

q3c :: Fractional a => a -> a -> a 
q3c n p = (n*(p^2) - 2*(n^2)*p) / (n*p)
a3c :: Fractional a => a -> a -> a 
a3c n p = (p - 2*n)

q3d :: Fractional a => a -> a -> a 
q3d s t = (4*s*t + 6*(s^2)*t + 9*(s^3)*t) / (2*t)
a3d :: Fractional a => a -> a -> a 
a3d s t = (s/2) * (4 + 6*s + 9*s^2)

q3e :: Fractional a => a -> a -> a 
q3e y z = (10*y*z^3 - 40*(y^3)*(z^3) + 60*(y^2)*(z^3)) / (10*z^2)
a3e :: Fractional a => a -> a -> a
a3e y z = y*z*(1 + 6*y - 4*y^2)

q3f :: Fractional a => a -> a -> a -> a
q3f c d e = (12*c*d - 6*(c^2)*d + 3*(c^3)*(d^2)) / (12*(c^2)*d*e)
a3f :: Fractional a => a -> a -> a -> a 
a3f c d e = (4 - 2*c + (c^2)*d) / (4*c*e)

q3g :: Fractional a => a -> a -> a
q3g x y = (2*x + (x^2)*y - x^2) / ((x^2) + 3*x)
a3g :: Fractional a => a -> a -> a 
a3g x y = (2 + (y-1)*x) / (x+3)

q3h :: Fractional a => a -> a -> a 
q3h g h = (4*(g^2) - 4*(h^2)) / ((g^2) + g*h)
a3h :: Fractional a => a -> a -> a 
a3h g h = 4 * (g-h) / g