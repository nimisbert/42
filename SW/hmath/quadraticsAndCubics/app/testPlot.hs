module Main where

import Graphics.Gloss
import Linear.V2
import Plot 

main :: IO ()
main = do
    let window = InWindow "Proto" (800, 600) (0, 0) 
        bgcolor = black
        fps = 30
        model = Model 10 10 [red, blue, green] $ [[(t, f t) | t <- [-20.0,-19.0 .. 20.0]]] ++ [[(t, g t) | t <- [-20.0,-19.0 .. 20.0]]]
    play window bgcolor fps model handleDisplay handleEvent handleTime
    where
        f :: Float -> Float 
        f x = x**3.0
        g :: Float -> Float 
        g x = x**2.0