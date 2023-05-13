
-- 5.

myMaximum :: (Ord a) => [a] -> a            -- takes a list of things that can be ordered and return that thing
myMaximum [] = error "maximum of empy list" -- pattern match on an empty list
myMaximum [x] = x                           -- pattern match on a singleton list
myMaximum (x:xs) = max x ( myMaximum xs)    -- pattern match on a list, maximum between the head and a recursive call to myMaximum on the head

myMaximumEx0 = myMaximum [2,5,1]

-- Num for addition, substraction ; Ord for comparisons
myReplicate :: (Num i, Ord i) => i -> a -> [a] -- takes a thing i that is a number who can be ordered and a thing a, returns a list of things a
myReplicate n x                                -- given n a number and x an element
    | n <= 0 = []                              -- when n hits 0 return an empty list
    | otherwise = x:myReplicate (n-1) x        -- otherwise append to x the recursive call to myReplicate with a decrement of n and x

myReplicateEx0 = myReplicate 3 5

-- otherwise of the guard falls through the other pattern match
myTake :: (Num i, Ord i) => i -> [a] -> [a] -- takes a thing i, a number with a sense of order and a list of things a and returns a list of things a
myTake n _                                  -- pattern match on n and anything 
    | n <= 0 = []                           -- taking 0 or less from anything returns the empty list
myTake _ []  = []                           -- pattern match on anything and an empty list, which returns an empty list
myTake n (x:xs) = x : myTake (n-1) xs       -- append to the head a recursive call to myTake with decrement and tail

myTakeEx0 = myTake 4 [1,1,1,1,2,2,2]

myReverse :: [a] -> [a]                -- takes a list of things and returns a list of things 
myReverse [] = []                      -- returns an empty list on an empty list
myReverse (x:xs) = myReverse xs ++ [x] -- concatenate the recusive call to myReverse to the head 

myZip :: [a] -> [b] -> [(a,b)]          -- takes a list of things a and b and returns a list of tuples a and b
myZip _ [] = []                         -- b is empty returns an empty list
myZip [] _ = []                         -- a is empty returns an empty list
myZip (x:xs) (y:ys) = (x,y):myZip xs ys -- to the tuple of both heads append the recursive call to myZip on both tails

myElem :: (Eq a) => a -> [a] -> Bool    -- takes a thing that can be equal or inequal and a list of such things and returns a boolean value
myElem a [] = False                     -- pattern match on empty list returns False
myElem a (x:xs)                         -- pattern match on a not empty list
    | a == x  = True                    -- if a is equal to the head return True
    | otherwise = a `myElem` xs         -- otherwise do a recursive infix call to myElem with a and the tail

myQuicksort :: (Ord a) => [a] -> [a]      -- takes a list of things that can be ordered and returns such a list
myQuicksort [] = []                       -- returns an empty list on an empty list
myQuicksort (x:xs) =                      -- pattern match on a list
    let smallerSorted = myQuicksort [a | a <- xs, a <= x] -- a smaller sorted list is a recursive call to a myQuicksort on a list comprehension of element smaller than the head in the tail
        biggerSorted = myQuicksort [a | a <- xs, a > x]   -- a bigger version of the above
    in smallerSorted ++ [x] ++ biggerSorted               -- concatenate the sorted lists to the head of the input

myQuicksortEx0 = myQuicksort [10,2,5,3,1,6,7,4,2,3,4,8,9]