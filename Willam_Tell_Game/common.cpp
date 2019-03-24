//Willam_Tell_Game
//Hongo Aki

/* common.cpp */
#include "common.h"
#include <DxLib.h>

using namespace std;

//ランダム変数
mt19937 mt{random_device{}()};
uniform_int_distribution<int> apple_x(275, 975);
uniform_real_distribution<> apple_vy(1.0, 6.0);

//ベジエ曲線を描画
void DrawBezier(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4, unsigned int color){
	const int DivNum = 350;
	double P12[2], P23[2], P34[2];
	double P13[2], P24[2];
	double P14[2];
	double u;
	int x, y;
	int pre_x = 0, pre_y = 0;
	int counter = 0; //カウンターを初期化

	//現在の点の位置を算出
	//ベジエ曲線の計算
	while(counter != DivNum){ //カウンターが分割数に達していない間ループ
		u = (1.0 / DivNum) * counter;

		P12[0] = (1.0 - u) * x1 + u * x2; P12[1] = (1.0 - u) * y1 + u * y2;
		P23[0] = (1.0 - u) * x2 + u * x3; P23[1] = (1.0 - u) * y2 + u * y3;
		P34[0] = (1.0 - u) * x3 + u * x4; P34[1] = (1.0 - u) * y3 + u * y4;

		P13[0] = (1.0 - u) * P12[0] + u * P23[0]; P13[1] = (1.0 - u) * P12[1] + u * P23[1];
		P24[0] = (1.0 - u) * P23[0] + u * P34[0]; P24[1] = (1.0 - u) * P23[1] + u * P34[1];

		P14[0] = (1.0 - u) * P13[0] + u * P24[0]; P14[1] = (1.0 - u) * P13[1] + u * P24[1];

		x = (int)P14[0];
		y = (int)P14[1];

		if(pre_x != 0.0 && pre_y != 0.0){
			DrawLine(pre_x, pre_y, x, y, color);
		}

		pre_x = x;
		pre_y = y;

		//カウンターをインクリメント
		counter++;
	}
}

//平行四辺形を描画
void DrawQuad(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4, unsigned int color, unsigned int out_color){
	DrawTriangle(x1, y1, x2, y2, x2, y1, color, TRUE);
	DrawTriangle(x3, y3, x4, y4, x4, y3, color, TRUE);
	DrawBox(x2, y2, x4, y4, color, TRUE);
	DrawLine(x1, y1, x2, y2, out_color);
	DrawLine(x2, y2, x3, y3, out_color);
	DrawLine(x3, y3, x4, y4, out_color);
	DrawLine(x4, y4, x1, y1, out_color);
}
