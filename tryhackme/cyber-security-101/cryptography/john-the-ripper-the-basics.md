作業日：2026/5/23 Sat

## 概要 **/ Overview**

強力で柔軟性の高いハッシュ解読ツール「John the Ripper」の使い方を学ぶ

## 実施内容 **/ Practical Work**

- 仮想環境でJohn the Ripper を操作しながら、設問に答える。

- ファイルは、VM内の以下にある。
    - `~/John-the-Ripper-The-Basics/Task04/`
- hash1.txt のハッシュ形式は？
    - user@ip-10-48-167-91:~/John-the-Ripper-The-Basics/Task04$ python3 hash-id.py を実行
    - HASHを確認し、形式を特定できた

- hash1.txt の解析結果は？
    - user@ip-10-48-167-91:~/John-the-Ripper-The-Basics/Task04$ john --format=raw-md5 --wordlist=/user/share/wordlists/rockyou.text hash1.txt
    - 英単語を確認できた

- hash2.txt のハッシュ形式は？
    - user@ip-10-48-167-91:~/John-the-Ripper-The-Basics/Task04$ python3 hash-id.py
    - HASHを確認し、形式を特定できた

- hash2.txt の解析結果は？
    - user@ip-10-48-167-91:~/John-the-Ripper-The-Basics/Task04$ john --format=raw-sha1 --wordlist=/usr/share/wordlists/rockyou.txt hash2.txt
    - 英単語を確認できた

- hash3.txt のハッシュ形式は？
    - HASH: D7F4D3CCEE7ACD3DD7FAD3AC2BE2AAE9C44F4E9B7FB802D73136D4C53920140A
    - HASHを確認し、形式を特定できた

- hash3.txt の解析結果は？
    - user@ip-10-48-167-91:~/John-the-Ripper-The-Basics/Task04$ john --format=raw-sha256 --wordlist=/usr/share/wordlists/rockyou.txt hash3.txt
    - 英単語を確認できた

- hash4.txt のハッシュ形式は？
    - HASH: c5a60cc6bbba781c601c5402755ae1044bbf45b78d1183cbf2ca1c865b6c792cf3c6b87791344986c8a832a0f9ca8d0b4afd3d9421a149d57075e1b4e93f90bf
    - HASHを確認し、形式を特定できた

- hash4.txt の解析結果は？
    - user@ip-10-48-167-91:~/John-the-Ripper-The-Basics/Task04$ john --format=whirlpool --wordlist=/usr/share/wordlists/rockyou.txt hash4.txt
    - --format=whirlpool時は、raw-sha256 などは不要
    - 英単語を確認できた

- `ntlm.txt`を解析してみましょう！ファイルは以下にあります。
    - `~/John-the-Ripper-The-Basics/Task05/`
- このパスワードの解析結果は？
    - user@ip-10-48-167-91:~/John-the-Ripper-The-Basics/Task05$ john --format=nt --wordlist=/usr/share/wordlists/rockyou.txt ntlm.txt
    - 同じ要領で英単語を確認できた

- それでは、`etchashes.txt` に含まれる root ユーザーのパスワードハッシュを解析してみましょう。ファイルは以下にあります。
    - `~/John-the-Ripper-The-Basics/Task06/`
- root のパスワードは？
    - john --wordlist=/usr/share/wordlists/rockyou.txt --format=sha512crypt unshadowed.txt
    - (root) の形でパスワードが出力できたことを確認

- 今度は実際にハッシュを解析してみましょう。対象ユーザー名は `Joker`。ファイルは以下にあります。
    - `~/John-the-Ripper-The-Basics/Task07/`
- Joker のパスワードは？
    - ファイルは hash07.txt
        - 7bf6d9bb82bed1302f331fc6b816aada
    - echo "Joker:7bf6d9bb82bed1302f331fc6b816aada" > hash07_fixed.txt
        - Hashの前に名前を付ける
    - user@ip-10-48-167-91:~/John-the-Ripper-The-Basics/Task07$ john --single --format=raw-md5 hash07_fixed.txt
    - Jokerのパスワードを確認できた

- それでは、「安全な」Zipファイルの解析に挑戦してみましょう！ファイルは以下にあります。
    - `~/John-the-Ripper-The-Basics/Task09/`
- secure.zip ファイルのパスワードは何ですか？
    - zip2john secure.zip > zip_hash.txt
    - user@ip-10-48-167-91:~/John-the-Ripper-The-Basics/Task09$ john --wordlist=/usr/share/wordlists/rockyou.txt zip_hash.txt
    - パスワードを確認できた

- Zipファイル内のフラグ内容は何ですか？
    - unzip secure.zip を実行し、パスワードを聞かれた際に、上記で確認したパスワードを入力  
    - 解凍後に  cat zippy/flag.txt を実行し、フラフを獲得

- それでは、「安全な」RARファイルの解析に挑戦してみましょう！ファイルは以下にあります。
    - `~/John-the-Ripper-The-Basics/Task10/`
- secure.rar ファイルのパスワードは何ですか？
    - rar2john secure.rar > rar_hash.txt
    - ser@ip-10-48-167-91:~/John-the-Ripper-The-Basics/Task10$ john --wordlist=/usr/share/wordlists/rockyou.txt rar_hash.txt
    - パスワードを確認できた


- RARファイル内のフラグ内容は何ですか？
    - unrar x secure.rar を実行し、パスワードを聞かれた際に、上記で確認したパスワードを入力  
    - cat flag.txt でフラグ獲得できた

- それでは、この課題に関連する id_rsa ファイルのハッシュを解読してみてください！ファイルは 以下にあります。
    - `~/John-the-Ripper-The-Basics/Task11/`
- SSH 秘密鍵のパスワードは何ですか？
    - ssh2john.py id_rsa > id_rsa_hash.txt
    - user@ip-10-48-167-91:~/John-the-Ripper-The-Basics/Task11$ john --wordlist=/usr/share/wordlists/rockyou.txt id_rsa_hash.txt
    - パスワードを確認できた


## 気づき・考察 **/ Key Insights & Analysis**

- 辞書攻撃のように既知の単語やパターンとの照合が中心になる点は、マルウェア解析におけるシグネチャベース検出や既知サンプルとの比較と共通していると感じた。
- zip2johnやunshadowのような変換処理は、生データをそのまま扱うのではなく、解析可能な形式に整える前処理が重要となる。
- ツールの使い方そのものよりも、「変換→解析→確認」という一連の流れを理解することが、実務的な解析において重要だと学んだ。

## メモ **/ Notes**

- John the Ripper (JtR)
    - パスワードハッシュの解析（クラッキング）に使用される代表的なツール
    - 辞書攻撃やブルートフォース攻撃を実行し、元のパスワード候補を特定する
- ハッシュ関数
    - 入力データから固定長のハッシュ値を生成する一方向関数
    - 元のデータへ逆算することは現実的に困難
- ハッシュクラッキング
    - ハッシュを「復号」するのではなく、候補となるパスワードをハッシュ化して照合する手法
    - 一致するハッシュが見つかれば元のパスワードを特定できる
- 辞書攻撃 (Dictionary Attack)
    - ワードリスト内の単語を順番に試してハッシュを照合する攻撃手法
    - シンプルなパスワードに対して非常に効果的
- ブルートフォース攻撃 (Brute Force Attack)
    - 可能な文字列の組み合わせを総当たりで試す攻撃手法
    - 成功率は高いが、文字数が増えるほど時間がかかる
- Jumbo John
    - John the Ripper の拡張版
    - 多数のハッシュ形式や追加機能に対応しており、実務や学習で広く利用される
- ワードリスト
    - パスワード候補をまとめた単語リスト
    - 辞書攻撃の成功率を左右する重要な要素
- rockyou.txt
    - 実際の情報漏洩事故から収集された有名なパスワードリスト
    - セキュリティ学習やパスワード監査で広く利用される
- SecLists
    - ペネトレーションテストやセキュリティ診断向けの辞書・ワードリスト集
    - パスワード、ユーザー名、URLなど多様なリストを提供する
- P vs NP（概念理解）
    - ハッシュ生成は高速に実行できる
    - 一方で、ハッシュ値から元の入力を求めることは極めて困難
    - この性質がパスワード保護の安全性を支えている
- パスワード解析の基本的な流れ
    - ハッシュ形式を特定する
    - 適切なワードリストを準備する
    - John the Ripperで候補をハッシュ化して照合する
    - 一致する候補が見つかればパスワードを特定できる
- Johnの動きは常にこれ：
    1. 入力（ハッシュ）
    2. 解析方法を選択
    3. 候補パスワードを生成
    4. ハッシュ化して比較
    5. 一致したら成功
- 基本構文
    - optionsで「攻撃方法」を変える
    - ファイルは「ハッシュが入ったデータ」

```bash
john [options] [hashファイル]
```

- 一番基本（辞書攻撃）
    - 単語リスト（辞書）を全部試す
    - 一番よく使うパターン

```bash
john --wordlist=/usr/share/wordlists/rockyou.txt hash.txt
```

- 結果の確認（超重要）

```bash
john --show hash.txt
```

- ハッシュ形式を指定する場合
    - 自動判定できないときに使う
    - よく使う形式：
        - raw-md5
        - raw-sha1
        - raw-sha256
        - whirlpool

```bash
john --format=raw-md5 --wordlist=rockyou.txt hash.txt
```

- Single Crack Mode（ユーザー名攻撃）
    - ユーザー名からパスワードを推測
    - 例：Joker → Joker1 / Joker@ / J0ker
    - 重要ルール
        - UserName:hash値

```bash
john --single --format=raw-md5 hash.txt
```

- ZIPファイル解析
    - ハッシュ化
    
    ```bash
    zip2john secure.zip > zip_hash.txt
    ```
    
    - クラック
    
    ```bash
    john --wordlist=rockyou.txt zip_hash.txt
    ```
    
- RARファイル解析

```bash
rar2john secure.rar > rar_hash.txt
john --wordlist=rockyou.txt rar_hash.txt
```

- SSH秘密鍵（id_rsa）

```bash
ssh2john id_rsa > id_rsa_hash.txt
john --wordlist=rockyou.txt id_rsa_hash.txt
```

- /etc/shadow（Linuxパスワード）
    - 結合処理（必須）
    
    ```bash
    unshadow passwd shadow > unshadowed.txt
    ```
    
    - クラック
    
    ```bash
    john --wordlist=rockyou.txt --format=sha512crypt unshadowed.txt
    ```
