//Willam_Tell_Game
//Hongo Aki

/* arrow.h */
#pragma once

//��
struct Arrow{
	int x; //x���W
	int y; //y���W
	int speed; //�X�s�[�h

};

extern int Pressed_flag; //���{�^���������ꂽ���ǂ����ۑ�����ϐ��i0�F������ĂȂ��A1�F�����ꂽ�j
extern Arrow arrow; //����̎��̐錾

extern void Arrow_Initialize(int mouseY); //��̏�����
extern void Draw_Arrow(); //���`��
extern void Arrow_Animation(int mouseY); //��̃A�j���[�V����
