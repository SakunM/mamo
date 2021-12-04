
class Reader {
  def lines, empty;
  Reader(path){
    def strs = new File(path).text; 
    if(strs == ""){ this.empty = true; this.lines = [];} 
    else { this.empty = false; this.lines = strs.split("\r\n");}
  }
  def list(){ return this.lines.collect{ it.trim();}}
}

static def ffUser(path){ return new Reader(path);}



def test(){ def ans = ffUser("a:/pj/sc/lib/rs/issues/issue1.txt"); println(ans.list());}
// test();
