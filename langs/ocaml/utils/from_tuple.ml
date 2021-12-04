(* タプルから展開して取り出す系メソッド*)
let to_tp2 lst = match lst with | (a::b::[]) -> (a,b) | _ -> failwith ("other!")
let to_tp3 lst = match lst with | (a::b::c::[]) -> (a,b,c) | _ -> failwith ("other!")
let to_tp4 lst = match lst with | (a::b::c::d::[]) -> (a,b,c,d) | _ -> failwith ("other!")
let to_tp5 lst = match lst with | (a::b::c::d::e::[]) -> (a,b,c,d,e) | _ -> failwith ("other!")