//Willam_Tell_Game
//Hongo Aki

/* flower.cpp */
#include "flower.h"
#include <DxLib.h>

int FlowerImageHandle; //flower.png�摜��ۑ����邽�߂̕ϐ�
double ratio = 0.9; //�k����
Flower flower[FLOWER_NUMBER]; //�ԏ��̎��̐錾

//�Ԃ̏�����
void Flower_Initialize(){
	//flower.png�摜�̃������ւ̓ǂݍ���
	FlowerImageHandle = LoadGraph("images\\flower.png"); //��
	for(int i = 0; i < FLOWER_NUMBER / 2; i++){
		flower[i].x = (int)(495 + (300 * i));
		flower[i].y = (int)(636);
	}
	for(int i = FLOWER_NUMBER/2; i < FLOWER_NUMBER; i++){
		flower[i].x = 645 + (300 * (i - (FLOWER_NUMBER /2)));
		flower[i].y =665;
	}
}

//�Ԃ�`��
void Draw_Flower(){
	for(int i = 0; i < FLOWER_NUMBER; i++){
		DrawGraph(flower[i].x, flower[i].y, FlowerImageHandle, TRUE);
	}
}

//�Ԃ��폜
void Delete_Flower(){
	//�ǂݍ��񂾉摜�̃O���t�B�b�N�n���h�����폜
	DeleteGraph(FlowerImageHandle);
}