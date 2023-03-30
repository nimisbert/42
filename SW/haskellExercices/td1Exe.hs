-- 1
-- [] -- cree liste elements de type a
-- :  -- ajoute un element en tete de liste
-- ++ -- ajoute une liste a une autre
-- .. -- creer une lista allant du premier argument jusqu au second
testAddToHead = 1:[2]                 -- [1, 2]
testAppend    = [3,4] ++ [1, 2]       -- [3,4,1,2]
testFromTo    = [3..10]               -- [3,4,5,6,7,8,9,10]
testTail      = tail [1..4] ++ 5:[]   -- [2,3,4,5]
testHead      = head [1..4] : [5]     -- [1,5]
testReverse   = reverse [1..4] ++ [5] -- [4,3,2,1,5]

-- 2 
-- head     -- get head from list 
-- tail     -- get tail from list
-- reverse  -- reverses a list
-- length   -- get length list
-- drop     -- from the n first element of a list
-- take     -- take the n first element from a list
-- !!       -- returns the n-th element from a list from [0 to n-1]
myGetLast0 :: [a] -> a
myGetLast0 (x:xs) = (x:xs) !! (length xs)

myGetLast1 :: [a] -> a
myGetLast1 (x:xs) = head (reverse (x:xs))

myGetInit0 :: [a] -> [a]
myGetInit0 (x:xs) = take (length xs) (x:xs)

myGetInit1 :: [a] -> [a]
myGetInit1 (x:xs) = reverse (drop 1 (reverse (x:xs)))

-- 3 
palindrome :: Eq a => [a] -> Bool
palindrome (x:xs) = (x:xs) == (reverse (x:xs))

-- 4 
-- $ == operateur application
f1 :: (Num a) => a -> a
f1 x = x +1

f2 :: (Num a) => a -> a -> a 
f2 x y = x + y

g :: (Num a) => a -> a -> a 
g x y = x - y

fg33 :: (Num a) => a -> a -> a
fg33 y z = f2 (g y z) 33

foo8g4423 = 8 * (g 44 23)

foo8pi3312 = f1 8 * pi * (33 + 21)

-- 5 
-- :t ['a','b','c']                 -- ['a','b','c'] :: [Char]
-- :t ('a','b','c')                 -- ('a','b','c') :: (Char, Char, Char)
-- :t [(False, '0') , (True , '1')] -- [(False, '0') , (True , '1')] :: [(Bool, Char)]
-- :t [tail, init, reverse]         -- [tail, init, reverse] :: [[a] -> [a]]

-- 6 

-- 7 

