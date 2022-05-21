module Main where

import System.Environment()

--Aufgabe 3

--a
mergeSort :: (a -> a -> Bool) -> [a] -> [a]
mergeSort _ [] = []
mergeSort _ [x] = [x]
mergeSort f xs = merge f (mergeSort f l) (mergeSort f r)
    where (l, r) = splitAt (length xs `div` 2) xs

merge :: (a -> a -> Bool) -> [a] -> [a] -> [a]
merge _ [] xs = xs
merge _ xs [] = xs
merge f (x:xs) (y:ys) 
    | f x y = x : merge f xs (y:ys)
    | otherwise = y : merge f (x:xs) ys



vecLength :: (Float, Float, Float) -> Float
vecLength (a,b,c) = sqrt(a^2+b^2+c^2)


compVecLength :: (Float, Float, Float) -> (Float, Float, Float) -> Bool
compVecLength v u | vecLength v <= vecLength u = True
    | otherwise = False

main :: IO ()
main = do
    --a.
    print(vecLength (2,2,2))
    --b.
    print(compVecLength (1,1,1) (2,2,2))
    --c.
    print(mergeSort compVecLength [(3,3,3),(2,2,2),(1,1,1)])
