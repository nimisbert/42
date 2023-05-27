-- Exercice 2.1 : Distribution
-- Q1 
q1a :: Int -> Int
q1a x = 5 * (x + 4)
a1a :: Int -> Int 
a1a x = 5 * x + 20

q1b :: Int -> Int -> Int 
q1b a b = a * (4 - 2*b)
a1b :: Int -> Int -> Int 
a1b a b = a * 4 - 2 * a * b

q1c :: Int -> Int -> Int 
q1c x y = - 2 * ( x^2 + y )
a1c :: Int -> Int -> Int 
a1c x y = - 2 * x^2 - 2 * y

q1d :: Int -> Int -> Int 
q1d m n = 6 * m * n * (m + 1)
a1d :: Int -> Int -> Int 
a1d m n = 6 * m^2 * n + 6 * m * n

q1e :: Int -> Int -> Int 
q1e h t = -4*h*t*(t^2 - 2*h*t - 3*h^3 ) 
a1e :: Int -> Int -> Int 
a1e h t = -4*h*(t^3) + 8*(h^2)*(t^2) + 12*(h^4)*t

q1f :: Int -> Int 
q1f z = 7*(z^2)*(2 + z)
a1f :: Int -> Int 
a1f z = 14*(z^2) + 7*(z^3)

q1g :: Int -> Int 
q1g x = 4 * (x + 2) + 3*(x - 5)
a1g :: Int -> Int 
a1g x = 7*x - 7

q1h :: Int -> Int -> Int 
q1h p q = p * (3*p^2 - 2*q) + (q + 4*p^3)
a1h :: Int -> Int -> Int 
a1h p q = - 2*p*q + q + 7*p^3

q1i :: Int -> Int -> Int -> Int 
q1i x y z = 7*x*y * (x^2 + z^2)
a1i :: Int -> Int -> Int -> Int
a1i x y z = 7*(x^3)*y + 7*x*y*z^2

q1j :: Int -> Int 
q1j x = x * (2*x + 3) - 3*x^2
a1j :: Int -> Int 
a1j x = 3*x - x^2

q1k :: Int -> Int -> Int 
q1k s t = s*t*(t - s) - s*(5 + t^2)
a1k :: Int -> Int -> Int 
a1k s t = s*t^2 - (s^2)*t - 5*s - s*t^2

q1l :: Int -> Int -> Int 
q1l x y = 2*x*(2 + 3*x*y) - x*y*(5*x + 4)
a1l :: Int -> Int -> Int 
a1l x y = 4*x + (x^2)*y - 4*x*y

-- Q2 
q2a :: Int -> Int
q2a x = (x + 5)*(x - 3)
a2a :: Int -> Int 
a2a x = x^2 + 2*x - 15

q2b :: Int -> Int
q2b z = (2*z + 3)*(3*z - 2)
a2b :: Int -> Int 
a2b z = 6*z^2 + 5*z - 6

q2c :: Int -> Int 
q2c u = (u + 8)^2
a2c :: Int -> Int 
a2c u = u^2 + 16*u + 64

q2d :: Int -> Int -> Int -> Int -> Int
q2d a b c d = (a*b + c*d) * (a*c + b*d) 
a2d :: Int -> Int -> Int -> Int -> Int
a2d a b c d = (a^2)*b*c + a*(b^2)*d + a*(c^2)*d + b*c*d^2

q2e :: Int -> Int -> Int 
q2e f g = (10 + f)*(2*f^2 - 3*g)
a2e :: Int -> Int -> Int 
a2e f g = 20*f^2 - 30*g + 2*f^3 - 3*f*g

q2f :: Int -> Int 
q2f q = (7 + q)*(7 - q)
a2f :: Int -> Int 
a2f q = 49 - q^2

q2g :: Int -> Int 
q2g w = (2 - 3*w)^2
a2g :: Int -> Int 
a2g w = 4 - 12*w + 9*w^2

q2h :: Int -> Int -> Int 
q2h r s = (4*r*s^2 + 3)^2
a2h :: Int -> Int -> Int 
a2h r s = 16*(r^2)*(s^4) + 24*r*s^2 + 9

q2i :: Int -> Int -> Int -> Int 
q2i k l n = (5*(k^2)*l - 2*k*n)^2
a2i :: Int -> Int -> Int -> Int 
a2i k l n = 25*(k^4)*(l^2) - 20*(k^3)*l*n + 4*(k^2)*(n^2)

q2j :: Int -> Int -> Int 
q2j g h = (3*g*h + 2*h)*(3*g*h - 4)
a2j :: Int -> Int -> Int 
a2j g h = 9*(g^2)*(h^2) - 12*g*h + 6*g*(h^2) - 8*h

q2k :: Int -> Int -> Int
q2k y z = (2*y*z + 7)*(7*y - 2*z)
a2k :: Int -> Int -> Int 
a2k y z = 14*(y^2)*z - 4*y*(z^2) + 49*y - 14*z

q2l :: Int -> Int
q2l c = (5*(c^2) - c)*((c^2) + 4*c)
a2l :: Int -> Int 
a2l c = 5*(c^4) + 19*(c^3) - 4*(c^2)

-- Q3 
q3a :: Int -> Int 
q3a l = (l + 5)*(l^2 + 2*l +3)
a3a :: Int -> Int 
a3a l = l^3 + 7*l^2 + 13*l +15

q3b :: Int -> Int 
q3b q = (2 + q)*(3 - q + 4*q^2)
a3b :: Int -> Int 
a3b q = 4*q^3 + 7*q^2 + q + 6

q3c :: Int -> Int 
q3c m = (m + 1)*(m + 2)*(m - 4)
a3c :: Int -> Int 
a3c m = m^3 - m^2 - 10*m - 8

q3d :: Int -> Int -> Int 
q3d r s = (r + s)^3
a3d :: Int -> Int -> Int 
a3d r s = r^3 + 2*(r^2)*s + r*(s^2) + (r^2)*s + 2*r*(s^2) + s^3

q3e :: Int -> Int -> Int 
q3e x y = (4 + x + y)*(1 - x - y)
a3e :: Int -> Int -> Int 
a3e x y = - x^2 - y^2 - 2*x*y - 3*x - 3*y + 4

q3f :: Int -> Int -> Int 
q3f c d = (2*c^2 - c*d + d)*(2*d -c -5*c^2)
a3f :: Int -> Int -> Int  
a3f c d = - 2*c^3 - 10*c^4 - 2*c*d^2 + 5*(c^3)*d + 2*d^2 - c*d

q3g :: Int -> Int -> Int 
q3g x y = ((2*x - 3*y)^2)*(x*y + 4*y)
a3g :: Int -> Int -> Int 
a3g x y = 4*(x^3)*y - 12*(x^2)*(y^2) + 9*x*(y^3) + 16*(x^2)*y - 48*x*(y^2) + 36*y^3

-- Q4 
carole :: Int -> Int 
carole x = x^2

mark :: Int -> Int 
mark x = (x+3) * (x*2 + 1)

deltaArea :: Int -> Int 
deltaArea x = x^2 + 7*x + 3