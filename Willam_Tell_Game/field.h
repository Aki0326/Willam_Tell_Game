//Willam_Tell_Game
//Hongo Aki

/* field.h */
#pragma once

//野原
struct Field{
	int x; //x座標
	int y; //y座標
};

extern Field field; //野原情報の実体宣言

extern void Field_Initialize(); //野原の初期化
extern void Draw_Field(); //野原を描画
extern void Delete_Field(); //野原を削除