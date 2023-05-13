-- 4.
-- where ... binding, example 
-- spans across guards
myBmi :: (RealFloat a) => a -> a -> String        -- function that takes two Real floating point value and returns a String 
myBmi weight height                               -- considering a weight and a height
    | bmi <= 18.5 = "underweight"                 -- a bmi less than ...
    | bmi <= 25.0 = "within range"                -- a bmi above but still less than ...
    | bmi <= 30.0 = "overweight"                  -- etc.
    | otherwise   = "..."                         -- default condition
    where bmi = weight / height ^ 2               -- such as bmi is defined as the equation for the bmi

myBmiEx0 = myBmi 58 1.78

myBmis :: (RealFloat a) => [(a, a)] -> [a]        -- function that takes two Real floating point values and returns a Real floating point value
myBmis xs = [bmi w h | (w, h) <- xs]              -- computes a list of bmi with w h such as w, h are the tuples of the input list
    where bmi weight height = weight / height ^ 2 -- such as bmi is defined as the equation for the bmi

myBmisEx0 = myBmis [(58, 1.78), (59, 1.78), (60, 1.78)]

-- let ... in ... binding, example
-- does not span across guards
-- can be cramed everywhere just like if ... then ... else ...
myCylinderSurfaceArea :: (RealFloat a) => a -> a -> a -- function that takes two Real floating point values and returns a Real floating point value
myCylinderSurfaceArea r h =                           -- considering a value r (radius) and h (height)
    let sideArea = 2 * pi * r * h                     -- let sideArea be 2 * pi * r * h
        topArea = pi * r ^ 2                          -- let topArea be pi * r ^ 2
    in sideArea + 2 * topArea                         -- in  sideArea + 2 * topArea

myCylinderSurfaceAreaEx0 = myCylinderSurfaceArea 2 3

-- case ... of ... , example
myDescribeList :: [a] -> String
myDescribeList xs = "The list is " ++ case xs of [] -> "an empty list."
                                                 [x] -> "a singleton list."
                                                 xs -> "a longer list."

myDescribeListEx0 = myDescribeList [1, 2, 3]