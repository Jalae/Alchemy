/******************************************************************************
*Author:		Kehnin Dyer
*File name:		Row.h
*Date Created:	2012/06/02
*Modifed:		
******************************************************************************/

#ifndef ROW_H_
#define ROW_H_

#include<stdlib.h>

template <typename T>
class Array2D;


/******************************************************************************
*Class:		Array2D
*
*Purpose:	A 2 dimentional array for anything.
*
*Functions:
*			Row()
*				don't use it
*			Row(Row& const copy)
*				don't use it
*			Row& operator=(Row& const rhs)
*				don't use it
*			Row(Array2D& const array, size_t row)
*				the only constuctor you will ever need. Stores row and a ref
*				to the Array2D that made it.
*			~Row()
*				default destructor
*			T& operator[](size_t column)
*				calls the select function of the Array2d that make the Row, and
*				returns the value. for writing
*			T& const operator[](size_t column) const
*				same as the not const version, but for reading only.
******************************************************************************/
template<typename T>
class Row
{
	Array2D<T> & m_array2D;
	size_t const m_row;

	Row()
	{}

	Row& operator=(Row& const rhs)
	{}

public:
	Row(Array2D<T> & array, size_t row):m_array2D(array), m_row(row)
	{}

	Row(Row const & copy):m_array2D(copy.m_array2D), m_row(copy.m_row)
	{}

	~Row()
	{}

	T & operator[](size_t const column)
	{
		return m_array2D.Select(m_row, column);
	}

	T const & operator[](size_t column) const
	{
		//Array2D<T> const temp = (const_cast<Array2D<T> &>(m_array2D));
		return m_array2D.Select(m_row, column);
	}
	
};

#endif

