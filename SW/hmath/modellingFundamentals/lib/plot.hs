module Plot (
      plotFunction
    , glossPlot
    , dotGrid
    , dotToCircle
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

dotGrid :: (Float, Float) -> (Float, Float) -> Float -> [Picture]
dotGrid (x0, y0) (x1, y1) s = 
    map dotToCircle positions
    where 
    positions = [ (x,y) | x<-[x0, x0+s .. x1], y<-[y0, y0+s .. y1] ]
dotToCircle :: (Float, Float) -> Picture
dotToCircle (x, y) = 
    color (makeColor r g b a) $ translate x y $ circleSolid 0.1 
    where 
        r = 0.0
        g = 0.0
        b = 0.0
        a = 1.0