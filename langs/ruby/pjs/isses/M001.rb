#encoding: UTF-8
require '../../utils/tester.rb'; require '../../utils/from_file.rb'
require '../../utils/from_string.rb'; require '../../utils/to_string.rb'

def m001(ss) to_nums ss[0] end
def test_m() res = m001 ["10 3 2 5 7 8"]; p(res) end   #exp is exp

def domain(ns)
  n = ns.size; ans = 0; bp = [];
  for i in 0..n-2 do
    bp << ns[i]
    if i > 0 then bp[i] = [bp[i],bp[i-1]].max end
    if i > 1 then bp[i] = [bp[i], bp[i-2] + ns[i]].max end
    ans = [ans, bp[i]].max
  end
  for i in 0..n-2 do
    bp[i] = ns[i+1]
    if i > 0 then bp[i] = [bp[i],bp[i-1]].max end
    if i > 1 then bp[i] = [bp[i],bp[i-2] + ns[i+1]].max end
    ans = [ans,bp[i]].max
  end
  ans
end
def test_d() res = domain [10,3,2,5,7,8]; p res end   #exp is exp

def domains(ss) # main
  arg = m001(ss)
  res = domain(arg)
  [res.to_s]
end
def test()  res = domains ["1 2 3 4 5 1 2 3 4 5"]; p res end

def user()
  res = [gets.strip!]
  res << gets.strip!;
  # lim = res[0].size() - 1
  # lim.times{ res << gets.strip!}; 
  return res
end

def product()
  u = user;
  # p u
  res = domains(u); puts (res.join("\n"))
end

def developer(issue,result,name)
  ans = domains((ffUser issue).all()); exp = (ffUser result).all(); zz_act "M001 Test", sNs(ans), exp, name
end
def develop() 
  issue1 = "a:/pj/mamo/refs/isses/issue1.txt"; result1 = "a:/pj/mamo/refs/isses/result1.txt"
  issue2 = "a:/pj/mamo/refs/isses/issue2.txt"; result2 = "a:/pj/mamo/refs/isses/result2.txt"
  issue3 = "a:/pj/mamo/refs/isses/issue3.txt"; result3 = "a:/pj/mamo/refs/isses/result3.txt"
  issue4 = "a:/pj/mamo/refs/isses/issue4.txt"; result4 = "a:/pj/mamo/refs/isses/result4.txt"
  issue5 = "a:/pj/mamo/refs/isses/issue5.txt"; result5 = "a:/pj/mamo/refs/isses/result5.txt"
  issue6 = "a:/pj/mamo/refs/isses/issue6.txt"; result6 = "a:/pj/mamo/refs/isses/result6.txt"
  developer(issue1,result1,"test-1"); developer(issue2,result2,"test-2");
  developer(issue3,result3,"test-3"); developer(issue4,result4,"test-4");
  developer(issue5,result5,"test-5"); developer(issue6,result6,"test-6");
end
def refactor()
  issue = "a:/pj/mamo/refs/isses/issue1.txt"; result = "a:/pj/mamo/refs/isses/result1.txt"
  # ans = (ffUser issue).all; exp = (ffUser result).all; p ans; p exp;
  ans = domains ((ffUser issue).all); exp = (ffUser result).all;
  zz_act "M001 Test", sNs(ans), exp, "refactor"
end

# main M001 m001 domain user
if __FILE__ == $0 then
  # test
  # refactor
  develop
  # product
end 