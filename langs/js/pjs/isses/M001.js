'use strict';
const user_path = '../../utils/from_file', t = require('../../utils/tester')("M001 Test"), fw = require('../../utils/from_wrap'),
      ts = require('../../utils/to_string'), tw = require('../../utils/to_wrap'), fs = require('../../utils/from_string'),
      ut = require('../../utils/util');

function m001(ss){ return fs.to_nums(ss[0]);}
function test_m(){ let res = m001(["10 3 2 5 7 8"]); console.log(res);}

function domain(ns){
  let ans = 0, dp = [];
  for(let i= 0; i<ns.length-1; i++){
    dp.push(ns[i]);
    if( i > 0){ dp[i] = Math.max(dp[i], dp[i-1]);}
    if( i > 1){ dp[i] = Math.max(dp[i], dp[i-2] + ns[i]);}
    ans = Math.max(ans, dp[i]);
  }
  for(let i= 0; i<ns.length-1; i++){
    dp[i] = ns[i+1];
    if( i > 0){ dp[i] = Math.max(dp[i], dp[i-1]);}
    if( i > 1){ dp[i] = Math.max(dp[i], dp[i-2] + ns[i+1]);}
    ans = Math.max(ans, dp[i]);
  }
  return ans;
}
function test(){
  let res = domain([10,3,2,5,7,8]); console.log(res);
}  // exp is exp
// main
function domains(args){
  let res = domain(m001(args));
  return [res.toString()];
}
function test_ds(){ let ans = domains(["10 3 2 5 7 8"]); console.log(ans);}  // exp is 

// user
class User{
  constructor(){ this.reader = require('readline').createInterface(process.stdin); this.ss = [];}
  done(){
    // console.log(this.ss);
    const ans = domains(this.ss); console.log(ans.join('\n'));
  }
  start(){
    let ss = this.ss,count=0, lim = 0;
    this.reader.on("line", line =>{
      if (count === 0) { ss.push(line.trim()); lim = (line.trim().length) - 1; }
      // if (count === 1) { ss.push(line.trim()); lim = parseInt(line.trim())+1;}
      // if (count > 0 && count < lim) {ss.push(line.trim());}
      if(count === 1){ ss.push(line.trim());this.reader.close();}
      count++;
    });
    this.reader.on("close", () => this.done());
  }
}

function product(){ const u = new User(); u.start();}

function developer(issue,result,name){
  let ff = require(user_path)(issue), ans = domains(ff.list()), exp = require(user_path)(result);
  t.test(ts.sNs(ans), ts.sNs(exp.list()), name);
}
function develop(){
  const issue1 = "a:/pj/mamo/refs/isses/issue1.txt", result1 = "a:/pj/mamo/refs/isses/result1.txt",
        issue2 = "a:/pj/mamo/refs/isses/issue2.txt", result2 = "a:/pj/mamo/refs/isses/result2.txt",
        issue3 = "a:/pj/mamo/refs/isses/issue3.txt", result3 = "a:/pj/mamo/refs/isses/result3.txt",
        issue4 = "a:/pj/mamo/refs/isses/issue4.txt", result4 = "a:/pj/mamo/refs/isses/result4.txt",
        issue5 = "a:/pj/mamo/refs/isses/issue5.txt", result5 = "a:/pj/mamo/refs/isses/result5.txt",
        issue6 = "a:/pj/mamo/refs/isses/issue6.txt", result6 = "a:/pj/mamo/refs/isses/result6.txt";
  developer(issue1, result1,"test-1"); developer(issue2, result2,"test-2");
  developer(issue3, result3,"test-3"); developer(issue4, result4,"test-4");
  developer(issue5, result5,"test-5"); developer(issue6, result6,"test-6");
}
function refactor(){
  const issue = "a:/pj/mamo/refs/isses/issue1.txt", result = "a:/pj/mamo/refs/isses/result1.txt";
  const arg = require(user_path)(issue), exp = require(user_path)(result);
  // console.log(arg.list()); console.log(exp.list());
  const ans = domains(arg.list()); t.test(ts.sNs(ans), ts.sNs(exp.list()), "refactor"); 
}
// M001 m001 domain user
if(require.main === module){
  // test();
  // refactor();
  develop();
  // product();
}
