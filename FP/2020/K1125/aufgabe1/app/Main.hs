module Main where

import System.Environment()

import Data.List

import Data.Char

--Aufgabe 1

--a.
shiftChar :: Char -> Int -> Char
shiftChar x k 
    | (fromEnum x) >= 97 && (fromEnum x) <=122 = toEnum (mod (fromEnum x - 96 + k) 26 + 96) 
    | (fromEnum x) >= 65 && (fromEnum x) <= 90 = toEnum (mod (fromEnum x - 65 + k) 26 + 65) 
    | fromEnum x == 32 = ' '
    | otherwise = error "ERROR"

--(fromEnum x /= 32) && (fromEnum x <41 || (fromEnum x >90 && fromEnum x < 97) || fromEnum x >122) = ''

--b.
decryptCeasar :: [Char] -> Int -> [Char]
decryptCeasar [] _ = []
decryptCeasar (x:xs) k = [(shiftChar x (-k))] ++ (decryptCeasar xs k)

--c.
crackCeasar :: [Char] -> [Char] -> ([Char], Int, [Char]) 
crackCeasar x y 
    | [[ls] | ls <- (map (\k -> decryptCeasar x k) [0..26]), isInfixOf y ls == True ] /= [] = (x, fromEnum (head x) - fromEnum (head (head (head [[ls] | ls <- (map (\k -> decryptCeasar x k) [0..26]), isInfixOf y ls == True ]))),(head (head [[ls] | ls <- (map (\k -> decryptCeasar x k) [0..26]), isInfixOf y ls == True ])))
    | otherwise = (x,-1,"ERROR")

--d.
printCeasar :: ([Char], Int, [Char]) -> IO ()
printCeasar (geh,schl,klar) = mapM_ print ["Geheim: "++geh,"Schluessel: "++ show schl,"Klartext: "++klar]

main :: IO ()
main = do

    --a.
    print(shiftChar 'c' 23)
    print(shiftChar 'a' 4)
    print(shiftChar 'L' (-5))

    --b.
    print(decryptCeasar "Gjnxunjq" 5)

    --c.
    --print(map (\k -> decryptCeasar "osx Losczsov" k) [0..26])
    print(crackCeasar "osx Losczsov" "Beispiel")
    print(crackCeasar "osx Losczsov" "Example")
    -- print(isSubsequenceOf "ein Beispiel" "Beispiel")

    --d.
    printCeasar(crackCeasar "osx Losczsov" "Beispiel")