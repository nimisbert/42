module Main where
import Graphics.Rendering.Chart.Easy
import Graphics.Rendering.Chart.Backend.Cairo

main :: IO()
main = toFile def "./plots/problem11.png" $ do
    layout_title .= "Maximum Power Transfer"
    setColors [ opaque red, opaque blue ]
    plot (line "Power" [zip ratios (map (/maximum p) p)])
    plot (line "Efficiency" [zip ratios (map (/maximum eta) eta)])
    where 
        rs = 1.0
        rl :: [Float]
        rl = [0.01,(0.02)..5.0]
        v0 = 5.0
        ratios = [loadR/rs | loadR<-rl]
        p  = [ ((1/(rs + loadR))**2)*loadR | loadR<-rl ]
        eta = [ (1/(1+(rs/loadR))) | loadR<-rl ]

-- + - rs - + -
-- |        |
-- v0       rl
-- |        |
-- + - -- - + -

-- P = U*I
-- I = U/rs
-- P_rl = (v_rl)^2 / rs
-- given rs = rl -> v_rl = v0/2
-- P_rl = (v0/2)^2 / rs