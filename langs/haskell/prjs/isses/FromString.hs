module FromString (toI,to_nums,neg1) where
import Tester(zz_act)

-- 文字を数値に
toI :: String -> Int; toI s = read s
test_toI = let res = toI "7" in (zz_act "toI Test" res  7  "hope so..")  -- 7

-- 空白区切りの数値文字列を数値のリストへ
to_nums :: String -> [Int]; to_nums = map read.words
test_to_nums = let res = to_nums "23 43 67" in (zz_act "to_nums Test" res [23,43,67] "hope so..")

-- １から始まる数値リストを０から始まる数値リストに変換　Paize対応
neg1 :: [Int] -> [Int]; neg1 = map(\n -> n - 1)
test_to_neg1 = let res = neg1$to_nums "3 4 5" in (zz_act "neg1 Test" res [2,3,4] "good!")

main = do
  putStrLn test_toI         -- 文字を数値に
  putStrLn test_to_nums     -- 空白区切りの数値文字列を数値のリストへ
  putStrLn test_to_neg1     -- １から始まる数値リストを０から始まる数値リストに変換　Paize対応

