#pragma once

#include <iostream>
using std::cin; using std::cout; using std::endl;

#include <vector>
using std::vector;

#include <string>
using std::string; using std::to_string;

#include "colors.cpp"

using Ns    = vector<int>;
using Nss   = vector<vector<int>>;
using Ss    = vector<string>;
using Sss   = vector<vector<string>>;
using Cs    = vector<char>;
using Css   = vector<vector<char>>;

// 何らかの値をうけて、文字列表現を返すよ sS,sSL,sSLL,sI,sIL,sILL,join etc..

// 簡単テスト関数 合否は期待値と実際値をともに文字列化する事だよ なので、文字列化モジュールに置くよ。
void ez_t(string title, string act, string exp, string disp = "説明はまだ無いよ（笑）"){
	string rsp = (act == exp) ? suc("true") : err("false");
	cout << norm("test "); cout.width(22);cout.setf(std::ios::left, std::ios::adjustfield);
	cout << title << ":" << rsp << "    disp : " << fine(disp) << endl;}

void ez_t_T() {
	ez_t("EZ_T Test", "hoge", "hoge", "should true");
	ez_t("EZ_T Test", "hoge", "mamo", "should false");
}

// トリム
string trim(const string& str, const char* trimCharacterList = " \t\v\r\n"){ string result = str;
	string::size_type left = str.find_first_not_of(trimCharacterList);
	if (left != string::npos){
		string::size_type right = str.find_last_not_of(trimCharacterList);
		result = str.substr(left, right - left + 1);}return result;}
void trimT(){ cout << "trim Testまだ作ってないよ（笑）" << endl;}

/* 		リストから		*/
string sS(string s){ return s;}		// これが必要な訳はVSCodeのスニペットの汎化の為だ
// 文字列リストの文字列表現
string sSL(Ss ss){
  string rsp = "["; for(int i=0; i<ss.size()-1; i++){ rsp += ss[i]; rsp += ",";}
	rsp += ss[ss.size()-1];rsp += "]"; return rsp;
}	
void sSLT(){ Ss act = {"hoge","fuga"}; ez_t("sSL", sSL(act), "[hoge,fuga]");}
// 文字列リストの文字列表現
string sSs(Ss ss){
  string rsp = "["; for(int i=0; i<ss.size()-1; i++){ rsp += ss[i]; rsp += ",";}
	rsp += ss[ss.size()-1];rsp += "]"; return rsp;
}	


//入れ子の文字列リストの文字列表現
string sSLL(Sss sss){
	string s = "["; for(int i=0; i<sss.size()-1; i++){ s += sSL(sss[i]); s += ",";}
	s += sSL(sss[sss.size()-1]); s += "]"; return s;
}
void sSLLT(){
	Sss arg = {{"hoge","fuga"},{"mamo","moga"},{"man","ab"}};
	ez_t("sSLL", sSLL(arg), "[[hoge,fuga],[mamo,moga],[man,ab]]");
}
//入れ子の文字列リストの文字列表現
string sSss(Sss sss){
	string s = "["; for(int i=0; i<sss.size()-1; i++){ s += sSL(sss[i]); s += ",";}
	s += sSL(sss[sss.size()-1]); s += "]"; return s;
}

//文字列リストをデリミタでつないで文字列にするよ、デリミタのデフォルトはただつなげる事
string join(const vector<string> &v, const char dmt = 0) {
  string s; s += v[0]; for (int i = 1, c = v.size(); i < c; ++i) { if(dmt){s += dmt;} s += v[i]; }return s;}
void joinT(){ vector<string> v = {"h","o","g","e"}; string h = join(v); ez_t("join",h,"hoge");}
void joinT2(){ vector<string> v = {"h","o","g","e"}; string h = join(v,'\n'); ez_t("join",h,"h\no\ng\ne");}


/* 	　数値から		*/
//数値を文字列に変更
string sI(int n){ return to_string(n);}
void sIT(){ ez_t("sI", sI(3), "3");}
//数値を文字列に変更
string sN(int n){ return to_string(n);}


// 数値ベクターの文字列化
string sIL(vector<int> nums){
	string resp = "[";
	for(int i=0; i<nums.size()-1; i++){ resp += to_string(nums[i]); resp += ",";}
	resp += to_string(nums[nums.size()-1]); resp += "]"; return resp;}
void sILT(){ vector<int> ns = {1,2,3}; ez_t("sIL Test", sIL(ns),"[1,2,3]");}
// 数値ベクターの文字列化
string sNs(vector<int> nums){
	string resp = "[";
	for(int i=0; i<nums.size()-1; i++){ resp += to_string(nums[i]); resp += ",";}
	resp += to_string(nums[nums.size()-1]); resp += "]"; return resp;}


//入れ子の数値リストをそれらしい文字列に変換
string sILL(vector<vector<int>> nss){
	string rsp = "["; for(int i=0; i<nss.size()-1; i++){ rsp += sIL(nss[i]); rsp += ",";}
	rsp += sIL(nss[nss.size()-1]); rsp += "]"; return rsp;}
void sILLT(){ vector<vector<int>> nss = {{1,2},{3,4}}; ez_t("sILL Test", sILL(nss),"[[1,2],[3,4]]");}
//入れ子の数値リストをそれらしい文字列に変換
string sNss(vector<vector<int>> nss){
	string rsp = "["; for(int i=0; i<nss.size()-1; i++){ rsp += sIL(nss[i]); rsp += ",";}
	rsp += sIL(nss[nss.size()-1]); rsp += "]"; return rsp;}

/* 	　配列から		*/
// 文字列配列の文字列化
string sIA(int *nums, int lim){ string resp = "[";	// 数値リストの文字列化
	for(int i=0; i<lim-1; i++){ resp += to_string(nums[i]); resp += ",";}
	resp += to_string(nums[lim-1]); resp += "]"; return resp;}

/** 文字列表現系 **/
//総称型を使って、色々な文字列化可能な型を受け取って文字列を返す関数を作ったよ！！
template <typename T> string to_s(T t){return to_string(t);}
void to_sT(){double arg = 1.0;
	ez_t("to_s", to_s(arg), to_s(1.0), "総称型を使って、色々な型を受け取って文字列を返す関数を作ったよ！！");}

//文字リストの文字列表現(文字列じゃないよ)
string sCL(vector<char> arg){ string rsp = "["; for(int i=0; i<arg.size()-1; i++){ rsp += arg[i]; rsp += ","; }
	rsp += arg[arg.size()-1]; rsp += "]"; return rsp;}
void sCLT(){ vector<char> arg = {'1','2','3'}; ez_t("sCL",sCL(arg), "[1,2,3]"); }

//入れ子の文字リストの文字列表現(文字列じゃないよ)
string sCLL(vector<vector<char>> arg){ string rsp = "["; 
	for(int i=0; i<arg.size()-1; i++){rsp += sCL(arg[i]); rsp += ",";} rsp += sCL(arg[arg.size()-1]); rsp += "]"; return rsp;}
void sCLLT(){ vector<vector<char>> arg = {{'h','o'},{'g','e'}}; ez_t("sCLL",sCLL(arg),"[[h,o],[g,e]]");}

void to_string_tests() {
	ez_t_T();		// 簡単テスト関数 合否は期待値と実際値をともに文字列化する事だよ
  trimT();		// トリム
  sSLT();			// 文字列リストの文字列表現
	sSLLT();		//入れ子の文字列リストの文字列表現
	joinT();		//文字列リストをデリミタでつないで文字列にするよ、デリミタのデフォルトはただつなげる事
	joinT2();		//文字列リストをデリミタでつないで文字列にするよ、デリミタのデフォルトはただつなげる事
	sIT();			//数値を文字列に変更
	sILT();			// 数値ベクターの文字列化
	sILLT();		//入れ子の数値リストをそれらしい文字列に変換
	to_sT(); 		//総称型を使って、色々な文字列化可能な型を受け取って文字列を返す関数を作ったよ！！
	sCLT();			//文字リストの文字列表現(文字列じゃないよ)
	sCLLT();		//入れ子の文字リストの文字列表現(文字列じゃないよ)
}
// int main(){ to_string_tests();}