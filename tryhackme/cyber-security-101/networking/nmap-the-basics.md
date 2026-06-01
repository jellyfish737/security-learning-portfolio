作業日：2026/5/19 Tue

## 概要 **/ Overview**

Nmap を使用して、稼働中のホストの検出、開いているポートの特定、およびサービスのバージョンの確認を行う方法を学ぶ

## 実施内容 **/ Practical Work**

- 仮想環境でnmapのハンズオンをしながら、設問に答える。
- スキャン対象が `192.168.0.1/27` の場合、最後にスキャンされる IP アドレスは何ですか？
    - nmap 192.168.0.1/27 -sL を実行
    - 最後のスキャンIPを確認できた
    - 合計32個のIPアドレスがスキャンされた

- ターゲットシステム `10.49.165.60` では、いくつの TCP ポートが開いていますか？
    - nmap 10.49.165.60 -sT を実行
    - open ポート数が確認できた
    - 7, 9, 8008 などのポートがオープンであった

- `10.49.165.60` 上で待ち受けている Web サーバーを見つけ、ブラウザでアクセスしてください。メインページに表示されるフラグは何ですか？
    - ↑ の結果に「8008」があるのでアクセスしてみる。
    - http://10[.]49.165.60:8008/
    - サイト上でフラグを確認できた

- `10.49.165.60` 上で動作している Web サーバーの名前と検出されたバージョンは何ですか？
    - nmap -sV 10.49.165.60 を実行
    - 8008/tcp の VERSION から、サーバ名とそのバージョンが確認できた


## 気づき・考察 **/ Key Insights & Analysis**

- SYN スキャン（`-sS`）は接続を最後まで確立しないため、ログが残りにくいという特徴があり、攻撃者も「目立たない調査」を意識していることが理解できた。防御側としては、通信量だけでなく SYN パケットの挙動監視も重要だと感じた。
- `-Pn` のように「応答しないホストも強制スキャンできる」機能から、ICMP を遮断していても完全な防御にはならないことが分かった。単に ping を拒否するだけでは隠れきれない。

## メモ **/ Notes**

- Live Host Discovery (`sn`)
    - ネットワーク上で稼働中（オンライン）のホストを発見する
    - ポートスキャンは行わず、まず調査対象を特定する際に利用する
- Target Specification
    - IPアドレス、IPレンジ、サブネット、ホスト名を指定してスキャン対象を柔軟に設定できる
    - 例: `192.168.1.1-10`、`192.168.1.0/24`、`example.com`
- Local Network Scan
    - 同一ネットワーク内ではARPを利用して高速かつ正確にホストを検出できる
    - MACアドレスやベンダー情報からデバイス種別の推測も可能
- Remote Network Scan
    - ルーターを経由するネットワークではICMPやTCP/UDPパケットを利用してホストの生存確認を行う
    - ARPは利用できない
- List Scan (`sL`)
    - 実際にスキャンせず、対象となるホスト一覧のみ表示する
    - スキャン前の対象確認に便利

---

### ポートスキャン

- TCP Connect Scan (`sT`)
    - TCPの3ウェイハンドシェイクを完了してポートの開閉を確認する
    - 権限不要で実行できるが、ログに残りやすい
- TCP SYN Scan (`sS`)
    - SYNパケットのみ送信してポート状態を確認する
    - 接続を確立しないため比較的ステルス性が高い
    - Nmapで最もよく利用されるスキャン手法
- UDP Scan (`sU`)
    - UDPサービスの有無を確認する
    - DNS、NTP、SNMPなどの調査に利用する
- Port Range Specification (`p`)
    - スキャン対象ポートを限定できる
    - 例: `p22`、`p80,443`、`p1-1024`
- Fast Scan (`F`)
    - 一般的な100ポートのみを対象に高速スキャンする

---

### 情報収集

- Service Version Detection (`sV`)
    - 稼働中サービスの種類やバージョンを特定する
    - 脆弱性調査の起点となる重要な情報を取得できる
- OS Detection (`O`)
    - ターゲットOSを推測する
    - Linux、Windowsなどの判別に利用する
- Aggressive Scan (`A`)
    - OS検出、サービス検出、Tracerouteなどをまとめて実行する
    - 詳細な情報収集を行う際に便利

---

### ホスト検出制御

- Skip Host Discovery (`Pn`)
    - ホスト検出をスキップして直接ポートスキャンを実行する
    - ICMPをブロックしているホストの調査に有効
- Host Discovery Methods
    - TCP SYN (`PS`)
    - TCP ACK (`PA`)
    - UDP (`PU`)
    - ホストの生存確認方法を細かく制御できる

---

### スキャン速度の調整

- Timing Templates (`T0` ～ `T5`)
    - スキャン速度と検知リスクを調整する
    - `T0`: 非常に低速
    - `T3`: デフォルト
    - `T5`: 最速
- Parallelism Control
    - `-min-parallelism`
    - `-max-parallelism`
    - 同時実行するプローブ数を制御する
- Rate Limiting
    - `-min-rate`
    - `-max-rate`
    - パケット送信レートを調整する
- Host Timeout (`-host-timeout`)
    - ホストへの最大待機時間を設定する

---

### 出力とデバッグ

- Verbose Mode (`v`)
    - スキャンの進行状況を詳細表示する
    - `vv`、`vvv`でさらに詳細化できる
- Debug Mode (`d`)
    - Nmap内部の動作を確認できる
    - トラブルシューティング時に利用する

---

### レポート保存

- Normal Output (`oN`)
    - 人が読みやすい形式で保存する
- XML Output (`oX`)
    - 他ツールとの連携や自動解析向け
- Grepable Output (`oG`)
    - grepやawkなどで加工しやすい形式
- All Formats (`oA`)
    - Normal / XML / Grepable を同時に出力する

---

### 実務で最初に覚えるべきコマンド

- Live Host Discovery
    
    ```
    nmap-sn192.168.1.0/24
    ```
    
- SYN Scan
    
    ```
    sudo nmap-sS192.168.1.10
    ```
    
- Service Version Detection
    
    ```
    sudo nmap-sS-sV192.168.1.10
    ```
    
- OS Detection
    
    ```
    sudo nmap-sS-O192.168.1.10
    ```
    
- Aggressive Scan
    
    ```
    sudo nmap-A192.168.1.10
    ```
    
- Full Port Scan
    
    ```
    sudo nmap-p-192.168.1.10
    ```
    
- Scan Result Export
