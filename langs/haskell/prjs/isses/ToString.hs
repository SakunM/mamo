module ToString (trim, sSs, sSss) where

import Data.Char (isSpace)
trim      :: String -> String
trim      = f . f
   where f = reverse . dropWhile isSpace

sSs :: Show a => [a] -> [Char]
sSs xs = '[' : (tail (loop xs)) where
  loop [] = ']' : []
  loop (x:xs) = ',' : show x  ++ loop xs

sSss' :: Show a => [[a]] -> [Char]
sSss' xss = '[' : (loop xss) where
  loop [] = []
  loop (xs : []) =  (tail (sSs xs)) ++ "]"
  loop (xs: xss) = (tail (sSs xs)) ++ (sSss' xss)

sSss xss = '[' : (sSss' xss)

main = do
  putStrLn (sSss [[1,2,3],[4,5,6],[7,8,9]])
  putStrLn (sSs [1])
  putStrLn (sSs ["hoge","fuga"])
  putStrLn (trim "  hoge   ")