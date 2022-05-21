module Main where

import System.Environment()

fib n | n >=3 = (fib (n - 1)) + (fib (n - 2)) 
    | otherwise = 1


fi n | n >= 3 = (\n -> fi (n-1)) n + (\n -> fi (n-2)) n 
    | otherwise = 1

main :: IO ()
main = do

    print(map fib [1..10])
    print(map fi [1..10])