#pragma once

#include <stdbool.h>	// フリースタンディング環境 ブール値の扱い？
#include <ctype.h>    // isspaceなど　is*	半角文字1文字を取り扱う関数群

#include "sizes.h"
#include "colors.c"
#include "from_heap.c"

#define p printf
#define sp sprintf

//解説付きの簡単テスト関数
void ez_t(char *title, char *act, char *exp, char *disp){ char *b=(strcmp(act,exp) == 0)?suc("true"):err("false");
	p("%s %-20s:%s %40s\n", norm("ez_test"), title, b, fine(disp));}
void ez_t_T() { ez_t("ez_t test", "mamo","hoge", "間違いの場合は");}


//数値を文字列に変換 １０桁対応　要：後始末
char *sI(int n){char buf[10]; sprintf(buf,"%d",n); return fh_line(buf);}
char *sN(int n){char buf[10]; sprintf(buf,"%d",n); return fh_line(buf);}
void sIT(){ char *ans = sI(3); ez_t("sI", ans, "3", "数値を文字列に変換"); fhSFree(ans);}


// Nums（サイズ付き数値配列）をそれらしい文字列表現に変換して返す　要：後始末
char *sIs(int *ns, int size){
  int i; char chars[WORDS] = {0};
	chars[0] = '['; for(i=0; i<size-1; i++){ char *n = sI(ns[i]); strcat(chars,n); fhSFree(n);strcat(chars,",");}
	char *n = sI(ns[i]); strcat(chars,n); strcat(chars,"]");fhSFree(n); return fh_line(chars);
}
void sIsT(){ int is[] = {1,2}; char *s = sIs(is,2); ez_t("sIs",s,"[1,2]", "それらしい文字列"); fhSFree(s);}
// Nums（サイズ付き数値配列）をそれらしい文字列表現に変換して返す　要：後始末
char *sNs(int *ns, int size){
  int i; char chars[WORDS] = {0};
	chars[0] = '['; for(i=0; i<size-1; i++){ char *n = sI(ns[i]); strcat(chars,n); fhSFree(n);strcat(chars,",");}
	char *n = sI(ns[i]); strcat(chars,n); strcat(chars,"]");fhSFree(n); return fh_line(chars);
}

// Issを受け取りそれらしい文字列にして返す
char *sIss(int r, int c, int nums[r][c]){
  int i; char chars[LINE] = {0};
  chars[0] = '['; for( i= 0; i<r-1; i++){ char *an = sIs(nums[i],c); strcat(chars,an); fhSFree(an); strcat(chars,",");}
  char *n = sIs(nums[i],c); strcat(chars,n); strcat(chars,"]"); fhSFree(n); return fh_line(chars);
}
void sIssT() {
  int nums[][2] = {{1,2},{3,4},{4,5}};
  char *ans = sIss(3,2,nums); char *exp = "[[1,2],[3,4],[4,5]]"; ez_t("sIss", ans,exp, "I hope so..");
  fhSFree(ans);
}
// Issを受け取りそれらしい文字列にして返す
// char *sNss(int r, int c, int nums[r][c]){
char *sNss(int r, int c, int **nums){
  int i; char chars[LINE] = {0};
  chars[0] = '['; for( i= 0; i<r-1; i++){ char *an = sIs(nums[i],c); strcat(chars,an); fhSFree(an); strcat(chars,",");}
  char *n = sIs(nums[i],c); strcat(chars,n); strcat(chars,"]"); fhSFree(n); return fh_line(chars);
}

//文字列配列をそれらしい文字列に変換
char *sSs(char **ss, int size){ char chars[128] = {0}; chars[0] = '[';
	for(int i=0; i<size-1; i++){ strcat(chars,ss[i]); strcat(chars,",");}
	strcat(chars, ss[size-1]); strcat(chars, "]"); return fh_line(chars);
}
void sSsT() {
  char *arg[] = {"hoge", "fuga", "mamo"};  char *act = sSs(arg, 3); char *exp = "[hoge,fuga,mamo]";
  ez_t("sSs", act, exp, "それらしい文字列に");
}

// Bool値をそれらしい文字列に　要：後始末
char *b_s(bool b){ char *t = "true", *f = "false"; if(b == true) return fh_line(t);
	else return fh_line(f);
}

// テーブルにItemが含まれているかを真偽値で返すよ
bool isinCs(char *item, char tbl[][3], int lim){
  for(int i= 0; i<lim; i++){if(strcmp(item, tbl[i]) == 0){ return true;}}
  return false;
}

// 数値の配列を空白区切りの文字列に変更 マイバックの[0]に'\0'を入れて送る事！！
void unwords(char *bag, const int *nums, int size){ char buf[10]; int i,end;
	for(i=0; i<size; i++){ sprintf(buf, "%d ", nums[i]); strcat(bag,buf);}
	end = strlen(bag) -1; bag[end] = '\0';}

/** トリムの実装 **/
//左トリム
char *ltrim(char *s){ int len = strlen(s),lws = strspn(s," \n\r\t\v"); memmove(s,s+lws,len-=lws); s[len] = '\0'; return s; }
void ltrimT(){ char arg[] = {" 	hoge"}; ez_t("ltrim", ltrim(arg),"hoge", "左トリム"); }
//右トリム
char *rtrim(char *s){ int len = strlen(s); while(len && isspace(s[len-1])){--len;} s[len] = '\0'; return s;}
void rtrimT(){ char arg[] = {" hoge 	 "}; ez_t("rtrim", rtrim(arg), " hoge", "右トリム");}
//左右のトリム
char *trim(char *s){ char *hs = fh_line(s); return ltrim(rtrim(hs));}
void trimT(){char *arg = "  hoge   "; ez_t("trim", trim(arg), "hoge", "左右のトリム");}

// 文字列のリストをデリミタ区切りの文字列に変更、デリミタはCharだよ
char *join(char **ss, int sz, char dmt, int ws){
  char line[ws*sz], word[ws]; int id=0, idx=0;
  sprintf(word,"%s\n",ss[0]); strcpy(line,word);
  for(int i= 1; i<sz-1; i++){ sprintf(word, "%s\n", ss[i]); strcat(line,word);}
  sprintf(word,"%s", ss[sz-1]); strcat(line,word); line[strlen(line)+1] = '\0';
  return fh_line(line);
}
void joinT(){ char *arg[] = {"1","2","3"}; char *act = join(arg, 3, '\n', WORD); ez_t("join", act, "1\n2\n3","I hope so..");}


void to_string_test() {
  ez_t_T();           //解説付きの簡単テスト関数
  sIT();              //数値を文字列に変換 １０桁対応　要：後始末
  sIsT();             // Nums（サイズ付き数値配列）をそれらしい文字列表現に変換して返す　要：後始末
  sIssT();            // Issを受け取りそれらしい文字列にして返す
  sSsT();             //文字列配列をそれらしい文字列に変換
  ltrimT();           //左トリム
  rtrimT();           //右トリム
  trimT();            //左右のトリム
  joinT();            //数値のリストをデリミタ区切りの文字列に変更、デリミタはCharだよ
}
// int main(void){ to_string_test();}