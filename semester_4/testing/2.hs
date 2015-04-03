data Tree a = Leaf a | Branch (Tree a) a (Tree a)
treeNegative :: Tree Int -> [Int] -> [Int]
treeNegative (Leaf a) xs = if (a < 0) then a : xs 
				      else xs
treeNegative (Branch lch a rch) xs = if (a < 0) then treeNegative rch (a : (treeNegative lch xs))
						else treeNegative rch (treeNegative lch xs)
finfNegative :: Tree Int -> [Int]
findNegative tree = treeNegative tree []
