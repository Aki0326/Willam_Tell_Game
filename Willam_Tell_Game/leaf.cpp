//Willam_Tell_Game
//Hongo Aki

/* leaf.cpp */
#include "leaf.h"
#include <DxLib.h>

int GreenLeaf_ImageHandle; //greenleaf.png画像を保存するための変数
int YellowgreenLeaf_ImageHandle; //yellowgreenleaf.png画像を保存するための変数
Leaf greenleaf[LEAF_NUMBER]; //緑色の葉の実体宣言
Leaf yellowgreenleaf[LEAF_NUMBER]; //黄緑色の葉の実体宣言

//葉の初期化
void Leaf_Initialize(){
	//緑色の葉
	GreenLeaf_ImageHandle = LoadGraph("images\\greenleaf.png"); //緑色の葉
	for(int i = 0; i < LEAF_NUMBER/2; i++){ //上段
		greenleaf[i].x = 200+ (200 * i);
		greenleaf[i].y = 0;
	}

	for(int i = LEAF_NUMBER/2; i < LEAF_NUMBER; i++){ //下段
		greenleaf[i].x = 300 + (200 * (i - (LEAF_NUMBER / 2)));
		greenleaf[i].y = 50;
	}

	//黄緑色の葉
	YellowgreenLeaf_ImageHandle = LoadGraph("images\\yellowgreenleaf.png"); //黄緑色の葉
	for(int i = 0; i < LEAF_NUMBER; i++){
		yellowgreenleaf[i].x = 250 + (100 * i);
		yellowgreenleaf[i].y = 25;
	}

}

//葉を描画
void Draw_Leaf(){
	for(int i = 0; i < LEAF_NUMBER; i++){
		//緑色の葉
		DrawGraph(greenleaf[i].x, greenleaf[i].y, GreenLeaf_ImageHandle, TRUE);
		//黄緑色の葉
		DrawGraph(yellowgreenleaf[i].x, yellowgreenleaf[i].y, YellowgreenLeaf_ImageHandle, TRUE);
	}
}

//葉を削除
void Delete_Leaf(){
	//読み込んだ画像のグラフィックハンドルを削除
	DeleteGraph(GreenLeaf_ImageHandle); //緑色の葉
	DeleteGraph(YellowgreenLeaf_ImageHandle); //黄緑色の葉
}