#include <stdio.h>		// 主にファイルを取り扱う関数	stdin 標準入力やchar *fgets(char *s, int n, FILE *fp)など
#include <string.h>		// str*文字列処理系,mem*メモリブロックの確保系
#include <stdlib.h>		// atoi,malloc,strto* 文字列からの変換系
#include <limits.h>		// INT_MAX
#include <stdarg.h>		// フリースタンディング環境
//#include <assert.h>		// void assert(int expression);	デバッグのために診断を行う。
#include <ctype.h>		// is*	半角文字1文字を取り扱う関数群

//現在ここまでテスト関数を実施した。以下順次本当にUtilにふさわしい関数だけを抽出しながら実装する
// マイバック運動推進系関数 
int my_bagC(char *str, char tk){ int i, size=0; for(i=0; i<strlen(str); i++) {if(str[i] == tk){size++;}} return size + 1;}
int my_bagI(int *box, int lim, int v){int s=0,i; for(i=0; i<lim; i++){if(box[i] == v){s++;}}return s;}

void idxs(const int *box, const int lim, int *rev, const int val){
	int idx = 0,i; for(i=0; i<lim; i++){ if(box[i] == val){rev[idx++] = i;}}
}

//ペアの構造を持つ構造体とその構造体を扱う関数達
typedef struct { int fst;int snd;} Piar;
void showP(Piar pr){ p("fst = %d: snd = %d\n", pr.fst, pr.snd);}
void nameP(Piar pr, char *bag){ sprintf(bag,"pos = (%d, %d)", pr.fst, pr.snd);}
Piar to_P(int *is){ Piar pr = {is[0],is[1]}; return pr;}

void util_test(){
	/** トリムの実装 **/
	ltrimT();			//左トリム
	rtrimT();			//右トリム
	trimT();			//左右のトリム
	sIT();				//数値を文字列に変換 １０桁対応　要：後始末
	sILT();				// Nums（サイズ付き数値配列）をそれらしい文字列表現に変換して返す　要：後始末
	splitNumsT();	// デリミタ付きの数値文字列をデリミタ区切りの数値配列に変更
	sumsT();				//配列の合計を返す
}

// int main(void){util_test();}
