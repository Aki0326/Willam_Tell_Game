//Willam_Tell_Game
//Hongo Aki

/* flower.h */
#pragma once

#define FLOWER_NUMBER 4 //�Ԃ̌�

//��
struct Flower{
	int x; //x���W
	int y; //y���W
};

extern Flower flower[FLOWER_NUMBER]; //�ԏ��̎��̐錾

extern void Flower_Initialize(); //�Ԃ̏�����
extern void Draw_Flower(); //�Ԃ�`��
extern void Delete_Flower(); //�Ԃ��폜

