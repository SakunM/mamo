module Tester (zz_act, pad_n)where
import Colors (suc,err,fine,norm)

-- 右パディング
pad_r :: Char -> Int -> String -> String; pad_r c val tar = reverse$take val $reverse$(replicate val c) ++ tar
--左パディング
pad_l :: Char -> Int -> String -> String; pad_l c val tar = take val $tar ++ (replicate val c)
-- 数値のパディング付き文字列へ
pad_n :: Int -> Int -> String; pad_n n val = pad_r '0' n (show val)
--文字列のパディング
pad_s :: Int -> String -> String; pad_s n str = if n < 0 then pad_l ' ' (abs n) str else pad_r ' ' n str

--自前テスト関数の説明付きバージョン
zz_act :: (Eq a,Show a) => String -> a -> a -> String -> String
zz_act title act exp disp =
  let at = norm "@" ; name = pad_s (-20)( at ++ " " ++ title) ++ "    test name is [ " ++ disp ++ " ]" in
    if act == exp then name ++ "    " ++ suc("Succes!") ++ " acutual : " ++ pad_s(-30)(show act) ++ "  =>  " ++ suc("OK!") ++ "passed"
      else name ++ pad_s(25)(" ** " ++ err("Fielid!")) ++ "\n" ++ line2 where
        line2 = pad_s(30)("-- Expect : ") ++ show exp ++ "\n" ++ pad_s(30)("bat was : ") ++ show act

main = do
  putStrLn$zz_act "B008 Test" 15    10 "test 1"
  putStrLn$zz_act "B008 Test" 15    15 "test 2"