#pragma once

#include "to_string.cpp"

// 画面表示に関する色々な関数を定義している整数表示はpI,pIL,pILL　文字列表示はpS,pSL,pSLL
void pI(int n) { cout << n << endl;}
void pi(int n) { cout << n << endl;}
void pIL(Ns ns) { cout << sIL(ns) << endl;}       // 数値ベクターの表示系
void pNs(Ns ns) { cout << sIL(ns) << endl;}       // 数値ベクターの表示系
void pILL(Nss nss) { cout << sILL(nss) << endl;}
void pNss(Nss nss) { cout << sILL(nss) << endl;}

void pS(string s) { cout << s << endl;}
void ps(string s) { cout << s << endl;}
void pSL(Ss s) { cout << sSL(s) << endl;}
void pSs(Ss s) { cout << sSL(s) << endl;}
void pSLL(Sss s) { cout << sSLL(s) << endl;}
void pSss(Sss s) { cout << sSLL(s) << endl;}

void pc(char c) { cout << c << endl;}
void pb(bool b) { if(b){cout << "true" << endl;} else{ cout << "false" << endl;}}
void pf(double d){ cout << d << endl;}


void p_u_tests() { Ns arg = {1,2,4}; pIL(arg);}
// int main(){p_u_tests();}