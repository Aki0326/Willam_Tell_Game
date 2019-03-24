//Willam_Tell_Game
//Hongo Aki

/* leaf.h */
#pragma once

#define LEAF_NUMBER 8 //葉の個数

//葉
struct Leaf{
	int x; //x座標
	int y; //y座標
};

extern Leaf greenleaf[LEAF_NUMBER]; //緑色の葉
extern Leaf yellowgreenleaf[LEAF_NUMBER]; //黄緑色の葉

extern void Leaf_Initialize(); //葉の初期化
extern void Draw_Leaf(); //葉を描画
extern void Delete_Leaf(); //葉を削除

