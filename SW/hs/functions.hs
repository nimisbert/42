-- if then else binding
in_range_num min max x =
    if x >= min && x <= max then 
        True
    else 
        False 

testInRangeTrue = in_range_num 0 2 1
testInRangeFalse = in_range_num 0 2 3

-- let binding  
in_range_int :: Integer -> Integer -> Integer -> Bool
in_range_int min max x =
    let in_lower_bound = min <= x
        in_upper_bound = max >= x
    in 
        in_lower_bound && in_upper_bound

testIntInRangeTrue = in_range_int 0 5 3
testIntInRangeFalse = in_range_int 0 5 6

-- where binding
in_range_flt :: Float -> Float -> Float -> Bool
in_range_flt min max x = in_lower_bound && in_upper_bound
    where
        in_lower_bound = min <= x
        in_upper_bound = max >= x

testFltInRangeTrue = in_range_flt 0.1 0.4 0.3
testFltInRangeFalse = in_range_flt 0.1 0.4 (-0.4)

-- recursion

-- guards |
-- otherwise == constant always evaluates to True
fac n 
    | n <= 1 = 1
    | otherwise = n * fac (n-1)

-- pattern matching
facp 0 = 1
facp 1 = 1
facp n = n * fac (n-1)

-- accumulator (tail recursive)
fact n = aux n 1
    where 
        aux n acc
         | n <= 1 = acc
         | otherwise = aux (n-1) (n*acc)