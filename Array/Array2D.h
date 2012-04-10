/******************************************************************************
*Author:		Kehnin Dyer
*File name:		Array2D.h
*Date Created:	2012/05/02
*Modifed:		
******************************************************************************/

#ifndef ARRAY2D_H_
#define ARRAY2D_H_

#include "Array.h"
#include "Row.h"


/******************************************************************************
*Class:		Array2D
*
*Purpose:	A 2 dimentional array for anything.
*
*Functions:
*		Array2D()
*			default constructor...
*		Array2D(size_t row, size_t col = 0)
*			standard constructor... i want column not defaulted,
*			and row defaulted to 1, but WHATEVER.
*		Array(Array2D & const copy)
*			copy constructor
*		~Array()
*			destructor, destucts the stuff
*		Array2D & operator=(Array2D& const rhs)
*			assignment op for assignment
*		Row<T> operator[](size_t const index)
*			get the correct row, for writing
*		Row<T> const operator[](size_t const index) const
*			get the correct row, for reading
*		size_t getRow() const
*			get the number of rows
*		void setRow(size_t rows)
*			change the number of rows
*		size_t getColumn() const
*			get the number of columns
*		void setColumn(size_t columns)
*			set the number of columns/row.
*		T& Select(size_t const row, size_t const col)
*			selector of element for writes
*		T& const Select(size_t const row, size_t const col) const
*			selector of element for writes
******************************************************************************/
template <typename T>
class Array2D
{
	Array<T> m_array;
	size_t m_row;
	size_t m_col;
public:
	Array2D():m_row(0), m_col(0)
	{}

	Array2D(size_t row, size_t col = 0):m_array(row*col), m_row(row), m_col(col)
	{}

	Array2D(Array2D const & copy):
						m_array(copy.m_array),
						m_row(copy.getRow()),
						m_col(copy.getColumn())
	{//we really don't have to do much do we?
	}

	~Array2D()
	{}//i have no mess to cleanup.

	Array2D & operator=(Array2D const & rhs)
// i want to call 'rhs' 'that', and it to be a pointer.
//so i can type if(this!=that)
	{
	//this doesn't make a bit of difference guys... the balls are inert
		if(this != &rhs)
		{
			m_col = rhs.m_col;
			m_row = rhs.m_row;
			m_array = rhs.m_array;
		}
		return *this;
	}

	Row<T> operator[](size_t const row)
	{
		return Row<T>(*this, row);
	}

	Row<T> const operator[](size_t const row) const
	{
		return Row<T>(const_cast<Array2D<T> &>(*this), row);
	}

	inline size_t getRow() const
	{
		return m_row;
	}

	inline void setRow(size_t rows)
	{
		m_row = rows;
	}

	inline size_t getColumn() const
	{
		return m_col;
	}
	
	inline void setColumn(size_t columns)
	{
		m_col = columns;
	}

	T & Select(size_t const row, size_t const col)
	{
		if(col > m_col)
		{
			throw(Exception("Invalid Column index"));
		}
		if(row > m_row)
		{
			throw(Exception("Invalid Row index"));
		}
		return m_array[(row*m_col)+col];
	}
	
	T const & Select(size_t const row, size_t const col) const
	{
		if(col > m_col)
		{
			throw(Exception("Invalid Column index"));
		}
		if(row > m_row)
		{
			throw(Exception("Invalid Row index"));
		}
		return m_array[(row*m_col)+col];
	}


};

#endif
