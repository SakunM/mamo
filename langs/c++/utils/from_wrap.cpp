#pragma once

#include <sstream>
using std::stringstream;

#include <climits> // INT_MAX

#include "to_string.cpp" // 色々な構造を文字列化するモジュール、このモジュールにEzTestが含まれるし、Colorsの関数も使えるよ

// 何らかのリストを受け取り何らかの処理をして結果を返すよ、isin,toIL_sL,toCLL_SL,tosL_CLL,toSL_IL,toSLL_ILL,maxs,mins,sumL,minL,maxL etc..

// 総称型のisin
template<typename T> bool isin(T e, vector<T> es){ for(int i=0; i<es.size(); i++){ if(es[i] == e){return true;}} return false;}
void isinT(){ cout << "isin Testまだ作ってないよ（笑）" << endl;}

// ベクタの要素の中に同じ要素が含まれているか検査する。一応総称型で作ってみたよ（笑）。Haskellのelemの実装だ。
template<typename T> bool elem(T v, vector<T> xs){ for(T n: xs){ if(n == v){return true;}} return false;}

//文字列リストを数値のリストに変換
Ns toIL_SL(const vector<string> strs){ vector<int>v; 
	for(int i=0; i<strs.size(); i++){ v.push_back(std::stoi(strs[i]));} return v;}
void toIL_SLT(){ Ss arg = {"1","2","3"}; Ns act = toIL_SL(arg);
	ez_t("toIL_SL", sIL(act), "[1,2,3]", "文字列リストを数値のリストに変換");}

/** 文字列リスト変換系 **/
//文字列リストから入れ子の文字リストへ
Css toCLL_SL(Ss ss){
  vector<vector<char>> resp;
	for(int i=0; i<ss.size(); i++){
    Cs cs; 
		for(int j=0; j<ss[i].size(); j++){
      cs.push_back(ss[i][j]);} resp.push_back(cs); 
    }
  return resp;
}
//入れ子の文字リストから文字列リストへ
Ss toSL_CLL(Css ccc){
  vector<string> resp;
	for(int i=0; i<ccc.size(); i++){
    string res;
    for(int j=0; j<ccc[i].size(); j++){
      res += ccc[i][j];}resp.push_back(res);
    }
	return resp;
}

//交互に入れ替える事でテスト完了！！
void toCLL_SLandtoSL_CLLT(){
  Ss arg = {"hoge","fuga"}; Css act = toCLL_SL(arg);
	Ss exp = toSL_CLL(act); 
	ez_t("toCLL_SL and toSL_CLL", sSL(exp),"[hoge,fuga]", "交互に入れ替える事でテスト完了！！");
}

//数値のリストを文字列リストへ変換
Ss toSL_IL(Ns ns){ Ss rsp;
	for(int i=0; i<ns.size(); i++){ rsp.push_back(to_string(ns[i]));} return rsp; }
void toSL_ILT(){ Ns arg = {1,2,3}; Ss act = toSL_IL(arg);
	ez_t("ToSL_IL Test", sSL(act), "[1,2,3]","数値のリストを文字列リストへ変換");}

//入れ子の数値リストを入れ子の文字列リストに変換
Sss toSLL_ILL(Nss nss){ Sss rsp;
	for(int i=0; i<nss.size(); i++){ rsp.push_back(toSL_IL(nss[i]));} return rsp;}
void toSLL_ILLT(){ Nss arg = {{1,2},{3,4}}; Sss act = toSLL_ILL(arg);
	ez_t("ToSLL_ILL Test", sSLL(act), "[[1,2],[3,4]]","入れ子の数値リストを入れ子の文字列リストに変換"); }

/** 数値配列の操作系 **/

// 数値配列の最大値を返す
int maxsA(int *ms,int l){int m = 0;       for(int i=0;i<l; i++){m = m > ms[i] ? m : ms[i];} return m;}
void maxsAT(){int nums[3] = {2,3,4}; ez_t("maxs",to_string(maxsA(nums,3)),to_string(4));}

// 数値配列の最小値を返す
int minsA(int *ms,int l){int m = INT_MAX; for(int i=0;i<l; i++){m = m < ms[i] ? m : ms[i];} return m;}
void minsAT(){ int nums[3] = {2,3,4}; ez_t("mins",to_string(minsA(nums,3)),to_string(2));}

/** 数値リストの操作系 **/

//数値リストの合計を返す
int sums(Ns ns){ int s = 0; for(auto n : ns){ s += n;} return s;}
void sumsT(){Ns ns = {1,2,3}; ez_t("sumL", sI(sums(ns)), "6");}

//数値リストから最小値を返す
int mins(Ns ns){ int min = INT_MAX; for(auto n : ns){min = min < n ? min : n;} return min;}
void minsT(){Ns ns = {1,2,3}; ez_t("minL", sI(mins(ns)), "1");}

//数値リストから最大値を返す
int maxs(Ns ns){ int max = 0; for(auto n : ns){max = max < n ? n : max;} return max;}
void maxsT(){Ns ns = {1,2,3}; ez_t("maxL", sI(maxs(ns)), "3");}

//１始まりの数値リストをゼロ始まりに変換するためにリストのすべての要素から１を引く
Ns neg1(Ns ns){ Ns res; for(int n: ns){ res.push_back(n-1);} return res;}

/** 文字列配列を扱う系 **/

//入れ子の文字配列を入れ子の文字リストへ変換
Css toCLL_CAA(char **arg, int x, int y){ Css rsp;
	for(int i=0;i<x;i++){ Cs rs; for(int j=0;j<y;j++){ rs.push_back(arg[i][j]);} rsp.push_back(rs);}return rsp;}
void toCLL_CAAT(){ cout << "toCLL_CAA まだ作ってないよ（笑）" << endl;}

/** 文字列を扱う系 **/

//入れ子の文字リストをトランスポーズ（転置）
template <typename T> vector<vector<T>> transpose( vector<vector<T>> xss){
	vector<vector<T>> res; int h,w; h = w = xss.size();
  for(int i= 0; i<h; i++){ vector<T> xs; for(int j= 0; j<w; j++){ xs.push_back(xss[j][i]);} res.push_back(xs);}
  return res;
}
void transposeT(){
  Nss arg; arg.push_back({1,2,3}); arg.push_back({4,5,6}); arg.push_back({7,8,9});
  Nss act = transpose(arg); for(Ns ac: act){ for(int a: ac){ printf("ans is   %d\n", a);}}
}

void f_w_test() {
  isinT();                  //文字列配列に文字が含まれているか
  toIL_SLT();               //文字列リストを数値のリストに変換
  toCLL_SLandtoSL_CLLT();   //交互に入れ替える事でテスト完了！！
  toSL_ILT();               //数値のリストを文字列リストへ変換
  toSLL_ILLT();             //入れ子の数値リストを入れ子の文字列リストに変換
  maxsAT();                  // 数値配列の最大値を返す
  minsAT();                  // 数値配列の最小値を返す
  sumsT();                  //数値リストの合計を返す
  minsT();                  //数値リストから最小値を返す
  maxsT();                  //数値リストから最大値を返す
  toCLL_CAAT();             //入れ子の文字配列を入れ子の文字リストへ変換
  transposeT();             //入れ子の文字リストをトランスポーズ（転置）
}
// int main(){ f_w_test();}
