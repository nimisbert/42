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
        , glossPlot [0.0,1.0 .. 100.0] (map (exponentialGrowth 20.0 (-0.1)) [0.0,1.0 .. 100.0]) red 
        , glossPlot [0.0,1.0 .. 100.0] (rk1 (differencialGrowth (-0.1)) 20.0 [0.0,1.0 .. 100.0]) blue
        , glossPlot [0.0,1.0 .. 100.0] (rk4 (differencialGrowth (-0.1)) 20.0 [0.0,1.0 .. 100.0]) green
--        , color blue  $ pictures $ map Line $ [zip [0.0,1.0 .. 100.0] (rk1 (differencialGrowth (-0.1)) 20.0 [0.0,1.0 .. 100.0])]
--        , color green $ pictures $ map Line $ [zip [0.0,1.0 .. 100.0] (rk4 (differencialGrowth (-0.1)) 20.0 [0.0,1.0 .. 100.0])]
    ]