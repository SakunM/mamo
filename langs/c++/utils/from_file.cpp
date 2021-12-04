#include <fstream>

#include "from_string.cpp" // このモジュールにto_string.cppが含まれる

//　User_FFはクラスなのでlistメソッドでファイルの内容をとりだすよ
class User_FF{
	public:
		User_FF(){}
		User_FF(string path){
			std::ifstream ifs(path); if(!ifs){cout << "not Open!!" << endl; return;}
			string buff; while(!ifs.eof()){std::getline(ifs,buff); context += buff + "\n";}
      if(context.empty()){empty = true;} else { empty = false;}
		}
    void show() { cout << context;}
		Ss list(){
			Ss res = split(context, '\n'); Ss ret;
			string s = res.back(); if(s == ""){ res.pop_back();}
			for(auto re: res){ ret.push_back(trim(re));}
			return ret;
		}
	private:
		string context; bool empty;
};

void userFF_test() {
	string issue1 = string("a:/pj/sc/lib/rs/issues/issue1.txt"), result1 = string("a:/pj/sc/lib/rs/issues/result1.txt");
  User_FF user(issue1); cout << sSL(user.list());
}

// int main(){ userFF_test();}