//Willam_Tell_Game
//Hongo Aki

/* tree.h */
#pragma once

//木
struct Tree{
	int x; //x座標
	int y; //y座標
};

extern Tree tree; //木情報の実体宣言

extern void Tree_Initialize(); //木の初期化
extern void Draw_Tree(); //木を描画
extern void Delete_Tree(); //木を削除