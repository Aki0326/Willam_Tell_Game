//Willam_Tell_Game
//Hongo Aki

/* flower.cpp */
#include "flower.h"
#include <DxLib.h>

int FlowerImageHandle; //flower.png画像を保存するための変数
double ratio = 0.9; //縮小率
Flower flower[FLOWER_NUMBER]; //花情報の実体宣言

//花の初期化
void Flower_Initialize(){
	//flower.png画像のメモリへの読み込み
	FlowerImageHandle = LoadGraph("images\\flower.png"); //花
	for(int i = 0; i < FLOWER_NUMBER / 2; i++){
		flower[i].x = (int)(495 + (300 * i));
		flower[i].y = (int)(636);
	}
	for(int i = FLOWER_NUMBER/2; i < FLOWER_NUMBER; i++){
		flower[i].x = 645 + (300 * (i - (FLOWER_NUMBER /2)));
		flower[i].y =665;
	}
}

//花を描画
void Draw_Flower(){
	for(int i = 0; i < FLOWER_NUMBER; i++){
		DrawGraph(flower[i].x, flower[i].y, FlowerImageHandle, TRUE);
	}
}

//花を削除
void Delete_Flower(){
	//読み込んだ画像のグラフィックハンドルを削除
	DeleteGraph(FlowerImageHandle);
}