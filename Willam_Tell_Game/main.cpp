//Willam_Tell_Game
//Hongo Aki

/* main.cpp */
#include "color.h"
#include "common.h"
#include "field.h"
#include "tree.h"
#include "stump.h"
#include "flower.h"
#include "leaf.h"
#include "sound.h"
#include "apple.h"
#include "arrow.h"
#include "arch.h"
#include <DxLib.h>

#define APPLECOUNT 10 //�N���A��
#define TIMEUP 0 //�������Ԑ؂�

//
//�����ŕϐ���p��
//

int AppleCounter; //�����������񂲂̌�
int StartTime, Time; //�J�n����, ��������
int SceneStatus = 0; //��ʑJ�ڏ��

//��񂲏��̎��̐錾
Apple applecount[APPLECOUNT];
Apple applebutton;

void GameMain(); //�Q�[���V�[��
void Draw_Background(); //��i�w�i�j��`��
void AppleCount_Initialize(); //��񂲃J�E���^�[�̏�����
void Draw_AppleCount(int apple_counter); //��񂲃J�E���^�[��`��
void AppleButton_Initialize(); //��񂲃{�^���̏�����
void Draw_AppleButton(); //��񂲃{�^����`��
void Timer(); //�������Ԃ𒲂ׂ�
int Collision(); //�Փ˔���
int isTimeUp(); //�^�C���A�b�v�������ǂ�����Ԃ��֐�
void GameStart(); //�X�^�[�g�V�[��
void GameOver(); //�Q�[���I�[�o�[�V�[��
void GameClear(); //�N���A�V�[��
int Retry(); //���g���C���邩�ǂ������ׂ�

//
//�v���O������WinMain����n�܂�
//
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdeLine, int nCmdShow){

	ChangeWindowMode(TRUE); //��S��ʂɃZ�b�g
	SetGraphMode(SCREEN_WIDTH, SCREEN_HEIGHT, 32); //��ʃT�C�Y�w��
	SetOutApplicationLogValidFlag(FALSE); //Log.txt�𐶐����Ȃ��悤�ɐݒ�

	if(DxLib_Init() == 1){
		return -1; //�������Ɏ��s���ɃG���[���N�����璼���ɏI��
	}

	do{
		ClearDrawScreen();

		switch(SceneStatus){
		case 0:
			//�X�^�[�g�V�[��
			GameStart();
			break;
		case 1:
			//�Q�[���V�[��
			GameMain();
			break;
		case 2:
			//�Q�[���I�[�o�[�V�[��
			GameOver();
			break;
		case 3:
			//�N���A�V�[��
			GameClear();
			break;
		default:
			DxLib_End(); //DX���C�u�����g�p�̏I������
			return 0; //�\�t�g�̏I��
			break;
		}
		if(ProcessMessage() == -1 || CheckHitKey(KEY_INPUT_ESCAPE) != 0){
			break;                 //�G���[���N������I��
		}
	} while(Retry());

	DxLib_End(); //DX���C�u�����g�p�̏I������
	return 0; //�\�t�g�I��
}

//�Q�[���V�[��
void GameMain(){
	SetDrawScreen(DX_SCREEN_BACK); //�`���𗠉�ʂ�
	ClearDrawScreen(); //����ʏ���

	//�}�E�X�J�[�\����X, Y���W���擾
	int mouseX, mouseY;
	GetMousePoint(&mouseX, &mouseY);

	//�����������񂲂̌�������
	AppleCounter = 0;

	//��i�w�i�j��`��
	Draw_Background();

	//
	//������
	//
	//��񂲂̏�����
	Apple_Initialize();

	//��̏�����
	Arrow_Initialize(mouseY);

	//��񂲃J�E���^�[�̏�����
	AppleCount_Initialize();

	//
	//�����ŉ摜�E����ǂݍ���
	//
	//�摜�t�@�C��
	//�쌴��������
	Field_Initialize();

	//�؂̏�����
	Tree_Initialize();

	//�؂芔�̏�����
	Stump_Initialize();

	//�Ԃ̏�����
	Flower_Initialize();

	//�t�̏�����
	Leaf_Initialize();

	//�|�̏�����
	Arch_Initialize(mouseY);

	//���t�@�C��
	//���ʉ��̏�����
	Sound_Initialize();

	//������0.l2�b�҂�
	WaitTimer(120);

	//���݌o�ߎ��Ԃ𓾂�
	StartTime = GetNowCount();

	while(1){
		ClearDrawScreen();

		//
	    //�����ɖ��t���[���Ăԏ���������
		//

		//�}�E�X�J�[�\����X, Y���W���擾
		GetMousePoint(&mouseX, &mouseY);

		//
		//�摜�`��
		//
		//�쌴��`��
		Draw_Field();

		//�؂�`��
		Draw_Tree();

		//�؂芔��`��
		Draw_Stump();

		//�Ԃ�`��
		Draw_Flower();

		//�t��`��
		Draw_Leaf();

		//
		//�`�揈��
		//
		//��񂲂�`��
		Draw_Apple();

		//���`��
		Draw_Arrow();

		//�|��`��
		Draw_Arch();

		//��񂲃J�E���^�[��`��
		Draw_AppleCount(AppleCounter);
		
		//
		//�A�j���[�V��������
		//
		//��񂲂̃A�j���[�V����
		Apple_Animation();

		//�|�̃A�j���[�V����
		Arrow_Animation(mouseY);

		//��̃A�j���[�V����
		Arch_Animation(mouseY);

		if(Pressed_flag != 0){
			AppleCounter = Collision(); //�Փ˔���
			if(Pressed_flag == 0){
				Play_HitSound(); //hit.mp3���Đ�
			}
		}

		//�������Ԃ𒲂ׂ�
		Timer();

		if(isTimeUp()){ //�������Ԑ؂�
			SceneStatus = 2;
			ScreenFlip(); //����ʂ�\��ʂɃR�s�[
			WaitTimer(180); //������0.l8�b�҂�
			break;
		}else if(AppleCounter == APPLECOUNT){ //�N���A
			Draw_AppleCount(AppleCounter);
			ScreenFlip(); //����ʂ�\��ʂɃR�s�[
			SceneStatus = 3;
			WaitTimer(180); //������0.l8�b�҂�
			break;
		}

		ScreenFlip(); //����ʂ�\��ʂɃR�s�[

		//�G���[���N������I��
		if(ProcessMessage() == -1 || CheckHitKey(KEY_INPUT_ESCAPE) != 0){
			break;
		}
	}

	//�ǂݍ��񂾉摜�̃O���t�B�b�N�n���h�����폜
	Delete_Field(); //�쌴
	Delete_Tree(); //��
	Delete_Stump(); //�؂芔
	Delete_Flower(); //��
	Delete_Leaf(); //�t
	Delete_Arch(); //�|

	//�T�E���h�n���h���̍폜
	Delete_Sound();
}

//��i�w�i�j��`��
void Draw_Background(){
	SetBackgroundColor(70, 150, 255);
}

//��񂲃J�E���^�[�̏�����
void AppleCount_Initialize(){
	for(int i=0; i < APPLECOUNT; i++){
		applecount[i].x = 50;
		applecount[i].y = 50 * (i + 1);
		applecount[i].vy = 0.0;
	}
}

//��񂲃J�E���^�[��`��
void Draw_AppleCount(int apple_counter){
	unsigned int apple_color = GetColor(235, 25, 40);
	unsigned int apple_leaf_color = GetColor(140, 115, 60);
	double ratio = 0.8; //�k����

	//�g
	DrawBox(20, 20, 80, 530, GetColor(255, 255, 185), TRUE);
	DrawBox(20, 20, 80, 530, Black, FALSE);

	for(int i=0; i < apple_counter; i++){
		DrawCircle(applecount[i].x, (int)applecount[i].y, (int)(APPLE_RADIUS * ratio), apple_color, TRUE);
		DrawCircle(applecount[i].x, (int)applecount[i].y, (int)(APPLE_RADIUS * ratio), Black, FALSE);
		DrawBezier((int)(applecount[i].x-10*ratio), (int)(applecount[i].y-15*ratio), (int)(applecount[i].x-5*ratio), (int)(applecount[i].y-11*ratio), (int)(applecount[i].x+5*ratio), (int)(applecount[i].y-11*ratio), (int)(applecount[i].x+10*ratio), (int)(applecount[i].y-15*ratio), Black);
		DrawTriangle(applecount[i].x, (int)(applecount[i].y - 15 * ratio), (int)(applecount[i].x - 5 * ratio), (int)(applecount[i].y - 30 * ratio), (int)(applecount[i].x + 5 * ratio), (int)(applecount[i].y - 30 * ratio), apple_leaf_color, TRUE);
		DrawTriangle(applecount[i].x, (int)(applecount[i].y - 15 * ratio), (int)(applecount[i].x - 5 * ratio), (int)(applecount[i].y - 30 * ratio), (int)(applecount[i].x + 5 * ratio), (int)(applecount[i].y - 30 * ratio), Black, FALSE);
	}
}

//��񂲃{�^���̏�����
void AppleButton_Initialize(){
		applebutton.x = SCREEN_WIDTH/2;
		applebutton.y = 500.0;
		applebutton.vy = 0.0;
}

//��񂲃{�^����`��
void Draw_AppleButton(){
	unsigned int apple_color = GetColor(235, 25, 40);
	unsigned int apple_leaf_color = GetColor(140, 115, 60);
	double ratio = 3; //�g�嗦

	DrawCircle(applebutton.x, (int)applebutton.y, (int)(APPLE_RADIUS * ratio), apple_color, TRUE);
	DrawCircle(applebutton.x, (int)applebutton.y, (int)(APPLE_RADIUS * ratio), Black, FALSE);
	DrawBezier((int)(applebutton.x-10*ratio), (int)(applebutton.y-15*ratio), (int)(applebutton.x-5*ratio), (int)(applebutton.y-11*ratio), (int)(applebutton.x+5*ratio), (int)(applebutton.y-11*ratio), (int)(applebutton.x+10*ratio), (int)(applebutton.y-15*ratio), Black);
	DrawTriangle(applebutton.x, (int)(applebutton.y - 15 * ratio), (int)(applebutton.x - 5 * ratio), (int)(applebutton.y - 30 * ratio), (int)(applebutton.x + 5 * ratio), (int)(applebutton.y - 30 * ratio), apple_leaf_color, TRUE);
	DrawTriangle(applebutton.x, (int)(applebutton.y - 15 * ratio), (int)(applebutton.x - 5 * ratio), (int)(applebutton.y - 30 * ratio), (int)(applebutton.x + 5 * ratio), (int)(applebutton.y - 30 * ratio), Black, FALSE);
	
}

//�Փ˔���
int Collision(){
	for(int i = 0; i < APPLE_NUMBER; i++){
		if((arrow.x-25)- apple[i].x < APPLE_RADIUS && apple[i].y - APPLE_RADIUS < arrow.y && arrow.y < apple[i].y + APPLE_RADIUS && arrow.x > apple[i].x){
			Pressed_flag = 0;
			apple[i].x = apple_x(mt);
			apple[i].y = 0.0;
			apple[i].vy = apple_vy(mt);
			AppleCounter++;
		}
	}
	return AppleCounter;
}

//��������
void Timer(){
	Time = (int)((60000 + StartTime - GetNowCount())/ 1000);
	SetFontSize(50);
	DrawFormatString(10, SCREEN_HEIGHT - 50, Black, "%d", Time);
}

//�������Ԑ؂ꂵ�����ǂ����𒲂ׂ�֐�
int isTimeUp(){
	if(Time == TIMEUP){ //�������Ԑ؂�
		return 1;
	} else{
		return 0;
	}
}

//�X�^�[�g�V�[��
void GameStart(){
	int ClickX, ClickY, Button, LogType;
	int TransitionFlag = 0; //��ʑJ�ڂ��邩�ǂ����̃t���O
	int DrawX, DrawY;
	double ratio = 3; //�g�嗦

	AppleButton_Initialize(); //��񂲃{�^���̏�����
	SetDrawScreen(DX_SCREEN_BACK); //�`���𗠉�ʂ�
	Draw_Background();
	ClearDrawScreen();
	SetDrawScreen(DX_SCREEN_FRONT); //�`����\��ʂ�
	SetFontSize(100);
	DrawFormatString(250, SCREEN_HEIGHT/3, White, "WILLAM TELL GAME");
	Draw_AppleButton(); //��񂲃{�^���̕`��
	SetFontSize(50);
	DrawFormatString(560, 490, White, "START");

	while(1){
		if((GetMouseInput() & MOUSE_INPUT_LEFT) != 0){
			// �}�E�X�̃{�^���������ꂽ�藣���ꂽ�肵�����ǂ����̏����擾����
			if(GetMouseInputLog2(&Button, &ClickX, &ClickY, &LogType, TRUE) == 0){
				// ���{�^���������ꂽ�藣���ꂽ�肵�Ă�������W��ۑ�����
				if((Button & MOUSE_INPUT_LEFT) != 0 && (LogType &  MOUSE_INPUT_LOG_UP) == 0 && (GetMouseInput() & MOUSE_INPUT_LEFT) != 0){
					DrawX = ClickX;
					DrawY = ClickY;
					//�w����W���Ƀ}�E�X������Ή�ʑJ�ڂ��邩�ǂ����̃t���O�𗧂Ă�
					if(((DrawX - applebutton.x) * (DrawX - applebutton.x) + (DrawY - applebutton.y) * (DrawY - applebutton.y)) <(APPLE_RADIUS * ratio) * (APPLE_RADIUS * ratio)){
						TransitionFlag = 1;
						break;
					}
				}
			}
		}else if(ProcessMessage() == -1 || CheckHitKey(KEY_INPUT_ESCAPE) != 0){
			break;
		}
	}

	// �`�悷�邩�ǂ����̃t���O�������Ă�����A��ʑJ��
	if(TransitionFlag){
		SceneStatus = 1;
	}else{
		SceneStatus = 4;
	}
}

//�Q�[���I�[�o�[�V�[��
void GameOver(){
	int ClickX, ClickY, Button, LogType;
	int TransitionFlag = 0; //��ʑJ�ڂ��邩�ǂ����̃t���O
	int DrawX, DrawY;
	double ratio = 3; //�g�嗦

	SetDrawScreen(DX_SCREEN_BACK); //�`���𗠉�ʂ�
	SetBackgroundColor(0, 0, 0);
	ClearDrawScreen();
	SetDrawScreen(DX_SCREEN_FRONT); //�`����\��ʂ�
	SetFontSize(100);
	DrawFormatString(400, SCREEN_HEIGHT/3, Red, "GAME OVER");
	Draw_AppleButton(); //��񂲃{�^���̕`��
	SetFontSize(50);
	DrawFormatString(560, 490, Black, "RETRY");
	
	while(1){
		if((GetMouseInput() & MOUSE_INPUT_LEFT) != 0){
			// �}�E�X�̃{�^���������ꂽ�藣���ꂽ�肵�����ǂ����̏����擾����
			if(GetMouseInputLog2(&Button, &ClickX, &ClickY, &LogType, TRUE) == 0){
				// ���{�^���������ꂽ�藣���ꂽ�肵�Ă�������W��ۑ�����
				if((Button & MOUSE_INPUT_LEFT) != 0 && (LogType &  MOUSE_INPUT_LOG_UP) == 0 && (GetMouseInput() & MOUSE_INPUT_LEFT) != 0){
					DrawX = ClickX;
					DrawY = ClickY;
					//�w����W���Ƀ}�E�X������Ή�ʑJ�ڂ��邩�ǂ����̃t���O�𗧂Ă�
					if(((DrawX - applebutton.x) * (DrawX - applebutton.x) + (DrawY - applebutton.y) * (DrawY - applebutton.y)) <(APPLE_RADIUS * ratio) * (APPLE_RADIUS * ratio)){
						TransitionFlag = 1;
						break;
					}
				}
			}
		}else if(ProcessMessage() == -1 || CheckHitKey(KEY_INPUT_ESCAPE) != 0){
			break;
		}
	}
	
	// �`�悷�邩�ǂ����̃t���O�������Ă�����A��ʑJ��
	if(TransitionFlag){
		SceneStatus = 0;
		//������0.12�b�҂�
		WaitTimer(120);
	}else{
		SceneStatus = 4;
	}
}

//�N���A�V�[��
void GameClear(){
	int ClickX, ClickY, Button, LogType;
	int TransitionFlag = 0; //��ʑJ�ڂ��邩�ǂ����̃t���O
	int DrawX, DrawY;
	double ratio = 3; //�g�嗦

	SetDrawScreen(DX_SCREEN_BACK); //�`���𗠉�ʂ�
	Draw_Background();
	ClearDrawScreen();
	SetDrawScreen(DX_SCREEN_FRONT); //�`����\��ʂ�
	SetFontSize(100);
	DrawFormatString(440, SCREEN_HEIGHT/3, White, "CLEAR!!");
	Draw_AppleButton(); //��񂲃{�^���̕`��
	SetFontSize(50);
	DrawFormatString(560, 490, White, "RETRY");

	while(1){
		// �}�E�X�̃{�^���������ꂽ�藣���ꂽ�肵�����ǂ����̏����擾����
		if(GetMouseInputLog2(&Button, &ClickX, &ClickY, &LogType, TRUE) == 0){
			// �E�{�^���������ꂽ�藣���ꂽ�肵�Ă�������W��ۑ�����
			if((Button & MOUSE_INPUT_LEFT) != 0 && (LogType &  MOUSE_INPUT_LOG_UP) == 0 && (GetMouseInput() & MOUSE_INPUT_LEFT) != 0){
				DrawX = ClickX;
				DrawY = ClickY;
				//�w����W���Ƀ}�E�X������Ή�ʑJ�ڂ��邩�ǂ����̃t���O�𗧂Ă�
				if(((DrawX - applebutton.x) * (DrawX - applebutton.x) + (DrawY - applebutton.y) * (DrawY - applebutton.y)) < (APPLE_RADIUS * ratio) * (APPLE_RADIUS * ratio)){
					TransitionFlag = 1;
					break;
				}
			}
		}else if(ProcessMessage() == -1 || CheckHitKey(KEY_INPUT_ESCAPE) != 0){
			break;
		}
	}

	// ��ʑJ�ڂ��邩�ǂ����̃t���O�������Ă�����A��ʑJ��
	if(TransitionFlag){
		SceneStatus = 0;
		//������0.12�b�҂�
		WaitTimer(120);
	}else{
		SceneStatus = 4;
	}
}

//���g���C���邩�ǂ������ׂ�
int Retry(){
	if(SceneStatus == 4){
		return 0;
	} else{
		return 1;
	}
}