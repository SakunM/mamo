'use strict';

const c = require('./colors')();

// ゼロ埋めや右詰や左詰
function padR(tar,n,ch){ return (mulC(n,ch) + tar).slice(-n);}
function padL(tar,n,ch){ return (tar + mulC(n,ch)).slice(0,n);}
function mulC(n,ch){ let resp = ch; for(var i= 0; i<n; i++){ resp = resp+ch;} return resp;}

// ゼロ埋めや右詰や左詰を文字や数値のプロトタイプとして実装;JSではグローバル扱いだよ
Number.prototype.pad = function(n){ return padL(this,n,"0");}
String.prototype.pad = function(n){ if(n >=0 )return padR(this,n," "); else return padL(this,Math.abs(n)," ");}

//表示が一行の最も簡単なテスト用関数、なのでUtil内で使用説明書を兼ねた簡単なテストに使用
function ez_t(title,act,exp,disp="now painting !!"){
  const test = c.norm("test"), res = act.toString() === exp.toString() ? c.suc("true") : c.err("false"); 
	console.log(`${test} ${title.pad(-20)}: ${res}  : ${c.fine(disp)}`);
} exports.ez_t = ez_t;

//数値や文字列リストをそれらしい文字列に置き換える
function sL(xs){
  let str = "[",i; for(i=0; i<xs.length-1; i++){ str += `${xs[i]},`;} str += `${xs[i]}]`; return str;} exports.sL = sL;
function sLT(){ ez_t("sL", sL(["a","b","c"]), "[a,b,c]");}

//入れ子のリストをそれらしい文字列に置き換える
function sLL(xss){ let str = "[",i; 
	for(i=0; i<xss.length-1; i++){ str += `${sL(xss[i])},`;} str += `${sL(xss[i])}]`; return str;} exports.sLL = sLL;
function sLLT(){ ez_t("sLL", sLL([[1,2],[3,4]]), "[[1,2],[3,4]]");} 

// 文字列リストをJavaScriptの標準出力に合わせた文字列表現を行う
function sSs(ss){
  const len = ss.length-1; let res = "[";
  for(let i= 0; i<len; i++){ res += "'" + ss[i] + "', ";}
  res += "'" + ss[len] + "' ]";
  return res;
} exports.sSs = sSs;

function test_sSs(){ let ans = sSs(["hoge", "fuga", "mamo"]); console.log(ans);}

// 数値リストをJavaScriptの標準出力に合わせた文字列表現を行う
function sNs(ns){
  let res = [];
  for(let i= 0; i<ns.length; i++){ res.push(ns[i].toString());}
  return sSs(res);
} exports.sNs = sNs;
function test_sNs(){ let res = sNs([3]); console.log(res);}  // exp is exp
if(require.main === module){
  ez_t("Test", "hog","hog", "hope so");
  sLT();
  sLLT();
  test_sSs();
  test_sNs();
}