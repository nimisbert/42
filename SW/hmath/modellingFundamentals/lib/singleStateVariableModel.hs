module SingleStateVariableModel () where 

-- Discrete Difference Growth Model
growthIterative :: Float -> Float -> Float -> Float 
growthIterative nt lambda t = lambda * nt

growthRecursive :: Float -> Float -> Float -> Float
growthRecursive n0 lambda t = (lambda**t) * n0

-- Continuous Differencial Model
growthExponential :: Float -> Float -> Float -> Float
growthExponential n0 r t = n0*exp(r*t)

growthLogistic :: Float -> Float -> Float -> Float -> Float -> Float
growthLogistic nt k n0 r t = k / (1 + ((k-n0)/n0)*exp(-r*t))

-- Numerical Approximation
growthEulerApproximation :: (Float -> Float) -> Float -> Float -> Float -> Float
growthEulerApproximation n r t dt = n(t) + r*n(t)*dt

-- Root Min Square Error
rmse :: [Float] -> [Float] -> Float 
rmse p a =
    sqrt( (1/n) * sum( map (**2) $ zipWith (-) p a ) )
    where 
        n = fromIntegral $ length p