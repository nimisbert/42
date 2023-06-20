module Main where 

import Graphics.Gloss
import Model 
import Solver 
import Plot

myWindow :: Display
myWindow = InWindow "Plots" (800,600) (200,200)

main :: IO()
main = display myWindow white . scale 5 15 . pictures $ [
          color black $ Line [ (0,-300), (0,300) ]
        , color black $ Line [ (-300,0), (300,0) ]
        , glossPlot [0.0,1.0 .. 100.0] (map (logisticGrowth 2.0 10.0 0.2) [0.0,1.0 .. 100.0]) red 
        , glossPlot [0.0,1.0 .. 100.0] (rk4 (differencialLogistic 0.2 10.0) 2.0 [0.0,1.0 .. 100.0]) green
    ]