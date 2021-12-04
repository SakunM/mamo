#pragma once

#include <sstream>
using std::stringstream;

#include "to_string.cpp" // 色々な構造を文字列化するモジュール、このモジュールにEzTestが含まれるし、Colorsの関数も使えるよ

// 文字列から何かに変換するモジュールだよ to_i spllit etc..

// 文字列リストを返すスプリット関数の実装、でもデリミタは文字だよ！！
Ss split(const string &str, char sep){
  Ss v; stringstream ss(str); string buffer;
  while( std::getline(ss, buffer, sep) ) { v.push_back(buffer);} return v;
}
void splitT(){ vector<string> act = split("ho/ge", '/'); string exp = "[ho,ge]"; ez_t("split",sSL(act),exp);}

// ベクター系	Haskellのtails関数の実装
Ss tails(string str){
	Ss ts; for(int i=0; i<str.size(); i++){ ts.push_back(str.substr(i));} return ts; }

/** 数値に変換系 **/
//数値化可能な文字を数値に変換
int to_i(const string str){ return std::stoi(str);}
void to_iT(){ ez_t("to_i", to_string(to_i("  3  ")), "3", "文字を数値に変換");}

// 数値に変換可能な空白区切りの文字列を受け取り数値のリストを返す
Ns to_nums(string s){
  Ss ss = split(s,' '); Ns res;
  for(string s: ss ){ res.push_back(to_i(s));}
  return res;
}


void f_f_test(){
  splitT();     // 文字列リストを返すスプリット関数の実装、でもデリミタは文字だよ！！
  to_iT();      //数値化可能な文字を数値に変換
}
// int main(){ f_f_test();}
