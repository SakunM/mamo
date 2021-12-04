module FromFile(user_f) where

import ToString(trim)

user_f :: FilePath -> IO [String]
user_f s = do
  strAll <- readFile s
  return $map trim(lines strAll)

main :: IO ()
main = do
  let issue1 = "a:/pj/sc/lib/rs/issues/issue1.txt"
  arg <- user_f issue1
  putStrLn $head arg