#pragma once

#include <stdbool.h>	// フリースタンディング環境 ブール値の扱い？
#include <stdlib.h>		// atoi,malloc,strto* 文字列からの変換系
#include <string.h>		// str*文字列処理系,mem*メモリブロックの確保系

int fh_size = 0;

void *fhGetHeap(int size){ void *res = malloc(size); if(res == NULL){ printf("%s","確保エラーだよ"); exit(1);} else { fh_size += size; return res; }}

int *fhIss(int n, int m, int arg[n][m]){
  int *heap = fhGetHeap(n * m * sizeof(int)), id=0;
  for(int i= 0; i<n; i++){ for(int j= 0; j<m; j++){ heap[id++] = arg[i][j];}}
  return heap;
}

char *fh_line(char *buf){ return strcpy(fhGetHeap(strlen(buf)+1),buf);}
char **fh_charss(int size) { return fhGetHeap(sizeof(char *) * size);}

char *fhS(int size) { return fhGetHeap(sizeof(char *) * size);}
char **fhSs(int size) { return fhGetHeap(sizeof(char *) * size);}
char ***fhSss(int size) { return fhGetHeap(sizeof(char *) * size);}

int *fh_ints(int size) { return fhGetHeap(sizeof(int *) * size);}
char *fh_chars(int size){ return fhGetHeap(sizeof(char) * size);}

int **fhNss(int size){ return fhGetHeap(sizeof(int *) * size);}

void fhCsFree(char **gc, int size) { fh_size -= (sizeof(char *) * size); free(gc);}
void fhSFree(char *gc) {  fh_size -= (strlen(gc) + 1); free(gc);}
void fhSsFree(char **gc, int size) { for(int i= 0; i<size; i++){ fhSFree(gc[i]);} fhCsFree(gc,size);}
void fhIsFree(int *gc, int size) { fh_size -= (sizeof(int *) * size); free(gc);}

void fsCzFree(char *gc, int size){ fh_size -= (sizeof(char)*size); free(gc);}

int *fhIss_test(int n, int m, int arg[n][m]){
  int id = 0;
  for(int i= 0; i<n; i++){ for(int j= 0; j<m; j++){ arg[i][j] = id++;}}
  return fhIss(n, m, arg);
}

void f_h_test() {

}
// int main(void){ f_h_test();}