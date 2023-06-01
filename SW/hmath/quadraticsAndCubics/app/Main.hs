module Main (main) where
import Graphics.Gloss
import Lib

graph :: (Float -> Float) -> (Float, Float, Float, Float) -> Float -> Picture
graph f (l, r, b, t) dx = pictures $ map Line visible
    where
        points :: [(Float, Float)]
        points = [(x, f x) | x <- [l,l+dx..r]]

        pairs :: [[(Float, Float)]]
        pairs = zipWith (\x y -> [x,y]) points $ tail points

        visible :: [[(Float, Float)]]
        visible = filter (all (\(_,y) -> b <= y && t >= y)) $ pairs

main :: IO ()
main = display FullScreen white . scale 20 20 . pictures $ [
        color blue $ graph f (-10, 10, -10, 10) 0.001,
        color black $ Line [(0, -10), (0, 10)],
        color black $ Line [(-10, 0), (10, 0)]
    ]
    where
        f :: Float -> Float
        f x = 1 / (x - 1)