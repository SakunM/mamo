#use "a:/PJ/SC/langs/OCaml/utils/print_util.ml"
#use "a:/PJ/SC/langs/OCaml/utils/to_wraper.ml"
#use "a:/PJ/SC/langs/OCaml/utils/to_string.ml"

let read_to_file path = let chan = open_in path in let buf = Buffer.create 4096 in
  let rec loop () = let line = input_line chan in Buffer.add_string buf line; Buffer.add_char buf '\n'; loop () in
    try loop() with End_of_file -> Buffer.contents buf

let ffUser path = let ls = lines(read_to_file path) in List.map(fun l -> String.trim l) ls

let f_f_test go = let issue1 = "a:/pj/sc/lib/rs/issues/issue2.txt"in let ans = ffUser issue1 in ps (sSL ans)

(* let() = f_f_test "go"*)
