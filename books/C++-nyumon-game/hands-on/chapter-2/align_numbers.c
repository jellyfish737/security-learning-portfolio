/*
printf()で桁数を指定し数値を出力する
- n桁の整数で出力：%nd
- 0で埋める：%0nd
- 小数点以下n桁まで出力：%.nf
*/

#include <stdio.h> // <stdio.h>をインクルード

int main(void) // main関数の定義
{
	int score = 1230;
	double pi = 3.141592;
	printf("----- 整数の出力 -----\n");
	printf("そのままの出力 :%d\n", score);
	printf("7桁で出力 :%7d\n", score);
	printf("0で埋めて7桁で出力 :%07d\n", score);
	printf("----- 小数の出力 -----\n");
	printf("そのままの出力 :%f\n", pi);
	printf("小数点以下2桁まで出力 :%.2f\n", pi);
	printf("小数点以下4桁まで出力 :%.4f\n", pi);
}
