#pragma once

#include <stdio.h>		// 主にファイルを取り扱う関数	stdin 標準入力やchar *fgets(char *s, int n, FILE *fp)など
#include <string.h>		// str*文字列処理系,mem*メモリブロックの確保系
#include <stdlib.h>		// atoi,malloc,strto* 文字列からの変換系

#include "to_string.c"

// 表示に関する関数
void pi(int arg){printf("%d\n",arg);}
void pc(char arg){printf("%c\n",arg);}
void ps(char *arg){printf("%s\n",arg);}
void pf(double arg){printf("%f\n", arg);}
void pp(void *arg){printf("%p\n", arg);}
void pb(bool b){printf("%s\n", b ? "ture" : "false");}

void ppi(int arg){printf("%d",arg);}
void ppc(char arg){printf("%c",arg);}
void pps(char *strs){printf("%s",strs);}
void ppf(double arg){printf("%f", arg);}
void ppp(void *arg){printf("%p", arg);}

void pSs(char **ss, int size){ printf("%s\n", sSs(ss,size));}
void pNs(int *ns, int size){ printf("%s\n", sNs(ns,size));}
void pNss(int r, int c, int **nss){ printf("%s\n", sNss(r,c,nss));}

void print_util_test() {
  int x = 5; pp(&x);
}
// int main(void){ print_util_test();}