#encoding: UTF-8
require '../../utils/tester.rb'; require '../../utils/from_file.rb'
require '../../utils/from_string.rb'; require '../../utils/to_string.rb'

@salaries
def m001(ss) l = ss.size(); @salaries = Array.new(l,0) end
def test_m() m001 ["N"]; p(@salaries) end   #exp is exp

def getSaraly(i, ss)
  if @salaries[i] == 0 then
    salary = 0; s = ss[i]
    for j in 0...s.size() do if s[j] == 'Y' then salary += getSaraly(j,ss) end end
    if salary == 0 then salary = 1 end
    @salaries[i] = salary
  end
  @salaries[i]
end

def domain(ss)
  total = 0
  for i in 0...ss.size() do total += getSaraly(i,ss) end
  total
end
def test_d() m001(ss); res = domain ["NNYN","NNYN","NNNN","NYYN"]; p res end   #exp is exp

def domains(ss) # main
  m001(ss)
  res = domain(ss)
  [res.to_s]
end
def test()  res = domains ["N"]; p res end

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
  issue1 = "a:/pj/sc/lib/rs/issues/issue1.txt"; result1 = "a:/pj/sc/lib/rs/issues/result1.txt"
  issue2 = "a:/pj/sc/lib/rs/issues/issue2.txt"; result2 = "a:/pj/sc/lib/rs/issues/result2.txt"
  issue3 = "a:/pj/sc/lib/rs/issues/issue3.txt"; result3 = "a:/pj/sc/lib/rs/issues/result3.txt"
  issue4 = "a:/pj/sc/lib/rs/issues/issue4.txt"; result4 = "a:/pj/sc/lib/rs/issues/result4.txt"
  issue5 = "a:/pj/sc/lib/rs/issues/issue5.txt"; result5 = "a:/pj/sc/lib/rs/issues/result5.txt"
  issue6 = "a:/pj/sc/lib/rs/issues/issue6.txt"; result6 = "a:/pj/sc/lib/rs/issues/result6.txt"
  developer(issue1,result1,"test-1"); developer(issue2,result2,"test-2");
  developer(issue3,result3,"test-3"); developer(issue4,result4,"test-4");
  developer(issue5,result5,"test-5"); developer(issue6,result6,"test-6");
end
def refactor()
  issue = "a:/pj/sc/lib/rs/issues/issue1.txt"; result = "a:/pj/sc/lib/rs/issues/result1.txt"
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