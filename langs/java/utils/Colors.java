public class Colors {
  public static void main(String[] args){
    Colors c = new Colors();
    String ans = c.suc("hoge");
    System.out.println(ans);
    String ans1 = c.norm("hoge");
    System.out.println(ans1);
    String ans2 = c.err("hoge");
    System.out.println(ans2);
    String ans3 = c.fine("hoge");
    System.out.println(ans3);
  }
  public final String black =  "\u001b[30m";
  public final String red =    "\u001b[31m";
  public final String green =  "\u001b[32m";
  public final String yellow = "\u001b[33m";
  public final String blue    = "\u001b[34m";
  public final String magenta = "\u001b[35m";
  public final String cyan    = "\u001b[36m";
  public final String white   = "\u001b[37m";
  public final String reset   = "\u001b[0m";
  String suc(String it){ return green + it + reset;}
  String norm(String it){ return blue + it + reset;}
  String err(String it){ return red + it + reset;}
  String fine(String it){ return yellow + it + reset;}
}