module Main (main) where
-- Graphics Library
import Graphics.Rendering.Chart.Easy
import Graphics.Rendering.Chart.Backend.Diagrams(toFile)
-- Own Library
import Models.LotkaVolterra

deers :: Population
deers = VerhulstParameters 10 30 0.2

time :: [Float]
time  = [0.0, 1.0 .. 100.0]

populationCount :: [Float]
populationCount = map (logisticEquation deers) time

timeSerie = zip time populationCount

main :: IO()
main = toFile def "Logistic Equation.png" $ do
    layout_title .= "Deer population model"
    setColors [opaque blue, opaque red]
    plot (line "Deers" [timeSerie])
    plot (points "Data Points" (timeSerie))