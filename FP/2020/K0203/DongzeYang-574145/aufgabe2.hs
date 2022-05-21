-- Dongze Yang 574145

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