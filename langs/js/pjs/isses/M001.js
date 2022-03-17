'use strict';
const user_path = '../../utils/from_file', t = require('../../utils/tester')("M001 Test"), fw = require('../../utils/from_wrap'),
      ts = require('../../utils/to_string'), tw = require('../../utils/to_wrap'), fs = require('../../utils/from_string'),
      ut = require('../../utils/util');
// fs => to_i; ts => padR,padL,sSs,sNs; fw => mins,maxs,sumus; tw => to_nums, replicate, fromZ; ut => isin,any,all

function m001(ss){
  let first = ss[0].split(" "), second = ss[1].split(" "); return first.concat(second);
}
// function test(){ let res = m001(["fishing gardening swimming fishing","hunting fishing fishing biting"]); console.log(res);}

function domain(ss){ let m = new Map(); for(let s of ss){ m.set(s, m.get(s) ? m.get(s) + 1 : 1);} return m;}
// function test(){ let res = domain(["fishing","gardening","swimming","fishing","hunting","fishing","fishing","biting"]); console.log(res);}

function domains(args){
  let maps = domain(m001(args)), res = fw.maxs(Array.from(maps.values()));
  return [res.toString()];
} // main
function test(){ let ans = domains(["fishing gardening swimming fishing","hunting fishing fishing biting"]); console.log(ans);}

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
