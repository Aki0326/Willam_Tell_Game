//Willam_Tell_Game
//Hongo Aki

/* arrow.cpp */
#include "arrow.h"
#include "color.h"
#include "common.h"
#include "sound.h"
#include <DxLib.h>

int Pressed_flag = 0; //左ボタンが押されたかどうか保存する変数（0：押されてない、1：押された）
Arrow arrow; //矢情報の実体宣言

//矢の初期化
void Arrow_Initialize(int mouseY){
	arrow.x = 1115;
	arrow.y = mouseY;
	arrow.speed = -10;
}

//矢を描画
void Draw_Arrow(){
	DrawTriangle(arrow.x-25, arrow.y, arrow.x, arrow.y-10, arrow.x, arrow.y + 10, GetColor(240, 230, 230), TRUE);
	DrawTriangle(arrow.x-25, arrow.y, arrow.x, arrow.y-10, arrow.x, arrow.y + 10, Black, FALSE);
	DrawQuad(arrow.x+50, arrow.y, arrow.x+60, arrow.y-15, arrow.x+95, arrow.y-15, arrow.x+85, arrow.y, White, Black);
	DrawQuad(arrow.x+50, arrow.y, arrow.x+60, arrow.y+15, arrow.x+95, arrow.y+15, arrow.x+85, arrow.y, White, Black);
	DrawQuad(arrow.x+60, arrow.y, arrow.x+70, arrow.y-15, arrow.x+85, arrow.y-15, arrow.x+75, arrow.y, Red, Black);
	DrawQuad(arrow.x+60, arrow.y, arrow.x+70, arrow.y+15, arrow.x+85, arrow.y+15, arrow.x+75, arrow.y, Red, Black);
	DrawBox(arrow.x, arrow.y+2, arrow.x + 85, arrow.y-2, GetColor(245, 130, 85), TRUE);
	DrawBox(arrow.x, arrow.y+2, arrow.x + 85, arrow.y-2, Black, FALSE);
}

//矢のアニメーション
void Arrow_Animation(int mouseY){
	int ClickX, ClickY, Button, LogType;
	GetMouseInputLog2(&Button, &ClickX, &ClickY, &LogType, TRUE);

	//左ボタンが押されたとき
	if((Button & MOUSE_INPUT_LEFT) != 0 && (GetMouseInput() & MOUSE_INPUT_LEFT) != 0 && (LogType & MOUSE_INPUT_LOG_UP) == 0){
		Arrow_Initialize(mouseY);
		Play_ShootSound();
		Pressed_flag = 1;
		arrow.y = mouseY;
	}

	if(Pressed_flag == 0){
		Arrow_Initialize(mouseY);
	}else{
		arrow.x += arrow.speed;  //加速
		if(arrow.x < 0){
			Pressed_flag = 0;
		}
	}
}
