public class Tester <T>{
  public static void main(String[] args){
    Tester<Integer> t = new Tester <>("Main Test");
    t.test("test-1",10, 10);
  }
  public final String title; private Colors c;
  Tester(String title){this.title = title; this.c = new Colors();}
  
  void test(String dsp, T act, T exp){
    String front = String.format("%s %s   %-25s", c.norm("@"),this.title, "disp is : "+ dsp); String res;
    if(act.equals(exp)){ res = String.format("%23s actual : %-10s => %s passed!", c.suc("Succes! "), act.toString(), c.suc("OK!"));}
    else{
      front += String.format("%28s\n", "** " + c.err("Fielid!!"));
      res = String.format("%20s %s\n", " ", "-- Expect : " + exp.toString()) + String.format("%22s %s", " ", "bat was : " + act.toString());
    }
    System.out.println(front + res);
  }
}