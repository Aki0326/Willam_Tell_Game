//Willam_Tell_Game
//Hongo Aki

/* apple.h */
#pragma once

#define APPLE_NUMBER 3 //りんごの数
#define APPLE_RADIUS 25 //りんごの半径

//りんご
struct Apple{
	int x; //x座標
	double y; //y座標
	double vy; //y座標のスピード
};

extern Apple apple[APPLE_NUMBER]; //りんご情報の実体宣言

extern void Apple_Initialize(); //りんごの初期化
extern void Draw_Apple(); //りんごを描画
extern void Apple_Animation(); //りんごのアニメーション
