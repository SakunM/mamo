#pragma once

#include "to_string.c"
#include "print_util.c"

// 空白区切りの文字列専用のstrtokを使わない分かり易いロジックを採用した10桁の数値までの限定だ
void to_nums(char *cs, int *ns){
  char w[10];
  int j = 0, k = 0;
  for(int i= 0; cs[i] != '\0'; i++){
    if(cs[i] == ' '){ w[j] = '\0'; ns[k++] = atoi(w); j = 0;}
    w[j++] = cs[i];
  }
  w[j] = '\0'; ns[k] = atoi(w);
}

// デリミタ付きの数値文字列をデリミタ区切りの数値配列に変更
void splitNums(char *str, char dmt, int *bag){ char *tp = strtok(str, &dmt); int i=0;
  bag[i++] = atoi(tp); while( tp = strtok(NULL, &dmt) ){bag[i++] = atoi(tp);}}
void splitNumsT(){ char iss[5] = {"1/2/3"}; int is[3]; 
	splitNums(iss,'/',is); char *s = sIs(is,3); ez_t("splitNums",s,"[1,2,3]", "数値配列に変更"); free(s);}

// 数値のリストを文字列のリストに変換
char **fromIsToSs(int *ns, int sz){
  char **res = fh_charss(sz),buf[WORD]; res[sz];
  for(int i= 0; i<sz; i++){ sp(buf,"%d",ns[i]); res[i] = fh_line(buf);}
  return res;
}
void fromIsToSsT(){ int arg[] = {1,2,3}; char **res = fromIsToSs(arg,3), *exp = "[1,2,3]"; ez_t("formIsToSs", sSs(res,3), exp, "hope so..");}

void t_w_test() {
  splitNumsT();     // デリミタ付きの数値文字列をデリミタ区切りの数値配列に変更
  fromIsToSsT();     // 数値のリストを文字列のリストに変換
}
// int main(void){ t_w_test();}
