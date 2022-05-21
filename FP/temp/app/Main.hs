module Main where

import System.Environment()


mergeSort :: (a->a->Bool)->[a]->[a]
mergeSort f [] = []
mergeSort f [x] = [x]
mergeSort f xs = merge2 f (mergeSort f (take ((length xs) `div` 2) xs)) (mergeSort f (drop ((length xs) `div` 2) xs))


merge2 :: (a->a->Bool)->[a]->[a]->[a]
merge2 f [] ys = ys
merge2 f xs [] = xs
merge2 f (x:xs) (y:ys) = if (f x y) then x : (merge2 f xs (y:ys)) else y : (merge2 f (x:xs) ys)



vecLength :: (Float,Float,Float)->Float
vecLength (a,b,c) = sqrt (a^2+b^2+c^2)

comVecLength :: (Float,Float,Float)->(Float,Float,Float)->Bool
comVecLength (a,b,c) (x,y,z) | vecLength (a,b,c) > vecLength (x,y,z) = False
    | otherwise = True

main :: IO ()
main = do

    print(mergeSort comVecLength [(3,3,3),(2,2,2),(1,1,1)])