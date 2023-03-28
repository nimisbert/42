import Data.Foldable

mysum :: [Int] -> Int
mysum = foldr (+) 0

myand :: [Bool] -> Bool
myand = foldr (&&) True

myor :: [Bool] -> Bool
myor  = foldr (||) False

mycount e = foldr (\x acc -> if e == x then acc+1 else acc) 0

mylength :: Num a => [a] -> Int
mylength = foldr (\x -> (+) 1) 0

mymap f = foldr ((:) . f) []

--foldr (\acc elem)
--foldl (\elem acc)

data Color = Red | Green | Blue
data PeaNum = Succ PeaNum | Zero

data Calculation = 
    Add Int Int

calc :: Calculation -> Int
calc (Add x y) = x + y

data Tree a = Leaf | Node (Tree a) a (Tree a)
tree :: Tree Int
tree =
    Node (Node Leaf 1 Leaf ) 2 (Node (Node Leaf 3 Leaf) 4 Leaf)

-- Exercices folding and data types
-- 1 
--rev :: [a] -> [a]
--rev = foldr (\x (y:ys) -> (y:ys) ++ x ) []

-- s
revl :: [a] -> [a] 
revl = foldl (\acc x -> x : acc) []
--revr :: [a] -> [a]
--revr = foldr (\x acc -> acc ++ x) []