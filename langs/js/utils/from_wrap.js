'use strict';

const ts = require('./to_string'); 

/*** リスト操作用関数 ***/
//リストの最小値を得る
function mins (nums){ return nums.reduce((a,b) => a < b ? a : b);} exports.mins = mins;
function minsT(){ ts.ez_t("mins",mins([1,2,3]),1,"get most smoll value of list");}

//リストの最大値を得る
function maxs(nums){ return nums.reduce((a,b) => a < b ? b : a);} exports.maxs = maxs;
function maxsT(){ ts.ez_t("maxs", maxs([1,2,3]),3, "get most big value of list");}

//リスト要素の合計
function sums(nums){ return nums.reduce((a,b) => a + b);} exports.sums = sums;
function sumsT(){ ts.ez_t("sum",sum([1,2,3]),6, "sum([1,2,3]) => 6");}

if(require.main === module){
  minsT();    //リストの最小値を得る
  maxsT();    //リストの最大値を得る
  sumsT();     //リスト要素の合計
}