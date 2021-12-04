#encoding: UTF-8

class FromFile
  attr_reader :empty, :ss
  def set(ss) if ss.size == 0 then @empty = true; @ss = ''; else @empty = false; @ss = ss end end
  def all() @ss end
end

def ffUser(path) ff = FromFile.new; f = File.open path,"r:utf-8"; ff.set f.readlines.each{|l| l.rstrip!}; f.close; ff; end

if __FILE__ == $0 then
  issue = "a:/pj/sc/lib/rs/issues/issue1.txt"
  res = ffUser(issue)
  puts res.all
end