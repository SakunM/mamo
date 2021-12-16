
// #include <map>
#include <tuple>
using std :: tuple; using std :: tie;
#include <queue>
using std::queue; using std::make_pair; using std::pair;

#include "../../utils/tester.cpp"       // zz_act関数は説明付きテスト 成功時は一行で表し失敗した時はどこが違うか教えるよ
// このモジュールにはcolors.cppが含まれているのでsuc,err,norm,fineが使えるよ
#include "../../utils/from_file.cpp"    //　User_FFはクラスなのでlistメソッドでファイルの内容をとりだすよ
//　このモジュールにはform_string.cppが含まれているので、to_i spllit etc..
#include "../../utils/print_util.cpp"   // 画面表示に関する色々な関数を定義している整数表示はpI,pIL,pILL　文字列表示はpS,pSL,pSLL
//　このモジュールにはto_string.cppが含まれているので、何らかの値をうけて、文字列表現を返すよ sS,sSL,sSLL,sI,sIL,sILL,join etc..
#include "../../utils/from_wrap.cpp"   // 何らかのリストを受け取り何らかの処理をして結果を返すよ、isin,toIL_sL,sumL,minL,maxL etc..
//　このモジュールにはto_string.cppが含まれているので、何らかの値をうけて、文字列表現を返すよ sS,sSL,sSLL,sI,sIL,sILL,join etc..
#include "../../utils/from_string.cpp" // 文字列を受け取って色々な物を返す関数達がいるよ split,tails, to_i, to_nums etc..

Ns m001(Ss ss){ return to_nums(ss[0]);}
void test_m(){ Ns res = m001({"10 3 2 5 7 8"}); pNs(res);}

int domain(Ns ns){
  int ans = 0; Ns bp;
  for(int i= 0; i<ns.size()-1; i++){
    bp.push_back(ns[i]);
    if( i > 0){ bp[i] = std::max(bp[i], bp[i-1]);}
    if( i > 1){ bp[i] = std::max(bp[i], bp[i-2] + ns[i]);}
    ans = std::max(ans, bp[i]);
  }
   for(int i= 0; i<ns.size()-1; i++){
    bp[i] = ns[i+1];
    if( i > 0){ bp[i] = std::max(bp[i], bp[i-1]);}
    if( i > 1){ bp[i] = std::max(bp[i], bp[i-2] + ns[i+1]);}
    ans = std::max(ans, bp[i]);
  }
  return ans;
}
void test_d() { int res = domain({10,3,2,5,7,8}); pi(res); }  // exp is
// main
Ss domains(Ss arg) {
  int res = domain(m001(arg));
  return {to_string(res)};
}
void test() { Ss res = domains({"10 3 2 5 7 8"}); pSs(res);}  // exp is 

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
  // test();
  // refactor();
  develop();
  // product();
}
