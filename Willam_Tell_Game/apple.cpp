//Willam_Tell_Game
//Hongo Aki

/* apple.cpp */
#include <DxLib.h>
#include "color.h"
#include "common.h"
#include "apple.h"

//
//ここで変数を用意
//

Apple apple[APPLE_NUMBER];//りんご情報の実体宣言

						  //りんごの初期化
void Apple_Initialize(){
	for(int i=0; i < APPLE_NUMBER; i++){
		apple[i].x = apple_x(mt);
		apple[i].y = 0.0;
		apple[i].vy = apple_vy(mt);
	}
}

//りんごを描画
void Draw_Apple(){
	unsigned int apple_color = GetColor(235, 25, 40);
	unsigned int apple_leaf_color = GetColor(140, 115, 60);
	for(int i=0; i < APPLE_NUMBER; i++){
		DrawCircle(apple[i].x, (int)apple[i].y, APPLE_RADIUS, apple_color, TRUE);
		DrawCircle(apple[i].x, (int)apple[i].y, APPLE_RADIUS, Black, FALSE);
		DrawBezier(apple[i].x-10, (int)apple[i].y-15, apple[i].x-5, (int)apple[i].y-11, apple[i].x+5, (int)apple[i].y-11, apple[i].x+10, (int)apple[i].y-15, Black);
		DrawTriangle(apple[i].x, (int)apple[i].y - 15, apple[i].x - 5, (int)apple[i].y - 30, apple[i].x + 5, (int)apple[i].y - 30, apple_leaf_color, TRUE);
		DrawTriangle(apple[i].x, (int)apple[i].y - 15, apple[i].x - 5, (int)apple[i].y - 30, apple[i].x + 5, (int)apple[i].y - 30, Black, FALSE);
	}
}

//りんごのアニメーション
void Apple_Animation(){
	for(int i = 0; i < APPLE_NUMBER; i++){
		// りんごが描画ウィンドウ外に出たらりんごを初期位置に
		if(apple[i].y > SCREEN_HEIGHT){
			apple[i].x = apple_x(mt);
			apple[i].y = 0.0;
			apple[i].vy = apple_vy(mt);
		} else{
			apple[i].y += apple[i].vy;
		}
	}
}