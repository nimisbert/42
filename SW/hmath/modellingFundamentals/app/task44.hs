module Main where
import Graphics.Rendering.Chart.Easy
import Graphics.Rendering.Chart.Backend.Cairo

import Model
import Solver

main :: IO()
main = toFile def "./plots/task44.png" $ do
  layout_title .= "Exponential Growth"
  setColors [ opaque blue, opaque red, opaque green ]
  plot (line "Analytic"   [growthAnalytic [0.0,0.1 .. 50.0]])
  plot (points "Runge Kutta 1" (growthRK1 [0.0,0.5 .. 50.0]))
  plot (points "Runge Kutta 4" (growthRK4 [0.0,0.5 .. 50.0]))
  where 
    growthAnalytic ts = [ (t, exponentialGrowth 100.0 (-0.1) t) | t <-ts ]
    growthRK1 ts = zip ts (rk1 (differencialGrowth (-0.1)) 100.0 ts)
    growthRK4 ts = zip ts (rk4 (differencialGrowth (-0.1)) 100.0 ts)