/******************************************************************************
*Author:		Kehnin Dyer
*File name:		Exception.h
*Date Created:	2012/04/02
*Modifed:		2012/04/04 - functionally complete
******************************************************************************/

#ifndef EXCEPTION_H
#define EXCEPTION_H
#include <ostream>
using std::ostream;

/******************************************************************************
*Class:		Exception
*
*Purpose:	a lame Exception class...
*
*Functions:
*		Exception()
*			should probably be private
*		Exception(char * const msg)
*			sets Exception's message to msg
*		Exception(Exception & e)
*			When am i going to use this?
*		~Exception()
*			Good ole destructor
*		Exception & operator=(Exception& rhs)
*			makes this be like that.
*		char* const getMessage() const
*			like what() in the stl
*		void setMessage(char* const msg)
*			sets the internal message, i don't like it... not one bit
*		char* const what() const
*			Returns a discription of the exception
*
*
******************************************************************************/
class Exception
{
	char * m_msg;
public:
	Exception();
	Exception(char * const msg);
	Exception(Exception & e);
	~Exception();
	Exception & operator=(Exception& rhs);
	char * const getMessage() const;
	void setMessage(char* const msg);
	char* const what() const;
};

ostream & operator<<(ostream & stream, Exception & except);

#endif
