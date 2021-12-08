open String

#use "../../utils/tester.ml"
#use "../../utils/from_file.ml"
#use "../../utils/print_util.ml"
#use "../../utils/to_string.ml"
#use "../../utils/to_wraper.ml"
#use "../../utils/from_wrap.ml"
#use "../../utils/from_string.ml"
#use "../../utils/from_tuple.ml"
#use "../../utils/for_paiza.ml"
#use "../../utils/util.ml"

module L = List
module S = String

let sT2 (s,v) =  "(" ^ s ^ "," ^ sI(v) ^ ")" 
let test_st2() = let res = sT2 ("NNNN",1) in ps res
let sT2s tps = L.map(sT2)tps
let pTps tps = let s = "[" ^ sJoin ";" (sT2s tps) ^ "]" in ps s
let test_pt() = pTps [("NNYN",0);("NNYN",0);("NNNN",1);("NYYN",0)]

let m001 ss = L.map(fun s -> if S.contains s 'Y' then (s,0) else (s,1))ss
let test_m() = let res = m001 ["NNYN";"NNYN";"NNNN";"NYYN"] in pTps res
let snd (s,v) = v
let rec saraly tps i = let sub s = sums(L.map(fun j -> if (S.get s j) = 'Y' then snd(saraly tps j) else 0)(nums0to((L.length tps) -1))) in
  let (s,v) = L.nth tps i in if v = 0 then (s, v + (sub s)) else (s,v)
let test_sl() = let res = saraly [("NNNNNN",1);("YNYNNY",0);("YNNNNY",0);("NNNNNN",1);("YNYNNN",0);("YNNYNN",0)] 1 in ps(sT2 res)  (* exp is exp *)

let domain tps = let dom i tps = let (s,v) = L.nth tps i in if v = 0 then saraly tps i else (s,v)
  in L.map(fun i -> dom i tps)(nums0to ((L.length tps)-1))
let test_d() = let res = domain [("NNNNNN",1);("YNYNNY",0);("YNNNNY",0);("NNNNNN",1);("YNYNNN",0);("YNNYNN",0)]  in pTps res

(* main *)
let domains ss = let res = domain(m001 ss) in let ans = sums(L.map(snd)res) in [sI ans]
let test() = let res = domains ["NNYN";"NNYN";"NNNN";"NYYN"] in pSs res (* exp is exp *)

let user() = let line = read_line() in let lim = (length line) - 1 in let lines = L.map(fun _ -> read_line())(replicate lim 0) in line ::lines

let product() = let u = user()
  in ps(sSL u)
  (* in let ans =domains u in List.iter(fun an -> ps an) ans *)

let developer exp ans name = zz_act ~dsp:name "M001 Test" (sSs ans) (sSs exp)

let develop() =
  let issue1 = "a:/pj/mamo/refs/isses/issue1.txt" and result1 = "a:/pj/mamo/refs/isses/result1.txt" in
  let issue2 = "a:/pj/mamo/refs/isses/issue2.txt" and result2 = "a:/pj/mamo/refs/isses/result2.txt" in
  let issue3 = "a:/pj/mamo/refs/isses/issue3.txt" and result3 = "a:/pj/mamo/refs/isses/result3.txt" in
  let issue4 = "a:/pj/mamo/refs/isses/issue4.txt" and result4 = "a:/pj/mamo/refs/isses/result4.txt" in
  let issue5 = "a:/pj/mamo/refs/isses/issue5.txt" and result5 = "a:/pj/mamo/refs/isses/result5.txt" in
  let issue6 = "a:/pj/mamo/refs/isses/issue6.txt" and result6 = "a:/pj/mamo/refs/isses/result6.txt" in
  developer (domains (ffUser issue1)) (ffUser result1) "test 1";
  developer (domains (ffUser issue2)) (ffUser result2) "test 2";
  developer (domains (ffUser issue3)) (ffUser result3) "test 3";
  developer (domains (ffUser issue4)) (ffUser result4) "test 4";
  developer (domains (ffUser issue5)) (ffUser result5) "test 5";
  developer (domains (ffUser issue6)) (ffUser result6) "test 6"

let refactor() = let issue = "a:/pj/mamo/refs/isses/issue1.txt" and result = "a:/pj/mamo/refs/isses/result1.txt" in
  let arg = ffUser(issue) and exp = ffUser(result)
  (* in ps(sSs arg); ps(sSs exp) *)
  in let ans = domains arg in zz_act ~dsp:"refactor" "M001 Test" (sSs ans) (sSs exp)

(* main M001 m001 domain user *)
let() =
  (* test() *)
  (* refactor() *)
  develop()
  (* product() *)

