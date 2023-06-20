module Model (
-- Exponential Growth Model
      differencialGrowth
    , exponentialGrowth
-- Logistic Growth Model 
    , differencialLogistic
    , logisticGrowth
) where 

-- Continuous Differential Exponential Model
differencialGrowth :: Float -> Float -> Float -> Float 
differencialGrowth r t n = r*n
-- Continuous Differential Exponential Model : Analytical Solution
exponentialGrowth :: Float -> Float -> Float -> Float
exponentialGrowth n0 r t = n0*exp(r*t)

-- Continuous Differential Logistic Model
differencialLogistic :: Float -> Float -> Float -> Float -> Float
differencialLogistic r k t n = r*n*(1-(n/k))
-- Continuous Differential Logistic Model : Analytical Solution 
logisticGrowth :: Float -> Float -> Float -> Float -> Float
logisticGrowth n0 k r t = k / (1 + ((k-n0)/n0)*exp(-r*t))