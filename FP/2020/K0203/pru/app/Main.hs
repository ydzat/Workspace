module Main where

import System.Environment()
import Data.List



------------------------------------ A1.

type Name = String

type Age = Float

type NumberOfChildren = Int

type Citizens = [Citizen]

-- a.

data Continent a = Countries [Country a] deriving (Show)

data Country a = Unitary Name Citizens | Federal Name [(State, Citizens)] deriving (Show)

type State = String

-- b.

data Citizen = Infant Age | Pupil Age | Adult Age NumberOfChildren 
    deriving (Show)

-- c.
countryMap :: Continent a -> (Country a-> b) -> [b]
countryMap (Countries a) f = map f a

-- d.

demographicDistribution :: Country Citizens -> (String,(Int, Int, Int))
demographicDistribution (Unitary b c) = (b,statistics c)
demographicDistribution (Federal b [(_, c)]) = (b,statistics c)

statistics :: Citizens -> (Int, Int, Int)
statistics s  = (length [x | x <- s,(f x) !! 0 == 'I'],length [x | x <- s, (f x) !! 0 == 'P'],length [x | x <- s, (f x) !! 0 == 'A'])

-- statistics1 :: [(State, Citizen)] -> (Int, Int, Int)
-- statistics1 s  = (length [x | x <- s,(f1 x) !! 0 == 'I'],length [x | x <- s, (f1 x) !! 0 == 'P'],length [x | x <- s, (f1 x) !! 0 == 'A'])

f :: Citizen -> String
f c = show c 

f1 :: (State, Citizen) -> String
f1 (_,b) = f b 

-- e.
numYngParents :: Country Citizens -> (Name, Int)
numYngParents (Unitary b c) = (b, statistics2 c)
numYngParents (Federal b [(_, c)]) = (b, statistics2 c)

statistics2 :: Citizens -> Int
statistics2 s = length [x | x <- s,(f x) !! 0 == 'A' && read (words (f x) !! 1) <= 30.0 && read (words (f x) !! 2) >= 2]

-- statistics3 :: [(State, Citizen)] -> Int
-- statistics3 s = length [x | x <- s,(f1 x) !! 0 == 'A' && read (words (f1 x) !! 1) <= 30.0 && read (words (f1 x) !! 2) >= 2]
-----------------------------------------------------------------------------------
-----------------------------------------------------------------------------------

------------------------------------ A2.
---- a.
-- Fakultaet
fac :: Float -> Float
fac 1 = 1
fac 0 = 1
fac a = foldl (*) a [1..a-1]

euler :: Float -> Float
euler k | k > 0 = (/) 1 (fac k)
    | otherwise = 1

-- sum of euler num
eulerSeries :: [Float]
eulerSeries = map euler [0..]

---- b.
eulerCalc :: Int -> Float
eulerCalc k = sum (take k eulerSeries)

---- c.
eulerFraction :: Int -> Float
eulerFraction k = read ("0" ++ drop 1 (show (eulerCalc k)))


--------------------untern sind die testen Daten von Aufgabe 1-----------------------

ct1 = Adult 29 3

countries001 = Unitary "Ger" [(Infant 2), (Pupil 9), (Adult 30 2), (Adult 20 0), (Adult 25 3)]

countries002 = Federal "Ger" [("Sachsen",[(Infant 2), (Pupil 9), (Adult 30 2), (Adult 20 0)])]

asia = Countries [countries001,countries002]

--------------------oben sind die testen Daten von Aufgabe 1-----------------------

main :: IO ()
main = do

-- A1.
    print(countries001)
    print(countries002)
    print(asia)
    print(demographicDistribution countries001)
    print(words  (f ct1))
    print(numYngParents countries001)

-- A2.
    -- print(take 5 eulerSeries)
    -- print(eulerCalc 5)
    -- print(eulerFraction 5)