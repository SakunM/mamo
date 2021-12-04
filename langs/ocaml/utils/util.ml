#use "a:/PJ/SC/langs/OCaml/utils/to_string.ml"

let rec transpose = function [] -> [] | [xs] -> List.map(fun x -> [x]) xs | x::xs -> List.map2(fun y ys -> y::ys) x (transpose xs)
let transposeT() = let res = transpose[[1;2;3];[4;5;6];[7;8;9]] in ps(sNss res)

let util_tests() =
  transposeT()

(* let() = util_tests() *)