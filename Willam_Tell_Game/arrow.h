//Willam_Tell_Game
//Hongo Aki

/* arrow.h */
#pragma once

//矢
struct Arrow{
	int x; //x座標
	int y; //y座標
	int speed; //スピード

};

extern int Pressed_flag; //左ボタンが押されたかどうか保存する変数（0：押されてない、1：押された）
extern Arrow arrow; //矢情報の実体宣言

extern void Arrow_Initialize(int mouseY); //矢の初期化
extern void Draw_Arrow(); //矢を描画
extern void Arrow_Animation(int mouseY); //矢のアニメーション
