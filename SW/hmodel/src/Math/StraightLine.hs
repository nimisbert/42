module Math.StraightLine(
    lineFromPoints,
    segmentMidPoint,
    segmentLength,
) where 

-- 1. The Equation of a Straight Line

-- | (y - y1) - m(x - x1) = 0
lineFromPoints :: (Floating a) => (a, a) -> (a, a) -> ( a, (a, a))
lineFromPoints p1 p2 = ( (y2 - y1)/(x2 - x1), p1 )
    where 
        x1 = fst p1
        y1 = snd p1
        x2 = fst p2
        y2 = snd p2

segmentMidPoint :: (Floating a) => (a, a) -> (a, a) -> (a, a)
segmentMidPoint p1 p2 = 
    let x = (fst p1 + fst p2) / 2
        y = (snd p1 + snd p2) / 2
    in (x, y)

segmentLength :: (Floating a) => (a, a) -> (a, a) -> a 
segmentLength a b = 
    sqrt $ (xB - xA )^2 + (yB - yA)^2
    where 
        xA = fst a
        yA = snd a
        xB = fst b
        yB = snd b

-- Parallel equal gradients
-- Normal gradients multiply to give -1