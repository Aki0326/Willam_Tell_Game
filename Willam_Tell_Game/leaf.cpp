//Willam_Tell_Game
//Hongo Aki

/* leaf.cpp */
#include "leaf.h"
#include <DxLib.h>

int GreenLeaf_ImageHandle; //greenleaf.png�摜��ۑ����邽�߂̕ϐ�
int YellowgreenLeaf_ImageHandle; //yellowgreenleaf.png�摜��ۑ����邽�߂̕ϐ�
Leaf greenleaf[LEAF_NUMBER]; //�ΐF�̗t�̎��̐錾
Leaf yellowgreenleaf[LEAF_NUMBER]; //���ΐF�̗t�̎��̐錾

//�t�̏�����
void Leaf_Initialize(){
	//�ΐF�̗t
	GreenLeaf_ImageHandle = LoadGraph("images\\greenleaf.png"); //�ΐF�̗t
	for(int i = 0; i < LEAF_NUMBER/2; i++){ //��i
		greenleaf[i].x = 200+ (200 * i);
		greenleaf[i].y = 0;
	}

	for(int i = LEAF_NUMBER/2; i < LEAF_NUMBER; i++){ //���i
		greenleaf[i].x = 300 + (200 * (i - (LEAF_NUMBER / 2)));
		greenleaf[i].y = 50;
	}

	//���ΐF�̗t
	YellowgreenLeaf_ImageHandle = LoadGraph("images\\yellowgreenleaf.png"); //���ΐF�̗t
	for(int i = 0; i < LEAF_NUMBER; i++){
		yellowgreenleaf[i].x = 250 + (100 * i);
		yellowgreenleaf[i].y = 25;
	}

}

//�t��`��
void Draw_Leaf(){
	for(int i = 0; i < LEAF_NUMBER; i++){
		//�ΐF�̗t
		DrawGraph(greenleaf[i].x, greenleaf[i].y, GreenLeaf_ImageHandle, TRUE);
		//���ΐF�̗t
		DrawGraph(yellowgreenleaf[i].x, yellowgreenleaf[i].y, YellowgreenLeaf_ImageHandle, TRUE);
	}
}

//�t���폜
void Delete_Leaf(){
	//�ǂݍ��񂾉摜�̃O���t�B�b�N�n���h�����폜
	DeleteGraph(GreenLeaf_ImageHandle); //�ΐF�̗t
	DeleteGraph(YellowgreenLeaf_ImageHandle); //���ΐF�̗t
}