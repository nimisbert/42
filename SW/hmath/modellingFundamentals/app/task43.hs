module Main where 

import Graphics.Gloss
import Model
import Plot

myWindow :: Display
myWindow = InWindow "Plots" (800,600) (800,600)

main :: IO ()
main = display myWindow white . pictures $ [
          color black $ Line [ (0,-300), (0,300) ]
        , color black $ Line [ (-400,0), (400,0) ]
        , color red   $ plotFunction (exponentialGrowth 5 (-0.1)) [0.0,1.0 .. 100.0]
        , color blue  $ plotFunction (exponentialGrowth 5   0.1 ) [0.0,1.0 .. 100.0]
        , color green $ plotFunction (exponentialGrowth 5   1.0 ) [0.0,1.0 .. 100.0]
    ]