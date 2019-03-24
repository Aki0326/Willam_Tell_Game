//Willam_Tell_Game
//Hongo Aki

/* arch.h */
#pragma once

//‹|
struct Arch{
	int x; //xÀ•W
	int y; //yÀ•W
};

extern Arch arch; //‹|î•ñ‚ÌÀ‘ÌéŒ¾

extern void Arch_Initialize(int mouseY); //‹|‚Ì‰Šú‰»
extern void Draw_Arch(); //‹|‚ğ•`‰æ
extern void Arch_Animation(int mouseY); //‹|‚ÌƒAƒjƒ[ƒVƒ‡ƒ“
extern void Delete_Arch(); //‹|	‚ğíœ