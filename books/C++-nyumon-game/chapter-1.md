# Chapter 1 - C/C++学習の準備

## ■ Summary（要点）

- 

## ■ Key Concepts（重要ポイント）

- API hookingとは何か
- packerの役割

## ■ My Understanding（自分の理解）

- なぜこれが必要なのか
- どこで使われるのか


## ■ Practice / Experiment（重要）

- ハンズオン１
    - プログラムの書き写し
        - テキスト通りに書き写しビルトしたところ、文字化けが発生
        - 以下のように解釈されている可能性大
            - ソースコード：UTF-8
            - コンソール：Shift_JIS（CP932）

```cpp
// 入力に慣れるためにプログラムの書き写しを行う
// アルファベットの大文字小文字を区別する点に注意
#include <iostream> // 標準入出力の機能を取り込む

using namespace std; // std名前空間を使用する

int main() // main(メイン)関数と呼ばれる関数を定義
{ // main関数の処理の始まりとなる波括弧
	cout << " ゲームを作って C++ を習得しよう " << endl; // coutは文字列を出力する命令、endl は改行するという意味
	return 0; // 0を返す
} // main関数の処理の終わりとなる波括弧
```

- AIに相談し、以下のように修正したところ、文字化けは解消した
    - `#include <windows.h>` 追加
    - main関数内に `SetConsoleOutputCP(CP_UTF8);` を追加

```cpp
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
```

- エディタ右下の文字コードをクリックし、「エンコード付きで保存」を選択＞「Unicode (UTF-8 シグネチャ付き) - コードページ 65001」を選択するだけで解決できそう・・

- デバッグ実習

```cpp
#include <iostream>
using namespace std;
int main()
{
    int i = 2147483647;
    cout << "最初のiの値 " << i << endl;
    i = i + 1;
    cout << "iに1を加えると " << i << "になる" << endl;
    i = i - 1;
    cout << "iから1を引くと " << i << "になる" << endl;
}
```


## ■ Learning（学び）

- アルファベットの大文字小文字を区別する点に注意
    - Main や Return だとエラーになる
- 命令や計算式の後にセミコロン(;) を記述する
- 文字列の出力や代入時は、文字の前後をダブルクォート(”) でくくる
- `()` 丸括弧
    - 計算式の記述
    - 関数の定義／呼び出し
- `[]`  角括弧
    - 配列の記述
- `{}` 波括弧
    - if / for 分のブロック
    - 関数の処理
    - 構造体やクラスの定義
    - 配列の初期化
- デバッグとは、バグを探し出して修正する作業のこと
    - デバッグの最も基本的な方法は変数の値を監視すること
