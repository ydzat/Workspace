{--1a--
fibs::Int -> Int
fibs i = if i < 3 then 1 else fibs(i-1) + fibs(i-2)
main = print(fibs(10))
--}

{--1b--
suma::Int -> Int
suma n = if n == 1 then 1 else n+suma(n-1)
main = print(suma(10))
--}

{--1c
ggT::Int -> Int -> Int
ggT x y = if y == 0 then x else ggT y (x `mod` y)
main = print(ggT 81 9)
-}

{--2a
fourEqual::Int->Int->Int->Int->Bool
fourEqual a b c d = if (a == b) && (a == c) && (a == d) then True else False
main = print(fourEqual 5 5 5 5)
-}

{--2b
xor3::Bool->Bool->Bool->Bool
xor3 x y z = if (x&&y&&z) || ((not)x&&y&&z) || (x&&(not)y&&z) || (x&&y&&(not)z) then False else True
main = print(xor3 True False False)
-}

{--3a
middleOfThree::Float->Float->Float->Float
middleOfThree x y z | (y<=x && x<=z) || (z<=x && x<=y) = x
                    | (x<=y && y<=z) || (z<=y && y<=x) = y 
                    | (x<=z && z<=y) || (y<=z && z<=x) = z 
main = print(middleOfThree 1.5 2.5 0.5)
-}

{--3b
howManyEqualOfThree::Int->Int->Int->Int
howManyEqualOfFour::Int->Int->Int->Int->Int
howManyEqualOfThree a b c | a==b && a==c = 3
                          | (a==b && a/=c) || (a/=b && a==c) = 2
                          | a/=b && a/=c && b/=c = 1
howManyEqualOfFour a b c d | a==b && a==c && a==d = 4
                           | ( a==b && a==c && a/=d ) || ( a==b && a/=c && a==d ) || ( a/=b && a==c && a==d ) = 3
                           | ( a==b && a/=c && a/=d ) || ( a/=b && a==c && a/=d ) || ( a/=b && a/=c && a==d ) = 2
                           | a/=b && a/=c && a/=d && b/=c && b/=d && c/=d = 1
main = print(howManyEqualOfThree 2 2 3)
main1 = print(howManyEqualOfFour 2 2 3 3)
main2 = print(howManyEqualOfFour 2 2 2 3)
-}

--4a
nand1::Bool->Bool->Bool
nand2::Bool->Bool->Bool
nand1 x y = if x&&y then False else True
nand2 a b = not (a && b)
main1 = print(nand1 True False)
main2 = print(nand2 True False)