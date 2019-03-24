//Willam_Tell_Game
//Hongo Aki

/* field.h */
#pragma once

//–ìŒ´
struct Field{
	int x; //xÀ•W
	int y; //yÀ•W
};

extern Field field; //–ìŒ´î•ñ‚ÌÀ‘ÌéŒ¾

extern void Field_Initialize(); //–ìŒ´‚Ì‰Šú‰»
extern void Draw_Field(); //–ìŒ´‚ğ•`‰æ
extern void Delete_Field(); //–ìŒ´‚ğíœ