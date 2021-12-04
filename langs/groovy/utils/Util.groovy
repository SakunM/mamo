import static Integer.parseInt
import static Double.parseDouble

//一番簡単なテスト関数
static def ezT(title, boo, dsp="説明無し（笑）"){ printf("TEST %-15s %b %30s\n",title,boo,dsp);}

static def p (str){ println(str);}

static def to_is(strs){return strs.collect{parseInt(it)}}
def to_isT(){ezT("to_is", (to_is(["45"]) == [45]),"文字列のリストを受けて数値リストを返す");}

static def to_nums(str){ return to_is(str.trim().split(" "))}
static def to_i(str){ return parseInt(str.trim())}
static def to_f(str){ return parseDouble(str.trim());}
static def to_s(x){ return x.toString();}
static def words(strs){return strs.split(" ");}
// 数値リストのすべての値をー１して１始まりを０始まりに直すPaize関係用のユーティリティ
static def neg1(ns){ return ns.collect{it - 1};}

