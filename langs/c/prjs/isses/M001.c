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

int m001(char **ss, int size){
  arg_sz = size; ans_sz = 1; int res = 0;
  for(int i= 0; i<strlen(ss[0]); i++){ if(ss[0][i] == ' '){ res++;}}
  return res+1;
}
void test_m(){
  char **args = fhSs(1); args[0] = fh_line("10 3 2 5 7 8"); int res = m001(args, 1); printf("res is %d",res);
}  // exp is exp

int max2(int a, int b){ return a > b ? a : b;}
int domain(int *ns, int sz){
  int ans = 0, bp[sz-1];
  for(int i= 0; i<sz-1; i++){
    bp[i] = ns[i];
    if( i > 0){ bp[i] = max2(bp[i], bp[i-1]);}
    if( i > 1){ bp[i] = max2(bp[i], bp[i-2] + ns[i]);}
    ans = max2(ans, bp[i]);
  }
  for(int i= 0; i<sz-1; i++){
    bp[i] = ns[i+1];
    if( i > 0){ bp[i] = max2(bp[i], bp[i-1]);}
    if( i > 1){ bp[i] = max2(bp[i], bp[i-2] + ns[i+1]);}
    ans = max2(ans, bp[i]);
  }
  return ans;
}
void test_d(){
  int ns[] = {1,2,3,4,5,1,2,3,4,5};
  int res = domain(ns,10);
  pi(res);
}
// main
char **domains(char **arg, int sz){
  int ns_sz = m001(arg,sz);
  int ns[ns_sz];
  to_nums(arg[0], ns);
  int res = domain(ns,ns_sz);
  char **ans = fhSs(ans_sz);
  ans[0] = sI(res);
  return ans;
}
void test(){
  char ** args = fhSs(1); args[0] = fh_line("10 3 2 5 7 8");
  char **res = domains(args,1); pSs(res,ans_sz);
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
  char *issue = "a:/pj/mamo/refs/isses/issue2.txt", *result = "a:/pj/mamo/refs/isses/result2.txt";
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