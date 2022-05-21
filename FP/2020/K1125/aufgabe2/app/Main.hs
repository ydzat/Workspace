module Main where

import System.Environment()
import Prelude
--Aufgabe 2

--a.
quadruples :: Int -> [(Int, Int, Int, Int)]
quadruples n = [(a,b,c,d) | a <- [1..n], b <- [1..n], c <- [1..n], d <- [1..n],a^2+b^2 == c^2+d^2]

--b.
tripleOrder :: [(Int, Int, Int)] -> Bool
tripleOrder [] = True
tripleOrder (x:xs) | aufs x == False = False
    | otherwise = tripleOrder xs

aufs :: Ord a => (a, a, a) -> Bool
aufs (a,b,c) | a <= b && b <= c = True
    | otherwise = False

--c.
perfects :: Int -> [Int]
perfects n = [x | x <-[2..n], foldl (+) 0 (factors x) == x]

factors :: Int -> [Int]
factors x = [a | a <- [1..x-1], mod x a == 0]

main :: IO ()
main = do
    --a.
    print(quadruples 2)

    --b.
    print(tripleOrder [(4,5,6), (1,2,3), (3,4,9)])
    print(tripleOrder [(4,5,6), (2,1,3), (3,4,9)])

    --c.
    print(perfects 500)