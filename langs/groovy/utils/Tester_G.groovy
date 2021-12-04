import static Colors_G.*

static def zz_act(name,act,exp,dsp="disp is none!"){
  def c = getColors(), res;
  def title = c.norm("@ ") + name + String.format("%15s", "    < ${c.fine(dsp)} >");
  if(act == exp){ res = String.format("%23s actual : %-20s => %s passed", c.suc("Succes!  "), act, c.suc("OK!"));}
  else{
    title += String.format("%28s\n", "** ${c.err("Fielid")}");
    res = String.format("%20s %s\n", " ", "-- Expect : ${exp}") + String.format("%22s %s", " ", "bat was : ${act}");
  }
  println(title + res);
}

zz_act("Teser Test", 10, 10, "test-1");
zz_act("Teser Test", 0, 0, "test-2");
zz_act("Teser Test", 17, 1217, "test-3");
zz_act("Teser Test", 0, 0, "test-4");