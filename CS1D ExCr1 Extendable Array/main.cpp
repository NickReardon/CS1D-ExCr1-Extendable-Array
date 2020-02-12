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


	for (int i = 0; i < 21; i++)
	{
		arr.insertBack(i);
	}

	arr.insertAt(15, 100000);

	cout << endl;
	arr.printAll(cout);

	system("pause");
	return 0;
}
