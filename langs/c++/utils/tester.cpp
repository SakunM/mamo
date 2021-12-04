#pragma once
#include <iostream>
using std::cin; using std::cout; using std::endl;
#include <string>
using std::string; using std::to_string;
#include <boost/format.hpp>
using boost::format;

#include "colors.cpp"


// zz_act関数は説明付きテスト 成功時は一行で表し失敗した時はどこが違うか教えるよ
void zz_act(string title, string act, string exp, string disp="disp is None.") {
  auto first =  format("%1% %2% %3$15s") % norm("@ ") % title % disp; string last = string();
  auto succes = format("%1$20s actual : %2$-20s %3% %4% passed") % suc("Succes!") % act % "=>" % suc("OK!");
  auto failed = format("%2$5s ** %1% \n %2$20s -- Expect : %3% \n %2$22s bat was : %4%") % err("Fieled!") % " " % exp % act;
  if (act == exp){ cout << first << succes << endl;} else { cout << first << failed << endl;}
}
void tester_test() {
  zz_act("Tester Test", "mamo", "mamo","should ture");
}
// int main(){ tester_test();}