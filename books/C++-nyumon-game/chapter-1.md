# Chapter 1 - C/C++学習の準備

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

- 以下のように修正したところ、文字化けは解消した
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

- エディタ右下の文字コードをクリックし、「エンコード付きで保存」を選択＞「Unicode (UTF-8 シグネチャ付き) - コードページ 65001」を選択するだけで解決できた・・
---
- アセンブリへの変換
    - Compiler Explorerを使ってアセンブリに変換してみる

```cpp
#include <iostream> 
using namespace std; 

int main() 
{  
	cout << " ゲームを作って C++ を習得しよう " << endl; 
	return 0; 
} 
```

```nasm
.LC0:
	.base64 "IOOCsuODvOODoOOCkuS9nOOBo+OBpiBDKysg44KS57+S5b6X44GX44KI44GGIAA="
"main":
	push    rbp
	mov     rbp, rsp
	mov     esi, OFFSET FLAT:.LC0
	mov     edi, OFFSET FLAT:"std::cout"
	call    "std::basic_ostream<char, std::char_traits<char>>& std::operator<<<std::char_traits<char>>(std::basic_ostream<char, std::char_traits<char>>&, char const*)"
	mov     esi, OFFSET FLAT:"std::basic_ostream<char, std::char_traits<char>>& std::endl<char, std::char_traits<char>>(std::basic_ostream<char, std::char_traits<char>>&)"
	mov     rdi, rax
	call    "std::ostream::operator<<(std::ostream& (*)(std::ostream&))"
	mov     eax, 0
	pop     rbp
	ret
```

- `ゲームを作って C++ を習得しよう` をUTF-8で格納している
    - Cyber Chef で From base64 でデコードすると `ゲームを作って C++ を習得しよう`になった
    - `cout << " Hello World " << endl;` に変更すると `.string " Hello World “` に変わった
        - 表示変換をCEが行っている可能性が高いらしい

```nasm
.LC0:
	.base64 "IOOCsuODvOODoOOCkuS9nOOBo+OBpiBDKysg44KS57+S5b6X44GX44KI44GGIAA="
```

- 関数に入った直後にコンパイラが作る「スタックフレームの準備」

```nasm
	push    rbp 　　　; 前の目印(rbp)を保存する
	mov     rbp, rsp  ;今の場所を新しい目印(rbp)にする
```

- `main`関数を呼んだ時、CPUは「`main`が終わったら、どこに戻ればいいんだっけ？」を覚えておく必要がある
    - そこで戻り先の住所をスタックに保存する
    - `push rbp` は `rbp`の現在の値 を送っている
        - 「今の`rbp`を念のため保存しておこう」
        - `rbp` は一旦「机の上の付箋」ぐらいに考えておく
            - コンパイラは変数を置く場所の目印が欲しい
            - その目印として使うのが `rbp`
    - `mov rbp, rsp`
        - rbp = rsp
        - 「今のスタックの位置を`rbp`という目印にしておこう」という意味
    - 「この関数専用の作業机を準備している」

```nasm
スタック ; main関数が読びだされた時点でのスタック

┌─────────────┐
│ 戻り先の住所 │ ← rsp ;スタックの先頭
└─────────────┘
```

```nasm
スタック ; push rbp 後

┌─────────────┐
│ 古いrbp     │ ← rsp ;スタックの先頭
├─────────────┤
│ 戻り先の住所 │
└─────────────┘
```

```nasm
スタック ; mov rbp, rsp 後

        rbp
         ↓
┌─────────────┐ ← rsp
│ 古いrbp     │
├─────────────┤
│ 戻り先の住所 │
└─────────────┘
```

| レジスタ | 用途 |
| --- | --- |
| rsp | スタックの先頭 |
| rbp | スタックフレームの基準点 |
| rip | 次に実行する命令 |
| rax | 戻り値など |
---
- `.LC0` は文字列そのものではなく、その文字列が置かれている場所についたラベル名
    - 今回だと「ゲームを作って C++ を習得しよう」
- OFFSET とは「文字列そのもの」ではなく「文字列の住所」を渡す
    - 文字列は長いから住所で渡す
- FLAT = 普通のメモリ空間（とりあえずはこの解釈でOK）
    - 現在のWindows/Linuxの64bitプログラムでは、ほぼ「全部ひとつの巨大なアドレス空間」として扱う
    - これを **FLAT memory model** と呼ぶ
- `mov     esi, OFFSET FLAT:.LC0`
    - `.LC0` の住所を `esi` に入れろ
- `mov edi, OFFSET FLAT:"std::cout”`
    - `std::cout` の住所を `edi` に入れろ
        - `std::` は「標準ライブラリの中にあるよ」という意味
            - `using namespace std;`これがあるので `std::`として扱われる
            - 仮に `namespace game` であれば `game::score` となる
- `call    "std::basic_ostream<char,….`
    - 「文字列を表示する関数を呼んでいる」
    - 戻り値として `std::cout` を返している
    - その戻り値が `rax` に入る

```nasm
	mov     esi, OFFSET FLAT:.LC0 ;フラットなアドレス空間における.LC0 のアドレス
	mov     edi, OFFSET FLAT:"std::cout"
	call    "std::basic_ostream<char, std::char_traits<char>>& std::operator<<<std::char_traits<char>>(std::basic_ostream<char, std::char_traits<char>>&, char const*)"
```

- `.LC0` → 文字列の住所
- `std::cout` → coutオブジェクトの住所
- `OFFSET` → 「その住所を取れ」
- `FLAT` → 「普通の64bitメモリ空間」
----
- `mov esi, OFFSET FLAT:std::endl`
    - endl関数の住所を渡して、esi に入れている
        - endl は文字列ではなく関数
    - 「endl関数の住所を準備してる」
- `mov rdi, rax`
    - `rax`には `call "std::basic_ostream<char, std::char_traits<char>>& std::operator<<<std::char_traits<char>>(std::basic_ostream<char, std::char_traits<char>>&, char const*)"` これの戻り値が入っている
    - 「さっきのcoutを準備してる」
- `call "std::ostream::operator<<(std::ostream& (*)(std::ostream&))”`
    - ostreamに対して関数を受け取るoperator<<を呼ぶ
    - 「cout << endl を実行してる」

- `mov eax, 0`
    - x86-64では、関数の戻り値は決められたレジスタに入れるというルールがある
    - 整数なら
        - eax (32bit)
        - rax (64bit)
- `pop rbp`
    - push rbp は、古い rbp を保存だった
    - なので、保存していた rbp を元に戻す
        - 保存していたrbpを取り出して復元
- `ret`
    - 呼び出し元へ戻る
        - スタックには「戻り先の住所」が保存されている
        - `ret` はその住所を取り出して「そこへジャンプ」する

- この形を見つけると、「ここから関数が始まり、ここで終わる」という目印になる

```nasm
push rbp
mov rbp, rsp

;...関数本体...

pop rbp
ret
```
---
- デバッグ実習
    - 左側の余白をクリックすることで、ブレークポイントの設定が可能
    - [F5] キーでデバッグ開始
    - [デバッグ] → [ウィンドウ] → [ウォッチ] → [ウォッチ1] を選択
    - [項目をウォッチに追加する] をクリックし、[名前] に変数i を入力
    - 変数i の値が [値] 欄に表示される
    - [F11] キー or ステップイン で処理を一行ずつ進め、値の変化に注目する

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
