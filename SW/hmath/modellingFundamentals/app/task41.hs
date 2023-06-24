module Main where
import Graphics.Rendering.Chart.Easy
import Graphics.Rendering.Chart.Backend.Cairo

main = toFile def "./plots/task41.png" $ do
    layout_title .= "Exponential Growth"
    setColors [ opaque blue, opaque red, opaque orange, opaque cyan, opaque magenta ]
    plot (line "rate=0.0" [ growth00 [0,(0.5).. 5] ])
    plot (line "rate=0.5" [ growth05 [0,(0.5).. 5] ])
    plot (line "rate=1.0" [ growth10 [0,(0.5).. 5] ])
    plot (line "rate=1.5" [ growth15 [0,(0.5).. 5] ])
    plot (line "rate=2.0" [ growth20 [0,(0.5).. 5] ])
    where
        recursiveGrowth :: Float -> Float -> Float -> Float
        recursiveGrowth l t n0 = (l**t)*n0
        growth00 xs = [ (t, recursiveGrowth 0.0 t 20.0) | t <- xs ]
        growth05 xs = [ (t, recursiveGrowth 0.5 t 20.0) | t <- xs ]
        growth10 xs = [ (t, recursiveGrowth 1.0 t 20.0) | t <- xs ]
        growth15 xs = [ (t, recursiveGrowth 1.5 t 20.0) | t <- xs ]
        growth20 xs = [ (t, recursiveGrowth 2.0 t 20.0) | t <- xs ]