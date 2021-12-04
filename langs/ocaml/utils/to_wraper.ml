#use "a:/PJ/SC/langs/OCaml/utils/print_util.ml"
#use "a:/PJ/SC/langs/OCaml/utils/to_string.ml"

(* リスト生成系メソッド *)
let rec rep0 n = match n with | 0 -> [] | _ -> 0 :: (rep0 (n-1))			(* ｎ個のリストを０で初期化して生成 *)
let rec numsto n = match n with | 0 -> [0] | _ -> n :: (numsto (n-1))	(* ０からｎまでのリストを生成 *)
let nums0to n = List.rev(numsto n)

(* Haskellメソッドの実装 n個の値ｖのリストを作成*) 
let rec replicate n v = if n <= 0 then [] else v :: replicate (n-1) v
(* Haskellメソッドの実装 文字列リストを改行区切りの文字列に変更*)
let lines l_line = Str.split(Str.regexp_string "\n") l_line
(* Haskellメソッドの実装 空白区切りの文字列を文字列リストに変更*)
let words str = Str.split(Str.regexp_string " ") str
(* Haskellメソッドの実装 xsリストの最初からnまでを取得　*)
let rec take n xs = if n = 0 then [] else List.hd xs :: take (n-1)(List.tl xs)
let test_tk() = let res = take 2 [1;2;3;4] in ps(sNs res)  (* exp is exp *)
(* Haskellメソッドの実装 xsリストの最初からｎ個の要素を除いたリストを取得*)
let rec drop n xs = if xs = [] || n = 0 then xs else drop (n-1) (List.tl xs)
let test_dp() = let res = drop 2 [1;2;3;4] in ps(sNs res)

(* 入れ子のリストの行列に関する処理メソッド 行列の入れ替え*)
let rec twTranspose = function []     -> []
	| [l]    -> List.map (fun x -> [x]) l 
	| v :: l -> List.map2 (fun x y -> x::y) v (twTranspose l)

(* 理論値のリストを受け取るメソッド *)
let rec any bs = match bs with [] -> false | hd :: tls -> if hd = true then true else any tls(* 一つでも真なら真*)
let anyT() = ezT "any" (any [1=0;3<2;1=1;5<4])

(* キューを実装*)
class ['a] queue args = object (self)
  val mutable ques = ( args : 'a list ) (* インスタンス変数 *)
  method add x = ques <- ques @ [x]
  method take = let result = List.hd ques in ques <- List.tl ques; result
  method peek = List.hd ques
  method size = List.length ques
end
let queueT() = let que = new queue [] in List.iter(fun it -> que#add it) ["hoge";"fuga";"mamo"];
	let act = que#peek in ezT "queue"("hoge" = act)

 (* OCamlは文字列と文字リストの型は異なる。ここでは、一文字の文字列を一文字ずつリストへ変換する*)
let twCL_S str = Str.split(Str.regexp_string "")str
let twCL_ST () = ezT "ToCL_S" (["h";"o";"g";"e"] = twCL_S "hoge")

(* 引数から始まる１刻みの増加数列を作る nが始まりの数でmがリストのサイズ*)
let rec toNsBy1 n m = if m <= 0 then [] else n :: toNsBy1(n + 1) (m - 1)

let t_w_test cs =
  let ans = toNsBy1 0 5 in ps(sNs ans)

(* let () = t_w_test "go" *)
