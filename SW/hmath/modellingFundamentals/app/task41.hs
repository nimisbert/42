module Main where

import Graphics.Gloss

plotFunction :: (Float -> Float) -> [Float] -> Picture
plotFunction f x = pictures $ map Line datapoints
    where
        datapoints = [zip x $ map f x]

growthRecursive :: Float -> Float -> Float -> Float 
growthRecursive n0 lambda t = (lambda**t)*n0

myWindow :: Display 
myWindow = InWindow "Plots" (800,600) (20,20)
myWindow2 :: Display 
myWindow2 = InWindow "Plots" (800,600) (20,20)

main :: IO ()
main = display myWindow white . scale 50 50 . pictures $ [
          color black $ Line [ (0,-20), (0,20) ]
        , color black $ Line [ (-20,0), (20,0) ]
        , color red        $ plotFunction growthModel0  [0.0, 0.5 .. 25.0 ]
        , color blue       $ plotFunction growthModel05 [0.0, 0.5 .. 25.0 ]
        , color green      $ plotFunction growthModel1  [0.0, 0.5 .. 25.0 ]
        , color cyan       $ plotFunction growthModel15 [0.0, 0.5 .. 25.0 ]
        , color magenta    $ plotFunction growthModel20 [0.0, 0.5 .. 25.0 ]
    ]
    where 
        growthModel0 :: Float -> Float
        growthModel0 t = growthRecursive 2 0.0 t
        growthModel05 :: Float -> Float 
        growthModel05 t = growthRecursive 2 0.5 t
        growthModel1 :: Float -> Float 
        growthModel1 t = growthRecursive 2 1.0 t
        growthModel15 :: Float -> Float 
        growthModel15 t = growthRecursive 2 1.5 t
        growthModel20 :: Float -> Float 
        growthModel20 t = growthRecursive 2 2.0 t