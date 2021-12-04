#pragma once

#include <sstream>
using std::stringstream;

#include "to_string.cpp" // 色々な構造を文字列化するモジュール、このモジュールにEzTestが含まれるし、Colorsの関数も使えるよ

Ns tw_gen(int size){ Ns res; for(int i= 0; i<size; i++){ res.push_back(i);} return res;}
void tw_genT() { Ns act = tw_gen(4); Ns exp = {0,1,2,3}; ez_t("split",sIL(act),sIL(exp),"これでFor文から卒業だ");}

void t_w_test() {
  tw_genT();
}
// int main(){ t_w_test();}