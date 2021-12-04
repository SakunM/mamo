(* 文字列への変換系メソッド *)
#use "a:/PJ/SC/langs/OCaml/utils/colors.ml"


let sB b = string_of_bool(b)  (* 真偽値から*)

(* これは世界一シンプルなテストだよ！！*)
let ezT ?(dsp = "now printing!!") title b = let bb = if b = true then (suc (sB b)) else (err (sB b)) in
  Printf.printf "%s %-13s:%s   %30s\n" (norm "TEST") title bb (fine dsp)

let sS s = s                  (* 文字列を文字列にする?*)
let sI n = string_of_int(n)		(* 数値から*)
let sN n = string_of_int(n)		(* 数値から*)
let sIsBT() = ezT ~dsp:"sI 4 => \"4\"" "sI" ((sI 4) = "4")

let sF f = 	string_of_float f	(* フロート値を文字列に変更 *)
let sFT() = ezT~dsp:"sF 0.4 => \"0.4\"" "sF" ((sF 0.4) = "0.4")

(* 文字列リストをデリミタ付きの文字列に変換 *)
let rec sJoin dmt list = match list with [] -> "" | [hd] -> hd | hd :: tl -> hd ^ dmt ^ sJoin dmt tl
let sJoinT() = ezT "sJoin" ("hoge/fuga/mamo" = sJoin "/" ["hoge";"fuga";"mamo"])

let slIL ns = List.map(fun n -> sI n)ns	(* 数値リストの各要素を文字列に変換する *)
(* 数値リストの文字列化 *)
let sIL ns = "[" ^ sJoin ";" (slIL ns) ^ "]" (* リストを文字列化してみる*)
let sNs ns = "[" ^ sJoin ";" (slIL ns) ^ "]" (* リストを文字列化してみる*)
let sILT() = ezT "sIL" (sIL [1;2;3] = "[1;2;3]")

(* 入れ子の数値リストの文字列化 *)
let sILL(nss) = let sss = List.map(fun ns -> sIL ns)nss in
	let ins = sJoin ";" sss in "[" ^ ins ^ "]" 
let sNss(nss) = let sss = List.map(fun ns -> sIL ns)nss in
	let ins = sJoin ";" sss in "[" ^ ins ^ "]" 
let sILLT() = ezT "sILL" (sILL [[1;2];[3;4]] = "[[1;2];[3;4]]")

(* 数値リストから文字列への変換系メソッドで、主に途中経過の結果を知るために使うよ。なので’が付いてる*)
let rec uw_lst' nums = match nums with [] -> "" | [hd] -> hd | hd :: tl -> hd ^ ";" ^ uw_lst' tl
let toStr_lst' nums = "[" ^ (uw_lst' nums) ^ "]"

(* Haskellメソッドの実装 *) 
let tsUnwords list = sJoin " " list

(* 文字列リストをそれらしく見せるよ*)
let strL strs = "[" ^ sJoin ";" strs ^ "]"
let sSs strs = "[" ^ sJoin ";" strs ^ "]"
let strLT() = ezT "strL" ("[hoge;fuga]" = strL ["hoge"; "fuga"])

(*文字列配列のそれらしい表現 *)
let sSL ss = "[" ^ (sJoin ";" ss) ^ "]"

(*入れ子の文字列配列のそれらしい表現 *)
let sSLL sss = "["^ (sJoin ";" (List.map(fun ss -> sSL ss)sss)) ^ "]"
let sSss sss = "["^ (sJoin ";" (List.map(fun ss -> sSL ss)sss)) ^ "]"

(* Charを一文字も文字のリストに変換 *)
let sC c = String.make 1 c
let sCT() = ezT "sC" ("c" = sC 'c')

let t_s_test sss =
	sIsBT();   	(* 数値から文字列への変換系メソッド *)
  sFT();      (* フロート値を文字列に変更 *)
  sJoinT();   (* 文字列リストをデリミタ付きの文字列に変換 *)
  sILT();     (* リストを文字列化してみる*)
  sILLT();    (* 入れ子の数値リストの文字列化 *)
  strLT();    (* 文字列リストをそれらしく見せるよ*)
  sCT()       (* Charを一文字も文字のリストに変換 *) 

(* let() = t_s_test "go" *)