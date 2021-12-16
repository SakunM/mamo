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

let m001 ss = to_nums (L.hd ss)
let test_m() = let res = m001 ["10 3 2 5 7 8"] in pNs res

let setter v i xs = let f = take i xs and r = drop (i+1) xs in f @ (v::r)
let test_s() = let res = setter 3 2 [0;0;0;0] in pNs res  (* exp is exp *)

let domain ns dp = 
  let folder1 ac i = let ac1 = setter (L.nth ns i) i ac in
    if i > 0 then let m = max (L.nth ac1 i) (L.nth ac1 (i-1)) in let ac2 = setter m i ac1 in
      if i > 1 then let m2 = max (L.nth ac2 i) ((L.nth ac2 (i-2)) + (L.nth ns i)) in setter m2 i ac2
      else ac2
    else ac1
  and folder2 ac i = let ac1 = setter (L.nth ns (i+1)) i ac in
    if i > 0 then let m = max (L.nth ac1 i) (L.nth ac1 (i-1)) in let ac2 = setter m i ac1 in
      if i > 1 then let m2 = max (L.nth ac2 i) ((L.nth ac2 (i-2)) + (L.nth ns (i+1))) in setter m2 i ac2
      else ac2
    else ac1
  in max (maxs(L.fold_left folder1 dp (nums0to (L.length dp-1)))) (maxs(L.fold_left folder2 dp (nums0to (L.length dp-1))))
let test_d() = let res = domain [10;3;2;5;7;8] [0;0;0;0;0]  in pi res

(* main *)
let domains ss = let ns = m001 ss in let dp = replicate ((L.length ns)-1) 0 in [sI(domain ns dp)]
let test() = let res = domains ["10 3 2 5 7 8"] in pSs res (* exp is exp *)

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

