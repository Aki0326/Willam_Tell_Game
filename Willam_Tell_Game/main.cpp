//Willam_Tell_Game
//Hongo Aki

/* main.cpp */
#include "color.h"
#include "common.h"
#include "field.h"
#include "tree.h"
#include "stump.h"
#include "flower.h"
#include "leaf.h"
#include "sound.h"
#include "apple.h"
#include "arrow.h"
#include "arch.h"
#include <DxLib.h>

#define APPLECOUNT 10 //クリア数
#define TIMEUP 0 //制限時間切れ

//
//ここで変数を用意
//

int AppleCounter; //矢が当たったりんごの個数
int StartTime, Time; //開始時間, 制限時間
int SceneStatus = 0; //画面遷移状態

//りんご情報の実体宣言
Apple applecount[APPLECOUNT];
Apple applebutton;

void GameMain(); //ゲームシーン
void Draw_Background(); //空（背景）を描画
void AppleCount_Initialize(); //りんごカウンターの初期化
void Draw_AppleCount(int apple_counter); //りんごカウンターを描画
void AppleButton_Initialize(); //りんごボタンの初期化
void Draw_AppleButton(); //りんごボタンを描画
void Timer(); //制限時間を調べる
int Collision(); //衝突判定
int isTimeUp(); //タイムアップしたかどうかを返す関数
void GameStart(); //スタートシーン
void GameOver(); //ゲームオーバーシーン
void GameClear(); //クリアシーン
int Retry(); //リトライするかどうか調べる

//
//プログラムはWinMainから始まる
//
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdeLine, int nCmdShow){

	ChangeWindowMode(TRUE); //非全画面にセット
	SetGraphMode(SCREEN_WIDTH, SCREEN_HEIGHT, 32); //画面サイズ指定
	SetOutApplicationLogValidFlag(FALSE); //Log.txtを生成しないように設定

	if(DxLib_Init() == 1){
		return -1; //初期化に失敗時にエラーが起きたら直ちに終了
	}

	do{
		ClearDrawScreen();

		switch(SceneStatus){
		case 0:
			//スタートシーン
			GameStart();
			break;
		case 1:
			//ゲームシーン
			GameMain();
			break;
		case 2:
			//ゲームオーバーシーン
			GameOver();
			break;
		case 3:
			//クリアシーン
			GameClear();
			break;
		default:
			DxLib_End(); //DXライブラリ使用の終了処理
			return 0; //ソフトの終了
			break;
		}
		if(ProcessMessage() == -1 || CheckHitKey(KEY_INPUT_ESCAPE) != 0){
			break;                 //エラーが起きたら終了
		}
	} while(Retry());

	DxLib_End(); //DXライブラリ使用の終了処理
	return 0; //ソフト終了
}

//ゲームシーン
void GameMain(){
	SetDrawScreen(DX_SCREEN_BACK); //描画先を裏画面に
	ClearDrawScreen(); //裏画面消す

	//マウスカーソルのX, Y座標を取得
	int mouseX, mouseY;
	GetMousePoint(&mouseX, &mouseY);

	//矢が当たったりんごの個数初期化
	AppleCounter = 0;

	//空（背景）を描画
	Draw_Background();

	//
	//初期化
	//
	//りんごの初期化
	Apple_Initialize();

	//矢の初期化
	Arrow_Initialize(mouseY);

	//りんごカウンターの初期化
	AppleCount_Initialize();

	//
	//ここで画像・音を読み込み
	//
	//画像ファイル
	//野原を初期化
	Field_Initialize();

	//木の初期化
	Tree_Initialize();

	//切り株の初期化
	Stump_Initialize();

	//花の初期化
	Flower_Initialize();

	//葉の初期化
	Leaf_Initialize();

	//弓の初期化
	Arch_Initialize(mouseY);

	//音ファイル
	//効果音の初期化
	Sound_Initialize();

	//ここで0.l2秒待つ
	WaitTimer(120);

	//現在経過時間を得る
	StartTime = GetNowCount();

	while(1){
		ClearDrawScreen();

		//
	    //ここに毎フレーム呼ぶ処理を書く
		//

		//マウスカーソルのX, Y座標を取得
		GetMousePoint(&mouseX, &mouseY);

		//
		//画像描画
		//
		//野原を描画
		Draw_Field();

		//木を描画
		Draw_Tree();

		//切り株を描画
		Draw_Stump();

		//花を描画
		Draw_Flower();

		//葉を描画
		Draw_Leaf();

		//
		//描画処理
		//
		//りんごを描画
		Draw_Apple();

		//矢を描画
		Draw_Arrow();

		//弓を描画
		Draw_Arch();

		//りんごカウンターを描画
		Draw_AppleCount(AppleCounter);
		
		//
		//アニメーション処理
		//
		//りんごのアニメーション
		Apple_Animation();

		//弓のアニメーション
		Arrow_Animation(mouseY);

		//矢のアニメーション
		Arch_Animation(mouseY);

		if(Pressed_flag != 0){
			AppleCounter = Collision(); //衝突判定
			if(Pressed_flag == 0){
				Play_HitSound(); //hit.mp3を再生
			}
		}

		//制限時間を調べる
		Timer();

		if(isTimeUp()){ //制限時間切れ
			SceneStatus = 2;
			ScreenFlip(); //裏画面を表画面にコピー
			WaitTimer(180); //ここで0.l8秒待つ
			break;
		}else if(AppleCounter == APPLECOUNT){ //クリア
			Draw_AppleCount(AppleCounter);
			ScreenFlip(); //裏画面を表画面にコピー
			SceneStatus = 3;
			WaitTimer(180); //ここで0.l8秒待つ
			break;
		}

		ScreenFlip(); //裏画面を表画面にコピー

		//エラーが起きたら終了
		if(ProcessMessage() == -1 || CheckHitKey(KEY_INPUT_ESCAPE) != 0){
			break;
		}
	}

	//読み込んだ画像のグラフィックハンドルを削除
	Delete_Field(); //野原
	Delete_Tree(); //木
	Delete_Stump(); //切り株
	Delete_Flower(); //花
	Delete_Leaf(); //葉
	Delete_Arch(); //弓

	//サウンドハンドルの削除
	Delete_Sound();
}

//空（背景）を描画
void Draw_Background(){
	SetBackgroundColor(70, 150, 255);
}

//りんごカウンターの初期化
void AppleCount_Initialize(){
	for(int i=0; i < APPLECOUNT; i++){
		applecount[i].x = 50;
		applecount[i].y = 50 * (i + 1);
		applecount[i].vy = 0.0;
	}
}

//りんごカウンターを描画
void Draw_AppleCount(int apple_counter){
	unsigned int apple_color = GetColor(235, 25, 40);
	unsigned int apple_leaf_color = GetColor(140, 115, 60);
	double ratio = 0.8; //縮小率

	//枠
	DrawBox(20, 20, 80, 530, GetColor(255, 255, 185), TRUE);
	DrawBox(20, 20, 80, 530, Black, FALSE);

	for(int i=0; i < apple_counter; i++){
		DrawCircle(applecount[i].x, (int)applecount[i].y, (int)(APPLE_RADIUS * ratio), apple_color, TRUE);
		DrawCircle(applecount[i].x, (int)applecount[i].y, (int)(APPLE_RADIUS * ratio), Black, FALSE);
		DrawBezier((int)(applecount[i].x-10*ratio), (int)(applecount[i].y-15*ratio), (int)(applecount[i].x-5*ratio), (int)(applecount[i].y-11*ratio), (int)(applecount[i].x+5*ratio), (int)(applecount[i].y-11*ratio), (int)(applecount[i].x+10*ratio), (int)(applecount[i].y-15*ratio), Black);
		DrawTriangle(applecount[i].x, (int)(applecount[i].y - 15 * ratio), (int)(applecount[i].x - 5 * ratio), (int)(applecount[i].y - 30 * ratio), (int)(applecount[i].x + 5 * ratio), (int)(applecount[i].y - 30 * ratio), apple_leaf_color, TRUE);
		DrawTriangle(applecount[i].x, (int)(applecount[i].y - 15 * ratio), (int)(applecount[i].x - 5 * ratio), (int)(applecount[i].y - 30 * ratio), (int)(applecount[i].x + 5 * ratio), (int)(applecount[i].y - 30 * ratio), Black, FALSE);
	}
}

//りんごボタンの初期化
void AppleButton_Initialize(){
		applebutton.x = SCREEN_WIDTH/2;
		applebutton.y = 500.0;
		applebutton.vy = 0.0;
}

//りんごボタンを描画
void Draw_AppleButton(){
	unsigned int apple_color = GetColor(235, 25, 40);
	unsigned int apple_leaf_color = GetColor(140, 115, 60);
	double ratio = 3; //拡大率

	DrawCircle(applebutton.x, (int)applebutton.y, (int)(APPLE_RADIUS * ratio), apple_color, TRUE);
	DrawCircle(applebutton.x, (int)applebutton.y, (int)(APPLE_RADIUS * ratio), Black, FALSE);
	DrawBezier((int)(applebutton.x-10*ratio), (int)(applebutton.y-15*ratio), (int)(applebutton.x-5*ratio), (int)(applebutton.y-11*ratio), (int)(applebutton.x+5*ratio), (int)(applebutton.y-11*ratio), (int)(applebutton.x+10*ratio), (int)(applebutton.y-15*ratio), Black);
	DrawTriangle(applebutton.x, (int)(applebutton.y - 15 * ratio), (int)(applebutton.x - 5 * ratio), (int)(applebutton.y - 30 * ratio), (int)(applebutton.x + 5 * ratio), (int)(applebutton.y - 30 * ratio), apple_leaf_color, TRUE);
	DrawTriangle(applebutton.x, (int)(applebutton.y - 15 * ratio), (int)(applebutton.x - 5 * ratio), (int)(applebutton.y - 30 * ratio), (int)(applebutton.x + 5 * ratio), (int)(applebutton.y - 30 * ratio), Black, FALSE);
	
}

//衝突判定
int Collision(){
	for(int i = 0; i < APPLE_NUMBER; i++){
		if((arrow.x-25)- apple[i].x < APPLE_RADIUS && apple[i].y - APPLE_RADIUS < arrow.y && arrow.y < apple[i].y + APPLE_RADIUS && arrow.x > apple[i].x){
			Pressed_flag = 0;
			apple[i].x = apple_x(mt);
			apple[i].y = 0.0;
			apple[i].vy = apple_vy(mt);
			AppleCounter++;
		}
	}
	return AppleCounter;
}

//制限時間
void Timer(){
	Time = (int)((60000 + StartTime - GetNowCount())/ 1000);
	SetFontSize(50);
	DrawFormatString(10, SCREEN_HEIGHT - 50, Black, "%d", Time);
}

//制限時間切れしたかどうかを調べる関数
int isTimeUp(){
	if(Time == TIMEUP){ //制限時間切れ
		return 1;
	} else{
		return 0;
	}
}

//スタートシーン
void GameStart(){
	int ClickX, ClickY, Button, LogType;
	int TransitionFlag = 0; //画面遷移するかどうかのフラグ
	int DrawX, DrawY;
	double ratio = 3; //拡大率

	AppleButton_Initialize(); //りんごボタンの初期化
	SetDrawScreen(DX_SCREEN_BACK); //描画先を裏画面に
	Draw_Background();
	ClearDrawScreen();
	SetDrawScreen(DX_SCREEN_FRONT); //描画先を表画面に
	SetFontSize(100);
	DrawFormatString(250, SCREEN_HEIGHT/3, White, "WILLAM TELL GAME");
	Draw_AppleButton(); //りんごボタンの描画
	SetFontSize(50);
	DrawFormatString(560, 490, White, "START");

	while(1){
		if((GetMouseInput() & MOUSE_INPUT_LEFT) != 0){
			// マウスのボタンが押されたり離されたりしたかどうかの情報を取得する
			if(GetMouseInputLog2(&Button, &ClickX, &ClickY, &LogType, TRUE) == 0){
				// 左ボタンが押されたり離されたりしていたら座標を保存する
				if((Button & MOUSE_INPUT_LEFT) != 0 && (LogType &  MOUSE_INPUT_LOG_UP) == 0 && (GetMouseInput() & MOUSE_INPUT_LEFT) != 0){
					DrawX = ClickX;
					DrawY = ClickY;
					//指定座標内にマウスがあれば画面遷移するかどうかのフラグを立てる
					if(((DrawX - applebutton.x) * (DrawX - applebutton.x) + (DrawY - applebutton.y) * (DrawY - applebutton.y)) <(APPLE_RADIUS * ratio) * (APPLE_RADIUS * ratio)){
						TransitionFlag = 1;
						break;
					}
				}
			}
		}else if(ProcessMessage() == -1 || CheckHitKey(KEY_INPUT_ESCAPE) != 0){
			break;
		}
	}

	// 描画するかどうかのフラグが立っていたら、画面遷移
	if(TransitionFlag){
		SceneStatus = 1;
	}else{
		SceneStatus = 4;
	}
}

//ゲームオーバーシーン
void GameOver(){
	int ClickX, ClickY, Button, LogType;
	int TransitionFlag = 0; //画面遷移するかどうかのフラグ
	int DrawX, DrawY;
	double ratio = 3; //拡大率

	SetDrawScreen(DX_SCREEN_BACK); //描画先を裏画面に
	SetBackgroundColor(0, 0, 0);
	ClearDrawScreen();
	SetDrawScreen(DX_SCREEN_FRONT); //描画先を表画面に
	SetFontSize(100);
	DrawFormatString(400, SCREEN_HEIGHT/3, Red, "GAME OVER");
	Draw_AppleButton(); //りんごボタンの描画
	SetFontSize(50);
	DrawFormatString(560, 490, Black, "RETRY");
	
	while(1){
		if((GetMouseInput() & MOUSE_INPUT_LEFT) != 0){
			// マウスのボタンが押されたり離されたりしたかどうかの情報を取得する
			if(GetMouseInputLog2(&Button, &ClickX, &ClickY, &LogType, TRUE) == 0){
				// 左ボタンが押されたり離されたりしていたら座標を保存する
				if((Button & MOUSE_INPUT_LEFT) != 0 && (LogType &  MOUSE_INPUT_LOG_UP) == 0 && (GetMouseInput() & MOUSE_INPUT_LEFT) != 0){
					DrawX = ClickX;
					DrawY = ClickY;
					//指定座標内にマウスがあれば画面遷移するかどうかのフラグを立てる
					if(((DrawX - applebutton.x) * (DrawX - applebutton.x) + (DrawY - applebutton.y) * (DrawY - applebutton.y)) <(APPLE_RADIUS * ratio) * (APPLE_RADIUS * ratio)){
						TransitionFlag = 1;
						break;
					}
				}
			}
		}else if(ProcessMessage() == -1 || CheckHitKey(KEY_INPUT_ESCAPE) != 0){
			break;
		}
	}
	
	// 描画するかどうかのフラグが立っていたら、画面遷移
	if(TransitionFlag){
		SceneStatus = 0;
		//ここで0.12秒待つ
		WaitTimer(120);
	}else{
		SceneStatus = 4;
	}
}

//クリアシーン
void GameClear(){
	int ClickX, ClickY, Button, LogType;
	int TransitionFlag = 0; //画面遷移するかどうかのフラグ
	int DrawX, DrawY;
	double ratio = 3; //拡大率

	SetDrawScreen(DX_SCREEN_BACK); //描画先を裏画面に
	Draw_Background();
	ClearDrawScreen();
	SetDrawScreen(DX_SCREEN_FRONT); //描画先を表画面に
	SetFontSize(100);
	DrawFormatString(440, SCREEN_HEIGHT/3, White, "CLEAR!!");
	Draw_AppleButton(); //りんごボタンの描画
	SetFontSize(50);
	DrawFormatString(560, 490, White, "RETRY");

	while(1){
		// マウスのボタンが押されたり離されたりしたかどうかの情報を取得する
		if(GetMouseInputLog2(&Button, &ClickX, &ClickY, &LogType, TRUE) == 0){
			// 右ボタンが押されたり離されたりしていたら座標を保存する
			if((Button & MOUSE_INPUT_LEFT) != 0 && (LogType &  MOUSE_INPUT_LOG_UP) == 0 && (GetMouseInput() & MOUSE_INPUT_LEFT) != 0){
				DrawX = ClickX;
				DrawY = ClickY;
				//指定座標内にマウスがあれば画面遷移するかどうかのフラグを立てる
				if(((DrawX - applebutton.x) * (DrawX - applebutton.x) + (DrawY - applebutton.y) * (DrawY - applebutton.y)) < (APPLE_RADIUS * ratio) * (APPLE_RADIUS * ratio)){
					TransitionFlag = 1;
					break;
				}
			}
		}else if(ProcessMessage() == -1 || CheckHitKey(KEY_INPUT_ESCAPE) != 0){
			break;
		}
	}

	// 画面遷移するかどうかのフラグが立っていたら、画面遷移
	if(TransitionFlag){
		SceneStatus = 0;
		//ここで0.12秒待つ
		WaitTimer(120);
	}else{
		SceneStatus = 4;
	}
}

//リトライするかどうか調べる
int Retry(){
	if(SceneStatus == 4){
		return 0;
	} else{
		return 1;
	}
}