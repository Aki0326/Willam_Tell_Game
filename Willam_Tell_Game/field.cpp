//Willam_Tell_Game
//Hongo Aki

/* field.cpp */
#include "field.h"
#include <DxLib.h>

int FieldImageHandle; //field.png�摜��ۑ����邽�߂̕ϐ�
Field field; //�쌴���̎��̐錾

//�쌴�̏�����
void Field_Initialize(){
	//field.png�摜�̃������ւ̓ǂݍ���
	FieldImageHandle = LoadGraph("images\\field.png"); //�쌴
	field.x = 0;
	field.y = 620;
}

//�쌴��`��
void Draw_Field(){
	DrawGraph(field.x, field.y, FieldImageHandle, TRUE);

}

//�쌴���폜
void Delete_Field(){
	//�ǂݍ��񂾉摜�̃O���t�B�b�N�n���h�����폜
	DeleteGraph(FieldImageHandle);
}