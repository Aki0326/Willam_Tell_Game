//Willam_Tell_Game
//Hongo Aki

/* sound.cpp */
#include "sound.h"
#include <DxLib.h>

int ShootSoundHandle; //矢を射るときの効果音
int HitSoundHandle; //りんごに矢が当たったときの効果音

//サウンドハンドルの初期化
void Sound_Initialize(){
	//音ファイルのメモリへの読み込み
	ShootSoundHandle = LoadSoundMem("sounds\\shoot.mp3"); //矢を射るときの効果音
	HitSoundHandle = LoadSoundMem("sounds\\hit.mp3"); //りんごに矢が当たったときの効果音
}

//弓を射るときの効果音を鳴らす
void Play_ShootSound(){
	PlaySoundMem(ShootSoundHandle, DX_PLAYTYPE_BACK);
}

//りんごに弓が当たったときの効果音を鳴らす
void Play_HitSound(){
	PlaySoundMem(HitSoundHandle, DX_PLAYTYPE_BACK);
}

//サウンドハンドルの削除
void Delete_Sound(){
	DeleteSoundMem(ShootSoundHandle);
	DeleteSoundMem(HitSoundHandle);
}