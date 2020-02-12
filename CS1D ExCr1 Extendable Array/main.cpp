/*****************************************************************************
 * AUTHOR 	  		: Nick Reardon
 * Extra Credit #1	: Extendable Array
 * CLASS			: CS1D
 * SECTION			: MW - 2:30p
 * DUE DATE			: 02 / 12 / 20
 *****************************************************************************/
#include "main.h"

using std::cout; using std::endl;


int main()
{

	/*
	 * HEADER OUTPUT
	 */
	PrintHeader(cout, "Prompt.txt");

	/********************************************************************/

	ExtendableArray<int> arr;

	arr.insertBack(14);
	arr.insertBack(5);
	arr.insertBack(4);
	arr.insertBack(1);
	arr.insertBack(21);
	arr.insertBack(33);
	arr.insertBack(12);
	arr.insertBack(8);


	arr.PrintWithLabel("",cout);


	arr.eraseFront();

	arr.PrintWithLabel("", cout);

	arr.eraseAt(2);

	arr.PrintWithLabel("", cout);

	arr.insertFront(9);

	arr.PrintWithLabel("", cout);

	arr.insertAt(5, 7);

	arr.PrintWithLabel("", cout);

	arr.insertBack(44);


	arr.PrintWithLabel("", cout);

	system("pause");
	return 0;
}
