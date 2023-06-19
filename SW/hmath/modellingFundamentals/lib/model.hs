module Model (
    exponentialGrowth
) where 

-- Continuous Differencial Model
differencialGrowth :: Float -> Float -> Float -> Float 
differencialGrowth n r = r*n
-- Continuous Differencial Model : Analytical Solution
exponentialGrowth :: Float -> Float -> Float -> Float
exponentialGrowth n0 r t = n0*exp(r*t)
