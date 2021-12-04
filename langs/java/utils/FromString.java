import java.util.List;
import java.util.ArrayList;
import java.util.stream.Stream;
import java.util.stream.IntStream;
import java.util.stream.Collectors;
import static java.util.Arrays.asList;
import static java.util.stream.Collectors.toList;

public class FromString {
  public static void main(String[] args){
    FromString fs = new FromString();
    fs.test_toNums();
    fs.test_neg1();
  }

  public List<Integer> toNums(String str){
    List<String> strs = asList(str.split(" ")); return strs.stream().map(Integer::parseInt).collect(toList());
  }
  public void test_toNums(){ List<Integer> res = toNums("10 20 30"); System.out.println(res);}  // exp is [10,20,30]

  public List<Integer> neg1(List<Integer> ns){ return ns.stream().map(n -> n - 1).collect(toList());}
  public void test_neg1(){ List<Integer> res = neg1(toNums("3 4 5")); System.out.println(res);}
}