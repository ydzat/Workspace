module Main where

import System.Environment

--寻找列表中最大值
-- maxInList :: Ord a => [a] -> a
-- maxInList [x] = x
-- maxInList (x:xs) = max x (maxInList xs)

--快速排序
-- quicksort :: Ord a => [a] -> [a]
-- quicksort [] = []
-- quicksort (x:xs) = (quicksort [y | y <- xs, y < x] ++ [x] ++ (quicksort [y | y<- xs, y >= x]))

-----------------------------------------------------------------------
--Ue 2 3

-- --斐波那契数列
-- calcFibonacci :: Int -> Int
-- calcFibonacci i = if i < 3 then 1
--     else calcFibonacci (i - 1) + calcFibonacci (i - 2)

-- --计算前n个自然数的和
-- calcSum :: Int -> Int
-- calcSum n = if n == 1 then 0
--     else n - 1 + calcSum (n-1)

-- --欧几里得算法求最大公约数（辗转相除法）
-- ggT :: Int->Int->Int
-- ggT x y = if y == 0 then x else ggT y (mod x y)

-- --判断4个数是否相等
-- fourEqual :: Int->Int->Int->Int->Bool
-- fourEqual a b c d = if a == b && b == c && c == d then True else False

-- --XOR3计算三个布尔值的异或，即奇偶校验
-- xor3 :: Bool->Bool->Bool->Bool
-- xor3 a b c = xor (xor a b) c 

-- --XOR计算两个布尔值异或
-- xor :: Bool->Bool->Bool
-- xor a b = if a == True then not (a && b)
--     else (a || b)

-- --计算3个浮点数的中间值
-- middleOfThree :: Float->Float->Float->Float
-- middleOfThree a b c | a >= b && a <=c = a
--     |a <=b && a >= c = a
--     |b >=a && b <= c = b
--     |b <= a && b >= c = b
--     |otherwise = c

-- --计算元素中有几个元素相等，若
-- howManyEqualOfThree :: (Eq a, Num p) => a -> a -> a -> p
-- howManyEqualOfThree a b c | a == b && a == c = 3
--     | a == b && a /= c = 2
--     | b == c && b /= a = 2
--     | otherwise = 1

-- --计算取反的逻辑与，即nand。用Guarded commands '|'
-- nand1 :: Bool->Bool->Bool
-- nand1 x y | (x && y == True) && x == True = False
--     |otherwise =True

-- --不用'|'
-- nand2 :: Bool->Bool->Bool
-- nand2 x y = not(x && y)

----------------------------------------------------------
--Ue 4

-- --元组，升序排序
-- orderTriple :: (Int, Int, Int)->(Int,Int,Int)
-- orderTriple (a,b,c) | a >= (min b c) && a <= (max b c) = ((min b c), a, (max b c))
--     | b >= min a c && b <= max a c = (min a c, b, max a c)
--     | c >= min a b && c <= max b a = (min b a, c, max b a)

-- --元组，右移
-- rotateQuadruple :: (Int, Int, Int, Int) -> Int -> (Int, Int, Int, Int)
-- rotateQuadruple (a,b,c,d) x | mod x 4 == 1 = (d,a,b,c)
--     | mod x 4 == 2 = (c,d,a,b)
--     | mod x 4 == 3 = (b,c,d,a)
--     | otherwise = (a,b,c,d)

-- --返回列表中，元组元素和最大的元组
-- maxpairs :: [(Int, Int)] -> (Int, Int)
-- maxpairs [] = (0,0)
-- maxpairs (x:xs) | (fst x) + (snd x) >= fst(maxpairs xs) + snd(maxpairs xs) = x
--     | otherwise = maxpairs xs

-- --计算标量积。要求长度一致，否则返回错误提示
-- scalar :: [Int]->[Int]->Int
-- scalar [] [] = 0
-- scalar (x:xs) (y:ys) | length (x:xs) == length (y:ys) = x*y + scalar xs ys
--     | otherwise = error "Program error: Vektoren ungleich lang"

-- --回文判断
-- isPalin :: [Int]->Bool
-- isPalin [] = True
-- isPalin [x] = True
-- isPalin (x:xs) | (x == (last xs)) && (isPalin (init xs)) = True
--     | otherwise = False

-- --匹配，返回所有符合匹配的数据，用表达式
-- matches1 :: [Int] -> Int -> [Int]
-- matches1 a n = [x | x <- a, x == n]

-- --匹配，不用表达式
-- matches2 :: [Int] -> Int -> [Int]
-- matches2 [] n = []
-- matches2 (x:xs) n | (x == n) = [x] ++ (matches2 xs n)
--     | otherwise =[] ++ (matches2 xs n)

--归并排序，Mergesort。升序
-- mergeSort :: Ord a => [a] -> [a]
-- mergeSort [] = []
-- mergeSort [x] = [x]
-- mergeSort xs = merge (mergeSort l) (mergeSort r)
--   where (l, r) = splitAt (length xs `div` 2) xs

-- merge :: Ord a => [a] -> [a] -> [a] 
-- merge [] xs = xs
-- merge xs [] = xs
-- merge (x:xs) (y:ys) 
--   | x < y = x : merge xs (y:ys)
--   | otherwise = y : merge (x:xs) ys


--nor3，在不使用Bool运算符的情况下计算 负逻辑 或者 3个布尔值。使用‘|’
--
nor3 :: Bool->Bool->Bool->Bool
nor3 x y z 
    | a == True = False
    | b == True = False
    | c == True = False 
    | otherwise = True

-- --nor3，使用Pattern matching
-- nor3a :: Bool->Bool->Bool->Bool
-- nor3a False False False = True
----------------------------------------------------------

main :: IO ()
main = do
    -- print (maxInList [1,2,3,4,5,1])
    -- print (quicksort [6,2,3,4,1,5,2])
    -- print (map (+1) (quicksort [6,2,3,4,1,5,2]))

    -----------------------------------------------------------------
    --Ue 2 3

    -- print (calcFibonacci 6)
    -- print (calcSum 5)

    -- print (ggT 8 16)
    -- print (ggT 1 5)
    -- print (ggT 2 3)
    -- print (ggT 32 16)

    -- print (fourEqual 2 2 2 2)
    -- print (fourEqual 1 2 3 2)

    -- print (xor3 True True True) --1
    -- print (xor3 True False True) --0
    -- print (xor3 False False True)--1
    -- print (xor3 False False False)--0

    -- print (middleOfThree 3 1 2)
    -- print (middleOfThree 7 6 5)
    -- print (middleOfThree 4 2 6)

    -- print (howManyEqualOfThree 6 6 6)
    -- print (howManyEqualOfThree 6 6 5)
    -- print (howManyEqualOfThree 6 5 4)

    -- print (nand1 False False)
    -- print (nand1 False True)
    -- print (nand1 True False)
    -- print (nand1 True True)

    -- print (nand2 False False)
    -- print (nand2 False True)
    -- print (nand2 True False)
    -- print (nand2 True True)
    -----------------------------------------------------------------
    --Ue 4
    -- print(orderTriple (3,1,2))

    -- print(rotateQuadruple (1,2,3,4) (-1))
    -- print(rotateQuadruple (1,2,3,4) 1)
    -- print(rotateQuadruple (1,2,3,4) 2)
    -- print(rotateQuadruple (1,2,3,4) 3)
    -- print(rotateQuadruple (1,2,3,4) 4)
    -- print(rotateQuadruple (1,2,3,4) 5)

    -- print(maxpairs[(2,1),(3,2),(5,3),(2,2)])

    -- print(scalar [1..10] [2,4..20])
    -- print(scalar [1,2,3] [1,2])
    
    -- print(isPalin [1,2,3,2,1])
    -- print(isPalin [1..7])

    -- print(matches1 [1,4,2,1,4,1,6,3] 1)
    -- print(matches2 [1,4,2,1,4,1,6,3] 1)
    -- print(matches1 [1,2,3,4,5] 6)
    -- print(matches2 [1,2,3,4,5] 6)

    -- print(mergeSort [2,1,3,6,4,5])

    -- print(nor3 False False False)
    -- print(nor3 False False True)
    -- print(nor3 True True False)
    -- print(nor3 True True True)

    -- print(nor3a False False False)
    -- print(nor3a False False True)