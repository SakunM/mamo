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
module A = Array

(* ts => sI,sJoin  fs => to_i,to_nums  tw => num0to,replicate,lines,words,take,drop,any fw => isin,notin, maxs,mins,sums*)
let m001 = function f::s::[] ->  let first = words f and second = words s in first @ second | _ -> failwith "err"
(* let test() = let res = m001 ["fishing gardening swimming fishing";"hunting fishing fishing biting"] in pSs res *)
let rec uniqe = function [] -> [] | x::xs -> if L.exists (fun s -> s = x) xs then uniqe xs else x :: (uniqe xs)
(* let test() = let res = uniqe ["fishing";"gardening";"swimming";"fishing";"hunting";"fishing";"fishing";"biting"] in pSs res *)
let showMap ms = A.iter(fun (k,v) -> printf "(%s,%d)" k v ) ms
let initMap un = let un_a = A.of_list un in A.map(fun a -> (a,0)) un_a
(* let test() = let res = initMap ["hoge";"fuga";"mamo"] in showMap res *)
let setMap s map = for i = 0 to (A.length map)-1 do let (k,v) = map.(i) in if k = s then map.(i) <- (k,v+1) else map.(i) <- (k,v) done
(* let test() = let res = [|("mamo",0);("hoge",0);("fuga",0)|] in setMap "hoge" res; showMap res *)
let domain ss = let un = uniqe ss in let map = initMap un in L.iter (fun s -> setMap s map) ss; map
(* let test() = let res = domain ["fishing";"gardening";"swimming";"fishing";"hunting";"fishing";"fishing";"biting"] in showMap res *)
let domains ss = let fs = m001 ss in let map = domain fs in let ns = A.map(fun (k,v) -> v) map in
  let res = maxs(A.to_list ns) in [sI res]
let test() = let res = domains ["fishing gardening swimming fishing";"hunting fishing fishing biting"] in pSs res
(* main *)

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

