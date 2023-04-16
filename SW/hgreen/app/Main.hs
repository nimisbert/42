module Main (main) where
import Graphics.Gloss
import Lib

window :: Display
window = InWindow "Nice window" (200, 200) (10, 10)

background :: Color 
background = white

drawing :: Picture
drawing = circle 80

main :: IO ()
main = display window background drawing
