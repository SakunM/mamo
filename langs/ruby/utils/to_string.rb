#encoding: UTF-8

def sNs(ns)
  res = '['; lim = ns.size()-1;
  lim.times{|i| res += '"' + ns[i].to_s + '", '}
  res += '"' + ns[lim].to_s + '"]'
  return res
end
def test() res = sNs([3]); puts(res) end   #exp is ["1","2","3"]

if __FILE__ == $0 then
  test
end