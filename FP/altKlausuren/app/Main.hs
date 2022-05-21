module Main where

import System.Environment()

--2017-----------------------

-- 1.

--    a) filterTriples mittels List-Comprehension implementieren. 使用列表推导实现filterTriples
   
--    b) swapPairs implementieren, um die Reihenfolge der Tupelelemente einer Liste beliebigen Datentyps zu vertauschen.
        --实现swapPairs以交换任何数据类型列表的元组元素的顺序。
--    c) Polymorphen algebraischen Datentyp BinTree für binäre Bäume implementieren.
        --为二叉树实现多态代数数据类型BinTree。
--       * Die inneren Knoten und Blattknoten sollen einen Wert speichern.
--       * Implementierung von depthBinTree zur Bestimmung der Baumtiefe.


-- 2.

--    a) LI-/LO-Reduktion LI / LO降低
   
--    b) f x = x * x mittels LI-, LO-Reduktion.
   
--    c) Reduktionsstrategie bei unendlichen Listen, Auswertung bei "take 2 zeros"无限列表的归约策略，评估“取2个零”
   
   
-- 3. Induktion sum xs + sum ys = sum (xs ++ ys) 归纳法


-- 4.

--    a) Bestimmung frei/gebunden 测定自由/有界
   
--       * λa.a b c
--       * λa.a (λb.b) b (λc.c) c
--       * λd.(λa.(λb.(λc.c d) b c) a b) d a

--    b) Äquivalenz zeigen. 显示等效性。
   
--       * (λa.a c) (λb.b) ↔ c
--       * ((λa.a a) (λb.b)) (λc.c c) ↔ λd.d d
--       * λc.(λb.(λa.b a) c) a ↔ λd.a d

-- 5.

--    a) Regel zur Definition der Semantik mittels IMP für "if b then c". 使用IMP为“ if b then c”定义语义的规则。
   
--    b) Das gleiche für "repeat c until b". 对于“重复c直到b”也是如此。
   
--    c) ⟨c_1, σ⟩ → σ''    ⟨c_0, σ''⟩ → σ'
--       ---------------------------------
--           ⟨myst(c_0, c_1), σ⟩ → σ'
    
--       * Funktionalität?功能性？
--       * Begründung der Äquivalenz von myst(myst(c', c''), c''')) und myst(c', myst(c'', c''')).
        --等价性的证明。

-- 6.

--    a) Definition partieller Korrektheit.部分正确性的定义。
   
--    b) Nachweis der partiellen Korrektheit.部分正确性的证明
   
--       { x > 0 ∧ z = 0 ∧ i = 0 }  while i < x do
--                                      i := i + 1;
--                                      z := z + y    { z = x * y }

-----------------------------
-----------------------------
--WS11-12

--1. Summe der Elemente
--(Int,Int,Int) -> Int
--(1,2,3) --> 1+2+3 --> 6
sumList :: (Int,Int,Int) -> Int
sumList (a,b,c) = a + b + c

--2. Tupel rotieren
--见Ue 4

--3. beide Listen zusammenführen und doppelte Elemente nur einmal 合并列表和重复项仅一次
--[1,2,3,4] -> [3,4,5,6,7] -> [1,2,3,4,5,6,7]
zuf :: [Int] -> [Int] -> [Int]
zuf x y = [z | z<-x , elem z y == False] ++ y

--4. nur die Elemente, welche in der ersten Liste sind, aber nicht in der zweiten 仅在第一个列表中的元素
nurInFst :: [Int] -> [Int] -> [Int]
nurInFst x y = [z | z<-x , elem z y == False]

--5. Ist in der Liste jedes Element nur einmal enthalten? 每个元素只出现1次？
nurEinMal :: [Int] -> Bool
nurEinMal [] = True
nurEinMal (x:xs) | elem x xs == True = False
    | otherwise = nurEinMal xs


--------------------------------
--------------------------------
--WS10-11
--A1.
--a1. zur Umwandlung eines gegebenen Tripels in eine dreielementige Liste 
--将给定的三元组转换为三元组列表
umTL :: (Int,Int,Int) -> [Int]
umTL (a,b,c) = [a] ++ [b] ++ [c]

--a2.
--反转a
umLT :: [Int]->(Int,Int,Int)
umLT [a,b,c] = (a,b,c) 

--b. Schreiben Sie eine Funktion, die fuer einen gegebenen Integer n eine Liste aller Tripel 
--(a,b,c) mit (a<=b<=c) und a+b+c=n erzeugt.
--aufgabe1b :: Int -> [(Int,Int,Int)]
aufgabe1b x = [(a,b,c) | a<-[0..10], b<-[0..10], c<-[0..10],(a<=b && b<=c), a+b+c==x]

--c.Definieren Sie eine generische Funktion "tripleSort", 
--die eine Liste von Integertripeln sortiert. 
--Eine Funktion für den Vergleich zweier Integertripel soll 
--als Parameter von "tripleSort" übergeben werden.
--定义一个通用函数“ tripleSort”，该函数对整数三元组列表进行排序。 
--比较两个整数三元组的函数应作为“ tripleSort”的参数传递。

--tripleSort :: (Int,Int,Int) -> (Int,Int,Int)
--不会

--A2. 
--a.取列表中指定区间的元素
--eg: [7,4,3,1,9,5] 2,4 --> [4,3,1]
fromTo :: [Int]->Int->Int -> [Int]
fromTo l a b = drop (a-1) (take b l)

--b.交集
--[1..5] [3..10] -->[3,4,5]

interSect :: [Int]->[Int]->[Int]
interSect a b = [x | x <- a, elem x b == True]

--c. 运算映射
--auswahl Funktion
f :: t -> (t -> Bool) -> Bool
f a op| op(a) == True = True
        |otherwise = False
partition :: [a] -> (a -> Bool) -> ([a], [a])
partition x op = ([y|y<-x,(f y op) ==True],[y|y<-x, (f y op) == False])

--A7.
-- --a.
-- EXPR : {+,-,*,/,数字}
-- TERM : {*,/,+,-,数字}
-- FAKTOR : {(+,-,*,/,数字),0...9}

-- --b.
-- EXPR ==> TERM ==> TERM * FAKTOR ==> FAKTOR * 3 ==> (EXPR) * 3 ==> (EXPR-TERM) * 3 ==> (TERM - FAKTOR) * 3 ==> (FAKTOR - 5) * 3 ==> (9-5)*3


main :: IO ()
main = do

-------------------------------
    --WS11-12
    print(sumList (1,2,3))

    --3.
    print(zuf [1,2,3,4] [3,4,5,6,7])
    --4.
    print(nurInFst [1,2,3,4] [3,4,5,6,7])
    --5.
    print(nurEinMal [1,2,2,3])
    print(nurEinMal [1,2,3,4])
-------------------------------
    --WS10-11
    --A1
    --a.
    print(umTL (1,2,3))
    print(umLT [1,2,3])
    --b.
    --print(aufgabe1b 5)

    --A2.
    --a.
    print(fromTo [7,4,3,1,9,5] 2 4)

    --b.
    print(interSect [1..5] [3..10])

    --c.
    print(partition [1,5,3,6,7] (<4))


