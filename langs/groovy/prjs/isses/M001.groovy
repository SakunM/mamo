import static Integer.parseInt

import static FromFile_G.ffUser
import static Tester_G.zz_act
import static Util.to_nums
import static Util.neg1

def m001(ss){ return to_nums(ss[0]);}
def test_m(){ def res = m001(["10 3 2 5 7 8"]); println(res);}   // exp is

def domain(ns){
  def ans = 0, dp = [];
  for(int i= 0; i<ns.size()-1; i++){
    dp << ns[i]; 
    if( i > 0){ dp[i] = Math.max(dp[i], dp[i-1]);}
    if( i > 1){ dp[i] = Math.max(dp[i], dp[i-2] + ns[i]);}
    ans = Math.max(dp[i], ans);
  }
  for(int i= 0; i<ns.size()-1; i++){
    dp[i] = ns[i+1];
    if( i > 0){ dp[i] = Math.max(dp[i], dp[i-1]);}
    if( i > 1){ dp[i] = Math.max(dp[i], dp[i-2] + ns[i+1]);}
    ans = Math.max(dp[i], ans);
  }
  return ans;
}
def test_d(){ def res = domain([10,3,2,5,7,8]); println(res);}   // exp is

def domains(ss){ // main
  def res = domain(m001(ss));
  return [res.toString()];
}
def test(){ def res = domains(["10 3 2 5 7 8"]); println(res);}

class User { 
  def stdin, lines = [];
  User(){ this.stdin = new BufferedReader(new InputStreamReader(System.in));}
  def gets(stream){ stream.readLine();}
  def set(){
    this.lines << gets(stdin).trim();
    this.lines << gets(stdin).trim();
    // def lim = this.lines[0].size() - 1;
    // (0..<lim).each{ this.lines << gets(stdin).trim()}
  }
  def list(){ return this.lines;}
}

def product(){
  def user = new User(); user.set(); 
  // println(user.list());
  def ans = domains(user.list()); println(ans.join("\n"));
}

def developer(issue,result,name){
  def arg = ffUser(issue); ans = domains(arg.list()); exp = ffUser(result).list();
  zz_act("M001 Test", ans,exp,name);
}

def develop(){
  def issue1 = "a:/pj/mamo/refs/isses/issue1.txt", result1 = "a:/pj/mamo/refs/isses/result1.txt",
      issue2 = "a:/pj/mamo/refs/isses/issue2.txt", result2 = "a:/pj/mamo/refs/isses/result2.txt",
      issue3 = "a:/pj/mamo/refs/isses/issue3.txt", result3 = "a:/pj/mamo/refs/isses/result3.txt",
      issue4 = "a:/pj/mamo/refs/isses/issue4.txt", result4 = "a:/pj/mamo/refs/isses/result4.txt",
      issue5 = "a:/pj/mamo/refs/isses/issue5.txt", result5 = "a:/pj/mamo/refs/isses/result5.txt",
      issue6 = "a:/pj/mamo/refs/isses/issue6.txt", result6 = "a:/pj/mamo/refs/isses/result6.txt";
  developer(issue1,result1,"test-1"); developer(issue2,result2,"test-2");
  developer(issue3,result3,"test-3"); developer(issue4,result4,"test-4");
  developer(issue5,result5,"test-5"); developer(issue6,result6,"test-6");
}   


def refactor(){
  def issue = "a:/pj/mamo/refs/isses/issue1.txt", result = "a:/pj/mamo/refs/isses/result1.txt";
  def arg = ffUser(issue), exp = ffUser(result);
  // println(arg.list()); println(exp.list());
  def ans = domains(arg.list()); exp = exp.list();
  zz_act("M001 Test", ans, exp, "refactor");
}

// main domain user M001 m001
// test();
// refactor();
develop();
// product();