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
static int *gns; static bool on = false;

void m001(char **ss, int size){
  arg_sz = size; ans_sz = 1; if(on){ fhIsFree(gns,size);}
  gns = fh_ints(size); for(int i= 0; i<size; i++){ gns[i] = 0;}
  on = true;
}
void test_m(){
  char **args = fhSs(2); args[0] = fh_line("N"); args[1] = fh_line("Y"); m001(args, 2); pNs(gns,2);
}  // exp is exp

int getSaraly(int i, char **ss){
  if(gns[i] == 0){
    int saraly = 0;
    char *s = ss[i];
    for(int j= 0; j<arg_sz; j++){ if(s[j] == 'Y'){ saraly += getSaraly(j,ss);}}
    if(saraly == 0){ saraly = 1;}
    gns[i] = saraly;
    return gns[i];
  }
  return gns[i];
}

int domain(char **ss){
  int total = 0;
  for(int i= 0; i<arg_sz; i++){ total += getSaraly(i,ss);}
  return total;
}
void test_d(){
  char **args = fhSs(4); args[0] = fh_line("NNYN"); args[1] = fh_line("NNYN"); args[2] = fh_line("NNNN"); args[3] = fh_line("NYYN");
  m001(args,4);
  int res = domain(args);
  pi(res);
}
// main
char **domains(char **arg, int sz){
  m001(arg,sz);
  int res = domain(arg);
  char **ans = fhSs(ans_sz);
  ans[0] = sI(res);
  return ans;
}
void test_ds(){
  char ** args = fhSs(4); args[0] = fh_line("NNYN"); args[1] = fh_line("NNYN"); args[2] = fh_line("NNNN"); args[3] = fh_line("NYYN");
  char **res = domains(args,4); pSs(res,ans_sz);
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
  test();
  // refactor();
  // develop();
  // product();
}