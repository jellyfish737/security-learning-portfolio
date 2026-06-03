作業日：2026/5/12 Tue

## 概要 **/ Overview**

スクリプト作成と、さまざまな種類のLinuxシェルについて学ぶ

## 実施内容 **/ Practical Work**

- 仮想環境において、Bash、shellの操作に慣れる
- Ubuntu マシンのデフォルトユーザーディレクトリ /home/user に、スクリプトが配置されています。
    - このスクリプトは、特定のディレクトリ内にある .log 拡張子のすべてのファイルから、特定のキーワードを検索するものです。
    - 以下の情報を参考に、スクリプトファイルを編集してください。
    
    | 項目 | 値 |
    | --- | --- |
    | Flag | thm-flag01-script |
    | Directory | /var/log |

- nano を使って3か所を編集

```bash
#!/bin/bash

#!/bin/bash

# Defining the directory to search our flag
directory="/var/log" #変更箇所1

# Defining the flag to search
flag="thm-flag01-script" #変更箇所2

echo "Flag search in directory: $directory in progress..."

# Defining for loop to iterate over all the files with .log extension in>
for file in "/var/log"/*.log; do #変更箇所3
    # Check if the file contains the flag
    if grep -q "$flag" "$file"; then
        # Print the filename
        echo "Flag found in: $(basename "$file")"
    fi
done

```

- スクリプト実行
    - root@tryhackme:/home/user# ./flag_hunt.sh
- キーワードが含まれているファイルが見つかった！

- 猫はどこで寝ていますか？
    - 上記のファイルを開くと記載があり、正解！


## 気づき・考察 **/ Key Insights & Analysis**

- GUIだけでなくCLIやシェルを使うことで、ログ調査やファイル検索を高速に実行できると分かった。フォレンジックでは大量のログを扱うため、`grep` のようなコマンドが非常に重要だと感じた。
- 条件分岐やループを使うだけでも、簡単な認証処理や自動探索スクリプトを作れることが分かった。

## メモ **/ Notes**

#### Linux Shell

- Bash（Bourne Again Shell）
    - 多くのLinuxディストリビューションでデフォルトシェルとして利用される
    - タブ補完、コマンド履歴、スクリプト実行機能を備える
    - Linux学習の基本となるシェル
- Shell（シェル）
    - ユーザーとOSの間でコマンドを解釈するプログラム
    - WindowsのCommand PromptやPowerShellに相当する
- 現在使用中のシェル確認
    - `echo $SHELL`
    - 現在ログインしているシェルを確認できる
- 利用可能なシェル一覧確認
    - `/etc/shells`
    - システムにインストールされているシェルを確認できる
- シェルの切り替え
    - `zsh`
    - 指定したシェルを起動する
- デフォルトシェル変更
    - `chsh -s <shell_path>`
    - ログイン時に起動するシェルを変更する

---

#### 代表的なシェル

#### Bash

- Linuxで最も広く利用されるシェル
- スクリプト作成に対応
- タブ補完機能を搭載
- コマンド履歴を保持する

#### Fish

- 初心者向けに使いやすさを重視したシェル
- 自動スペル修正機能を持つ
- シンタックスハイライト機能を搭載
- カスタマイズしやすい

#### Zsh

- Bashの機能を拡張した高機能シェル
- 高度な補完機能を持つ
- カスタマイズ性が高い
- Oh My Zshなどの便利なフレームワークが利用できる

---

#### ファイル検索・文字列検索

- grep
    - ファイル内の特定文字列やパターンを検索する
    - 大きなログファイルや設定ファイルの調査でよく利用される

```bash
grep THM dictionary.txt
```

---

#### Bashスクリプト

- シェルスクリプト
    - 複数のコマンドを1つのファイルにまとめて自動実行する仕組み
    - 定型作業の自動化に利用される
- `.sh`
    - Bashスクリプトでよく利用される拡張子

---

#### Shebang

- Shebang（シバン）
    - スクリプトをどのインタープリタで実行するか指定する
    - スクリプトの先頭に記述する

```bash
#!/bin/bash
```

---

#### 変数

- Variables（変数）
    - データを保存して再利用するための仕組み
    - 入力値やファイルパスなどの管理に利用する

```bash
name="John"
echo$name
```

- `read`
    - ユーザー入力を受け取り変数へ格納する

```bash
read name
```

---

#### スクリプト実行

- 実行権限付与

```bash
chmod+x script.sh
```

- スクリプト実行

```bash
./script.sh
```

- `./`
    - 現在のディレクトリにあるファイルを実行することを示す
    - PATH上のコマンドと区別するために必要

---

#### ループ処理

- for文
    - 同じ処理を繰り返し実行する

```bash
for iin {1..10}
do
echo$i
done
```

- `do`
    - ループ開始
- `done`
    - ループ終了

---

#### 条件分岐

- if文
    - 条件によって処理を分岐する

```bash
if ["$name"="John" ];then
echo"Welcome"
else
echo"Access Denied"
fi
```

- `then`
    - 条件成立時の処理
- `else`
    - 条件不成立時の処理
- `fi`
    - if文の終了

---

#### コメント

- コメント
    - コードの説明やメモを記載する
    - 可読性や保守性向上に役立つ

```bash
# User authentication process
```

---

#### ユーザー認証スクリプト

- 認証処理
    - ユーザー名・会社名・PINを入力させる
    - 条件と一致した場合のみアクセスを許可する
- 論理AND演算子（`&&`）
    - すべての条件が真の場合のみ処理を実行する

```bash
if ["$username"="John" ] && \
   ["$companyname"="Tryhackme" ] && \
   ["$pin"="7385" ];then
```

- 入力値検証
    - ユーザー認証やアクセス制御の基本的な考え方を学べる
- 各シェル比較

| 機能 | Bash | Fish | Zsh |
| --- | --- | --- | --- |
| 正式名称 | Bourne Again Shell | Friendly Interactive Shell | Z Shell |
| スクリプト | 高い互換性 | 制限あり | 高機能 |
| タブ補完 | 基本的 | 高度 | プラグインでさらに強化可能 |
| カスタマイズ | 基本的 | 良好 | 非常に高度 |
| ユーザーフレンドリー | 普通 | 最も高い | カスタマイズ次第 |
| シンタックスハイライト | なし | 標準搭載 | プラグインで追加可能 |
