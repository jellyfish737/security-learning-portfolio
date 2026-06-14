作業日：2026/6/14 Sun

## 概要 **/ Overview**

インシデント対応の準備段階について学ぶ。

## 実施内容 **/ Practical Work**

- 実行したテストに関連する **File Created** ルールの Event ID は何ですか？
    - Event Viewerで以下を開く。
    - Application and Service Logs -> Microsoft -> Windows -> Sysmon -> Operational
    - そこで Task Category が「File Created」となっているものを探し、Event ID欄を確認することで正解

- Software Restriction Policies において、すべてのポリシーに割り当てられているデフォルトのセキュリティレベルは何ですか？
    - **Windows Administrative Tools → Local Security Policy → Security Settings →** Software Restriction Policies → Security Levels を開く
    - Description に「Software access rights are determined by the access rights of the user.」と記載されているもののNameがセキュリティレベル

- Local Policies 配下の Audit Policy フォルダを確認してください。**Audit logon events** ポリシーにはどの設定が割り当てられていますか？
    - **Windows Administrative Tools → Local Security Policy → Security Settings →** Local Policies → Audit Policy → **Audit logon events** を確認
    - プロパティを開いても設定値を確認できるし、Audit Policy内の一覧上でも「Security Setting」から設定を確認できた

## 気づき・考察 **/ Key Insights & Analysis**

- CSIRTには技術担当だけでなく、法務や広報も含まれる点が印象的だった。マルウェア感染は技術的な問題だけでなく、情報漏えいや社会的影響への対応も必要になることが分かった。
- 資産管理（Asset Inventory）ができていないと、どのサーバーや端末が感染したのか判断できない。フォレンジック調査の前提として、組織内のシステム構成を把握しておく重要性を感じた。
- フォレンジック用ツール（FTK Imager、EnCase、The Sleuth Kitなど）を準備しておくことの重要性を学んだ。インシデント発生後に慌ててツールを探すのではなく、事前準備が対応速度と証拠保全の品質を左右すると感じた。

## メモ **/ Notes**

#### Incident Response（インシデント対応）

- Incident Response（IR）
    - サイバー攻撃やセキュリティ侵害を検知・対応し、被害と復旧コストを最小限に抑える活動
- Event（イベント）
    - システムやネットワークで発生した通常の出来事
- Incident（インシデント）
    - 組織へ実害を与える、または与える可能性があるセキュリティ上の問題

#### インシデント対応ライフサイクル

- Preparation（準備）
    - インシデント発生前に体制・手順・ツールを整備する
- Identification（識別）
    - 異常な活動を検知し、インシデントかどうかを判断する
- Analysis / Scoping（分析・影響範囲特定）
    - 影響を受けたシステムやデータを特定する
- Containment（封じ込め）
    - 被害拡大を防ぐために影響範囲を隔離する
- Eradication（根絶）
    - マルウェアや攻撃者の痕跡を除去する
- Recovery（復旧）
    - システムを正常な状態へ戻し、業務を再開する
- Lessons Learned（教訓化）
    - 対応内容を振り返り、再発防止策へ反映する

#### Incident Response Plan（IRP）

- Incident Response Plan（IRP）
    - インシデント発生時の対応手順や役割を定義した計画書
- IRPの主な内容
    - 対応フロー
    - 役割と責任
    - 連絡手段
    - エスカレーション手順
    - 成果測定指標
- Playbook
    - 特定のインシデントに対する具体的な対応手順書

#### 人材面の準備

- CSIRT（Cyber Security Incident Response Team）
    - インシデント対応を担当する専門チーム
- CSIRTに必要な部門
    - 技術部門
    - ビジネス部門
    - 法務部門
    - 広報部門
- セキュリティ教育
    - フィッシングやソーシャルエンジニアリングへの対応力を向上させる
- 継続的な訓練
    - 実際の攻撃を想定した演習により対応能力を維持する

#### ドキュメント管理

- インシデント記録
    - 調査内容や対応履歴を記録し、証拠や再発防止に活用する
- セキュリティポリシー
    - 組織内で守るべきルールや対応方針を定義する
- コミュニケーション計画
    - インシデント発生時の報告先や連絡手順を明確化する
- Chain of Custody
    - 証拠の取得・保管・移送履歴を記録し、証拠能力を維持する

#### 資産管理（Asset Inventory）

- Asset Inventory
    - 組織内の重要資産を一覧化して管理する
- 高価値資産の例
    - サーバー
    - 顧客データ
    - 従業員データ
    - 知的財産
    - ブランド価値
- 資産分類の目的
    - 保護すべき対象を明確化し、防御の優先順位を決める

#### CIAトライアド

- Confidentiality（機密性）
    - 許可されたユーザーのみが情報へアクセスできる状態
- Integrity（完全性）
    - データが改ざんされていない状態
- Availability（可用性）
    - 必要なときにシステムやデータを利用できる状態

#### 技術的な監視基盤

- Telemetry（テレメトリ）
    - システムやネットワークから収集する監視データ
- EDR（Endpoint Detection and Response）
    - エンドポイントの脅威検知・調査・対応を支援する
- DLP（Data Loss Prevention）
    - 機密情報の持ち出しや漏えいを防止する
- IDPS（Intrusion Detection and Prevention System）
    - 不正アクセスや攻撃を検知・防御する
- ログ収集基盤
    - インシデント発生時の調査に必要な証跡を蓄積する

#### ネットワーク防御

- サブネット化（Subnetting）
    - ネットワークを論理的に分割し、アクセス制御を強化する
- Firewall
    - 通信を制御し、不正アクセスを防ぐ
- DMZ（Demilitarized Zone）
    - 外部公開サーバーを内部ネットワークから分離する領域
- IP Segmentation
    - システムごとにアクセス範囲を制限する仕組み

#### 調査・フォレンジック準備

- ディスクイメージ取得ツール
    - 証拠保全のためストレージ内容を複製する
- メモリイメージ取得ツール
    - 実行中プロセスや揮発性データを取得する
- サンドボックス
    - マルウェアを安全に実行・分析する環境
- 安全な証拠保管領域
    - 取得した証拠を改ざんから保護する
- Incident-Handling Jump Bag
    - インシデント対応に必要なツールをまとめた持ち出しキット

#### 可視性（Visibility）

- Visibility
    - 組織内で発生している活動を把握できる状態
- 可視性の目的
    - 不正活動の早期発見
    - インシデント調査の効率化
    - 証拠収集の容易化
- 脅威インテリジェンス
    - 最新の攻撃手法や脅威情報を収集する活動
- パッチ管理
    - 脆弱性を修正し攻撃リスクを低減する

#### ログ管理

- SIEM（Security Information and Event Management）
    - ログの集約・分析・相関分析を行う基盤
- Event Log
    - システムやネットワークで発生したイベントを記録する
- Audit Log
    - ユーザー操作やシステム応答を記録する
- Error Log
    - システム障害やエラーを記録する
- Debug Log
    - 問題解析やトラブルシューティング用のログ

#### 主なログ収集元

- Network Logs
    - ルーターやスイッチなどの通信ログ
- Firewall Logs
    - 許可・拒否された通信履歴
- VPN Logs
    - リモートアクセス履歴
- System Logs
    - OSやサービスの動作履歴
- Application Logs
    - アプリケーション固有の操作・エラー履歴

#### ログ活用のポイント

- Detect（検知）
    - 異常な活動を発見する
- Identify（識別）
    - 発生した事象の内容を特定する
- Assess（評価）
    - 影響度や優先度を判断する
- Alert（通知）
    - 関係者へ迅速に共有する
- Mitigate（緩和）
    - 被害拡大を防ぐ対応を行う
