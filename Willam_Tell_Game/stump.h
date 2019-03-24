//Willam_Tell_Game
//Hongo Aki

/* stump.h */
#pragma once

//切り株
struct Stump{
	int x; //x座標
	int y; //y座標
};

extern Stump stump; //切り株情報の実体宣言

extern void Stump_Initialize(); //切り株を初期化
extern void Draw_Stump(); //切り株を描画
extern void Delete_Stump(); //切り株を削除