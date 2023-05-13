-- import Data.List             -- import a module
-- import Data.List (nub, sort) -- import some functions
-- import Data.List hiding (nub)-- import a module except some function
-- qualified is useful to prevent conflict of same function name in different modules

-- All about lists
import qualified Data.List as L
-- intersperse
intersperseEx0 = L.intersperse '.' "MONKEY"
-- intercalate
intercalteEx0 = L.intercalate [0,0,0] [[1,2,3],[4,5,6],[7,8,9]]
-- transpose
transposeEx0 = L.transpose [[1,2,3],[4,5,6],[7,8,9]]
-- concat 
concatEx0 = L.concat ["foo", "bar", "car"]
-- concatMap
concatMapEx0 = L.concatMap ("cat" ++) ["foo", "bar", "car"]
-- and
andEx0 = L.and $ map (>4) [5,6,7,8] -- True
andEx1 = L.and $ map (<4) [3,3,4,3] -- False 
-- or 
orEx0 = L.or $ map (<4) [3,3,4,3] -- True 
orEx1 = L.or $ map (<4) [4,4,4,4] -- False
-- any
anyEx0 = L.any (==4) [2,3,5,6,1,4] -- True
anyEx1 = L.any (`elem` ['A'..'Z']) "HEYGUYSwhatsup" -- True
-- all 
allEx0 = L.all (>4) [6,9,10] -- True
allEx1 = L.all (`elem` ['A'..'Z']) "HEYGUYSwhatsup" -- False
-- iterate
iterateEx0 = take 10 $ L.iterate (*2) 1
-- splitAt
splitAtEx0 = L.splitAt 3 "heyman"
-- takeWhile
takeWhileEx0 = L.takeWhile (>3) [6,5,4,3,2,1,6,5]
-- dropWhile
dropWhileEx0 = L.dropWhile (<3) [0,1,2,3,4,5,0,1]
-- span
spanEx0 = L.span (>3) [6,5,4,3,2,1,6,5]
spanEx1 = L.span (/=4) [1,2,3,4,5,6,7]
-- break 
breakEx0 = L.break (==4) [1,2,3,4,5,6,7]
-- sort 
sortEx0 = L.sort [8,7,2,3,1,5,6]
-- group 
groupEx0 = L.group [1,1,1,1,2,3,3,3,2,1,2,2,5,6,7]
-- inits 
initsEx0 = L.inits "w00t"
-- tails
tailsEx0 = L.tails "w00t"
-- isInfixOf
isInfixOfEx0 = "cat" `isInfixOf` "I'm a cat burglar" -- True
isInfixOfEx0 = "Cat" `isInfixOf` "I'm a cat burglar" -- False

