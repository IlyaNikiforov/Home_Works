divisors :: Int -> [Int]
divisors n = [m | m <- [1..n `div` 2], mod n m == 0]

primes = [n | n <- [1..], isPrime n]
         where isPrime x = (divisors x == [1])