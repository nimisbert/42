module Solver (
      rk1
    , rk4
) where 

-- 1st Order Runge-Kutta, Euler Method
rk1 :: Num a => (a -> a -> a) -> a -> [a] -> [a]
rk1 f yn [] = []
rk1 f yn (x:xs) = yn:rk1 f ynn xs 
    where
        h = abs $ head xs - x
        ynn = yn + h*f x yn

-- 4th Order Runge-Kutta
rk4 :: Num a => (a -> a -> a) -> a -> [a] -> [a]
rk4 f yn [] = []
rk4 f yn (x:xs) = yn:rk4 f ynn xs
    where 
        h   = abs $ head xs - x 
        k1  = h * f x yn 
        k2  = h * f (x+(h/2)) (yn + k1/2)
        k3  = h * f (x+(h/2)) (yn + k2/2)
        k4  = h * f (x+h) (yn + k3)
        ynn = yn + (1/6) * (k1 + 2*k2 + 2*k3 + k4)