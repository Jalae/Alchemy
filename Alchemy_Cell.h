/******************************************************************************
*Author:		Kehnin Dyer
*File name:		Alchemy_Cell.h
*Date Created:	2012/04/10
*Modifed:		
*					:see git commits for more details
******************************************************************************/

#ifndef _ALCHEMY_CELL__
#define _ALCHEMY_CELL__

#include "Alchemy_Shape.h"
#include "console\Console_Object.h"
namespace alchemy
{

class Cell:public absObject
{
	Shape * m_shape;
	bool m_touched;
public:
	Cell():m_shape(&BLANKSHAPE), m_touched(false)
	{}
	Cell(COORD pos):


	void touch()
	{

	}

	void Draw()
	{
	}

}

}

#endif