module OwnTypeclasses (
      Point (..)
    , Shape (..) -- Shape (Rectangle, Circle)
    , surface
) where 
-- Value Constructor are functions 
-- Circle is a function, Rectangle is a function
-- The type is Shape
data Point = Point Float Float deriving (Show)
data Shape = Circle Point Float | Rectangle Point Point deriving (Show)

-- 
-- record syntax
data Person = Person {
      firstName :: String
    , lastName :: String
    , age :: Int 
    , height :: Float 
    , phoneNumber :: String 
    , flavor :: String 
} deriving (Show)

-- Type parameters
-- data Maybe a = Nothing | Just a 

data Car = Car {
      company :: String 
    , model :: String 
    , year :: Int 
} deriving (Show)

--data Car a b c = Car {
--      company :: a 
--    , model :: b
--    , year :: c   
--} deriving (Show)

-- Shapes 
surface :: Shape -> Float 
surface (Circle _ r) = pi * r ^ 2
surface (Rectangle (Point x1 y1) (Point x2 y2)) = (abs $ x2 - x1) * (abs $ y2 - y1)

surfaceEx0 = surface $ Circle (Point 10 20) 10 
surfaceEx1 = surface $ Rectangle (Point 0 0) (Point 100 100)

-- People
person0 = Person "Buddy" "Finklestein" 43 184.2 "526-2928" "Chocolate"

getFirstName :: Person -> String
getFirstName (Person firstname _ _ _ _ _) = firstname

getLastName :: Person -> String
getLastName (Person _ lastname _ _ _ _) = lastname

getAge :: Person -> Int 
getAge (Person _ _ age _ _ _) = age

getHeight :: Person -> Float
getHeight (Person _ _ _ height _ _) = height

getPhoneNumber :: Person -> String 
getPhoneNumber (Person _ _ _ _ number _) = number

getIcecreamFlavor :: Person -> String 
getIcecreamFlavor (Person _ _ _ _ _ flavor) = flavor

-- 