/******************************************************************************
*Author:		Kehnin Dyer
*File name:		k_string.h
*Date Created:	2012/04/02
*Modifed:		2012/04/04 - functionally complete
******************************************************************************/

#ifndef K_STRING_
#define K_STRING_
//needed for size_t
#include <iostream>

size_t k_strlen(char* str);
void k_strcpy(char* src, char* & des);
bool k_strcmp(char* src, char* des);

#endif
