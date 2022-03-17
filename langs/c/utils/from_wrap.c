#pragma once

#include <limits.h>		// INT_MAX
#include "to_string.c"

//配列の合計を返す
int sums(const int *box, int lim){int sm=0,i; for(i=0; i<lim; i++){sm += box[i];} return sm;}
void sumsT(){ int ns[] = {1,2,3}; char *act = sI(sums(ns,3)); ez_t("sums", act, "6", "配列の合計を返す");}

/** 配列関係の関数 **/
void setZero(int *box, int lim){ int i; for(i=0; i<lim; i++){box[i] = 0;}}
int maxs(const int *box, int lim){int m=0,i; for(i=0; i<lim; i++){m = m<box[i] ? box[i]:m;}return m;}
int mins(const int *box, int lim){int m=INT_MAX,i; for(i=0; i<lim; i++){m = m>box[i] ? box[i]:m;}return m;}

void f_w_test() {
  sumsT();       //配列の合計を返す
}
// int main(void){ f_w_test();}