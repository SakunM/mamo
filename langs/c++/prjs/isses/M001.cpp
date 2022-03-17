#include <map>
using std::make_pair; using std::pair;
#include <tuple>
using std :: tuple; using std :: tie;
#include <queue>
using std::queue;
#include <sstream>
using std::ostringstream;

#include "../../utils/tester.cpp"       // zz_act関数は説明付きテスト 成功時は一行で表し失敗した時はどこが違うか教えるよ
#include "../../utils/from_file.cpp"    //　User_FFはクラスなのでlistメソッドでファイルの内容をとりだすよ
#include "../../utils/print_util.cpp"   // 画面表示に関する色々な関数を定義している
#include "../../utils/from_wrap.cpp"   // 何らかのリストを受け取り何らかの違う構造を返す
#include "../../utils/from_string.cpp" // 文字列を受け取って色々な違う構造を返す
// print_util -> pi,pNs,pNss,ps, pSs,PSss,pc,pb,pf; from_string -> <sstream>, split,tails,to_i,to_nums;
// from_wrap -> <sstream><climits> maxs,mins,sums;
Ss m001(Ss ss){
  Ss fst = split(ss[0],' '), snd = split(ss[1],' ');
  fst.insert(fst.end(),snd.begin(),snd.end());
  return fst;
}
// void test(){ Ss res = m001({"fishing gardening swimming fishing","hunting fishing fishing biting"}); pSs(res);}
void showMap(std::map<string,int> map){
  ostringstream oss;
  for(auto itr = map.begin(); itr != map.end(); ++itr){ oss << "(" << itr->first << "," << itr->second << ")/";}
  Ss res = split(oss.str(), '/'); pSs(res);
}
std::map<string,int> domain(Ss ss){
  std::map<string,int> res;
  for(string s: ss){ if(res[s]){ res[s] += 1;} else { res[s] = 1;}}
  return res;
}
void test() {
  std::map<string,int> res = domain({"fishing","gardening","swimming","fishing","hunting","fishing","fishing","biting"});
  showMap(res);
}

Ss domains(Ss arg) {
  Ss ss = m001(arg); std::map<string,int> map = domain(ss); Ns res;
  for(auto itr = map.begin(); itr != map.end(); ++itr){ res.push_back(itr->second);}
  return {sI(maxs(res))};
} // main
// void test() { Ss res = domains({"fishing gardening swimming fishing","hunting fishing fishing biting"}); pSs(res);}

Ss user(){
  Ss lines;
  string line; std::getline(cin,line); lines.push_back(trim(line));
  std::getline(cin,line); lines.push_back(trim(line));
  // int lim = trim(line).size()-1;
  // for(int i= 0; i<lim; i++){ string s; std::getline(cin, s);  if(s != ""){lines.push_back(trim(s));}}
  return lines;
}
void product() {
  Ss res = user();
  pSs(res);
  // Ss ans = domains(res); for(string an: ans){ ps(an);};
}
void developer(string arg_s, string exp_s, string name){
  User_FF arg(arg_s); Ss ans = domains(arg.list()); User_FF exp(exp_s); zz_act("M001 Test", sSs(ans),sSs(exp.list()), name);
}
void develop() {
  string issue1 = string("a:/pj/mamo/refs/isses/issue1.txt"), result1 = string("a:/pj/mamo/refs/isses/result1.txt"),
         issue2 = string("a:/pj/mamo/refs/isses/issue2.txt"), result2 = string("a:/pj/mamo/refs/isses/result2.txt"),
         issue3 = string("a:/pj/mamo/refs/isses/issue3.txt"), result3 = string("a:/pj/mamo/refs/isses/result3.txt"),
         issue4 = string("a:/pj/mamo/refs/isses/issue4.txt"), result4 = string("a:/pj/mamo/refs/isses/result4.txt"),
         issue5 = string("a:/pj/mamo/refs/isses/issue5.txt"), result5 = string("a:/pj/mamo/refs/isses/result5.txt"),
         issue6 = string("a:/pj/mamo/refs/isses/issue6.txt"), result6 = string("a:/pj/mamo/refs/isses/result6.txt");
  developer(issue1, result1, "test-1"); developer(issue2, result2, "test-2");
  developer(issue3, result3, "test-3"); developer(issue4, result4, "test-4");
  developer(issue5, result5, "test-5"); developer(issue6, result6, "test-6");
}
void refactor() {
  string issue = string("a:/pj/mamo/refs/isses/issue1.txt"), result = string("a:/pj/mamo/refs/isses/result1.txt");
  // User_FF arg(issue); User_FF exp(result); pSs(arg.list()); pSs(exp.list());
  User_FF arg(issue); Ss ans = domains(arg.list()); User_FF exp(result); zz_act("M001 Test", sSs(ans),sSs(exp.list()), "refactor");
}
// M001 m001 domain user
int main(){
  test();
  // refactor();
  // develop();
  // product();
}
