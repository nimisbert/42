module ProjectEuler (
    problem1
) where

problem1 :: Integer -> Integer
problem1 m = 
    sum [ x | x <- [1 .. m], x `mod` 3 == 0 || x `mod` 5 == 0 ]