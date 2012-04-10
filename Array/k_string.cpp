/******************************************************************************
*Author:		Kehnin Dyer
*File name:		k_string.cpp
*Date Created:	2012/04/02
*Modifed:		2012/04/04 - functionally complete
******************************************************************************/

#if defined _WIN32
	#define _CRTDBG_MAP_ALLOC
	#include <stdlib.h>
	#include <crtdbg.h>
#define MEMDUMP _CrtDumpMemoryLeaks();
#else
#define MEMDUMP ;
#endif

#include "k_string.h"

/******************************************************************************
*Purpose:	find the length of a cString
*
*Entry:		str is a cString
*
*Exit:		returns the length
*
******************************************************************************/
size_t k_strlen(char* str)
{
	size_t i(0);
	for(i; str[i] != 0; i++);
	return i;
}

/******************************************************************************
*Purpose:	copies one cString to another, deeply
*
*Entry:		src and des are cStrings, des is on the heap
*
*Exit:		des is newed and set to be the same as src
*
******************************************************************************/
void k_strcpy(char* src, char* & des)
{
	if(src==des)
		return;
	size_t len = k_strlen(src);
	if(des)
		delete[] des;
	des = new char[len+1];
	for(size_t i(0); i < (len + 1); i++)
	{
		des[i] = src[i];
	}
}

/******************************************************************************
*Purpose:	compares 2 cStrings
*
*Entry:		src and des are cStrings
*
*Exit:		returns true if all chars are the same.
*
******************************************************************************/
bool k_strcmp(char* src, char* des)
{
	size_t i(0);
	while(src[i]==des[i] && src[i])
		i++;
	return src[i]==des[i];
}
