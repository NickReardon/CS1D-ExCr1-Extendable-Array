/*****************************************************************************
 * AUTHOR 	  		: Nick Reardon
 * Extra Credit #1	: Extendable Array
 * CLASS			: CS1D
 * SECTION			: MW - 2:30p
 * DUE DATE			: 02 / 12 / 20
 *****************************************************************************/
#ifndef _EXTENDABLEARRAY_H_
#define _EXTENDABLEARRAY_H_

#include <string>
#include <exception>
#include "Except.h"

 /**
  * @class	ExtendableArray ExtendableArray.h ExtendableArray.h
  *
  * @brief	Extendable circular array template class
  *
  * @author	Nick Reardon
  * @date	11/25/2020
  *
  * @tparam	Type	template datatype.
  */
template<class Type>
class ExtendableArray
{
private:
	Type* typeAr;		/** @brief	Template datatype pointer for array allocation */

	int capacity;		/** @brief	The current reserved memory locations of the array */
	int currentSize;	/** @brief	count of used indeces in the array */

	int frontIndex;		/** @brief	tracks the first index of the circular array */
	int endIndex;		/** @brief	tracks the last index of the circular array */


protected:

#ifndef Protected_Methods //--------------------------------------------------

	/**
	 * @fn	void ExtendableArray::shiftRight(const int givenIndex)
	 * @brief	Shift array members right/up, wrapping around to the end
	 *
	 * @exception	Except	Exception thrown when class is empty.
	 *
	 * @param 	givenIndex	int value passed from outside of the object index is adjusted for use in
	 * 						the method.
	 */
	void shiftRight(const int givenIndex)
	{

		if (empty())
		{
			throw Except("Array is empty", EMPTY, 5);
		}

		if (full())
		{
			expand();
		}


		if (endIndex == capacity - 1)
		{
			endIndex = 0;
		}
		else
		{
			endIndex++;
		}


		int tempIndex = endIndex;
		for (int i = capacity - 1; i >= givenIndex; i--)
		{
			if (tempIndex == 0)
			{
				typeAr[tempIndex] = typeAr[capacity - 1];

				tempIndex = 0;
			}
			else
			{
				typeAr[tempIndex] = typeAr[tempIndex - 1];

				tempIndex--;
			}
		}
	}

	/**
	 * @fn	void ExtendableArray::shiftLeft(const int givenIndex)
	 * @brief	Shift array members left/down, wrapping around to the end
	 *
	 * @exception	Except	Exception thrown when class is empty.
	 *
	 * @param 	givenIndex	int value passed from outside of the object index is adjusted for use in
	 * 						the method.
	 */
	void shiftLeft(const int givenIndex)
	{

		if (empty())
		{
			throw Except("Array is empty", EMPTY, 5);
		}

		if (full())
		{
			expand();
		}

		if (frontIndex == 0)
		{
			frontIndex = capacity - 1;
		}
		else
		{
			frontIndex--;
		}

		int tempIndex = frontIndex;
		for (int i = 0; i < givenIndex; i++)
		{
			if (tempIndex == capacity - 1)
			{
				typeAr[tempIndex] = typeAr[0];

				tempIndex = 0;
			}
			else
			{
				typeAr[tempIndex] = typeAr[tempIndex + 1];

				tempIndex++;
			}
		}
	}

	/**
	 * @fn	void ExtendableArray::expand(const int minIncrease = 1)
	 * @brief	Expands the array to accomodate a given minimum increase
	 *
	 * @param 	minIncrease	(Optional) The minimum increase. Supports larger increases (e.g. adding
	 * 						multiple instances at once )
	 */
	void expand(const int minIncrease = 1)
	{
		int newCapacity = capacity;
		do
		{
			newCapacity = newCapacity * 2;

		} while (newCapacity < currentSize + minIncrease);

		Type* tempAr = new Type[newCapacity];

		int tempIndex = frontIndex;
		for (int i = 0; i < capacity; i++)
		{
			tempAr[i] = typeAr[tempIndex];

			if (tempIndex == capacity - 1)
			{
				tempIndex = 0;
			}
			else
			{
				tempIndex++;
			}
		}

		Type* hold = typeAr;
		typeAr = tempAr;

		delete[] hold;
		hold = nullptr;
		tempAr = nullptr;

		frontIndex = 0;
		endIndex = currentSize - 1;

		capacity = newCapacity;
	}

	/**
	 * @fn	int ExtendableArray::adjustedIndex(const int givenIndex) const
	 * @brief	Given a normal index ( 0 .. capacity ) return the adjusted index to accomodate the
	 * 			circular array
	 *
	 * @exception	Except	Exception thrown when class is empty Except	Exception index is out of
	 * 						range.
	 *
	 * @param 	givenIndex	Zero-based index of the given.
	 * @returns	int the adjusted index.
	 */
	int adjustedIndex(const	int givenIndex) const
	{

		if (empty())
		{
			throw Except("Array is empty - nothing to return", EMPTY, 5);
		}
		else if (givenIndex < 0)
		{
			throw Except("Index out of range", OUT_OF_RANGE, 5);
		}
		else if (givenIndex > capacity - 1)
		{
			throw Except("Index out of range", OUT_OF_RANGE, 5);
		}
		else if (givenIndex > currentSize - 1)
		{
			throw Except("Index out of range", OUT_OF_RANGE, 5);
		}
		else
		{
			int realIndex;

			if ((frontIndex + givenIndex) > capacity - 1)
			{
				realIndex = frontIndex + givenIndex - capacity;
			}
			else
			{
				realIndex = frontIndex + givenIndex;
			}
			return realIndex;
		}

	}

	/**
	 * @fn	void ExtendableArray::destroy()
	 * @brief	Deletes the array
	 */
	void destroy()
	{
		delete[] typeAr;
	}

#endif // !Protected_Methods //--------------------------------------------------

public:

#ifndef Constructors_/_Deconstructors //--------------------------------------------------

	/**
	 * @fn	ExtendableArray::ExtendableArray<Type>(const int newCapacity = 8)
	 * @brief	Constructor
	 *
	 * 			@par	Creates empty array of either a specified capacity or uses the default value if
	 * 			not provided
	 *
	 * @tparam	Type	Template datatype.
	 * @param 	newCapacity	(Optional) The new capacity.
	 */
	ExtendableArray<Type>(const int newCapacity = 8)
	{
		frontIndex = -1;
		endIndex = 0;
		capacity = newCapacity;

		typeAr = new Type[capacity];
	}

	/**
	 * @fn	ExtendableArray::ExtendableArray<Type>(const ExtendableArray<Type>& otherExArray)
	 * @brief	Copy Constructor
	 *
	 * 			@par	Copies the values of the contents of another ExtendableArray into this one
	 *
	 * @tparam	Type	Template datatype.
	 * @param 	otherExArray	The other array.
	 */
	ExtendableArray<Type>(const ExtendableArray<Type>& otherExArray)
	{
		frontIndex = 0;
		endIndex = otherExArray.currentSize - 1;

		capacity = otherExArray.capacity;
		currentSize = otherExArray.currentSize;

		typeAr = new Type[capacity];

		int tempIndex = frontIndex;
		for (int i = 0; i < otherExArray.currentSize - 1; i++)
		{
			typeAr[i] = otherExArray.at[tempIndex];

			if (tempIndex == capacity - 1)
			{
				tempIndex = 0;
			}
			else
			{
				tempIndex++;
			}
		}
	}

	/**
	 * @fn	ExtendableArray::ExtendableArray<Type>(const Type* ptrArray, const int arSize)
	 * @brief	Constructor
	 *
	 * 			@par Copies the values of the contents of a given array into this one
	 *
	 * @tparam	Type	Template datatype.
	 * @param 	ptrArray	array to copy values from.
	 * @param 	arSize  	size of the given array.
	 */
	ExtendableArray<Type>(const Type* ptrArray, const int arSize)
	{
		frontIndex = 0;
		endIndex = arSize - 1;

		currentSize = arSize;
		capacity = currentSize;

		typeAr = new Type[capacity];

		int tempIndex = frontIndex;
		for (int i = 0; i < currentSize - 1; i++)
		{
			typeAr[i] = ptrArray[tempIndex];

			if (tempIndex == capacity - 1)
			{
				tempIndex = 0;
			}
			else
			{
				tempIndex++;
			}
		}
	}

	/**
	 * @fn	ExtendableArray::~ExtendableArray()
	 * @brief	Destructor
	 */
	~ExtendableArray()
	{
		delete[] typeAr;
	}

#endif // !Constructors_/_Deconstructors --------------------------------------------------

#ifndef Public_Methods //--------------------------------------------------

	/**
	 * @fn	void ExtendableArray::clearAll(const int newCapacity = capacity)
	 * @brief	Deletes current array and allocates a new one with a given capacity
	 *
	 * @param 	newCapacity	(Optional) The capacity for the new array Can be left out to use current
	 * 						capacity.
	 */
	void clearAll(const int newCapacity = capacity)
	{
		delete[] typeAr;

		frontIndex = -1;
		endIndex = 0;
		capacity = newCapacity;

		typeAr = new Type[capacity];
	}

	/**
	 * @fn	bool ExtendableArray::empty() const
	 * @brief	evaluates if the array is empty or not
	 *
	 * @returns	True / False.
	 */
	bool empty() const
	{
		return (currentSize == 0);
	}

	/**
	 * @fn	bool ExtendableArray::full() const
	 * @brief	evaluates if the array is full or not
	 *
	 * @returns	True / False.
	 */
	bool full() const
	{

		return (currentSize == capacity);
	}

	/**
	 * @fn	int ExtendableArray::size() const
	 * @brief	Gets the size
	 *
	 * @returns	An int.
	 */
	int size() const
	{
		return currentSize;
	}

	/**
	 * @fn	void ExtendableArray::insertAt(const int givenIndex, const Type& newItem)
	 * @brief	Inserts the value at the given index ( after adjustment )
	 *
	 * @exception	Except	Exception thrown when class is empty.
	 *
	 * @param 	givenIndex	Zero-based index of the array.
	 * @param 	newItem   	The new value to insert.
	 */
	void insertAt(const int givenIndex, const Type& newItem)
	{
		int adjIndex = adjustedIndex(givenIndex);

		if (full())
		{
			expand();
		}

		if (empty())
		{
			throw Except("Array is empty", EMPTY, 5);
		}
		else
		{
			if (adjIndex <= (currentSize - 1 / 2))
			{
				shiftLeft(givenIndex);
				adjIndex--;
			}
			else
			{
				shiftRight(givenIndex);
				adjIndex++;
			}

			typeAr[adjIndex] = newItem;

			currentSize++;

		}

	}

	/**
	 * @fn	template<class Type> void ExtendableArray::insertFront(const Type& newItem)
	 * @brief	Inserts the paramater value at the front of the array
	 *
	 * @tparam	Type	template datatype.
	 * @param 	newItem	The new item.
	 */
	template<class Type>
	void insertFront(const Type& newItem)
	{
		if (full())
		{
			expand();
		}

		if (empty())
		{
			frontIndex = 0;
			endIndex = 0;
		}
		else if (frontIndex == 0)
		{
			frontIndex = capacity - 1;
		}
		else
		{
			frontIndex--;
		}

		typeAr[frontIndex] = newItem;

		currentSize++;

	}

	/**
	 * @fn	template<class Type> void ExtendableArray::insertBack(const Type& newItem)
	 * @brief	Inserts the paramater value at the end of the array
	 *
	 * @tparam	Type	template datatype.
	 * @param 	newItem	The new item.
	 */
	template<class Type>
	void insertBack(const Type& newItem)
	{
		if (full())
		{
			expand();
		}

		if (empty())
		{
			frontIndex = 0;
			endIndex = 0;
		}
		else if (endIndex == capacity - 1)
		{
			endIndex = 0;
		}
		else
		{
			endIndex++;
		}

		typeAr[endIndex] = newItem;

		currentSize++;


	}

	/**
	 * @fn	void ExtendableArray::eraseFront()
	 * @brief	Erase the value at the front of the array
	 *
	 * 			@par 	Moves the frontIndex value to the right, excluding the value from the valid
	 * 			range in the array
	 *
	 * @exception	Except	Thrown when an except error condition occurs.
	 */
	void eraseFront()
	{
		if (empty())
		{
			throw Except("Array is empty", EMPTY, 5);
		}
		else
		{
			if (frontIndex == endIndex)
			{
				frontIndex = -1;
				endIndex = -1;
			}
			else
			{
				if (frontIndex == capacity - 1)
				{
					frontIndex = 0;
				}
				else
				{
					frontIndex++;
				}
			}

			currentSize--;

		}
	}

	/**
	 * @fn	void ExtendableArray::eraseBack()
	 * @brief	Erase the value at the end of the array
	 *
	 * 			@par	Moves the endIndex value to the right, excluding the value from the valid range
	 * 			in the array
	 *
	 * @exception	Except	Thrown when an except error condition occurs.
	 */
	void eraseBack()
	{
		if (empty())
		{
			throw Except("Array is empty", EMPTY, 5);
		}
		else
		{
			if (frontIndex == endIndex)
			{
				frontIndex = -1;
				endIndex = -1;
			}
			else if (endIndex == 0)
			{
				endIndex = capacity - 1;
			}
			else
			{
				endIndex--;
			}

			currentSize--;
		}
	}

	/**
	 * @fn	Type ExtendableArray::front() const
	 * @brief	Gets the value at the front of the array
	 *
	 * @exception	Except	Exception thrown when class is empty.
	 *
	 * @returns	&lt;Type&gt; the front index value.
	 */
	Type front() const
	{
		if (empty())
		{
			throw Except("Array is empty - nothing to return", EMPTY, 5);
		}
		else
		{
			return typeAr[frontIndex];
		}
	}

	/**
	 * @fn	Type ExtendableArray::back() const
	 * @brief	Gets the value at the end of the array
	 *
	 * @exception	Except	Exception thrown when class is empty.
	 *
	 * @returns	&lt;Type&gt; the end index value.
	 */
	Type back() const
	{
		if (empty())
		{
			throw Except("Array is empty - nothing to return", EMPTY, 5);
		}
		else
		{
			return typeAr[endIndex];
		}
	}

	/**
	 * @fn	Type& ExtendableArray::at(const int index) const
	 * @brief	Accesses the value at the given index ( after adjustment )
	 *
	 * @param 	index	Zero-based index of the array.
	 * @returns	&lt;Type&gt; the index value.
	 */
	Type& at(const int index) const
	{
		return typeAr[adjustedIndex(index)];
	}

	/**
	 * @fn	Type& ExtendableArray::operator[](const int index) const
	 * @brief	Array indexer operator ( adjusted inside )
	 *
	 * @param 	index	Zero-based index of the.
	 * @returns	&lt;Type&gt; the index value.
	 */
	Type& operator[](const int index) const
	{
		return typeAr[adjustedIndex(index)];
	}

	/**
	 * @fn	void ExtendableArray::printAll(std::ostream& output) const
	 * @brief	Print all values in the valid array range line by line
	 *
	 * @exception	Except	Exception thrown when class is empty.
	 *
	 * @param [in,out]	output	ostream object ( cout, file, etc. )
	 */
	void printAll(std::ostream& output) const
	{
		if (empty())
		{
			throw Except("Array is empty - nothing to print", EMPTY, 5);
		}
		else
		{
			int tempIndex = frontIndex;
			for (int i = 0; i < currentSize; i++)
			{
				output << typeAr[tempIndex] << '\n';

				if (tempIndex == capacity - 1)
				{
					tempIndex = 0;
				}
				else
				{
					tempIndex++;
				}
			}
		}
	}

	/**
	 * @fn	void ExtendableArray::PrintWithLabel(const std::string& label, std::ostream& output) const
	 * @brief	Allows a string to be passed to output before calling the printAll method
	 *
	 * @exception	Except	Exception thrown when class is empty.
	 *
	 * @param 		  	label 	The label.
	 * @param [in,out]	output	ostream object ( cout, file, etc. )
	 */
	void PrintWithLabel(const std::string& label, std::ostream& output) const
	{
		output << '\n' << label << '\n';

		if (empty())
		{
			throw Except("Array is empty - nothing to print", EMPTY, 5);
		}
		else
		{
			printAll(output);
			output << '\n';
		}
	}

#endif // !Public_Methods //--------------------------------------------------

};
#endif // !_EXTENDABLEARRAY_H_ 
//-----------------------------------------------------------------------------------------
