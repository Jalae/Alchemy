/******************************************************************************
*Author:		Kehnin Dyer
*File name:		AlchemyShape.h
*Date Created:	2012/04/10
*Modifed:		
*					:see git commits for more details
******************************************************************************/

#ifndef _ALCHEMY_SHAPE__
#define _ALCHEMY_SHAPE__

namespace alchemy
{
enum COLOR
{
	BLACK = L'0',
	GRAY = L'8',
	L_BLUE = L'9',
	BLUE = L'1',
	L_AQUA = L'B',
	AQUA = L'3',
	L_GREEN = L'A',
	GREEN = L'2',
	L_YELLOW = L'6',
	YELLOW = L'E',
	PINK = L'4',
	RED = L'C',
	L_PURPLE = L'D',
	PURPLE = L'5',
	L_GRAY = L'7',
	WHITE = L'F',
	FILLED = BLUE,

};

class Shape
{
	wchar_t symbol;
	wchar_t FG_Color;
	//wchar_t BG_Color;
	wchar_t str[6];
public:
	Shape(wchar_t s = L' ', wchar_t fg = COLOR::BLACK):
				symbol(s),
				FG_Color(fg),
				BG_Color(bg)
	{
		str[0] = L'$';
		str[1] = FG_Color;
		str[2] = symbol;
		str[3] = L'$';
		str[4] = L'F';
		str[5] = 0;
	}

	~Shape()
	{
	}

	wchar_t * toString()
	{
		return str;
	}
};

Shape BLANKSHAPE();

}

#endif