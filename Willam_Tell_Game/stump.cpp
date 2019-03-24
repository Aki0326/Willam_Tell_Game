#include "stump.h"
#include <DxLib.h>

Stump stump; //切り株情報の実体宣言

int StumpImageHandle;

//切り株の初期化
void Stump_Initialize(){
	//PNG画像のメモリへの読み込み
	StumpImageHandle = LoadGraph("images\\stump.png"); //切り株
	stump.x = 280;
	stump.y = 593;
}

//切り株を描画
void Draw_Stump(){
	DrawGraph(stump.x, stump.y, StumpImageHandle, TRUE);
}

//切り株を削除
void Delete_Stump(){
	//読み込んだ画像のグラフィックハンドルを削除
	DeleteGraph(StumpImageHandle);
}