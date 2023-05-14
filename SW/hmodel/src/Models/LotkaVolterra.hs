module Models.LotkaVolterra (
    Population(..)
  , logisticEquation
) where 

data Population = VerhulstParameters {
    headCount        :: Float -- N, P
  , carryingCapacity :: Float -- K
  , growthRate       :: Float -- r
} deriving (Show)

logisticEquation :: Population -> Float -> Float
logisticEquation (VerhulstParameters p0 k r) t = 
  k / (1 + ((k-p0) / p0) * exp( - r * t ))