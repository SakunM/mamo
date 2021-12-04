# coding: utf-8

def sSs(args):
  res = "["; lim = len(args) - 1
  for i in range(lim):
    res += "'" + args[i] + "'" + ", "
  res += "'" + args[lim] + "']"
  return res
def test_sSs(): res = sSs(["hoge","fuga","mamo"]); print(res)   #exp is ['1', '2', '3']

def sNs(args):
  return sSs([str(arg) for arg in args])
def test_sNs(): res = sNs([1,2,3]); print(res)   #exp is ['1', '2', '3']

def to_ss(ns): return [str(n) for n in ns]
def unwords(ns): ss = to_ss(ns); return " ".join(ss)
def test_unwords(): res = unwords([1,2,3]); print(res)

if __name__ == "__main__":
  test_sSs()
  test_sNs()
  test_unwords()