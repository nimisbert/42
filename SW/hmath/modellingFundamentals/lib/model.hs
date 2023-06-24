module Model (
-- Exponential Growth Model
      differencialGrowth
    , exponentialGrowth
-- Logistic Growth Model 
    , differencialLogistic
    , logisticGrowth
-- Schaffer Growth Model 
    , equilibriumYieldSchaefer
    , equilibriumPopSchaefer
    , equilibriumYieldSchaeferFromPop
) where 

-- Single State Variable Models

-- Exponential Model : Differencial Equation (dN(t)/dt)
differencialGrowth :: Float -> Float -> Float -> Float 
differencialGrowth r t n = r*n
-- Exponential Model : Analytical Solution (N(t))
exponentialGrowth :: Float -> Float -> Float -> Float
exponentialGrowth n0 r t = n0*exp(r*t)

-- Logistic Model : Differencial Equation (dN(t)/dt)
differencialLogistic :: Float -> Float -> Float -> Float -> Float
differencialLogistic r k t n = r*n*(1-(n/k))
-- Logistic Model : Analytical Solution (N(t))
logisticGrowth :: Float -> Float -> Float -> Float -> Float
logisticGrowth n0 k r t = k / (1 + ((k-n0)/n0)*exp(-r*t))

-- Schaffer Model : Differencial Equation (dN(t)/dt)
differencialSchaefer :: Float -> Float -> Float -> Float -> Float 
differencialSchaefer r k f n = r*n * (1 - n/k) - f*n
-- Schaffer Population size at equilibrium (N*)
equilibriumPopSchaefer :: Float -> Float -> Float -> Float
equilibriumPopSchaefer r k f = k * (1 - f/r)
-- Schaffer Population harvest yield at equilibrium (Y*)
equilibriumYieldSchaefer :: Float -> Float -> Float -> Float 
equilibriumYieldSchaefer r k f = f*k * (1 - f/r)
equilibriumYieldSchaeferFromPop :: Float -> Float -> Float 
equilibriumYieldSchaeferFromPop f n = f*n