import java.util.*;
import java.util.stream.*;
import static java.util.stream.Collectors.*;

public class Util{
	public static void main(String[] args)throws Exception{
		
	}
	//	数値に変換可能な文字列を受け取って数値（Integer）を返すよ
	public static Integer to_i(String str){return Integer.parseInt(str.trim());}
	
	//	値とリストを受け取り、値がリストに含まれていればTrue無ければFalseを返す
	public static <T>boolean isin(T val, List<T>vals){for(T v : vals){if(v.equals(val)){return true;}}return false;}
	
	//	値とリストを受け取り、値がリストに含まれていればFalse無ければTrueを返す
	public static <T>boolean notin(T val, List<T>vals){ return !(isin(val,vals));}
	
	//	入れ子のリストを行列に見立てて縦横を入れ替える
	public static <T> List<List<T>> transpose(List<List<T>> imp){
		int outS = imp.size(), inS = Collections.max(imp.stream().map(im -> im.size()).collect(toList()));
		List<List<T>> exp = new ArrayList<>(); for(int i=0; i<inS; i++){exp.add(new ArrayList<T>());}
		for(int row=0; row<inS; row++){for(int col=0; col<outS; col++){
			List<T> getter = imp.get(col), setter = exp.get(row); setter.add(getter.get(row));}} return exp;}
	
	// Haskellのtails関数のJava実装
	public static List<String> tails(String str){
		return nums_z(str.length()).stream().map(id -> str.substring(id)).collect(toList());}
	
	// ０からsizeまでの数列を生成
	public static List<Integer> nums_z(int size){return IntStream.range(0,size).boxed().collect(toList());}
	
	// リストを簡単に生成するよ
	@SafeVarargs public static <T>List<T> list(T... xs){
   	List<T> lst = new ArrayList<>(); for(T x: xs){lst.add(x);} return lst;}
	
	// サムの実装
	public static int sums(List<Integer> nums){ return nums.stream().mapToInt(i -> i).sum();}
}
