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
mynub (x:xs) 
    | solutionelem x xs = mynub xs
    | otherwise = x:mynub xs
-- s 
solutionnub :: (Eq a) => [a] -> [a]
solutionnub [] = []
solutionnub (x:xs)
    | x `elem` xs = nub xs
    | otherwise = x : nub xs

-- 3
myIsAsc :: [Int] -> Bool
myIsAsc [] = False
myIsAsc (x:xs) 
    | null xs = True
    | x > head xs = False
    | otherwise = myIsAsc xs
-- s
sIsAsc :: [Int] -> Bool
sIsAsc [] = True
sIsAsc [x] = True
sIsAsc (x:y:xs) = 
    (x <= y) && sIsAsc (y:xs)

-- 4 
-- List  : [(1,2), (2,3), (3,2), (4,3), (4,5)]
-- Graph : 1 -> 2 <-> 3 <- 4 -> 5
myHasPath :: [(Int,Int)] -> Int -> Int -> Bool
myHasPath [] b e = False -- 
myHasPath (x:xs) b e
    | b == e = True -- bof...
    | fst x == b = hasPath xs fst x e
    | otherwise = False

testGraph = [(1,2), (2,3), (3,2), (4,3), (4,5)]
-- s
-- Start a starting node
-- Take all reachable nodes
-- Delete edges looked at
-- Start new search for reachable nodes looked at
hasPath :: [(Int, Int)] -> Int -> Int -> Bool
hasPath [] x y = x == y
hasPath xs x y
    | x == y = True 
    | otherwise = 
        let xs' = [ (n,m) | (n,m) <- xs, n /= x ] in -- xs' tuple from xs so that n is not x
        or [ hasPath xs' m y | (n,m) <- xs, n == x]  --