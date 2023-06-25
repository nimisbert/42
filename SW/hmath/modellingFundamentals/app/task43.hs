module Main where 
import Graphics.Rendering.Chart.Easy
import Graphics.Rendering.Chart.Backend.Cairo
import Model

main :: IO ()
main = toFile def "./plots/task43.png" $ do
  layout_title .= "Exponential Growth"
  setColors [ opaque blue, opaque red, opaque green ]
  plot (line "rate=-0.1" [growthMinus01 [0.0,0.1 .. 2.0]])
  plot (line "rate=+0.1" [growthPlus01  [0.0,0.1 .. 2.0]])
  plot (line "rate=+1.0" [growthPlus10  [0.0,0.1 .. 2.0]])
  where 
    growthMinus01 ts = [ (t, exponentialGrowth 5 (-0.1) t) | t <- ts ] 
    growthPlus01  ts = [ (t, exponentialGrowth 5 (0.1) t) | t <- ts ]
    growthPlus10  ts = [ (t, exponentialGrowth 5 (1.0) t) | t <- ts ]
     
