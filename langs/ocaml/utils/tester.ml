#use "a:/PJ/SC/langs/OCaml/utils/print_util.ml"
#use "a:/PJ/SC/langs/OCaml/utils/to_string.ml"
#use "a:/PJ/SC/langs/OCaml/utils/colors.ml"

(* これは汎用のテストメソッドなので、テストは無理でもないよ！！*)
let zz_act ?(dsp = "now printing!!") name act exp = 
  let title = sprintf "%s %-10s  test name is  %-15s" (norm "@") name ("<" ^ (fine dsp) ^ ">") and sp = " " in
    let res = if act = exp
      then sprintf "%20s actual : %-20s => %s passed" (suc "Succes!") act (suc "OK!")
      else sprintf "%5s **%s \n %10s %s \n %12s %s" sp (err "Fielid!") sp ("-- Expect : " ^ exp) sp ("bat was : " ^ act)
	in printf "%s %s \n" title res

let tester_test title = 
  zz_act ~dsp:title "Tester Test" (sI 10) (sI 10);
  zz_act ~dsp:title "Tester Test" (sI 10) (sI 5)


(*
let () = tester_test "Teter test"
*)