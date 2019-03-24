//Willam_Tell_Game
//Hongo Aki

/* flower.h */
#pragma once

#define FLOWER_NUMBER 4 //‰Ô‚ÌŒÂ”

//‰Ô
struct Flower{
	int x; //xÀ•W
	int y; //yÀ•W
};

extern Flower flower[FLOWER_NUMBER]; //‰Ôî•ñ‚ÌÀ‘ÌéŒ¾

extern void Flower_Initialize(); //‰Ô‚Ì‰Šú‰»
extern void Draw_Flower(); //‰Ô‚ğ•`‰æ
extern void Delete_Flower(); //‰Ô‚ğíœ

