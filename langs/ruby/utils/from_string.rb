#encoding: UTF-8

def to_nums(str) str.split(" ").collect{|s| s.to_i} end
def test_tn() res = to_nums("6 -1 2"); p(res) end   #exp is [6,7,8]

if __FILE__ == $0 then
  test_tn
end