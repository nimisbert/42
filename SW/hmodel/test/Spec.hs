import Test.Hspec
import ProjectEuler

main :: IO()
main = hspec $ do 
    describe "Sum of multiples of 3 or 5" $ do
        it "Below   10" $ problem1 9   `shouldBe` 23
        it "Below 1000" $ problem1 999 `shouldBe` 233168