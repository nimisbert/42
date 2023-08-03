module Plot (
  Model(..)
  , handleDisplay
  , handleEvent
  , handleTime
) where 

import Graphics.Gloss
import Graphics.Gloss.Interface.Pure.Game
import Linear.V2

data Model = Model {
    _sx         :: Float
  , _sy         :: Float
  , _plotColors :: [Color]
  , _data       :: [[(Float,Float)]]
}

handleDisplay :: Model -> Picture
handleDisplay (Model sx sy plotColors dataPoints) = 
  Pictures $ zipWith (makePlot (sx, sy)) plotColors dataPoints
  ++ [color white $ Line [bottomLeft, bottomRight, topRight, topLeft, bottomLeft]]
  ++ [color white $ Line [(-sx*0.01,0), (sx*0.01,0)]]
  ++ [color white $ Line [(0,-sy*0.01), (0,sy*0.01)]]
  where 
    bottomLeft  = ((-sx/2)*0.9, (-sy/2)*0.9)
    bottomRight = ((-sx/2)*0.9, ( sy/2)*0.9)
    topRight    = (( sx/2)*0.9, ( sy/2)*0.9)
    topLeft     = (( sx/2)*0.9, (-sy/2)*0.9)

handleEvent :: Event -> Model -> Model 
handleEvent (EventResize (x, y)) (Model _ _ plotColors dataPoints) = Model { 
  _sx = fromIntegral x
  , _sy = fromIntegral y
  , _plotColors = plotColors
  , _data = dataPoints
}
handleEvent _ m = m

handleTime :: Float -> Model -> Model
handleTime dt m = m

makePlot :: (Float, Float) -> Color -> [(Float, Float)] -> Picture
makePlot scale c dataPoints = color c $ Line [((fst d / maxAbscissa)*(sx/2)*0.9, (snd d / maxOrdinate)*(sy/2)*0.9) | d<-dataPoints]
  where 
    sx = fst scale
    sy = snd scale
    maxOrdinate = maximum $ snd $ unzip dataPoints
    maxAbscissa = maximum $ fst $ unzip dataPoints