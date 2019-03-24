//Willam_Tell_Game
//Hongo Aki

/* arch.cpp */
#include "arch.h"
#include <DxLib.h>

int ArchImageHandle; //arch.png画像を保存するための変数
Arch arch; //弓情報の実体宣言

//弓の初期化
void Arch_Initialize(int mouseY){
	//arch.png画像のメモリへの読み込み
	ArchImageHandle = LoadGraph("images\\arch.png"); //弓
	arch.x = 1125;
	arch.y = mouseY-50;
}

//弓を描画
void Draw_Arch(){
	DrawGraph(arch.x, arch.y, ArchImageHandle, TRUE);
}

//弓のアニメーション
void Arch_Animation(int mouseY){
	arch.y = mouseY-50;
}

//弓を削除
void Delete_Arch(){
	//読み込んだ画像のグラフィックハンドルを削除
	DeleteGraph(ArchImageHandle);
}
