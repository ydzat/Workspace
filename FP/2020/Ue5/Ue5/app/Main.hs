module Main where

import System.Environment()

import Prelude

import Data.List()

--Ue5高阶函数

-----------------------------------Prelude 常用库函数

--id: 恒值函数，返回给定的任何值，可以作为占位符用，例如可以和const联合，返回第二个参数的值的函数const id
--id :: a -> a
--id 5
--输出：5
--id True
--输出：True

--const: 常值函数，类型为const::a->b->a，即给定两个元素，返回第一个
--const id True 3
--输出：3
-- const id True 3
-- =(const id True) 3  --函数应用为左结合
-- =id 3 --{应用const函数，将id函数返回}
-- =3 --{应用id函数}


--flip: 参数反转函数，类型为flip :: (a->b->c) -> (b->a->c)，对于一个接收两个参数的函数，如果要返回只接收第一个参数的函数，可以使用flip

--error: 错误函数，类型为error::String -> a，会抛出异常

--undefined: 定义是undefined = error "Prelude; undefined"，其实是一个异常，可以在调试或者测试时占位。

--min/max: 返回两个参数中最小、最大的那个

--even/odd: 判断一个数是否为偶数、奇数。


-----------------------------------

--A1
--a. 交换传递函数的参数顺序。即参数反转函数。
--flip :: (a->b->c) -> (b->a->c)

--b. 计算f0+f1+f2+...+fn。即求和

total :: (Int -> Int) -> (Int -> Int)
total a b | b /=0 = a(b) + (total a (b-1))
    | otherwise = a(0)

--c. composeList, 将函数列表转换为函数。该函数一个接一个地执行列表中的函数，若列表为空，则应用id函数。
--composeList :: a->a->(a->a)
composeList [] a = id a
composeList (x:xs) a = (composeList xs (x(a)))

--d. integrate，计算给定函数f的积分的数值近似值。生成的函数应该能计算两点之间f的图形下方的面积。
--Ich bin mir nicht sicher, wie ich "Unendlichkeit" ausdrücken soll.
--integrate1 :: (Float -> Float) -> (Float -> Float -> Float)
integrate1 f a b i | i /= 99999 = f(a+i/99999*(b-a))*(b-a)/99999 + integrate1 f a b (i+1)
    | otherwise = f(b)*(b-a)/99999

integrate :: (Float -> Float) -> (Float -> Float -> Float)
integrate f a b = integrate1 f a b 1

--e. 
--浮点四则运算，形如[(+),(-),(*),(/)]，以及两个数，比如3和4
--则输出为[7,-1,12,0.75]
calcOps :: [(Float -> Float -> Float)] -> Float -> Float -> [Float]
calcOps [] _ _ = []
calcOps (x:xs) a b = (x a b):(calcOps xs a b)


--f. linearSearch （列表中）线性搜索，若搜索到则返回位置，否则-1
linearSearch :: (a -> Bool) -> [a] -> Int
linearSearch _ [] = -1
linearSearch a l = case isIn a l of
    True -> search a l
    False -> -1
--先判断是否存在
isIn :: (a -> Bool) -> [a] -> Bool
isIn a (x:xs) | a(x) == True = True
    | null xs == False = isIn a xs 
    | otherwise = False

search :: Num p => (t -> Bool) -> [t] -> p
search a (x:xs) | a(x) == True = 0
    |otherwise = (+1)(search a xs)


--g. quick sort
quickSortStrings :: [Char] -> [Char]
quickSortStrings [] = []
quickSortStrings (x:xs) = (quickSortStrings [y | y <- xs, y < x]) ++ [x] ++ (quickSortStrings [y | y <- xs, y>=x])


main :: IO ()
main = do

    --a.
    print(flip (-) 3 4)     --表示4-3
    print(flip const True False)
    print(flip (:) [1,2,3] 5)

    print(flip const True 3)
    
    --b.
    print(total (+2) 1)     
    print(total (+2) 3)
    print(total (+2) 6)
    print(total id 100)

    --c.
    print(composeList [(*2), (+2)] 1)
    print(composeList [(++"Hallo"), (++" "), (++"Welt"), (++"!")] [])

    --d.
    print(integrate (^2) 1 2 )
    print(integrate id 0 5)

    --e.
    print(calcOps [(+),(-),(*),(/)] 3 4)

    --f.
    print(linearSearch (==3) [1..5])
    print(linearSearch (==4) [1..5])
    print(linearSearch (==5) [1..5])
    print(linearSearch (==7) [1..5])
    
    --g.
    print(quickSortStrings ['b','c','d','a'])