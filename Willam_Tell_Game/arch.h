//Willam_Tell_Game
//Hongo Aki

/* arch.h */
#pragma once

//�|
struct Arch{
	int x; //x���W
	int y; //y���W
};

extern Arch arch; //�|���̎��̐錾

extern void Arch_Initialize(int mouseY); //�|�̏�����
extern void Draw_Arch(); //�|��`��
extern void Arch_Animation(int mouseY); //�|�̃A�j���[�V����
extern void Delete_Arch(); //�|	���폜