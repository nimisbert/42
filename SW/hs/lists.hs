import Data.List

mysum :: [Int] -> Int
mysum []     = 0
mysum (x:xs) = x + sum xs

testSumPatternMatchOnNullList = mysum []
testSumPatternMatch = mysum [1,2,3,4]

evens :: [Int] -> [Int]
evens [] = []
evens (x:xs)
    | mod x 2 == 0 = x:evens xs
    | otherwise    = evens xs

testEvens = evens [1,2,3,4]

-- Exercices
-- 1
myelem :: (Eq a) => a -> [a] -> Bool
myelem _ [] = False
myelem v (x:xs) 
    | v == x = True
    | v /= x = myelem v xs
testMyElem0 = myelem 4 [1,2,4,3,2]
testMyElem1 = myelem 4 []
-- s
solutionelem :: (Eq a) => a -> [a] -> Bool
solutionelem _ [] = False
solutionelem e (x:xs) = (e == x) || (elem e xs)

-- 2
mynub :: (Eq a) => [a] -> [a]
mynub [] = []
mynub (x:xs) =