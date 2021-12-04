#pragma once

#include <stdio.h>
#include "sizes.h"
#include "colors.c"
#include "to_string.c"

void zz_act(char *title, const char *act, char *exp, char *disp){
  char tds[WORDS],res[LINES]; sprintf(tds, "%s %s %20s", norm("@ "), title, disp);
  if (strcmp(act,exp) == 0 ){ sprintf(res, "%20s actual : %-20s => %s passed", suc("Succes!"), act, suc("OK!"));}
  else{ sprintf(res, "%10s ☆ -- %s \n %20s -- Expect : %s \n %22s bat was : %s", " ",err("Failid!"), " ", exp, " ", act);}
  printf("%s %s\n", tds, res);
}

void tester_test() {
  zz_act("Tester Test", "[-----------------------------------------------------------------------]", "[-------------------------------------------------]" , "１０のはず");
  zz_act("Tester Test", sI(1456), sI(1456) , "１０のはず");
  zz_act("Tester Test", sI(34), sI(1456) , "１０のはず");
}
// int main(void){ tester_test();}

