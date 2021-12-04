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

let m001 = function s::[] -> s | _ -> failwith "err"
let test_t() = let res = m001 ["YYYY"]in ps res

let replace cs f v = Str.global_replace (Str.regexp_string f) v cs
let test_rp() = let res = replace (replace "YNYN" "Y" "0") "N" "1" in ps res

let domain cs = if String.contains cs 'Y'= false then 16 else if String.contains cs 'N' = false then 1 else
  let res = replace(replace cs "Y" "0") "N" "1" in (int_of_string ("0b" ^ res) + 1)
let test_d() = let res = domain "YNYY" in pi res

(* main *)
let domains ss = ["1"]
let test() = let res = domains ["NNNN"] in pSs res (* exp is exp *)

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

