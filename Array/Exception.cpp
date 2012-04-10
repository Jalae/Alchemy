/******************************************************************************
*Author:		Kehnin Dyer
*File name:		Exception.h
*Date Created:	2012/04/02
*Modifed:		2012/04/04 - functionally complete
*				2012/04/06 - moved k_string to a seperate project
******************************************************************************/

#if defined _WIN32
	#define _CRTDBG_MAP_ALLOC
	#include <stdlib.h>
	#include <crtdbg.h>
#define MEMDUMP _CrtDumpMemoryLeaks();
#else
#define MEMDUMP ;
#endif

#include "Exception.h"
#include "k_string.h"

Exception::Exception():m_msg(nullptr)
{}

Exception::Exception(char * const msg):m_msg(nullptr)
{
	k_strcpy(msg, m_msg);
}

Exception::Exception(Exception & e):m_msg(nullptr)
{
	*this = e;
}

Exception::~Exception()
{
	if(m_msg)
		delete[] m_msg;
	m_msg = nullptr;
}

Exception & Exception::operator=(Exception& rhs)
{
	if(this != &rhs)
		k_strcpy(rhs.getMessage(), m_msg);
	return *this;
}

char* const Exception::getMessage() const
{
	return m_msg;
}

void Exception::setMessage(char* const msg)
{
	k_strcpy(msg, m_msg);
}

char* const Exception::what() const
{
	return m_msg;
}

/******************************************************************************
*Purpose:	i guess it writes the exception to the given stream.
*
*Entry:		except is inited, stream is open and good
*
*Exit:		gives you your stream back.
*
******************************************************************************/
ostream & operator<<(ostream & stream, Exception & except)
{
	return stream << except.what();
}
