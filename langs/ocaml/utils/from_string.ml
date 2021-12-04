(* 文字列からいろいろな型へ変換 preFixはto*)
#use "a:/PJ/SC/langs/OCaml/utils/print_util.ml"
#use "a:/PJ/SC/langs/OCaml/utils/to_string.ml"
#use "a:/PJ/SC/langs/OCaml/utils/to_wraper.ml"


let toI s = int_of_string(String.trim s)	(* 文字列から数値への変換系メソッド *)
let to_i s = int_of_string(String.trim s)	(* 文字列から数値への変換系メソッド *)
let toIL ss = List.map(fun s -> toI s) ss (* 数値化可能な文字列のリストを　数値リストに変換*)

(* 文字列からフロート値への変換系メソッド *)
let toF_S s = float_of_string(String.trim s)
let toF_ST() = ezT ~dsp:"toF_S \"0.01\" => 0.01" "toF_S" (toF_S "0.01" = 0.01)

(*  空白区切りの文字列を受け取り、数値のリストを返す*)
let to_nums str = toIL (words str)
let to_numsT ()=  ezT ~dsp:"to_nums \"12 34\" => [12;34]" "to_nums" ((sIL(to_nums "12 34")) = (sIL [12;34]))



let f_s_test cs =
  to_numsT()

(* let() = f_s_test "go"*)
