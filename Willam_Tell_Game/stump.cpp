#include "stump.h"
#include <DxLib.h>

Stump stump; //�؂芔���̎��̐錾

int StumpImageHandle;

//�؂芔�̏�����
void Stump_Initialize(){
	//PNG�摜�̃������ւ̓ǂݍ���
	StumpImageHandle = LoadGraph("images\\stump.png"); //�؂芔
	stump.x = 280;
	stump.y = 593;
}

//�؂芔��`��
void Draw_Stump(){
	DrawGraph(stump.x, stump.y, StumpImageHandle, TRUE);
}

//�؂芔���폜
void Delete_Stump(){
	//�ǂݍ��񂾉摜�̃O���t�B�b�N�n���h�����폜
	DeleteGraph(StumpImageHandle);
}