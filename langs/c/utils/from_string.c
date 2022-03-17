#pragma once

#include "sizes.h"
#include "to_string.c"
// 文字を数値にするよ
int to_i(char s) {return atoi(&s);}
void to_iT() { int act = to_i('2'); ez_t("to_i", sI(act), sI(2), "hope so..");}

// 数値に変換可能なデリミタ区切りの文字列をもらって引数の数値配列のバッグに入れるよ
void toIs(char *arg, int *is, char dmt) {
  char ch, buf[WORD]; int id = 0, idx = 0, len = strlen(arg);
  for(int i=0; i<len; i++){
    if(ch == dmt){ buf[id] = '\0'; is[idx++] = atoi(buf); id = 0;}
    ch = arg[i]; buf[id++] = ch;
  }
  buf[id] = '\0'; is[idx] = atoi(buf);
}
void toIsT() {
  char *arg = "34 56", *exp = "[34,56]"; int is[2]; toIs(arg, is, ' ');
  ez_t("toIs", sIs(is,2),exp, "should it!");
}
// 数値に変換可能なデリミタ区切りの文字列をもらって引数の数値配列のバッグに入れるよ
void toNs(char *arg, int *is, char dmt) {
  char ch, buf[WORD]; int id = 0, idx = 0, len = strlen(arg);
  for(int i=0; i<len; i++){
    if(ch == dmt){ buf[id] = '\0'; is[idx++] = atoi(buf); id = 0;}
    ch = arg[i]; buf[id++] = ch;
  }
  buf[id] = '\0'; is[idx] = atoi(buf);
}

//　数値に変換可能な文字列の配列を取って、入れ子の数値の入れ列を引数のバッグに入れるよ
void toIss(char **arg, int n, int m, int iss[n][m], char dmt) {
  for(int i=0; i<n; i++){ toIs(arg[i], iss[i], dmt);}
}
void toIssT() {
  char *arg[] = {"12 34","56 78","910 1112"}; int iss[3][2];
  toIss(arg, 3, 2, iss, ' ');
  ez_t("toIss", sIss(3,2,iss), "[[12,34],[56,78],[910,1112]]", "I hope so..");
}

//C言語は何かとサイズにうるさいので、受け取った文字列の配列に含まれる文字の数を返す関数が必要だ
int fsCSize(char *cs) {
  int id = 0, n = 0;
  for(int i= 0; i<(int)strlen(cs); i++){ if(cs[i] == '\n'){ id++; n = 0;} n++;}
  if(n == 1){ id--;} return id;
}
void fsCSizeT() {
  char *arg = "hoge\nmamo\nhoge\nmon"; int act = fsCSize(arg), exp = 3;
  ez_t("fsCSize", sI(act), sI(exp), "I hope so..");
}

//　文字列をデリミタで分割、ヒープ領域に作った文字列リストを返す
char **split( char *ss, char dmt){
  ss = trim(ss);
  int size = 0;for(int i= 0; i<(int)strlen(ss); i++){if(ss[i] == dmt){ size++;}};
  char buf[WORD]; int b_id = 0, s_id = 0; int i;
  char **res = fhGetHeap(sizeof(char *) * size);
  for(i= 0; i<(int)strlen(ss); i++){
    if(ss[i] == dmt){
      buf[b_id] = '\0';
      res[s_id++] = fh_line(buf);
      b_id = 0;
      continue;
    }
    buf[b_id++] = ss[i];
  }
  res[size] = fh_line(buf);
  return res;
}
void splitT(){
  char src[] = "aa\nbb\ncc\ndd\n"; char **act = split(src, '\n');
  char *exp = "[aa,bb,cc,dd]"; ez_t("split", sSs(act,4), exp, "hope so..");
}

void from_string_test() {
  to_iT();            // 文字を数値にするよ        
  toIsT();            // 数値に変換可能なデリミタ区切りの文字列をもらって引数の数値配列のバッグに入れるよ
  toIssT();           //　数値に変換可能な文字列の配列を取って、入れ子の数値の入れ列を引数のバッグに入れるよ
  fsCSizeT();         // C言語は何かとサイズにうるさいので、受け取った文字列の配列に含まれる文字の数を返す関数が必要だ
  splitT();           //　文字列をデリミタで分割、ヒープ領域に作った文字列リストを返す
}
// int main(void){ from_string_test();}