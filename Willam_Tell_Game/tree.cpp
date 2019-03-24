//Willam_Tell_Game
//Hongo Aki

/* tree.cpp */
#include "tree.h"
#include <DxLib.h>

int TreeImageHandle; //tree.png�摜��ۑ����邽�߂̕ϐ�
Tree tree; //�؏��̎��̐錾

//�؂̏�����
void Tree_Initialize(){
	//tree.png�摜�̃������ւ̓ǂݍ���
	TreeImageHandle = LoadGraph("images\\tree.png"); //��
	tree.x = -3;
	tree.y = -3;
}

//�؂�`��
void Draw_Tree(){
	DrawGraph(tree.x, tree.y, TreeImageHandle, TRUE);
}

//�؂��폜
void Delete_Tree(){
	//�ǂݍ��񂾉摜�̃O���t�B�b�N�n���h�����폜
	DeleteGraph(TreeImageHandle);
}