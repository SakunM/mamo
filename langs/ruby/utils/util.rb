#encoding: UTF-8
=begin 
  タグの管理									C:\offline\tags\オフラインタグ一覧.txt (4,8): 
=end

module Util
##	開発時に必要な失敗の詳細なテスト関数
  def zz_act(title,act,exp,disp = "")
    titleJ = title.to_s.encode("Shift_JIS"); dispJ = disp.to_s.encode("Shift_JIS")
    puts "@ %s %40s" %[titleJ,dispJ]
  	  if exp == act 
  	    then puts "Succes! actual : #{act.to_s.encode("Shift_JIS")} OK! passed"
  	    else actJ = act.to_s.encode("Shift_JIS"); expJ = exp.to_s.encode("Shift_JIS"); star = "☆".encode("Shift_JIS")
  	      puts " %s - Fielid! -- Expect : %20s\n                but was : %20s" %[star,expJ,actJ]
  	  end
  	end; module_function :zz_act
	def zz_actT() zz_act("Test",3,2,"開発時に必要な失敗の詳細なテスト関数")end
##  実行時のメソッド名を取得する。テスト時に有効
  def test_name(name) names = name.split('_'); names[1] end; module_function :test_name
  def nameID(t_name, id)  "#{t_name} - #{id}" end; module_function :nameID
## UTF-8 とサクラのアウトプットへの対応
  def jis(msg) msg.to_s.encode("Shift_JIS") end
##  表示が一行で収まる一番簡単なテスト
  def ez_t(title,act,exp,disp = "")
    puts "Test %-20s: %s %25s" %[title.to_s.encode("Shift_JIS"),act == exp,disp.to_s.encode("Shift_JIS")] 
  end; module_function :ez_t
	def ez_tT() Util.ez_t("ez_t",1,1,"表示が一行で収まる一番簡単なテスト")end
  
##	数値化可能な文字列リストを数値リストの変換
  def to_is(strs) strs.map(&:to_i) end
  def to_isT() puts "to_is Test まだ作ってないよ（笑）".encode("Shift_JIS") end

##	空白区切りの数値化可能文字列を空白区切りで数値リストに変換
  def to_nums(str) to_is(str.split(" ")) end; module_function :to_nums
  def to_numsT() ez_t "to_nums Test", (to_nums " 12 34 56 "),[12,34,56], "空白区切りで数値リストに変換"end
  
##リストの文字列化
	def sL(lst) str = "["; str << lst.join(","); str << "]" end; module_function :sL
##	def sLT() ez_t "SL Test", (sL [1,2,3]), "[1,2,3]" end 
	def sLT() ez_t "SL Test", (sL [1]), "[1]", "リストの文字列化" end 
	
##入れ子リストの文字列化
	def sLL(lst) str = "["; strs = lst.map{|it| sL it}; str << strs.join(","); str << "]" end; module_function :sLL
	def sLLT() ez_t "SLL Test", (sLL [[1,2],["3","4"]]), "[[1,2],[3,4]]", "入れ子リストの文字列化" end
end

class Adder
  def initialize(num) @num = num end
  def ad() @num += 1; @num end
end
include Util
if __FILE__ == $0 then
	zz_actT  	##	開発時に必要な失敗の詳細なテスト関数
	ez_tT			##  表示が一行で収まる一番簡単なテスト
	to_isT 		##	数値化可能な文字列リストを数値リストの変換
	to_numsT	##	空白区切りの数値化可能文字列を空白区切りで数値リストに変換
	sLT				##リストの文字列化
	sLLT			##入れ子リストの文字列化
end

__END__
