module Main where 
import Graphics.Rendering.Chart.Easy
import Graphics.Rendering.Chart.Backend.Cairo

import Model 
import Solver 

main :: IO()
main = toFile def "./plots/task46.png" $ do
  layout_title .= "Logistic Growth"
  setColors [ opaque blue, opaque red, opaque green ] 
  plot (line "Analytic" [logisticAnalytic [0.0,0.1 .. 50.0]])
  plot (line "RK1" [logisticRK1 [0.0,0.1 .. 50.0]])
  plot (line "RK4" [logisticRK4 [0.0,0.1 .. 50.0]])
  where
    logisticAnalytic ts = [ (t, logisticGrowth 2.0 10.0 t 0.2) | t<-ts ]
    logisticRK1 ts = zip ts (rk1 (differencialLogistic 0.2 10.0) 2.0 ts)
    logisticRK4 ts = zip ts (rk4 (differencialLogistic 0.2 10.0) 2.0 ts)