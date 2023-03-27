-- takes a function as argument

myapp :: (a->b) -> a -> b
myapp f x = f x

add1 :: Int -> Int 
add1 x = x+1

testExample = myapp add1 1

-- lambdas (\<args> -> <expr>)

testLambda0 = (\x -> x+1) 1
testLambda1 = (\x y z-> x+y+z ) 1 2 3

-- Map 
testMap0 = map (\(x, y) -> x+y) [(1,2),(3,4),(5,6)]

-- Filter 
testfilter0 = filter (\x -> x > 3) [1,2,3,4,5,6]