//Willam_Tell_Game
//Hongo Aki

/* leaf.h */
#pragma once

#define LEAF_NUMBER 8 //�t�̌�

//�t
struct Leaf{
	int x; //x���W
	int y; //y���W
};

extern Leaf greenleaf[LEAF_NUMBER]; //�ΐF�̗t
extern Leaf yellowgreenleaf[LEAF_NUMBER]; //���ΐF�̗t

extern void Leaf_Initialize(); //�t�̏�����
extern void Draw_Leaf(); //�t��`��
extern void Delete_Leaf(); //�t���폜

