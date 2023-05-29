-- Exercice 3.1 : Laws of Indices
-- Q1 

q1a :: Int 
q1a = 10*10^4
a1a :: Int 
a1a = 10^5

q1b :: Floating a => a -> a  
q1b y = y**(-1) * y**(-2) * y**7
a1b :: Floating a => a -> a
a1b y = y**4

q1c :: Floating a => a
q1c = 5**(1/2) * 5**3 * 5**(-3/2)
a1c :: Floating a => a 
a1c = 5**2

q1d :: Floating a => a 
q1d = 6**5 / 6**2
a1d :: Floating a => a 
a1d = 6**3

q1e :: Floating a => a
q1e = 3**4 / 3**(-1)
a1e :: Floating a => a 
a1e = 3**5

q1f :: Floating a => a
q1f = 6**11 / 6
a1f :: Floating a => a
a1f = 6**10

q1g :: Floating a => a -> a 
q1g r = r**2 / r**6
a1g :: Floating a => a -> a 
a1g r = r**(-4)

q1h :: Floating a => a
q1h = (3**2)**3
a1h :: Floating a => a 
a1h = (3**6)

q1i :: Floating a => a -> a 
q1i k = (k**(-2))**5
a1i :: Floating a => a -> a 
a1i k = k**(-10)

q1j :: Floating a => a -> a 
q1j z = (z**4)**(-1/8)
a1j :: Floating a => a -> a 
a1j z = z**(-1/2)

q1k :: Floating a => a 
q1k = (8**(-6))**(-1/2)
a1k :: Floating a => a 
a1k = 8**3

q1l :: Floating a => a -> a -> a
q1l p q = (p**5)*(q**4) / ((p**4)*q)
a1l :: Floating a => a -> a -> a 
a1l p q = p * q**3 

q1m :: Floating a => a -> a -> a 
q1m c d = (c**(-1)) * (d**(-2)) / ((c**2) * (d**4))
a1m :: Floating a => a -> a -> a 
a1m c d = (c**(-3)) * (d**(-6))

q1n :: Floating a => a -> a -> a
q1n a b = (a*b**2)**2
a1n :: Floating a => a -> a -> a
a1n a b = (a**2)*(b**4)

q1o :: Floating a => a -> a -> a 
q1o y z = (12 * y * (z**(-1/2))) / (4*y*(z**(1/2)))
a1o :: Floating a => a -> a 
a1o z = 3*z**(-1)

q1p :: Floating a => a -> a -> a
q1p m n = (m*(n**(1/2)))**4
a1p :: Floating a => a -> a -> a 
a1p m n = (m**4)*(n**2)

-- Q2 
q2a :: Floating a => a
q2a = (4**(1/2)) * (4**(3/2))
a2a :: Floating a => a 
a2a = 16.0

q2b :: Floating a => a 
q2b = ((2**3)*2) / (2**5) 
a2b :: Floating a => a 
a2b = 0.5

q2c :: Floating a => a 
q2c = 7**5 * 7**3 / 7**6
a2c :: Floating a => a 
a2c = 49.0

q2d :: Floating a => a 
q2d = (3**2)**5 / (3**3)**3
a2d :: Floating a => a
a2d = 3

q2e :: Floating a => a 
q2e = (4**(-1/2))**2 * (4**(-3))**(-1/3)
a2e :: Floating a => a 
a2e = 1.0

q2f :: Floating a => a 
q2f = ((2**(1/2))**6 * (2**(-2))**(-2)) / ((2**(-1))**(-1))
a2f :: Floating a => a 
a2f = 64.0

q2g :: Floating a => a 
q2g = 1**0
a2g :: Floating a => a
a2g = 1.0

q2h :: Floating a => a 
q2h = (4/5)**0
a2h :: Floating a => a
a2h = 1.0 

q2i :: Floating a => a 
q2i = (-5.726324)**0
a2i :: Floating a => a
a2i = 1.0

-- Q3 

q3a :: Floating a => a -> a 
q3a p = 1/p
a3a :: Floating a => a -> a 
a3a p = 1**(-p)

q3b :: Floating a => a -> a 
q3b q = sqrt( q )
a3b :: Floating a => a -> a 
a3b q = q**(1/2)

q3c :: Floating a => a -> a 
q3c r = sqrt( r**3 )
a3c :: Floating a => a -> a 
a3c r = r**(3/2)

q3d :: Floating a => a -> a 
q3d s = s**(5/4)
a3d :: Floating a => a -> a 
a3d s = s**(5/4)

q3e :: Floating a => a -> a 
q3e t = 1 / (t**(1/3))
a3e :: Floating a => a -> a 
a3e t = t**(-1/3)

q3f :: Floating a => a -> a 
q3f x = (1/(x**(1/3)))**4
a3f :: Floating a => a -> a 
a3f x = x**(-4/3)

-- Q4 

q4a :: Floating a => a 
q4a = 9**(1/2)
a4a :: Floating a => a
a4a = 3 

q4b :: Floating a => a 
q4b = 8**(1/3)
a4b :: Floating a => a
a4b = 2

q4c :: Floating a => a 
q4c = 4**(3/2)
a4c :: Floating a => a 
a4c = 8

q4d :: Floating a => a
q4d = 27**(-1/3)
a4d :: Floating a => a 
a4d = 1/3

q4e :: Floating a => a 
q4e = 16**(-3/4)
a4e :: Floating a => a 
a4e = 8

-- Q5
q5pToq :: Floating a => a -> a
q5pToq q = (1/16)*(q**2)

q5a :: Floating a => a -> a
q5a p = p**(1/2)
a5a :: Floating a => a -> a 
a5a q = (1/4)*q

q5b :: Floating a => a -> a 
q5b p = 2*(p**(-1))
a5b :: Floating a => a -> a 
a5b q = 32/(q**2)

q5c :: Floating a => a -> a 
q5c p = (p**(1/2)) / (2*(p**(-1)))
a5c :: Floating a => a -> a 
a5c q = (1/128)*(q**3)

q5d :: Floating a => a -> a -> a
q5d p q = (p**2)*q
a5d :: Floating a => a -> a 
a5d q = (1/256)*(q**5)

q5e :: Floating a => a -> a -> a
q5e p q = (4*p)/(q**3)
a5e :: Floating a => a -> a 
a5e q = (1/4)*q

q5f :: Floating a => a -> a -> a
q5f p q = (q**2) / (4*p**2)
a5f :: Floating a => a -> a 
a5f q = 64/(q**2)

-- Q6 
q6a :: Floating a => a -> a 
q6a x = (4**x)
a6a :: Floating a => a
a6a = 1 

q6b :: Floating a => a -> a 
q6b x = 9**x
a6b :: Floating a => a
a6b = -1/2

q6c :: Floating a => a -> a 
q6c x = sqrt(5) * (5**x) 
a6c :: Floating a => a
a6c = -4

q6d :: Floating a => a -> a 
q6d x = (16**x)**2
a6d :: Floating a => a 
a6d = -1/4

q6e :: Floating a => a -> a 
q6e x = x**(-3)
a6e :: Floating a => a 
a6e = -1/2

q6f :: Floating a => a -> a 
q6f x = sqrt(100**x)
a6f :: Floating a => a 
a6f = -3