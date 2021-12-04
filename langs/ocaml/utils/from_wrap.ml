#use "a:/PJ/SC/langs/OCaml/utils/to_string.ml"
#use "a:/PJ/SC/langs/OCaml/utils/print_util.ml"

let toID a = a		(*自分自身をそのまま渡す*)

(* リストメンバーの存在確認系メソッド *)
let isin v ns = List.exists (fun n  -> v = n) ns
let isinT() = ezT "isin" (isin 3 [2;3;4])
let notin v ns = not(isin v ns)
let notinT() = ezT "notin" (notin "a" ["b";"c";"d"])

(* リスト処理系メソッド *)
(* リストの最大値を返す*)
let rec maxs ns = match ns with [] -> 0 | n :: nts -> max n (maxs nts)
let maxsT() = ezT "maxs" (maxs [3;4;5] = 5)

(* リストの最小値を返す*)
let rec mins ns = match ns with [] -> max_int | n :: nts -> min n (mins nts)
let minsT() = ezT ~dsp:"choice min val in list of int" "mins" (sI(mins [1;2;3]) = sI 1)

(* リストの要素の合計を返す*)
let rec sums ns = match ns with [] -> 0 | n :: ns ->  n + (sums ns)
let sumsT() = ezT ~dsp:"return by list sum val" "sum" (sums [1;2;3] = 6)

(* 文字列をひと文字ずつの文字列リストの変換*)
let rec toSL len id str = if len = id then [] else sC(str.[id]) :: (toSL len (id+1) str)
let test_sl() = let res = toSL 3 0 "123" in pSs res  (* ["1";"2","3"] *)

(* 数値のリストから一番大きい数を返す *)
let rec maxs = function [] -> 0 | n :: ns -> max n (maxs ns)
let test_mx() = let res = maxs [3;1;4;10] in pi res  (* exp is exp *)

let u_allTs sc =
  isinT();
  notinT();
  maxsT();   (* リストの最大値を返す*)
  minsT();   (* リストの最小値を返す*)
  sumsT()    (* リストの要素の合計を返す*)

(* let() = u_allTs "go"*)
