# coding: utf-8

# 文字を数値に変換
def to_i(s): return int(s.strip())
def to_i_test(): ans = to_i("32"); print(ans) # exp is 32

# 文字列配列を数値配列に変換
def to_is(strs): return [int(str) for str in strs]
def to_is_test(): ans = to_is(["48", "52", "1"]); print(ans) # exp is [48, 52, 1]

# 空白区切りの数値文字列を数値配列に変換
def to_nums(s): return to_is(s.strip().split(" "))
def to_nums_test(): ans = to_nums("3 23 12"); print(ans) # exp is [3,23,12]

if __name__ == "__main__":
  to_i_test()     # 文字を数値に変換
  to_is_test()    # 文字列配列を数値配列に変換
  to_nums_test()  # 空白区切りの数値文字列を数値配列に変換
