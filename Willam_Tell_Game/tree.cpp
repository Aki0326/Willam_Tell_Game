//Willam_Tell_Game
//Hongo Aki

/* tree.cpp */
#include "tree.h"
#include <DxLib.h>

int TreeImageHandle; //tree.png画像を保存するための変数
Tree tree; //木情報の実体宣言

//木の初期化
void Tree_Initialize(){
	//tree.png画像のメモリへの読み込み
	TreeImageHandle = LoadGraph("images\\tree.png"); //木
	tree.x = -3;
	tree.y = -3;
}

//木を描画
void Draw_Tree(){
	DrawGraph(tree.x, tree.y, TreeImageHandle, TRUE);
}

//木を削除
void Delete_Tree(){
	//読み込んだ画像のグラフィックハンドルを削除
	DeleteGraph(TreeImageHandle);
}