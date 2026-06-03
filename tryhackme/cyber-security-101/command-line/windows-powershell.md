作業日：2026/5/11 Mon

## 概要 **/ Overview**

PowerShellの「パワー」を発見し、その基礎を学ぶ

## 実施内容 **/ Practical Work**

- 仮想環境のWindowsにおいて、cmdコマンドを実行しながら設問に答える
- 自分のユーザーとデフォルトの「Administrator」以外で、有効になっているユーザーは誰ですか？
    - Get-LocalUser を実施
    - Enabled が True となっているユーザを確認
    - 「Administrator」以外で有効になっているユーザが確認できた

- この人物は他のユーザーの中に隠れており、アカウントの説明欄に非常に率直なモットーを書いています。そのモットーは何ですか？
    - 上記コマンド結果のDescription から確認できた

- 今回の小さなチャレンジ：この怪しいユーザーのホームフォルダは「C:\Users」内に存在します。ファイルシステムを移動して、その海賊の隠された宝を見つけてください。
    - 以下のコマンドを実行し、宝の内容を確認できた！

```powershell
PS C:\Users\captain> Set-Location -path c:\Users
PS C:\Users> Get-ChildItem
PS C:\Users> Set-Location -path \p1r4t
PS C:\Users\p1r4t3> Set-Location -path ".\hidden-treasure-chest\"
PS C:\Users\p1r4t3\hidden-treasure-chest> Get-ChildItem
PS C:\Users\p1r4t3\hidden-treasure-chest> Get-Content -Path .\big-treasure.txt
```

- 前のタスクで見つけた「宝物」を含むファイルのハッシュ値は何ですか？
    - Get-FileHash コマンドからハッシュ値を確認できた


## 気づき・考察 **/ Key Insights & Analysis**

- PowerShellはオブジェクトベースなので、`Get-Process` や `Get-NetTCPConnection` から「実行中プロセスや通信状況」を直接構造化データとして取得でき、異常挙動の検知に向いている
- `Get-FileHash` によりファイルの改ざん検知（既知ハッシュとの比較）ができ、マルウェアの同一性確認やIOC検出に使える

## メモ **/ Notes**

#### PowerShellの概要

- PowerShell
    - Microsoftが提供するコマンドラインシェル兼スクリプト言語
    - WindowsだけでなくLinuxやmacOSでも利用できる
- オブジェクト指向
    - PowerShellでは文字列ではなく「オブジェクト」を扱う
    - プロパティやメソッドを保持したままデータ処理できるため、高度な操作や自動化が可能
- Cmdlet（コマンドレット）
    - PowerShellで使用するコマンド
    - 「Verb-Noun（動詞-名詞）」形式で命名される
    
    例：
    
    - `Get-Content`
        - ファイル内容を取得する
    - `Set-Location`
        - 作業ディレクトリを変更する

---

#### PowerShellの学習で最初に覚えるコマンド

- `Get-Command`
    - 利用可能なコマンドを一覧表示する
    - PowerShellで「何が使えるか」を調べる際の基本コマンド
- `Get-Help`
    - コマンドの使い方やオプションを確認する
    - 新しいCmdletを学ぶ際に必須
- `Get-Alias`
    - エイリアス（別名コマンド）を確認する
    - `dir` → `Get-ChildItem`
    - `cd` → `Set-Location`

---

#### ファイル・ディレクトリ操作

- `Get-ChildItem`
    - ファイルやディレクトリを一覧表示する
    - Windowsの `dir`、Linuxの `ls` に相当
- `Set-Location`
    - 作業ディレクトリを変更する
    - Windowsの `cd` に相当
- `New-Item`
    - ファイルやディレクトリを作成する
- `Remove-Item`
    - ファイルやディレクトリを削除する
- `Copy-Item`
    - ファイルやディレクトリをコピーする
- `Move-Item`
    - ファイルやディレクトリを移動する
- `Get-Content`
    - ファイル内容を表示する
    - Linuxの `cat`、Windowsの `type` に相当

---

#### パイプライン（Pipeline）

- パイプ（`|`）
    - あるコマンドの出力を次のコマンドへ渡す仕組み
    - PowerShellの最も重要な機能の一つ

```
Get-ChildItem | Sort-Object Length
```

- `Sort-Object`
    - 指定したプロパティで並び替える
- `Where-Object`
    - 条件に一致するデータのみ抽出する

```
Get-ChildItem | Where-Object Extension -eq ".txt"
```

- `Select-Object`
    - 必要なプロパティのみ表示する

```
Get-ChildItem | Select-Object Name, Length
```

---

#### 比較演算子

- `eq`
    - 等しい
- `ne`
    - 等しくない
- `gt`
    - より大きい
- `ge`
    - 以上
- `lt`
    - より小さい
- `le`
    - 以下
- `like`
    - ワイルドカードを利用した部分一致検索

---

#### 文字列検索

- `Select-String`
    - ファイル内から特定の文字列を検索する
    - Linuxの `grep` に相当

```
Select-String -Path ".\sample.txt" -Pattern "password"
```

---

#### システム情報の収集

- `Get-ComputerInfo`
    - OS・BIOS・ハードウェア情報を取得する
    - システム全体の情報収集に利用する
- `Get-LocalUser`
    - ローカルユーザー一覧を取得する
    - アカウント調査や権限確認に利用する

---

#### ネットワーク調査

- `Get-NetIPConfiguration`
    - ネットワーク設定を確認する
    - IPアドレスやDNS設定を把握できる
- `Get-NetIPAddress`
    - システムに設定されたIPアドレスを一覧表示する
- `Get-NetTCPConnection`
    - 現在のTCP通信を確認する
    - 不審な通信やバックドア調査に活用できる

---

#### プロセス・サービス管理

- `Get-Process`
    - 実行中のプロセスを確認する
    - CPU使用率やメモリ使用量も確認可能
- `Get-Service`
    - サービスの状態を確認する
    - 実行中・停止中サービスの調査に利用する

---

#### フォレンジック・インシデント対応で重要なコマンド

- `Get-FileHash`
    - ファイルのハッシュ値を計算する
    - 改ざん検知や整合性確認に利用する
- Alternate Data Streams（ADS）
    - ファイルに隠されたデータストリームを確認する
    - マルウェアや不正ファイル調査で重要

```
Get-Item -Path "sample.txt" -Stream *
```

---

#### リモート管理

- `Invoke-Command`
    - リモートシステム上でコマンドやスクリプトを実行する
    - 複数端末の管理や自動化に利用される

```
Invoke-Command -ComputerName Server01 -ScriptBlock { Get-Process }
```

- ScriptBlock
    - リモート端末で実行するコマンド群を定義する仕組み

---

#### PowerShellスクリプト

- PowerShell Script（.ps1）
    - 複数のコマンドをまとめて自動実行するファイル
- スクリプト自動化
    - ログ分析
    - システム監視
    - ユーザー管理
    - ネットワーク調査
    - インシデント対応
- PowerShellスクリプトの重要性
    - ブルーチーム：ログ分析や脅威ハンティングを自動化できる
    - レッドチーム：情報収集や環境調査を効率化できる
    - システム管理者：運用作業や設定管理を自動化できる
