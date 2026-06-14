#include <stdio.h> // <stdio.h>をインクルード

int main(void) // main関数の定義
{
	float f; // float型の変数を宣言
	int s = sizeof f; // 変数fのsizeofをsに代入
	printf("float型の変数サイズ %d バイト \n", s); // sの値を出力
	printf("double型の変数サイズ %d バイト \n", sizeof(double)); // sizeof(double)を出力
}
	
