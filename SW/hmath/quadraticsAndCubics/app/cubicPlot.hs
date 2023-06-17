module Main where 

import Graphics.Gloss
import Polynomials
import Plot 

window :: Display
window = InWindow "Plots" (800,600) (20,20)

main :: IO()
main = display window white . scale 20 20 . pictures $ [
          color black $ Line [ (0,-20), (0,20) ]
        , color black $ Line [ (-20,0), (20,0) ]
        , color red   $ plotFunction f [-20.0, -19.9 .. 20.0]
    ]
    where 
        f :: Float -> Float 
        f x = computePolynomial (Cubic 2.0 (-3.0) (-3.0) 2.0) x