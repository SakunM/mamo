'use strict';

const ts = require('./to_string');

// 文字列系から数値系へ変換
function to_is(strs){ return strs.map(str => parseInt(str));} exports.to_is = to_is;

//文字列を数値に変換：冗長なのでシンプルにしただけ
function to_i(str){ return parseInt(str.trim());} exports.to_i = to_i;
function to_iT(){ ts.ez_t("to_i", to_i("123"),123);}

// 空白区切りの数値化可能な文字列を受けて数値のリストを返す
function to_nums(str){ return str.split(" ").map(s => parseInt(s));} exports.to_nums = to_nums;
function test_ns(){ let res = to_nums("30 30 10 10"); console.log(res);}  // exp is [30,30,10,10]

if(require.main === module){
  to_iT();
  test_ns();
}