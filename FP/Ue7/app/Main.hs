module Main where

import System.Environment()
import Data.List
-----------------------------------------------------------------------------------
--------1a.
class Visible a where
    toString :: a -> String
    size :: a -> Int

instance Visible Char where
    toString ch = [ch]
    size _ = 1

instance Visible Bool where
    toString True = "True"
    toString False = "False"
    size _ = 1

instance Visible a => Visible [a] where
    toString = concat.map toString
    size = foldr (+) 0 . map size

--------1b.
data Tree a = Leaf a | Branch (Tree a) (Tree a)

instance (Eq a) => Eq (Tree a) where
    Leaf x == Leaf y = x == y
    (Branch l1 r1) == (Branch l2 r2) = (l1 == l2) && (r1 == r2)
    _ == _ = False

v1 = (Branch (Leaf 1) (Leaf 2))
v2 = (Branch (Leaf 1) (Leaf 2))
v3 = (Branch (Leaf 3) (Leaf 2))

------------2.
--惰性求值评估
--nature = 0 : map (+1) nature
-- 1.LI-Reduktion(最左侧最内侧还原)(及早/贪婪求值)
-- --左侧最不包含任何其他redex的redex被减少。
-- --(与命令式语言的按值调用参数传递相对应)
-- --优点：重复出现的局部表达式仅计算一次
-- --缺点：可能不必要的计算

--Bsp: fst(5, square 4) -> fst (5, 4*4) -> fst (5,16) -> 5

-- 2. LO-Reduktion(最外面的降低)(惰性求值)
-- --任何其他redex中不包含的最左边的redex将被减少。
-- --(对应于命令式语言中的"按名字呼叫"参数传输)
-- --优点：仅计算实际需要的部分表达式
-- --缺点：对重复子表达式的多重评估

--Bsp: fst(5, square 4) -> 5

--a.
-- add (mul 1 2) (mul 3 4)
-- add x y = x + y
-- mul x y = x * y

--  -> add (mul 1 2) (3 * 4)
--  -> add (3 * 4) (3 * 4)
--  -> (3 * 4) + (3 * 4)
--  -> 7 + (3 * 4)
--  -> 7 + 7
--  -> 14

--b.
-- foldr (&&) True [True,False,True]

--  -> foldr (&&) (True && True) [True,False]
--  -> foldr (&&) ((True && True)&&False) [True]
--  -> ((True && True)&&False)&&True
--  -> (True&&False)&&True
--  -> False&&True
--  -> False


-----------------3.

getMultiple :: Int -> Int ->  [Int]
getMultiple c n = [ x | x <- [c+1..n], x `mod` c == 0]

delSub :: [Int] -> [Int]  -> [Int]
delSub cs fc = (filter (`notElem` fc) cs)

siebDesEratosthenes :: [Int] -> Int -> [Int]
siebDesEratosthenes [] _ = []
siebDesEratosthenes (c:cs) n 
    | (head (delSub (c:cs) (getMultiple c n ))) <= n = (head (delSub (c:cs) (getMultiple c n ))) : 
        (siebDesEratosthenes (tail (delSub (c:cs) (getMultiple c n ))) n )
    | otherwise = []
    
---------------4.

--a.
-- take 1 (foldr (++) [] (repeat [1]))

--  -> take 1 (foldr (++) ([] ++ [1]) (repeat [1]))
--  -> ([] ++ [1])
--  -> [1]

--b.
-- take 1 (foldl (++) [] (repeat [1]))

--  -> take 1 (([]:[1]):(..))   ->unendlich

--c.
-- take 0 (foldl (++) [] (repeat [1]))
-- []







-----------------------------------------------------------------------------------


main :: IO ()
main = do

    --------1.
    print(toString 'a')
    print(toString ['a','b','c','d'])
    print(v1 == v2, v1 == v3)

    

    --------2.
    --print(take 5 nature)

    --------3.
    print(siebDesEratosthenes [2..] 1000 )

    ----------4.
    print(take 1 (foldr (++) [] (repeat [1])))
    print(take 1 (foldr (++) [] [[1],[2],[3]]      ))
    print(scanr (++) [] [[1],[2],[3]]      )
    print(take 1 (foldl (++) [] [[1],[2],[3]]      ))
    print(scanl (++) [] [[1],[2],[3]]      )
    -- print(take 1 (foldl (++) [] (repeat [1])))

    print(take 0 (foldl (++) [] (repeat [1])))