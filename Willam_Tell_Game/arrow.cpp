//Willam_Tell_Game
//Hongo Aki

/* arrow.cpp */
#include "arrow.h"
#include "color.h"
#include "common.h"
#include "sound.h"
#include <DxLib.h>

int Pressed_flag = 0; //���{�^���������ꂽ���ǂ����ۑ�����ϐ��i0�F������ĂȂ��A1�F�����ꂽ�j
Arrow arrow; //����̎��̐錾

//��̏�����
void Arrow_Initialize(int mouseY){
	arrow.x = 1115;
	arrow.y = mouseY;
	arrow.speed = -10;
}

//���`��
void Draw_Arrow(){
	DrawTriangle(arrow.x-25, arrow.y, arrow.x, arrow.y-10, arrow.x, arrow.y + 10, GetColor(240, 230, 230), TRUE);
	DrawTriangle(arrow.x-25, arrow.y, arrow.x, arrow.y-10, arrow.x, arrow.y + 10, Black, FALSE);
	DrawQuad(arrow.x+50, arrow.y, arrow.x+60, arrow.y-15, arrow.x+95, arrow.y-15, arrow.x+85, arrow.y, White, Black);
	DrawQuad(arrow.x+50, arrow.y, arrow.x+60, arrow.y+15, arrow.x+95, arrow.y+15, arrow.x+85, arrow.y, White, Black);
	DrawQuad(arrow.x+60, arrow.y, arrow.x+70, arrow.y-15, arrow.x+85, arrow.y-15, arrow.x+75, arrow.y, Red, Black);
	DrawQuad(arrow.x+60, arrow.y, arrow.x+70, arrow.y+15, arrow.x+85, arrow.y+15, arrow.x+75, arrow.y, Red, Black);
	DrawBox(arrow.x, arrow.y+2, arrow.x + 85, arrow.y-2, GetColor(245, 130, 85), TRUE);
	DrawBox(arrow.x, arrow.y+2, arrow.x + 85, arrow.y-2, Black, FALSE);
}

//��̃A�j���[�V����
void Arrow_Animation(int mouseY){
	int ClickX, ClickY, Button, LogType;
	GetMouseInputLog2(&Button, &ClickX, &ClickY, &LogType, TRUE);

	//���{�^���������ꂽ�Ƃ�
	if((Button & MOUSE_INPUT_LEFT) != 0 && (GetMouseInput() & MOUSE_INPUT_LEFT) != 0 && (LogType & MOUSE_INPUT_LOG_UP) == 0){
		Arrow_Initialize(mouseY);
		Play_ShootSound();
		Pressed_flag = 1;
		arrow.y = mouseY;
	}

	if(Pressed_flag == 0){
		Arrow_Initialize(mouseY);
	}else{
		arrow.x += arrow.speed;  //����
		if(arrow.x < 0){
			Pressed_flag = 0;
		}
	}
}
