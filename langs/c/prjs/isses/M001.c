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

void m001(char **ss, int size){ arg_sz = 0; ans_sz = 1;}
void test_t(){
  char *arg = fh_line("YYYY"); char **args = fhSs(1); args[0] = arg; m001(args, 1); printf("arg_sz is %d ans_siz is %d", arg_sz, ans_sz);
}  // exp is exp

int domain(char *cs){
  if (strchr(cs, 'Y') == NULL) { return 16;}
  if (strchr(cs, 'N') == NULL) { return 1;}
  char res[strlen(cs) + 1]; res[strlen(cs)] = '\0';
  for(int i= 0; i<(strlen(cs)); i++){
    if(cs[i] == 'Y') { res[i] = '0'; continue;}
    if(cs[i] == 'N') { res[i] = '1'; continue;}
    res[i] = cs[i];
  }
  int ans = 0;
  for(int i= 0; i<strlen(res); i++){
    ans = ans * 2 + (to_i(res[i]));
  }

  return ans + 1;
}
void test_d(){
  char *arg = {"YNYY"};
  int res = domain(arg);
  printf("ans is %d",res);
}
// main
char **domains(char **arg, int sz){
  // m001(arg,sz);
  // int res = domain(arg[arg_sz]);
  ans_sz = 1;
  char **ans = fhSs(ans_sz);
  // ans[0] = sI(res);
  ans[0] = fh_line("1");
  return ans;
}
void test(){
  char *arg = fh_line("NNNN"); char **args = fhSs(1); args[0] = arg;
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
  fhSsFree(exp.lines,exp.size); fhSsFree(ans,ans_sz);
}
void develop() {
  char *issue1 = "a:/pj/mamo/resf/isses/issue1.txt", *result1 = "a:/pj/mamo/refs/isses/result1.txt",
       *issue2 = "a:/pj/mamo/resf/isses/issue2.txt", *result2 = "a:/pj/mamo/refs/isses/result2.txt",
       *issue3 = "a:/pj/mamo/resf/isses/issue3.txt", *result3 = "a:/pj/mamo/refs/isses/result3.txt",
       *issue4 = "a:/pj/mamo/resf/isses/issue4.txt", *result4 = "a:/pj/mamo/refs/isses/result4.txt",
       *issue5 = "a:/pj/mamo/resf/isses/issue5.txt", *result5 = "a:/pj/mamo/refs/isses/result5.txt",
       *issue6 = "a:/pj/mamo/resf/isses/issue6.txt", *result6 = "a:/pj/mamo/refs/isses/result6.txt";
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