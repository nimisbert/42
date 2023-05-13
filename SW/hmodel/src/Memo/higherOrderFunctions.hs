-- 6. 
applyTwice :: (a -> a) -> a -> a -- function that takes function, that takes a thing and returns a thing, a thing and returns a thing
applyTwice f x = f (f x)         -- given a function f and a thing x, apply f twice to x

applyTwiceEx0 = applyTwice (+3) 10

myZipWith :: (a -> b -> c) -> [a] -> [b] -> [c]        -- takes a function that takes two things and returns a thing, two list, and returns a list of things
myZipWith _ [] _ = []                                  -- pattern match on any function, an empty list, a list, returns an empty list 
myZipWith _ _ [] = []                                  -- pattern match on any function, a list, an empty list, returns an empty list
myZipWith f (x:xs) (y:ys) = f x y : myZipWith f xs ys  -- apply the function to the heads of input lists and append the recursive call on the tails

myZipWithEx0 = myZipWith max [6,3,2,1] [7,3,1,5]

-- map
-- takes a function and applies it to a list

-- filter 
-- takes a predicate and a list, returns the list of elements who satisfy the predicate

myReadableQuicksort :: (Ord a) => [a] -> [a]
myReadableQuicksort [] = []
myReadableQuicksort (x:xs) =
    let smallerSorted = myReadableQuicksort (filter (<=x) xs)
        biggerSorted  = myReadableQuicksort (filter (>x) xs)
    in smallerSorted ++ [x] ++ biggerSorted

-- folds 

mySum :: (Num a) => [a] -> a                -- takes a list of things that are number and returns a thing that is a number
mySum xs = foldl (\acc x -> acc + x) 0 xs   -- left fold with lambda function that takes two value and returns its sum
-- the first value of the function given to a left fold is an accumulator
-- foldl goes through a list from the head of the list to its last element

myMap :: (a -> b) -> [a] -> [b]                 -- takes a function that takes two things, a list and returns a list
myMap f xs = foldr (\x acc -> f x : acc ) [] xs -- 
-- the second value of the function given to a right fold is an accumulator

myReverse0 :: [a] -> [a]
myReverse0 xs = foldl (\acc x -> x : acc) [] xs

myReverse0Ex0 = myReverse0 [1,2,3,4,5]

-- function application with space is left-associative
-- function application with $ is right-associative

myFaEx0 = sum (map sqrt [1..130])
myFaEx1 = sum $ map sqrt [1..130]
myFaEx2 = sqrt 3 + 4 + 9
myFaEx3 = sqrt $ 3 + 4 + 9
myFaEx4 = sqrt (3 + 4 + 9)

-- function composition
myFcEx0 = map (negate . abs) [5, -3, -7 , 3]