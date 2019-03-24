//Willam_Tell_Game
//Hongo Aki

/* sound.cpp */
#include "sound.h"
#include <DxLib.h>

int ShootSoundHandle; //����˂�Ƃ��̌��ʉ�
int HitSoundHandle; //��񂲂ɖ���������Ƃ��̌��ʉ�

//�T�E���h�n���h���̏�����
void Sound_Initialize(){
	//���t�@�C���̃������ւ̓ǂݍ���
	ShootSoundHandle = LoadSoundMem("sounds\\shoot.mp3"); //����˂�Ƃ��̌��ʉ�
	HitSoundHandle = LoadSoundMem("sounds\\hit.mp3"); //��񂲂ɖ���������Ƃ��̌��ʉ�
}

//�|���˂�Ƃ��̌��ʉ���炷
void Play_ShootSound(){
	PlaySoundMem(ShootSoundHandle, DX_PLAYTYPE_BACK);
}

//��񂲂ɋ|�����������Ƃ��̌��ʉ���炷
void Play_HitSound(){
	PlaySoundMem(HitSoundHandle, DX_PLAYTYPE_BACK);
}

//�T�E���h�n���h���̍폜
void Delete_Sound(){
	DeleteSoundMem(ShootSoundHandle);
	DeleteSoundMem(HitSoundHandle);
}