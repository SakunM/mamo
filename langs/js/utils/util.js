"use strict";

//フィルター関数のお供だよ
exports.isin = function(tb,val){ for(let t of tb){if(t == val){return true;}} return false;}
//理論演算の列挙をシンプルにするためのany関数の実装
exports.any = function(bs){ for(let b of bs){if(b){return true}} return false;}
//理論演算の列挙をシンプルにするためのall関数の実装
exports.all = function(bs){ for(let b of bs){if(b){return false}} return true;}

//文字列リスト版スプリット関数
exports.split_L = function(lst,dmt){
  return lst.join("/").split("--").filter(it => it != "").map(it => it.split("/").filter(it => it !== ""));}

//Shift_JISに変換して標準出力へ
exports.jis = function(text){
  let iconv = require('iconv-lite');
  let textend = text + "\n";
  let buf = iconv.encode(textend, "Shift_JIS");
  process.stdout.write(buf)
}

if(require.main === module){
}
