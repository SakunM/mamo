const fs = require('fs');
class FromFile{
  set(ss){
    if(ss.length == 0){ this.empty = true; this.ss = '';}
    else { this.empty = false; this.ss = ss;}
  }
  all(){ return this.ss;}
  list(){ let ss = this.ss.split("\r\n"); ss = ss.map(s => s.trim()); let l = ss.pop(); if(l){ss.push(l);} return ss;}
}

function ffUser(path){ const t = fs.readFileSync(path, "utf-8"), ff = new FromFile(); ff.set(t); return ff;}
module.exports = ffUser;
if(require.main === module){
  const issue1 = "a:/pj/sc/lib/rs/issues/issue1.txt", res = ffUser(issue1)
  console.log(res.all());
}