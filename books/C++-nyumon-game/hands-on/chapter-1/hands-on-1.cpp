// 入力に慣れるためにプログラムの書き写しを行う
// アルファベットの大文字小文字を区別する点に注意

#include <windows.h>
#include <iostream> // 標準入出力の機能を取り込む

using namespace std; // std名前空間を使用する
int main() // main(メイン)関数と呼ばれる関数を定義
{ // main関数の処理の始まりとなる波括弧
	SetConsoleOutputCP(CP_UTF8);
	cout << " ゲームを作って C++ を習得しよう " << endl; // coutは文字列を出力する命令、endl は改行するという意味
	return 0; // 0を返す
} // main関数の処理の終わりとなる波括弧
