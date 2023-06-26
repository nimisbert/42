module Main where

import Model
import Solver

main :: IO()
main = toFile def "./plots/task51.png" $ do
    layout_title .= "Ricker Growth"
    setColors [ opaque blue ]
    plot (line "Ricker" [])
    where
        ricker0M = ricker 2 0.001
        ricker0P n0 ts = [] 

