#pragma once

#include <stdio.h>

#include "sizes.h"
#include "from_heap.c"
#include "to_string.c"
#include "print_util.c"

typedef struct{ int size; char **lines;} UserFF;
UserFF ff_set(int sz, char **ss) { UserFF u = {sz, ss}; return u; }

int ff_Lsize(char *path) { FILE *fp; fp = fopen(path,"r"); char ch; int id = 0;
  while((ch = fgetc(fp)) != EOF) { if(ch == '\n'){ id++;}} fclose(fp); return id;
}
void test_ls() { char *issue1 = "a:/pj/sc/lib/rs/issues/issue1.txt"; int res = ff_Lsize(issue1); printf("%d\n", res);}

UserFF ff_list(char *path){
  int size = ff_Lsize(path); char **lines = fh_charss(size);
  // int size = ff_Lsize(path); char **lines = fh_charss(size); *lines[size];
  FILE *fp; fp = fopen(path,"r"); char ch, line[LINE]; int idx = 0, id = 0;
  while((ch = fgetc(fp)) != EOF){
    if(ch == '\n'){ line[idx] = '\0'; lines[id++] = trim(line); idx = 0; continue;} line[idx++] = ch;
  }
  fclose(fp); line[idx] = '\0'; lines[id] = fh_line(line); return ff_set(size, lines);
}
void test_ff(){ char *issue = "a:/pj/sc/lib/rs/issues/issue2.txt"; UserFF res = ff_list(issue); ps(sSs(res.lines, res.size));}

int ff_size(char *path){
  int res = 0;
  FILE *fp; fp = fopen(path,"r"); char ch;
  while((ch = fgetc(fp)) != EOF) { res++;} fclose(fp); return res;
}
void ff_read(char *path, char *buf){
  int id = 0;
   FILE *fp; fp = fopen(path,"r"); char ch;
  while((ch = fgetc(fp)) != EOF) { buf[id++] = ch;} fclose(fp);
}


char *ff_sSs(UserFF ff){ return  sSs(ff.lines, ff.size);}

void from_file_test() {
  test_ff();
}
// int main(void){ from_file_test();}