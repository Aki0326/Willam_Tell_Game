//Willam_Tell_Game
//Hongo Aki

/* apple.h */
#pragma once

#define APPLE_NUMBER 3 //��񂲂̐�
#define APPLE_RADIUS 25 //��񂲂̔��a

//���
struct Apple{
	int x; //x���W
	double y; //y���W
	double vy; //y���W�̃X�s�[�h
};

extern Apple apple[APPLE_NUMBER]; //��񂲏��̎��̐錾

extern void Apple_Initialize(); //��񂲂̏�����
extern void Draw_Apple(); //��񂲂�`��
extern void Apple_Animation(); //��񂲂̃A�j���[�V����
