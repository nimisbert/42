module Plot (
      plotFunction
    , glossPlot
) where 

import Graphics.Gloss

plotFunction :: (Float -> Float) -> [Float] -> Picture
plotFunction f x = pictures $ map Line datapoints
    where
        datapoints = [zip x $ map f x]

glossPlot :: [Float] -> [Float] -> Color -> Picture
glossPlot x y c = color c $ pictures $ map Line datapoints
    where 
        datapoints = [zip x y]