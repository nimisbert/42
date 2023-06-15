module Plot (
    plotFunction
) where

import Graphics.Gloss

plotFunction :: (Float -> Float) -> [Float] -> Picture
plotFunction f x = pictures $ map Line datapoints
    where 
        datapoints = [zip x $ map f x]