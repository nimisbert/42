module Main where

import Graphics.Gloss
import Plot 

window :: Display
window = InWindow "Plots" (800,600) (20,20)

main :: IO ()
main = display window white .scale 20 20 . pictures $ [
          color black $ Line [ (0, -20), (0, 20) ]
        , color black $ Line [ (-20, 0), (20, 0) ]
        , color red   $ plotFunction f [ -20.0, -19.9 .. 20.0 ]
        , color blue  $ plotFunction g [ -20.0, -19.9 .. 20.0 ]
        , color green $ plotFunction h [ -20.0, -19.9 .. 20.0 ]
    ]
    where
        f :: Float -> Float
        f x = x^2

        g :: Float -> Float 
        g x = -x^2

        h :: Float -> Float 
        h x = sin( x )