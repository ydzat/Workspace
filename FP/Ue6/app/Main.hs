module Main where

import System.Environment()
import Prelude

-------A1.

-- --a. benutzt foldl und Listengenerator, berechnet Fakultaet wie 5!=5x4x3x2x1
-- fac :: Int -> Int
-- fac 1 = 1
-- fac 0 = 1
-- fac a = foldl (*) a [1..a-1]

-- --b. benutzt map und foldr auf [0..n], um 0^2+1^2+...+n^2 zu berechnen
-- sumQua :: Int -> Int
-- sumQua n = foldr (+) 0 (map (^2) [0..n])

-- --c. benutzt foldl oder foldr um Laenge einer Liste zu berechnen
-- len :: [Int] -> Int
-- len x = foldl (+) 0 [1| _<-x]


-- --d. foldl oder foldr, umkehren einer Liste
-- rev :: [Int] -> [Int]
-- rev = foldl (\xs x -> x : xs) []

-- --e. [0..n] gerader und ungerader Quadratzahlen
-- numOddEvenSquares :: Int -> [Int]
-- numOddEvenSquares n = [foldl (+) 0 (map (^2) [x| x<-[0..n], x `mod` 2 /= 0]),foldl (+) 0 (map (^2) [x| x<-[0..n], x `mod` 2 == 0])]

-- -------2.
data FloatExpr = Val Float
    | Add FloatExpr FloatExpr
    | Mul FloatExpr FloatExpr
    | Sqrt FloatExpr
    | Abs FloatExpr
    deriving (Show)

numOps :: FloatExpr -> Int
numOps (Val _) = 0
numOps (Add x y) = 1 + (numOps x) + (numOps y)
numOps (Mul x y) = 1 + (numOps x) + (numOps y)
numOps (Sqrt x) = 1 + (numOps x)
numOps (Abs x) = 1 + (numOps x)

numVals :: FloatExpr ->Int
numVals (Val _) = 1
numVals (Add x y) = (numVals x) + (numVals y)
numVals (Mul x y) = (numVals x) + (numVals y)
numVals (Sqrt x) = (numVals x)
numVals (Abs x) = (numVals x)

evalExpr :: FloatExpr -> Float
evalExpr (Val x) = x
evalExpr (Add x y) = evalExpr x + evalExpr y
evalExpr (Mul x y) = evalExpr x * evalExpr y
evalExpr (Sqrt x) = sqrt(evalExpr x)
evalExpr (Abs x) = abs(evalExpr x)

showExpr::FloatExpr->String
showExpr (Val x) = show x
showExpr (Add x y) = "(" ++ showExpr (x) ++ "+" ++ showExpr (y) ++ ")"
showExpr (Mul x y) = "(" ++ showExpr (x) ++ "*" ++ showExpr (y) ++ ")"
showExpr (Sqrt x) = "sqrt(" ++ show(x) ++ ")"
showExpr (Abs x) = "abs(" ++ show(x) ++ ")"

-------A3. Tree
--树的内部节点可以包含任意数量的子节点(多叉树); 外部节点可以接受任何数据类型
--多态代数数据类型GenTree
--确定树中有多少个元素满足给定谓词功能的功能(查找符合条件的节点)
--输出所有元素
--计算树的深度，某节点的最大子节点个数
--确定一棵树是否是完整的k元树(即每个结点具有0个或k个子节点)，是否是完美k元树(具有所有外部节点的完整k元树)

data GenTree a = Leaf a 
    | Branch [GenTree a]
    deriving (Show)

tree = (Branch [(Branch [(Leaf 1),(Leaf 2)]),(Leaf 3),(Leaf 4)])

tree1 = (Branch [(Branch [(Leaf 1),(Leaf 2)]),(Branch [(Leaf 3),(Leaf 4)])])

getElements :: GenTree a -> [a]
getElements (Leaf a) = [a]
getElements (Branch []) = []
getElements (Branch (x:xs)) = getElements x ++ getElements (Branch xs)


howManyFitGenTree :: (a -> Bool) -> GenTree a -> Int
howManyFitGenTree func tree = foldl (+) 0 [1 | x<- getElements tree, func x]


treeCount :: GenTree a -> (a -> Bool) -> Int
treeCount (Leaf x) p = if p x then 1 else 0
treeCount (Branch []) p = 0
treeCount (Branch (x:xs)) p = treeCount x p + treeCount (Branch xs) p

depth :: GenTree a -> Int
depth (Leaf a) = 1
depth (Branch []) = 0
depth (Branch x) = 1 + (foldl max 0 (map depth (x)))

maxChildren :: GenTree a -> Int
maxChildren (Leaf _) = 1
maxChildren (Branch []) = 0
maxChildren (Branch (x:xs)) = max (maxChildren x) (1 + maxChildren (Branch xs))

treeChild :: GenTree a -> Int
treeChild (Leaf _) = 1
treeChild (Branch xs) = max (length xs) ((foldl max 0 . map treeChild) xs)

kTree :: GenTree a -> Int -> Bool
kTree (Leaf _) _ = True
kTree (Branch []) _= True
kTree (Branch (x:xs)) n = (k n x) && (kTree (Branch xs) n) where
    k _ (Leaf _) = True
    k n (Branch xs) | n == length xs = True
        | otherwise = False

perfKTree :: GenTree a -> Int -> Bool
perfKTree t n | kTree t n == False = False
    | foldl (+) 0 (map (n^) [0..((depth t) - 1)]) == howManyNode t = True 
    | otherwise = False

howManyNode :: GenTree a -> Int
howManyNode (Leaf a) = 1
howManyNode (Branch []) = 1
howManyNode (Branch (x:xs)) = howManyNode x + howManyNode (Branch xs)

------------------------------------------------------------

------------4.Induktion 归纳法

--1.
--已知：
sum1 :: [Int] -> Int
sum1 [] = 0                                 -- A1
sum1 (x : xs) = x + sum1 xs                 -- A2

doubleAll  :: [Int] -> [Int]
doubleAll  [] = []                          -- B1
doubleAll (x:xs) = (2*x) : doubleAll  xs    -- B2

--归纳：sum1 (doubleAll xs) = 2 * sum xs

------以下为答案 ↓↓↓↓↓↓：

--Induktionsanfang:

--  sum1 (doubleAll []) == 2 * sum1 []      --将初值[]带入
--  sum1 ([]) == s * sum1 []                --nach B1
--  0 == s * sum1 []                        --nach A1
--  0 == s * 0                              --nach A1
--  0 == 0                                  --nach *
--  wahr Aussage

--Induktionsvoraussetzung:
--  sum1 (doubleAll xs) == 2 * sum1 xs

--Induktionsbehauptung:
--  sum1 (doubleAll (c:cs)) == 2 * sum1 (c:cs)
--  sum1 ((2*c) : doubleAll cs) == 2* sum1 (c:cs)
--  (2*c) + sum1 (doubleAll cs) == 2 * sum1 (c:cs)
--  (2*c) + sum1 (doubleAll cs) == 2* (c + sum1 cs)
--  (2*c) + sum1 (doubleAll cs) == (2*c) + 2 * (sum1 cs)
--  sum1 (doubleAll cs) == 2 * (sum1 cs)
--  wahr Aussage

--2.
--已知：
-- map :: (a -> b) -> [a] -> [b]
-- map f [] = []                        -- M1
-- map f (x : xs) = f x : map f xs      -- M2

-- (++) :: [a] -> [a] -> [a]
-- [] ++ ys = ys                        -- C1
-- (x:xs) ++ ys = x : (xs ++ ys)        -- C2

--归纳：map f (xs ++ ys) = map f xs ++ map f ys

--Induktionsanfang
--  map f ([] ++ []) = map f [] ++ map f []
--  map f [] = [] ++ []
--  [] == []
--  wahr

--Induktionsbehauptung
-- map f ((c:cs) ++ ys) = map f (c:cs) ++ map f ys
-- map f (c:(cs ++ ys)) = map f (c:cs) ++ map f ys
-- f c : map f (cs ++ ys) = map f (c:cs) ++ map f ys
-- f c : map f (cs ++ ys) = f c : map f cs ++ map f ys
-- map f (cs ++ ys) = map f cs ++ map f ys
-- wahr




main :: IO ()
main = do

    -----------3.
    print("///////////////////")
    print(getElements tree)
    -- print(howManyFitGenTree (==5) tree)
    -- print(howManyFitGenTree (>=2) tree)
    -- print(treeCount tree even)
    print(depth tree)
    print(maxChildren tree)
    print(treeChild tree)
    print(kTree tree 3)
    print(perfKTree tree 3)
    print(howManyNode tree)
    print(perfKTree tree1 2)
    print(howManyNode tree1)
    print("///////////////////")
    -- ----------1.
    -- --a.
    -- print(fac 5)
    -- print(fac 4)
    -- print(fac 1)
    -- print(fac 0)

    -- --b.
    -- print(sumQua 5)
    -- print(sumQua 1)
    -- print(sumQua 2)
    -- print(sumQua 3)
    -- print(sumQua 0)

    -- --c.
    -- print(len [1,1,1])

    -- --d.
    -- print(rev [1,2,3,4,5])

    -- --e.
    -- print(numOddEvenSquares 5)


    -- -------2.
    print(numVals (   Mul (Val 5.0) (Val 9.0)     )) 

    print(evalExpr (   Mul (Val 5.0) (Val 9.0)     ))

    print(showExpr (   Mul (Val 5.0) (Val 9.0)     ))