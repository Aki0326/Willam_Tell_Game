//Willam_Tell_Game
//Hongo Aki

/* arch.cpp */
#include "arch.h"
#include <DxLib.h>

int ArchImageHandle; //arch.png�摜��ۑ����邽�߂̕ϐ�
Arch arch; //�|���̎��̐錾

//�|�̏�����
void Arch_Initialize(int mouseY){
	//arch.png�摜�̃������ւ̓ǂݍ���
	ArchImageHandle = LoadGraph("images\\arch.png"); //�|
	arch.x = 1125;
	arch.y = mouseY-50;
}

//�|��`��
void Draw_Arch(){
	DrawGraph(arch.x, arch.y, ArchImageHandle, TRUE);
}

//�|�̃A�j���[�V����
void Arch_Animation(int mouseY){
	arch.y = mouseY-50;
}

//�|���폜
void Delete_Arch(){
	//�ǂݍ��񂾉摜�̃O���t�B�b�N�n���h�����폜
	DeleteGraph(ArchImageHandle);
}
