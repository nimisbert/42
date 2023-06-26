module Basics (

) where

import Data.Complex

frequencyRange :: Float -> (Float, String)
frequencyRange f 
    | 30e9  < f && f < 300e9 = (lambda, "EHF : Extremely High Frequency")
    | 3e9   < f && f < 30e9  = (lambda, "SHF : Super High Frequency")
    | 300e6 < f && f < 3e9   = (lambda, "UHF : Ultra High Frequency")
    | 30e6  < f && f < 300e6 = (lambda, "VHF : Very High Frequency")
    | 3e6   < f && f < 30e6  = (lambda, "HF : High Frequency")
    | 300e3 < f && f < 3e6   = (lambda, "MF : Medium Frequency")
    | 30e3  < f && f < 300e3 = (lambda, "LF : Low Frequency")
    | f < 30e3               = (lambda, "VLF : Very Low Frequency") 
    | otherwise              = (lambda, "Out of radio-frequencies ranges")
    where 
        lambda = 1/f

-- z : Impedance
-- y : Admittance

zL w l = 0 :+ w*l 
yL w l = 1 / (0 :+ w*l) 

zC w c = 1/ (0 :+ w*c) 
yC w c = 0 :+ w*c

zR r = r :+ 0.0
yR r = 1/r :+ 0.0