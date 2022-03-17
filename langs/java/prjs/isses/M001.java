import java.io.InputStreamReader;
import java.io.BufferedReader;
import java.io.IOException;
import java.util.List;
import java.util.ArrayList;
import java.util.Set;
import java.util.Map;
import java.util.HashSet;
import java.util.HashMap;
import java.util.Optional;
import java.util.stream.Stream;
import java.util.stream.IntStream;
import java.util.stream.Collectors;
import java.util.Arrays;
import java.util.Queue;
import java.util.LinkedList;
import static java.util.Arrays.asList;
import static java.util.stream.Collectors.toList;
import static java.util.stream.Collectors.joining;
import static java.util.stream.Collectors.toCollection;
import static java.util.Collections.reverse;
import static java.util.Collections.max;
import static java.util.Collections.min;

public class M001{
  public static void main(String[] args) throws Exception{
    // refactor();
    develop();
    // product();
  } // m001 M001 domain input
  
  public static void refactor() throws Exception {
    final String issue = "a:/pj/mamo/refs/isses/issue1.txt"; final String result = "a:/pj/mamo/refs/isses/result1.txt";
    final UserFile uf = new UserFile(); uf.ffUser(result); final List<String> exp = uf.list(); uf.ffUser(issue);
    // System.out.println(uf.list()); System.out.println(exp);
    M001 m001 = new M001(uf); m001.test();
    // developer(issue,result,"refactor");
  }
  public static void product() throws Exception{ 
    User user = new User(); 
    // System.out.println(user.list());
    M001 m001 = new M001(user);
    List<String> ans = m001.domains(); System.out.println(ans.stream().collect(joining("\n")));
  }
  public static void develop () throws Exception {
    final String issue1 = "a:/pj/mamo/refs/isses/issue1.txt"; final String result1 = "a:/pj/mamo/refs/isses/result1.txt";
    final String issue2 = "a:/pj/mamo/refs/isses/issue2.txt"; final String result2 = "a:/pj/mamo/refs/isses/result2.txt";
    final String issue3 = "a:/pj/mamo/refs/isses/issue3.txt"; final String result3 = "a:/pj/mamo/refs/isses/result3.txt";
    final String issue4 = "a:/pj/mamo/refs/isses/issue4.txt"; final String result4 = "a:/pj/mamo/refs/isses/result4.txt";
    final String issue5 = "a:/pj/mamo/refs/isses/issue5.txt"; final String result5 = "a:/pj/mamo/refs/isses/result5.txt";
    final String issue6 = "a:/pj/mamo/refs/isses/issue6.txt"; final String result6 = "a:/pj/mamo/refs/isses/result6.txt";
    developer(issue1, result1, "test-1"); developer(issue2, result2, "test-2");
    developer(issue3, result3, "test-3"); developer(issue4, result4, "test-4");
    developer(issue5, result5, "test-5"); developer(issue6, result6, "test-6");
  } // main
  public static void developer(String issue, String result, String name) throws Exception{
    UserFile uf = new UserFile(); uf.ffUser(result); List<String> exp = uf.list(); uf.ffUser(issue);
    M001 m001 = new M001(uf); List<String> ans =  m001.domains(); Tester<String> t = new Tester<>("M001 Test");
    t.test(name, ans.toString(),exp.toString());
  }
  public final List<String> lines; public final FromString fs;
  private List<String> all = new ArrayList<>();

  public M001(UserFile user){ this.lines = user.list(); this.fs = new FromString();}
  
  private void m001() {
    String[] fst = this.lines.get(0).split(" "), snd = this.lines.get(1).split(" ");
    this.all.addAll(asList(fst)); this.all.addAll(asList(snd));
  }
  // public void test(){ m001(); System.out.println(this.all);} // exp is 

  private Map<String,Integer> domain(List<String> ss) {
    Map<String,Integer> res = new HashMap<>();
    for(String s: ss){ res.put(s,res.get(s) == null ? 1 : res.get(s) + 1);}
    return res;
  }
  public void test_d(){
    List<String> arg = asList("fishing","gardening","swimming","fishing","hunting","fishing","fishing","biting");
    Map<String,Integer> res = domain(arg); System.out.println(res);
  }  // exp is exp

  public List<String> domains(){
    m001(); Map<String,Integer> map = domain(this.all);
    int res = max(map.values());
    return asList(String.valueOf(res));
  }// main
  public void test(){ List<String> res = domains(); System.out.println(res);}
}
// input product
class User extends UserFile{
  List<String> lines; final FromString fs = new FromString();
  public User() throws IOException{
    this.lines = new ArrayList<>();
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in)); 
    String line = br.readLine(); lines.add(line.trim());
    line = br.readLine(); lines.add(line.trim());
    // int lim = lines.get(0).length() - 1;
    // for(int i= 0; i<lim; i++){ lines.add(br.readLine().trim());}
    br.close();
  }
  public List<String> list(){ return this.lines;}
}
