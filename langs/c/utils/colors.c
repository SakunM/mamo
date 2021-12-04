#pragma once

#include <stdio.h>    // 主にファイルを取り扱う関数	stdin 標準入力やchar *fgets(char *s, int n, FILE *fp)など
#include <string.h>   // str*文字列処理系,mem*メモリブロックの確保系
#include <stdlib.h>		// atoi,malloc,strto* 文字列からの変換系
#include "sizes.h"

char *black   = "\x1b[30m";
char *red     = "\x1b[31m";
char *green   = "\x1b[32m";
char *yellow  = "\x1b[33m";
char *blue    = "\x1b[34m";
char *magenta = "\x1b[35m";
char *cyan    = "\x1b[36m";
char *white   = "\x1b[37m";
char *reset   = "\x1b[0m";

char *strcachers(char *str, char *color){
  char buf[WORD];
  char *res = strcpy(buf,color); res = strcat(res, str); res = strcat(res,reset);
  return strcpy(malloc(strlen(buf) + 1), buf);
}
char *suc(char *str){ return strcachers(str,green);}
char *norm(char *str){ return strcachers(str,blue);}
char *err(char *str){ return strcachers(str,red);}
char *fine(char *str){ return strcachers(str,yellow);}

void colors_test() {
  char *ans = suc("まも"); printf("%s\n", ans);
  ans = norm("まも"); printf("%s\n", ans);
  ans = err("まも"); printf("%s\n", ans);
  ans = fine("まも"); printf("%s\n", ans);
}
// int main(void){ colors_test();}