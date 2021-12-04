{- 
-}

module Util(to_i, to_f, to_nums, show_nss', pad_n, pad_s, trim, show_ns, getNumLines, show_nss, isin, notin,
  getStrLines)where

import Data.Char (isSpace)
-- 文字列を数値に
to_i :: String -> Int; to_i s = read s
to_iT = do ez_t "to_i : " (act == exp) where act = 45 + to_i "23"; exp = 68

--文字列を小数値に
to_f :: String -> Float; to_f s = read s
to_fT = do ez_t "to_f :" (act == exp) where act = to_f "0.012"; exp = 0.012

-- 空白区切りの数値文字列を数値のリストへ
to_nums :: String -> [Int]; to_nums = map read.words
to_numsT = do ez_t "to_nums : " (ans == [23,45,67]) where ans = to_nums "23 45 67"

-- 数値のリストをそれらしく見せる
show_ns :: [Int] -> String; show_ns ns = "[" ++ (unwords(to_str(ns)))++ "]" where to_str ns = map(show)ns
show_nsT = do ez_t "show_ns : " (ans == "[1 2 3]") where ans = show_ns [1,2,3]

-- 入れ子の数値リストを入れ子ごとに改行した空白区切りの数値文字列に
show_nss' :: [[Int]] -> String; show_nss' nss = unlines(map (\ns -> show_ns ns ) nss)
show_nss'T = do ez_t "show_nss' : " ("[1 2]\n[3 4]\n[5 6]\n" == show_nss' [[1,2],[3,4],[5,6]])

-- 表を表示するならすべて文字列で渡さないと・・
show_nss :: [[Int]] -> String; show_nss nss = unlines(map (\ns -> unwords(map show ns)) nss)
show_nssT = do ez_t "show_nss : " ("1 2 3\n4 5 6\n" == show_nss [[1,2,3],[4,5,6]])

-- 右パディング
pad_r :: Char -> Int -> String -> String; pad_r c val tar = reverse$take val $reverse$(replicate val c) ++ tar
pad_rT = do ez_t "pad_r : " ("    hoge" == pad_r ' ' 8 "hoge")
--左パディング
pad_l :: Char -> Int -> String -> String; pad_l c val tar = take val $tar ++ (replicate val c)
pad_lT = do ez_t "pad_l : " ("hoge    " == pad_l ' ' 8 "hoge")
-- 数値のパディング付き文字列へ
pad_n :: Int -> Int -> String; pad_n n val = pad_r '0' n (show val)
pad_nT = do ez_t "pad_n : " ("00045" == pad_n 5 45)
--文字列のパディング
pad_s :: Int -> String -> String; pad_s n str = if n < 0 then pad_l ' ' (abs n) str else pad_r ' ' n str
pad_sT = do ez_t "pad_s : " ("    hoge" == pad_s 8 "hoge")

--トリムの実装
trim :: String -> String; trim = f . f where f = reverse . dropWhile isSpace
trimT = do ez_t "trimT : " ("hoge" == trim " hoge   ")

--入れ子のリストのメンバーの存在で振り分ける
isin :: Int -> [[Int]] -> [[Int]]; isin n nss = filter(\ns -> elem n ns)nss
isinT = do ez_t "isin : " ([[1,2,3],[2,3,4]] == isin 3 [[1,2,3],[2,3,4],[5,6,7]])
--入れ子のリストのメンバーの不在で振り分ける
notin :: Int -> [[Int]] -> [[Int]]; notin n nss = filter(\ns ->  not(elem n ns))nss
notinT = do ez_t "notin : " ([[2,3,4],[5,6,7]] == notin 1 [[1,2,3],[2,3,4],[5,6,7]])

--ここだけの内輪のテスト（笑）
ez_t :: String -> Bool -> IO(); ez_t name b = putStrLn$(pad_s (-12) name) ++ show b
--ここだけの内輪のテストの説明付きバージョン
ez_tD :: String -> Bool -> String -> IO(); ez_tD name b disp = putStrLn$(pad_s (-12) name) ++ show b ++ pad_s(30) disp

main = do
  to_iT         -- 文字列を数値に
  to_fT         --文字列を小数値に
  to_numsT      -- 空白区切りの数値文字列を数値のリストへ
  show_nsT      -- 数値のリストをそれらしく見せる
  show_nss'T    -- 入れ子の数値リストを入れ子ごとに改行した空白区切りの数値文字列に
  show_nssT     -- 表を表示するならすべて文字列で渡さないと・・
  pad_rT        -- 右パディング
  pad_lT        --左パディング
  pad_nT        -- 数値のパディング付き文字列へ
  pad_sT        --文字列のパディング
  trimT         --トリムの実装
  isinT         --入れ子のリストのメンバーの存在で振り分ける
  notinT        --入れ子のリストのメンバーの不在で振り分ける

--IOがらみの関数のテストは考え中・・引数分だけ入力から空白区切りの数値をリストにするよ
getInts = do n <- getLine; let y = (map$to_i)$words n in return y
getNumLines :: Int -> IO[[Int]]
getNumLines 1 = do 
  y <- getInts; return [y]
getNumLines n = do
  y <- getInts; z <- getNumLines(n-1)
  let w = [y] ++ z in return w

getStrLines :: Int -> IO[String]
getStrLines n = do sequence[getLine | _ <- [0.. n-1]]
