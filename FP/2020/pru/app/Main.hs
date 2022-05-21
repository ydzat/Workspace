module Main where

import System.Environment()

type Name = String

type Age = Float

type NumberOfChildren = Int

type Citizens = [Citizen]

-- A1.a

data Continent = Countries [Country] deriving (Show)

data Country = Unitary Name Citizens | Federal Name Citizens [State] deriving (Show)

data State = Name deriving (Show)


-- b.

data Citizen = Infant Age | Pupil Age | Adult Age NumberOfChildren 
    deriving (Show)

-- c.
-- countryMap :: Continent a -> (Country a-> b) -> [b]
-- countryMap f con = map f con


countries001 = Unitary "Ger" [(Infant 2), (Pupil 9), (Adult 30 2), (Adult 20 0)]

countries002 = Federal "Ger" [(Infant 2), (Pupil 9), (Adult 30 2), (Adult 20 0)] Byen,Sachsen


main :: IO ()
main = do

    print(countries001)