//Willam_Tell_Game
//Hongo Aki

/* arch.h */
#pragma once

//弓
struct Arch{
	int x; //x座標
	int y; //y座標
};

extern Arch arch; //弓情報の実体宣言

extern void Arch_Initialize(int mouseY); //弓の初期化
extern void Draw_Arch(); //弓を描画
extern void Arch_Animation(int mouseY); //弓のアニメーション
extern void Delete_Arch(); //弓	を削除