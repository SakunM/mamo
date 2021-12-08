open Printf
#use "a:/PJ/SC/langs/OCaml/utils/to_string.ml"

(* 改行付き表示系メソッド*)
let ps str  = printf "%s\n" str
let pi i    = printf "%d\n" i
let pb b    = printf "%b\n" b
let pf f    = printf "%f\n" f
let pc c    = printf "%c\n" c

(* 改行無し表示系メソッド*)
let pps str  = printf "%s" str
let ppi i    = printf "%d" i
let ppb b    = printf "%b" b
let ppf f    = printf "%f" f
let ppc c    = printf "%c" c

(* 色々なリスト構造の表示 *)
let pSs ss = printf "%s\n" (sSs ss)
let pNs ns = printf "%s\n" (sNs ns)
let pSss sss = printf "%s\n" (sSss sss)
let pNss nss = printf "%s\n" (sNss nss)
