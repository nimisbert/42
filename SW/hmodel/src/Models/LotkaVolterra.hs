
data Population = VerhulstParameters {
    headCount        :: Float -- N, P
  , carryingCapacity :: Float -- K
  , growthRate       :: Float -- r
} deriving (Show)

logisticEquation :: Population -> Population
logisticEquation (VerhulstParameters p k r) = 
  (VerhulstParameters (p + r*p*(1-(p/k))) k r)

lotkaVolterraEquation :: Population -> Population -> Float -> Population
lotkaVolterraEquation (VerhulstParameters p1 k1 r1) (VerhulstParameters p2 k2 r2) alpha =
  (VerhulstParameters (p1 + r1*p1*(k1-p1-alpha*p2)/k1)) k1 r1