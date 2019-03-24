//Willam_Tell_Game
//Hongo Aki

/* common.h */
#pragma once
#include <random>

using namespace std;

#define SCREEN_WIDTH 1250 //スクリーンの幅
#define SCREEN_HEIGHT 700 //スクリーンの高さ

//ランダム変数
extern mt19937 mt;
extern uniform_int_distribution<int> apple_x;
extern uniform_real_distribution<> apple_vy;

//ベジエ曲線を描画
extern void DrawBezier(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4, unsigned int color);

//平行四辺形を描画
extern void DrawQuad(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4, unsigned int color, unsigned int out_color);
