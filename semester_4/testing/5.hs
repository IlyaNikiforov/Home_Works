data PrintedProduct =  Book { 
    			        name :: String,
				author :: String,
				price :: Int 
			    }
				|
		       Magazine {
				    name :: String,
				    year :: Int,
				    number :: Int,
				    price :: Int
				}

printedProductListPrice :: [PrintedProduct] -> Int
printedProductListPrice = foldr ((+) . price) 0