module Main (main) where
-- Graphics Library
import Graphics.Rendering.Chart
import Graphics.Rendering.Chart.Easy
import Graphics.Rendering.Chart.Grid()
import Graphics.Rendering.Chart.Backend.Diagrams(toFile)
-- Own Library
import ProjectEuler

x :: [Integer]
x = [1, 2 .. 999]

s :: [(Integer, Integer)]
s = zip x $ map problem1 x

main :: IO()
main = 
    toFile def "charts/ProjectEulerProblem1.png" $ do
    layout_title .= "Sum of multiples of 3 or 5"
    setColors [opaque blue, opaque red]
    plot (line   "Analytical" [s])
    plot (points "Numerical"  (s))  