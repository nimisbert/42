module Quadratics (
) where

data Quadratic = Quadratic Float Float Float deriving(Show)

computeQuadratic :: Quadratic -> Float -> Float 
computeQuadratic (Quadratic a b c) x = a * x^2 + b * x + c