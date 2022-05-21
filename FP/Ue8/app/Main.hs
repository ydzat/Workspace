module Main where

import System.Environment()

-------------------------Lambda λ 表达式

-- func :: 参数1的类型 -> 参数2的类型 -> .. -> 结果的类型
-- func = \参数1 -> 参数2 -> .. -> 函数体

fAbs = (\x -> \y -> x y) abs (-5)
--  = (\y -> abs y) (-5)
--  = abs (-5)
--  =5

fSum = (\x -> foldl (+) 0 x) [1..10]  

-- fAbs中，把abs替换为x；把-5替换为y，这个过程称为β化
-- fSum中，把[1..10]替换为x，为β化。

fGetSquare = (\x n -> x ^ n) 5 2

-------------------------

-- α替换 α - conversion: 在不出现命名冲突的前提下，将函数的参数重新命名
-- bsp. λx -> λy -> x+y 恒等于 λa -> λy -> a + y   此时称为 α等价 α - equivalence

-- β化简 β - reduction：(λx -> x + 2) y -> y + 2 。这样就不用再给x + 2这个函数起名了。
fBetaRedOfAbs = (\x -> abs x) (-5)      --等价于前面的fAbs，就是fAbs的β化简
-----------------------------

---------参数绑定

-- bsp. 计算三角形面积，用海伦-秦九韶公式 S = sqrt( p(p-a)(p-b)(p-c) ), p = (a+b+c)/2
s a b c = let p = (a + b + c ) / 2
    in sqrt (p * (p-a) * (p-b) * (p-c))
-- 在上式中，p会与(a+b+c)/2绑定在一起。(与 表达式 绑定)
xAdd1 = let f x = x + 1 in f 5      -- 6
-- 与 函数f 绑定
xAddy = let x = 2; y = 3 in x + y       -- 5
-- 多个表达式用分号隔开

-- where f = <Expr> 也是绑定

---------------------------------------------Ue8

-----------A2

-- (λx . x y) (λz.z)
--  = (λz.z) y
--  = y
f2a = (\x -> x 5) (\z -> z)  -- 5

-- (λx.x)((λy.y)x)
--  = (λy . y) x
--  = x
f2b = (\x -> x) ((\y -> y) 6)

-- (λx . λy . x (λz . z) y ) (λx . x x)
--  = λy . (λx . x x) (λz . z) y
--  = λy . (λz . z) (λz . z) y
--  = λy . (λz . z) y
--  = λy . y
--  = y
-- f2c = (\x -> \y -> x (\z -> z) y) (\x -> x x)

-- (λg . g (λy . y) ) (λf . λx . f x)
--  = (λf . λx . f x) (λy . y)
--  = λx . (λy . y) x
--  = λx . x
--  = x
f2d = (\g -> g (\y -> y)) (\f -> \x -> f x)

-- (λx . x x) ((λx . x) y)
--  = ((λx . x) y) ((λx . x) y)
--  = y y
-- 

-- (λx . x x) (λx . x) y
--  = (λx . x) (λx . x) y
--  = (λx . x) y
--  = y
-- f2f = (\x -> x x) (\x -> x) y ???
---------------

---------3.略

---------4.

---- a.
-- (λx . (λy . y) x) v
--  = (λy . y) v
--  = v
-- (λy.y) v = v

---- b.
-- (λs.s s) (λf . λs . s) ((λg . λw . g w) w)
--  = (λf . λs . s) (λf . λs . s) ((λg . λw . g w) w)
 = (λs . s) ((λg . λw . g w) w)
 = (λg . λw . g w) w
 = (λg . λx . g x) w
 = λx . w x
---- c.
-- (λp . p (λt . λe . e)) ((λf . λs . λi . i f s) 2 3)
 = ((λf . λs . λi . i f s) 2 3) (λt . λe . e)
 = ((λs .  λi . i 2 s) 3) (λt . λe . e)
 = (λi . i 2 3) (λt . λe . e)
 = (λt . λe . e) 2 3
 = (λe . e) 3
 = 3


main :: IO ()
main = do


    print(f2a)
    print(f2b)
    --print(f2c 6)
    print(f2d (sqrt 4))

---------------------------------------
    print("//////////////////////////////////////////////")
    print(fSum)
    print(fGetSquare)
    print(fBetaRedOfAbs)
    print("//////////////////////////////////////////////")
---------------------------------------