作業日：2026/5/22 Fri

## 概要 **/ Overview**

ハッシュ関数について、およびパスワード認証やファイルの整合性チェックにおけるその活用方法について学ぶ

## 実施内容 **/ Practical Work**

- 仮想環境でハンズオンをしながら、設問に答える。
- `~/Hashing-Basics/Task-2` にある `passport.jpg` ファイルの SHA256 ハッシュ値は何ですか？
    - sha256sum passport.jpg を実行し、ハッシュを確認できた

- `rockyou.txt` の20番目のパスワードは何ですか？
    - head -n 20 rockyou.txt を実行し、20番目のパスワードを確認できた

- ~/Hashing-Basics/Task-6/hash1.txt に保存されているハッシュ$2a$06$7yoU3Ng8dHTXphAg913cyO6Bjs3K5lBnwq5FJyA6d01pMSrddr1ZG を hashcat を使ってクラックしてください。
    - hashcat -m 3200 -a 0 hash1.txt /usr/share/wordlists/rockyou.txt を実行
    - hashcat -m 3200 --show hash1.txt で答えを確認できた
    - --show を使わないと結果が見れなかったので注意

- SHA2-256 ハッシュ 9eb7ee7f551d2f0ac684981bd1f1e2fa4a37590199636753efe614d4db30e8e1 を hashcat を使ってクラックしてください（~/Hashing-Basics/Task-6/hash2.txt に保存されています）。
    - hashcat -m 1400 -a 0 hash2.txt /usr/share/wordlists/rockyou.txt を実行
    - hashcat -m 1400 --show hash2.txt で答えを確認できた

- ~/Hashing-Basics/Task-6/hash3.txt に保存されているハッシュ$6$GQXVvW4EuM$ehD6jWiMsfNorxy5SINsgdlxmAEl3.yif0/c3NqzGLa0P.S7KRDYjycw5bnYkF5ZtB8wQy8KnskuWQS3Yr1wQ0 を hashcat を使ってクラックしてください。
    - hashcat -m 1800 -a 0 hash3.txt /usr/share/wordlists/rockyou.txt
    - hashcat -m 1800 --show hash3.txt で答えを確認できた

- ~/Hashing-Basics/Task-6/hash4.txt に保存されているハッシュb6b0d451bbf6fed658659a9e7e5598fe をクラックしてください。
    - hashcat -m 0 -a 0 hash4.txt /usr/share/wordlists/rockyou.txt を実行
    - Status...........: Exhausted ：rockyouに存在しない（失敗）
    - Decrypt MD5, SHA1, MySQL, NTLM, SHA256, MD5 Email, SHA256 Email, SHA512, Wordpress, Bcrypt hashes for free online で実行
    - クラック成功！

- `~/Hashing-Basics/Task-7` にある `libgcrypt-1.11.0.tar.bz2` の SHA256 ハッシュ値は何ですか？
    - sha256sum libgcrypt-1.11.0.tar.bz2 実行し、ハッシュを確認できた

- HMAC-SHA512（キー = `$pass`）の hashcat モード番号はいくつですか？
    - [example_hashes [hashcat wiki]](https://hashcat.net/wiki/doku.php?id=example_hashes) でHMAC-SHA512を検索して確認できた

- decode-this.txt（~/Hashing-Basics/Task-8に保存）にある RU5jb2RlREVjb2RlCg== を base64 でデコードしたときの元の単語は何ですか？
        - CyberChef のFromBase64で確認し正解！

## 気づき・考察 **/ Key Insights & Analysis**

- ハッシュ値は「ファイルの指紋」のようなもので、マルウェア解析では不審ファイルが既知のマルウェアと同一かを素早く確認できると分かった。フォレンジックでも、取得した証拠ファイルが改ざんされていない確認に使われるのが重要だと感じた。
- Salt付きハッシュは、同じパスワードでも異なるハッシュになるため、攻撃者による一括解析への耐性を高めていることが理解できた。実際の認証システムで非常に重要な考え方だと思った。

## メモ **/ Notes**

### Hash（ハッシュ値）

- 任意のデータから生成される固定長の文字列
- データの要約（Digest）として利用される
- 同じ入力からは必ず同じハッシュ値が生成される

#### 特徴

- 入力サイズに関係なく出力サイズは固定
- 元データを復元できない（一方向関数）
- 入力が少し変わるだけで結果が大きく変化する

---

### Hash Function（ハッシュ関数）

- データからハッシュ値を生成するアルゴリズム
- データの整合性確認やパスワード保護に利用される

#### 主な用途

- ファイル改ざん検知
- パスワード保存
- デジタル署名
- メッセージ認証

---

### Hashing と Encryption の違い

- Hashing（ハッシュ化）
    - 一方向変換
    - 元データへ戻せない
    - パスワード保存に利用
- Encryption（暗号化）
    - 鍵を利用して変換
    - 復号可能
    - 通信データ保護に利用

#### ポイント

- パスワードは「暗号化」ではなく「ハッシュ化」して保存する

---

### Integrity（整合性確認）

- データが改ざんされていないことを確認する仕組み
- ファイル配布時によく利用される

#### 例

- ダウンロードしたISOファイルのSHA256値を比較する
- 一致すれば改ざんされていないと判断できる

---

### Hash Collision（ハッシュ衝突）

- 異なるデータから同じハッシュ値が生成される現象

#### ポイント

- 理論上は必ず発生する
- 優れたハッシュ関数は衝突確率を極めて低くしている

---

### MD5

- 128bitのハッシュアルゴリズム
- 現在は衝突攻撃が可能

#### 注意

- セキュリティ用途では使用しない

---

### SHA1

- 160bitのハッシュアルゴリズム
- MD5同様に安全ではない

#### 注意

- 新規システムでは使用非推奨

---

### SHA256 / SHA512

- SHA-2ファミリーのハッシュアルゴリズム
- 現在も広く利用されている

#### 用途

- ファイル整合性確認
- 電子署名
- 証明書

---

### Password Hashing（パスワードハッシュ化）

- パスワードそのものではなくハッシュ値を保存する仕組み

#### 認証の流れ

1. ユーザーがパスワード入力
2. システムがハッシュ値を計算
3. 保存済みハッシュと比較
4. 一致すれば認証成功

#### メリット

- データベース流出時も平文パスワードが漏れない

---

### Rainbow Table（レインボーテーブル）

- ハッシュ値と平文パスワードの対応表

#### リスク

- ソルトなしのハッシュは高速に解析される可能性がある

---

### Salt（ソルト）

- パスワードに追加するランダムな値

#### 目的

- 同じパスワードでも異なるハッシュ値を生成する

#### 効果

- レインボーテーブル攻撃を無効化できる

#### ポイント

- ユーザーごとに異なる値を使用する
- 秘密にする必要はない

---

### 安全なパスワード保存

- 強力なハッシュアルゴリズムを使用する
- ユーザーごとに一意のソルトを付与する
- 平文保存しない

#### 推奨アルゴリズム

- Argon2
    - 現在の推奨方式
- bcrypt
    - 実務で広く利用
- scrypt
    - GPU攻撃への耐性あり
- PBKDF2
    - 多くのシステムで利用実績あり

---

### なぜパスワードを暗号化しないのか

- 暗号化は復号鍵が必要
- 鍵が漏洩すると全パスワードが復元される

#### ポイント

- 認証に必要なのは「一致確認」
- 元のパスワードを復元する必要はない

---

### /etc/shadow

- Linuxでパスワードハッシュを保存するファイル

#### 特徴

- rootのみ閲覧可能
- ユーザー名・ソルト・ハッシュ値などを保持

#### 保存形式

```
$prefix$options$salt$hash
```

---

### Password Hash Prefix

- 使用されているハッシュアルゴリズムを識別する値

#### よく見る例

| Prefix | Algorithm |
| --- | --- |
| `$y$` | yescrypt |
| `$7$` | scrypt |
| `$2b$` | bcrypt |
| `$6$` | sha512crypt |
| `$1$` | md5crypt |

---

### NTLM

- Windowsで利用されるパスワードハッシュ形式

#### 特徴

- MD4ベース
- WindowsのSAMデータベースに保存される

---

### Password Cracking

- ハッシュ値を復号するのではなく候補を試して比較する手法

#### 主なツール

- Hashcat
- John the Ripper

#### 流れ

1. パスワード候補を用意
2. ハッシュ化
3. 対象ハッシュと比較
4. 一致すればパスワード特定

---

### GPU Password Cracking

- GPUを利用して大量のハッシュ計算を高速実行する手法

#### メリット

- CPUより大幅に高速

#### 対策

- bcrypt
- scrypt
- Argon2

これらはGPUによる高速解析を困難にする設計

---

### HMAC

- ハッシュ関数と秘密鍵を組み合わせた認証方式

#### 保証できること

- Authenticity（真正性）
    - 正しい送信者が作成したこと
- Integrity（完全性）
    - データが改ざんされていないこと

#### 利用例

- API認証
- Webhook署名
- JWT署名

---

### Encoding（エンコーディング）

- データを別の表現形式へ変換する処理

#### 代表例

- ASCII
- UTF-8
- UTF-16
- Base32
- Base64

---

### Base64

- バイナリデータを文字列で表現するエンコーディング方式

#### 例

```
TryHackMe
↓
VHJ5SGFja01lCg==
```

#### 重要

- Base64は暗号化ではない
- 誰でも元に戻せる
