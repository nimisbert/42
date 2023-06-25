module Main where 
import Graphics.Rendering.Chart.Easy
import Graphics.Rendering.Chart.Backend.Cairo

import Model 
import Solver 

-- TODO

main :: IO()
main = toFile def "./plots/task47.png" $ do 
      layout_title .= "Gordon Schaefer"
      setColors [opaque red, opaque blue]
--      plot (line "Y*" [yStar])
      plot (line "Y*" [underfishedN])
      plot (line "N*" [underfishedY])
      where
-- Task 4.7 : Yield in relation to the fishing effort
            yStar = [ (q, equilibriumYieldSchaefer 0.1 100.0 (0.001*q)) | q<-[0.0,1.0 .. 100.0] ]
-- Task 4.8 : Population Growth, Harvesting rate and Population density
            biologicalGrowths = [0.0, 0.001 .. 0.08 ]
--            underfishedN = [ (r, equilibriumPopSchaefer r 100.0 (0.001*2.0) ) | r<-biologicalGrowths  ]
--            underfishedY = [ (n, equilibriumYieldSchaeferFromPop (0.001*2) n) | n<-(map (snd) underfishedN) ]
