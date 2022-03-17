#include "../../utils/sizes.h"
#include "../../utils/to_string.c"
#include "../../utils/from_file.c" 
#include "../../utils/tester.c"
#include "../../utils/from_string.c"
#include "../../utils/from_heap.c"
#include "../../utils/print_util.c"
#include "../../utils/to_wrap.c"
#include "../../utils/from_wrap.c"

static int arg_sz, ans_sz;

void showSs(char ss[][WORD], int size){
  char chars[LINE] = {0}; chars[0] = '[';
  for(int i= 0; i<size-1; i++){ strcat(chars,ss[i]); strcat(chars,",");}
  strcat(chars,ss[size-1]); strcat(chars,"]"); ps(chars);
}
// void test(){ char arg[][WORD] = {"hoge","fuga","moge"}; showSs(arg,3);}
void m001(char *str, char dmt, char res[][WORD], int size){
  int id = 0, id_str = 0;
  for(int i= 0; i<size; i++){
    for(int j= 0; j<WORD; j++){
      char ch = str[id_str];
      if(ch == dmt || ch == '\0'){
        if(ch == dmt){ res[i][id] = '\0'; id = 0; id_str++; break;}
        if(ch == '\0'){ res[i][id] = '\0'; return;}
      }
      res[i][id] = str[id_str]; id++; id_str++;
    }
  }
}
// void test(){ char str[] = {"hoge fuga mamo"}; char res[3][WORD]; m001(str, ' ', res, 3); showSs(res,3);}
int domain(char all[][WORD], int size){
  int res[size];
  for(int i= 0; i<size; i++){
    int count = 0;
    for(int j= 0; j<size; j++){
      if(strcmp(all[i], all[j]) == 0){ count++;}
    }
    res[i] = count;
  }
  return maxs(res,size);
}
// void test(){ char arg[][WORD] = {"hoge","fuga","mamo","fuga"}; int res = domain(arg,4); pi(res);}
// main develop
char **domains(char **arg, int sz){
  arg_sz = sz; ans_sz = 1; int size = 1;
  for(int i= 0; i<(int)strlen(arg[0]); i++){ if(arg[0][i] == ' '){ size++;}}
  char fst[size][WORD]; m001(arg[0], ' ', fst, size);
  char snd[size][WORD]; m001(arg[1], ' ', snd, size);
  char all[size*2][WORD]; int id = 0;
  for(int i= 0; i<size; i++){ strcpy(all[id++],fst[i]);}
  for(int i= 0; i<size; i++){ strcpy(all[id++],snd[i]);}
  int res = domain(all,size*2);
  char **ans = fhSs(ans_sz);
  ans[0] = sI(res);
  return ans;
}
void test(){
  char ** args = fhSs(2); 
  args[0] = fh_line("fishing gardening swimming fishing");
  args[1] = fh_line("hunting fishing fishing biting");
  char **res = domains(args,2); pSs(res,ans_sz);
  // develop();
}  // exp is exp

UserFF user() {
  char line[LINE]; 
  fgets(line, LINE, stdin);
  int lim = strlen(line) - 1;
  char **res = fhSs(lim);
  res[0] = fh_line(line);
  for(int i= 1; i<lim; i++){ fgets(line, LINE, stdin); res[i] = fh_line(trim(line));}
  return ff_set(lim, res);
}
void product() {
  UserFF u = user();
  // pSs(u.lines, u.size);
  char **res = domains(u.lines,u.size); for(int i= 0; i<ans_sz; i++){ ps(res[i]);}
}

void developer(char *issue, char *result, char *name){
  UserFF arg = ff_list(issue), exp = ff_list(result); char **ans = domains(arg.lines,arg.size);
  zz_act("M001 Test", sSs(ans,ans_sz), sSs(exp.lines,ans_sz), name);
  fhSsFree(exp.lines,exp.size); fhSsFree(ans,ans_sz); fhSsFree(arg.lines,arg.size);
}
void develop() {
  char *issue1 = "a:/pj/mamo/refs/isses/issue1.txt", *result1 = "a:/pj/mamo/refs/isses/result1.txt",
       *issue2 = "a:/pj/mamo/refs/isses/issue2.txt", *result2 = "a:/pj/mamo/refs/isses/result2.txt",
       *issue3 = "a:/pj/mamo/refs/isses/issue3.txt", *result3 = "a:/pj/mamo/refs/isses/result3.txt",
       *issue4 = "a:/pj/mamo/refs/isses/issue4.txt", *result4 = "a:/pj/mamo/refs/isses/result4.txt",
       *issue5 = "a:/pj/mamo/refs/isses/issue5.txt", *result5 = "a:/pj/mamo/refs/isses/result5.txt",
       *issue6 = "a:/pj/mamo/refs/isses/issue6.txt", *result6 = "a:/pj/mamo/refs/isses/result6.txt";
  developer(issue1, result1,"test-1"); developer(issue2, result2,"test-2");
  developer(issue3, result3,"test-3"); developer(issue4, result4,"test-4");
  developer(issue5, result5,"test-5"); developer(issue6, result6,"test-6");
}

void refactor() {
  char *issue = "a:/pj/mamo/refs/isses/issue1.txt", *result = "a:/pj/mamo/refs/isses/result1.txt";
  UserFF arg = ff_list(issue), exp = ff_list(result); 
  // ps(ff_sSs(arg)); ps(ff_sSs(exp)); pi(arg.size);
  char **ans = domains(arg.lines,arg.size);
  zz_act("M001 Test", sSs(ans,ans_sz),  sSs(exp.lines,ans_sz),"refactor");
}

// M001 m001 domain user
int main(void){
  // test();
  // refactor();
  develop();
  // product();
}