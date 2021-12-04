'use strict';

const ts = require('./to_string');

//Fromで始まりToで終わる一つ刻みの数値リストを返す
function toIL_FT(from,to){ return Array.apply(null,new Array(to-from+1)).map((v,i) => i+from);} exports.toIL_FT = toIL_FT;
function toIL_FTT(){ ts.ez_t("toIL_FT", toIL_FT(2,5), [2,3,4,5], "toIL_FT(2,5) => [2,3,4,5]");}

// ゼロから引数までの一つ刻みの数値リストを返す
function toIL_Z(num){return toIL_FT(0,num);} exports.toIL_Z = toIL_Z;
function toIL_ZT(){ ts.ez_t("toIL_Z", toIL_Z(5),[0,1,2,3,4,5],"making list 0to n")}

// ゼロから始まる等価数列のリストを返す
function fromZ(num){ return toIL_FT(0,num);} exports.fromZ = fromZ;

// 数値文字列のリストを数値リストへ変換
function to_is(ss){ return ss.map(s => parseInt(s));} exports.to_is = to_is

// 空白区切りの数値文字列を数値リストに変換
function to_nums(str){ return to_is(str.trim().split(" "));} exports.to_nums = to_nums;

//行列を入れ替えるトランスポーズ！！
exports.transpose = function(nss){return nss[0].map((_,c) => nss.map(r => r[c]));}

// 指定した値を指定した数でリストにするHaskellのReplicate関数の実装
function replicate(size,val){ return Array.apply(null, new Array(size)).map(v => val)} exports.replicate = replicate;
function replicateT(){ ts.ez_t("replicate", replicate(3,0), [0,0,0],"replicate(3,0) => [0,0,0]");}

if(require.main === module){
  toIL_FTT();         //Fromで始まりToで終わる一つ刻みの数値リストを返す
  toIL_ZT();          // ゼロから引数までの一つ刻みの数値リストを返す
  replicateT();       // 指定した値を指定した数でリストにするHaskellのReplicate関数の実装
}