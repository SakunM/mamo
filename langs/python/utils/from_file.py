class FromFile:
  def set(self,ss):
    if len(ss) == 0: self.empty = True; self.ss =""
    else: self.empty = False; self.ss = ss
  def all(self)  : return self.ss
  def head(self) : return self.ss[0]
  def tails(self): return [self.ss[i] for i in range(1,len(self.ss))]

def ffUser(path):
  ff = FromFile()
  with open(path, mode='r', encoding='utf-8') as f:
    ff.set([s.strip() for s in f.readlines() if s != ""])
  return ff
if __name__ == "__main__":
  issue1 = "a:/pj/sc/lib/rs/issues/issue1.txt"
  res = ffUser(issue1)
  print(res.head())