expr' :: [Double] -> Double -> Double -> (Double, Double)
expr' [] s p = (s, p)
expr' (x:xs) s p = expr' xs (s + x) (p * (cos x))

expr :: [Double] -> Double
expr xs = (fst result) / (snd result)
    where result = expr' xs 0 1