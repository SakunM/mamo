import Data.List (transpose,tails,isPrefixOf,permutations)
import qualified Data.Map as Map
import Data.Maybe (fromMaybe, fromJust)
import Control.Monad(guard, MonadPlus, mzero, mplus, when)
import Control.Monad.ST (ST)
import Control.Applicative(pure)
import Numeric(showHex, readInt)
import Data.Char(digitToInt)

import FromFile(user_f)
import Tester(zz_act,pad_n)
import FromString(toI,to_nums,neg1)
import Util(isin,notin,show_nss)

m001 :: [String] -> [Int]
m001 (s:_) =  to_nums s
test_m = let res = m001 ["10 3 2 5 7 8"] in show res  -- exp is

setter :: a -> Int -> [a] -> [a]
setter v i xs = f ++ (v:r) where f = take i xs; r = drop (i+1) xs
test_s = let res = setter 10 0 [0,0,0,0,0] in show res

domain :: (Num a, Ord a) => [a] -> [a] -> a
domain ns dp = max (maximum (foldl(folder1) dp [0..(length dp)-1])) (maximum (foldl(folder2) dp [0..(length dp)-1])) where
  folder1 ac i = let ac1 = setter (ns!!i) i ac in if i > 0 
    then let m = max (ac1!!i) (ac1!!(i-1)) in let ac2 = setter m i ac1 in if i > 1
      then let m2 = max (ac2!!i) (ac2!!(i-2) + ns!!i) in setter m2 i ac2
      else ac2
    else ac1
  folder2 ac i = let ac1 = setter (ns!!(i+1)) i  ac in if i > 0
    then let m = max (ac1!!i) (ac1!!(i-1)) in let ac2 = setter m i ac1 in if i > 1
      then let m2 = max (ac2!!i) (ac2!!(i-2) + ns!!(i+1)) in setter m2 i ac2
      else ac2
    else ac1
test = let res = domain [10,3,2,5,7,8] [0,0,0,0,0] in show res

domains :: [String] -> [String]
domains ss = let ns = m001 ss; dp = replicate (length ns - 1) 0 in [show $domain ns dp]
test_ds = let res = domains ["10 3 2 5 7 8"] in show res

user :: IO [String]; user = do 
  -- line <- getLine; o
  -- let lim  = (length line) - 2
  -- tbls <- sequence [getLine | _ <- [0..1]]
  line1 <- getLine
  line2 <- getLine
  return ([line1,line2])

paiza :: IO String; 
paiza = do
  arg <- user
  -- return (show arg)
  let ans = domains arg in return (unlines ans)

from_file :: FilePath -> IO [String]; from_file path = user_f path

developer:: String -> String -> String -> IO String; developer issue result name =  do
  arg <- from_file issue; exp <- from_file result; let ans = domains(arg)
  return(zz_act "M001 Test" ans exp name)


develop :: IO String; develop = do
  let issue1 = "a:/pj/mamo/refs/isses/issue1.txt"; result1 = "a:/pj/mamo/refs/isses/result1.txt"
  let issue2 = "a:/pj/mamo/refs/isses/issue2.txt"; result2 = "a:/pj/mamo/refs/isses/result2.txt"
  let issue3 = "a:/pj/mamo/refs/isses/issue3.txt"; result3 = "a:/pj/mamo/refs/isses/result3.txt"
  let issue4 = "a:/pj/mamo/refs/isses/issue4.txt"; result4 = "a:/pj/mamo/refs/isses/result4.txt"
  let issue5 = "a:/pj/mamo/refs/isses/issue5.txt"; result5 = "a:/pj/mamo/refs/isses/result5.txt"
  let issue6 = "a:/pj/mamo/refs/isses/issue6.txt"; result6 = "a:/pj/mamo/refs/isses/result6.txt"
  res1 <- developer issue1 result1 "test 1"; res2 <- developer issue2 result2 "test 2"
  res3 <- developer issue3 result3 "test 3"; res4 <- developer issue4 result4 "test 4"
  res5 <- developer issue5 result5 "test 5"; res6 <- developer issue6 result6 "test 6"
  -- return (res1 ++ "\n" ++ res2 ++ "\n" ++ res3 ++ "\n" ++ res4)
  -- return (res1 ++ "\n" ++ res2 ++ "\n" ++ res3 ++ "\n" ++ res4 ++ "\n" ++ res5)
  return (res1 ++ "\n" ++ res2 ++ "\n" ++ res3 ++ "\n" ++ res4 ++ "\n" ++ res5 ++ "\n" ++ res6)

refactor :: IO String; refactor = do
  let issue  = "a:/pj/mamo/refs/isses/issue1.txt"; result = "a:/pj/mamo/refs/isses/result1.txt"
  arg  <- from_file  issue; exp <- from_file result
  -- return((unlines arg) ++ (unlines exp))
  return (zz_act "M001 Test" (domains(arg)) exp  "refactor")

-- M001 m001 domain domains user permutations
main = do
  -- ans <- paiza
  ans <- develop
  -- ans <- refactor
  -- let ans = test
  putStrLn ans