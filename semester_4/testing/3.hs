position :: [Int] -> Int -> Int
position xs n 
		| previous == xs = -1
		| otherwise = length(previous) + 1
	where
		previous = takeWhile (/=n) xs