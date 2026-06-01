作業日：2026/5/17 Sun

## 概要 **/ Overview**

Wiresharkの基本と、プロトコルやPCAPの分析方法を学ぶ

## 実施内容 **/ Practical Work**

- 仮想環境でWiresharkのハンズオンを行いながら、設問に答える。

- キャプチャファイルの SHA256 ハッシュ値は何ですか？
    - Hash (SHA256) で確認できた

- TTL 値はいくつですか？
    - パケット詳細の Time to Live の数字を確認し正解！

- TCP ペイロードサイズはいくつですか？
    - パケット詳細の [TCP Segment Len:] の数字を確認し正解！

- e-tag 値は何ですか？
    - Hypertext Transfer Protocol内の ETag: の値を確認し正解！

- "r4w" をパケット詳細で検索してください。Artist 1 の名前は何ですか？
    - h3 タグ内にArtist 1の名前を確認できた

- パケット12を開き、パケットコメントを読んでください。答えは何ですか？（※ md5sum <filename> コマンドで MD5 ハッシュを取得してください）
    - パケット12のコメント見るとこんなメッセージがあった。
    
    ```
    Go to packet number 39765
    Look at the "packet details pane". 
    Right-click on the JPEG section and "Export packet bytes". 
    This is an alternative way of extracting data from a capture file. 
    What is the MD5 hash value of extracted image?
    ```
    
    - Go packet 39765 を実行
    - JPEG File Interchange Format を右クリックし、Export packet bytes
    - Desktopに保存したら、ターミナルでmd5sum <filename> コマンドを実行
    - ハッシュを確認できた

- キャプチャ内の「.txt」ファイルを見つけて内容を読み取ってください。エイリアンの名前は何ですか？
    - Find packet で「.txt」を検索。3つ目の検索結果でnote.txtがヒット。
    - パケット詳細でエイリアンの名前を確認できた

- Expert Info を確認してください。Warning の数はいくつですか？
    - 左下のアイコンをクリックして、Expert Infoを開き、Warningの数を確認できた

- パケット番号4へ移動し、「Hypertext Transfer Protocol」を右クリックしてフィルタ適用する。フィルタクエリは何ですか？
    - 「Hypertext Transfer Protocol」で右クリック → **Apply as Filter**
    - 右上にフィルタークエリが表示されていることを確認した

- 表示されているパケット数はいくつですか？
    - 上記のフィルターをかけたまま、Displayedの数字を確認し正解！

- パケット33790へ移動し、HTTPストリームをフォローしてください。Webサーバー応答から、アーティストの総数はいくつですか？
    - Follow → HTTP Stream 実施
    - リクエストを中身を確認し、artist= の箇所を数え正解！

- 2番目のアーティスト名は何ですか？
    - artist=2 の名前を確認できた


## 気づき・考察 **/ Key Insights & Analysis**

- ネットワーク通信は「見えない行動ログ」なので、マルウェアは必ず何らかの通信痕跡（C2通信・データ送信・外部接続）を残す前提で見る。
- Follow Streamは「通信のストーリー再構築」であり、ログ単体では分からない認証情報やコマンド送信の流れが一気に見えることがある。
- 色分けやExpert Infoは「人間が見逃しやすい異常のサイン」であり、未知の通信パターン発見の初動トリアージに役立つ。

## メモ **/ Notes**

- Wireshark
    - ネットワーク通信（パケット）を可視化し、トラブルシューティングやセキュリティ調査を行うためのパケット解析ツール
    - パケットを変更せず「読むだけ」のため、解析者の知識が重要
- パケットキャプチャ
    - ネットワーク上を流れる通信データを収集する機能
    - 青ボタンで開始、赤ボタンで停止できる
- Packet List Pane
    - キャプチャしたパケットを一覧表示する
    - 通信の全体像を素早く把握できる
- Packet Details Pane
    - 選択したパケットの詳細情報を階層構造で確認できる
    - 各OSIレイヤーの情報を分析する際に使用する
- Packet Bytes Pane
    - パケットの生データを16進数とASCII形式で表示する
    - ペイロードやバイナリデータの確認に役立つ
- Coloring Rules
    - プロトコルや条件ごとに色分けして視認性を向上させる
    - 異常通信や特定プロトコルを素早く識別できる
- Packet Dissection
    - パケットを各プロトコル層ごとに解析して内容を表示する
    - Ethernet、IP、TCP、HTTPなどの構造を理解できる
- Packet Search
    - 特定の文字列やパターンをパケット内から検索する
    - 不審な通信や特定イベントの調査に利用する
- Packet Marking
    - 注目したパケットに一時的な目印を付ける
    - 調査中の重要パケットを見失わないようにする
- Packet Comment
    - パケットへメモや調査内容を保存する
    - 他のアナリストとの情報共有に役立つ
- Packet Export
    - 必要なパケットのみを抽出して別ファイルとして保存する
    - 不要な通信を除外して共有できる
- File Extraction
    - HTTPやSMBなどの通信から転送されたファイルを抽出する
    - マルウェア解析やフォレンジック調査で活用される
- Expert Information
    - Wiresharkが検出した異常や警告を一覧表示する
    - 通信障害や不正通信の発見を支援する
- Capture Filter
    - パケット取得時に収集対象を制限する
    - 不要な通信を最初から記録しない
- Display Filter
    - 取得済みパケットの表示対象を絞り込む
    - 大量の通信から必要な情報を効率よく探せる
- Apply as Filter
    - 選択したフィールドを条件として即座にフィルタを適用する
    - 関連する通信だけを表示できる
- Conversation Filter
    - 特定ホスト間の通信全体を表示する
    - 通信フローの分析に便利
- Colourise Conversation
    - 関連する通信を色付けして視認しやすくする
    - 通信の流れを追跡しやすくなる
- Prepare as Filter
    - フィルタ条件を作成するが即時適用はしない
    - 複雑な条件を組み立てる際に便利
- Apply as Column
    - 特定フィールドを一覧画面の列として追加する
    - 全パケットを比較しやすくなる
- Follow Stream
    - 分割されたパケットを再構成して通信全体を表示する
    - HTTP通信や認証情報の流れを確認できる
- Protocol Filter
    - 特定プロトコルのみ表示する
    - 例: http、ftp、smtp、arp
- Port Filter
    - 特定ポート番号の通信のみ表示する
    - 例: tcp.port == 80
- IP Filter
    - 特定IPアドレスに関連する通信のみ表示する
    - 特定ホストの通信調査に利用する
- OSI Layer Analysis
    - 通信をレイヤーごとに分解して確認する
    - 問題が発生している層を特定しやすくなる
- Merge Capture Files
    - 複数のpcapファイルを1つに統合する
    - 分散した通信ログをまとめて分析できる
- Time Display Format
    - パケットの時刻表示形式を変更する
    - 時系列分析やイベント相関に役立つ
