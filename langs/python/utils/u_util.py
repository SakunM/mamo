# coding: utf-8 

from pprint import pprint

# Rubyにインスパイアされた表示に関する関数：よく使う関数ほど名前は短くね！puts関数に相当するので自動的に改行するよ
def p(strs): print(strs)

# Rubyのp関数に対応する関数、言語のリテラル表現をそのまま表示する
def pp(strs): pprint(strs)

# 使用説明書を兼ねた簡単なテスト関数引数は文字表現で渡す
def ez_t(title,act,exp,disp = ""): p(f"Test {title:<20}: {act == exp} {disp:>30}")

# 多態テストのための便利な関数、仕様は他の言語と同じよ
def zz_act(title,act,exp,disp = ""):
  print(f"@ {title} {disp:>30}")
  if act == exp : print(f"Succes! actual : {act} => OK! passed")
  else : print(f"  ☆-Fielid! -- Expect : {exp:>10}\n               bat was : {act:>10}")

def toSL_IL(ns): return [str(n)for n in ns] 
def toSL_ILT(): ez_t("toSL_IL",str(toSL_IL([1,2,3,4])),"['1', '2', '3', '4']", "数値のリストを文字列リストへ変換")

def toIL_SL(strs): return [int(str) for str in strs]
def toIL_SLT():
  ez_t("toIL_SL",str(toIL_SL(["12","3","123"])),"[12, 3, 123]","数値化可能な文字列リストを受けて、数値のリストをかえす")

def toIL_S(s,dmt=" "): return toIL_SL(s.strip().split(dmt))
def toIL_ST(): ez_t("toIL_S", str(toIL_S("1 2 3")), "[1, 2, 3]","デリミタ付きの文字列を数値リストに変換")

def split_L(lst,dmt): return [[j for j in i.split('/') if j] for i in '/'.join(lst).split(dmt) if i]
def split_LT():
  ez_t("Split_L", str(split_L(["ab","--","cde","--","aaa","bbb","--"],"--")),"[['ab'], ['cde'], ['aaa', 'bbb']]",
  "文字列のリストに対応したSplit関数 ToDo:総称化")

def to_is(strs): return [int(str) for str in strs]
def to_isT(): ez_t("to_is", to_is(["1","2","3"]), [1,2,3], "数値化可能な文字リストを受け取り整数リストを返す")

def to_nums(str): return to_is(str.strip().split(" "))
def to_numsT(): ez_t("to_nums", to_nums("1 2 3"),[1,2,3],"空白区切りの数値化可能文字列を整数化して数値リストを返す")

def test_name(str): sss = str.split("_"); ss = sss[1].split(" "); return ss[0]
def test_nameT():
  ez_t("test_name", test_name("test_ファイルじゃテストしにくい (__main__)"), "ファイルじゃテストしにくい","for unittest")
def docker(obj): print(repr(obj.__doc__))
if __name__ == '__main__':
  toSL_ILT()  # 数値のリストを文字列リストへ変換
  toIL_SLT()  # 数値化可能な文字列リストを受けて、数値のリストをかえす
  toIL_ST()   # デリミタ付きの文字列を数値リストに変換
  split_LT()  # 文字列のリストに対応したSplit関数 ToDo:総称化
  to_isT()    # 数値化可能な文字リストを受け取り整数リストを返す
  to_numsT()  # 空白区切りの数値化可能文字列を整数化して数値リストを返す
  test_nameT() # テストメソッドからメソッド名を切り出す
