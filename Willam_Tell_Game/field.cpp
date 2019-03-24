//Willam_Tell_Game
//Hongo Aki

/* field.cpp */
#include "field.h"
#include <DxLib.h>

int FieldImageHandle; //field.png画像を保存するための変数
Field field; //野原情報の実体宣言

//野原の初期化
void Field_Initialize(){
	//field.png画像のメモリへの読み込み
	FieldImageHandle = LoadGraph("images\\field.png"); //野原
	field.x = 0;
	field.y = 620;
}

//野原を描画
void Draw_Field(){
	DrawGraph(field.x, field.y, FieldImageHandle, TRUE);

}

//野原を削除
void Delete_Field(){
	//読み込んだ画像のグラフィックハンドルを削除
	DeleteGraph(FieldImageHandle);
}