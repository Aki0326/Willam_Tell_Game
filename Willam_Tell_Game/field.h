//Willam_Tell_Game
//Hongo Aki

/* field.h */
#pragma once

//�쌴
struct Field{
	int x; //x���W
	int y; //y���W
};

extern Field field; //�쌴���̎��̐錾

extern void Field_Initialize(); //�쌴�̏�����
extern void Draw_Field(); //�쌴��`��
extern void Delete_Field(); //�쌴���폜