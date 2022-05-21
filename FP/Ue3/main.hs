insert :: Int -> [Int] -> [Int]
insert x[] = [x]
insert x (y:ys)
    | x<y = x:y:ys
    | otherwise = y : insert x ys
orderTriple:: [Int] -> [Int] -> [Int]
orderTriple xs [] = xs
orderTriple xs (y:ys) = orderTriple (insert y xs) ys
main = print(orderTriple [3,6,5,7,2])