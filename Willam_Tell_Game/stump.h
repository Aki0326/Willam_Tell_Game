//Willam_Tell_Game
//Hongo Aki

/* stump.h */
#pragma once

//�؂芔
struct Stump{
	int x; //x���W
	int y; //y���W
};

extern Stump stump; //�؂芔���̎��̐錾

extern void Stump_Initialize(); //�؂芔��������
extern void Draw_Stump(); //�؂芔��`��
extern void Delete_Stump(); //�؂芔���폜