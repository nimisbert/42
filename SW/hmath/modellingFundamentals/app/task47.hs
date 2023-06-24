module Main where 

import Graphics.Gloss
import Model 
import Solver 
import Plot

myWindow :: Display 
myWindow = InWindow "Plots" (800,600) (200,200)

main :: IO()
main = display myWindow white . scale 10 10 . pictures $ [
          color black $ Line [ (0,-300), (0,300) ]
        , color black $ Line [ (-300,0), (300,0) ]
        , glossPlot efforts yields green
        , glossPlot underfishedN rateLists blue -- meh
        , glossPlot overfishedN rateLists cyan -- meh
        , glossPlot underfishedY underfishedN red -- meh
        , glossPlot overfishedY overfishedN magenta -- meh
    ]
    where
-- Task 4.7 : Yield in relation to the fishing effort
      r  = 0.1                     -- fish population growth rate 
      efforts = [0.0,1.0 .. 100.0] -- fishing efforts
      k  = 100                     -- Carrying capacity of the environement
      q  = 0.001                   -- fishing effectiveness
      f  = map (q*) efforts        -- mortality from fishing pressure
      yields = map (equilibriumYieldSchaefer r k) f
-- Task 4.8 : Population growth, Harvesting rate and Population density
      rateLists = [0.0,0.1 .. 100.0]
      -- Underfished 
      underfishedN = map ($ q*50.0) (map ($ k) (map equilibriumPopSchaefer rateLists))
      underfishedY = map (equilibriumYieldSchaeferFromPop (q*50.0)) underfishedN
      -- Overfished
      overfishedN = map ($ q*150.0) (map ($ k) (map equilibriumPopSchaefer rateLists))
      overfishedY = map (equilibriumYieldSchaeferFromPop (q*150.0)) overfishedN