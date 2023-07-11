module Plots (
) where 

import Graphics.Gloss
import Linear.V2

data Model = Model {
      _abscissa :: (V2 Int, V2 Int)
    , _ordinate :: (V2 Int, V2 Int)
}

handlePlot :: Model -> Picture
handlePlot (Model ((ax0, ay0), (ax1, ay1)) ((ox0, oy0) (ox1, oy1))) = 
    Pictures [
          color white $ Line [(ax0, ay0), (ax1, ay1)]
        , color white $ Line [(ox0, oy0), (ox1, oy1)]
    ]

handleEvent :: Event -> Model -> Model 
handleEvent (EventResize (x, y)) m = m { 
          _abscissa = (V2 0 0, V2 x y)
        , _ordinate = (V2 0 0, V2 y x)
    }

handleTime :: Float -> Model -> Model 
handleTime dt m =
    let (V2 )