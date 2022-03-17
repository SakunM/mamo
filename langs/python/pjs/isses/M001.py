# from functools import reduce
from itertools import combinations, permutations
# import numpy as np
# import sys
from collections import deque
import math

from tester import zz_act
from from_file import ffUser
from to_string import sSs, sNs, unwords
from from_string import to_i, to_is, to_nums

def m001(ss):
  first = ss[0].split(" "); second = ss[1].split(" ")
  return first + second
# def test(): ss = m001(["fishing gardening swimming fishing","hunting fishing fishing biting"]); print(ss)

def domain(ss):
  res = {}
  for s in ss:
    res[s] = res[s] + 1 if res.get(s) else 1
  return res
# def test(): res = domain(["fishing","gardening","swimming","fishing","hunting","fishing","fishing","biting"]); print(res)

def domains(ss): #main
  all = m001(ss); dom = domain(all); res = max(dom.values()); return [str(res)]
def test(): ans = domains(["fishing gardening swimming fishing","hunting fishing fishing biting"]); print(ans)

def user():
  res = []
  res.append(input().strip())
  res.append(input().strip())
  # lim = len(res[0])-1
  # for _ in range(lim): res.append(input().strip())
  return res

def product():
  u = user()
  # print(u)
  ans = domains(u)
  print("\n".join(ans))

def developer(issue, result, name):
  ans = domains(ffUser(issue).all()); exp = ffUser(result).all(); zz_act("M001 Test", sSs(ans),str(exp), name)
def develop():
  issue1 = "a:/pj/mamo/refs/isses/issue1.txt"; result1 = "a:/pj/mamo/refs/isses/result1.txt"
  issue2 = "a:/pj/mamo/refs/isses/issue2.txt"; result2 = "a:/pj/mamo/refs/isses/result2.txt"
  issue3 = "a:/pj/mamo/refs/isses/issue3.txt"; result3 = "a:/pj/mamo/refs/isses/result3.txt"
  issue4 = "a:/pj/mamo/refs/isses/issue4.txt"; result4 = "a:/pj/mamo/refs/isses/result4.txt"
  issue5 = "a:/pj/mamo/refs/isses/issue5.txt"; result5 = "a:/pj/mamo/refs/isses/result5.txt"
  issue6 = "a:/pj/mamo/refs/isses/issue6.txt"; result6 = "a:/pj/mamo/refs/isses/result6.txt"
  developer(issue1, result1, "test-1"); developer(issue2, result2, "test-2")
  developer(issue3, result3, "test-3"); developer(issue4, result4, "test-4")
  developer(issue5, result5, "test-5"); developer(issue6, result6, "test-6")

def refactor():
  issue = "a:/pj/mamo/refs/isses/issue7.txt"; result = "a:/pj/mamo/refs/isses/result7.txt"
  user = ffUser(issue).all(); exp = ffUser(result).all()
  # print(user); print(exp)
  ans = domains(user)
  zz_act("M001 Test", sSs(ans),str(exp), "refactor")

# main M001 m001 domain user
if __name__ == '__main__':
  # test()
  # refactor()
  develop()
  # product()

