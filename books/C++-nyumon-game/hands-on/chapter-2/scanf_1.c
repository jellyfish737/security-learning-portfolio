/*
scanf()は使い方を誤ると処理に悪影響を及ぼす可能性がある
Microsoftは、scanf_s()という安全な関数の使用を推奨している
*/

#define _CRT_SECURE_NO_WARNINGS // Visual Studio でscanf()を使うための記述
#include <stdio.h> // <stdio.h>をインクルード

int main(void) // main関数の定義
{
	int life; // 整数を代入する変数lifeを宣言
	printf("主人公の体力の値は？ \n"); // printf()で文字列を出力、\nは改行コード
	scanf("%d", &life); // scanf()で入力した値をlifeに代入
	printf("主人公の体力は %d です", life); // 文字列とlifeの値を出力

}
