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
	 * HEADER OUTPUT.
	 */
	PrintHeader(cout, "Prompt.txt");

	/********************************************************************/

	cout << "Initializing int ExtendableArray vector with capacity of 4" << endl << endl;
	ExtendableArray<int> arr(4);
	try
	{
		cout << endl << "Calling print method to show the vector is empty" << endl;

		arr.PrintRealArray("Current vector", cout);
	}
	catch (Except err)
	{
		err.outputError(cout);
	}


	//----------------------------------------------------------------


	cout << endl << "Inserting 14, 5, 4, 1 into vector using insertBack()" << endl;

	arr.insertBack(14);
	arr.PrintRealArray("Current vector", cout);
	arr.oneLinePrintAdjusted(cout, "Useable order: ");
	arr.insertBack(5);
	arr.PrintRealArray("Current vector", cout);
	arr.oneLinePrintAdjusted(cout, "Useable order: ");

	arr.insertBack(4);
	arr.PrintRealArray("Current vector", cout);
	arr.oneLinePrintAdjusted(cout, "Useable order: ");

	arr.insertBack(1);
	arr.PrintRealArray("Current vector", cout);
	arr.oneLinePrintAdjusted(cout, "Useable order: ");


	//----------------------------------------------------------------

	
	cout << endl << endl << "Inserting 21 into vector using insertBack()" << endl;
	cout << endl << "Insertion would exceed capacity, so protected expand() " << endl
		<< "method is called to double the vector's capacity " << endl;

	arr.insertBack(21);
	arr.PrintRealArray("Current vector", cout);
	arr.oneLinePrintAdjusted(cout, "Useable order: ");

	cout << endl << "Inserting 33, 12, 8 intop vector using insertBack()" << endl;
	arr.oneLinePrintAdjusted(cout, "Useable order: ");

	arr.insertBack(33);
	arr.PrintRealArray("Current vector", cout);
	arr.oneLinePrintAdjusted(cout, "Useable order: ");

	arr.insertBack(12);
	arr.PrintRealArray("Current vector", cout);
	arr.oneLinePrintAdjusted(cout, "Useable order: ");

	arr.insertBack(8);
	arr.PrintRealArray("Current vector", cout);
	arr.oneLinePrintAdjusted(cout, "Useable order: ");


	//----------------------------------------------------------------

	cout << endl << endl << "removing 14, using eraseFront()" << endl;
	arr.eraseFront();
	arr.PrintRealArray("Current vector", cout);
	arr.oneLinePrintAdjusted(cout, "Useable order: ");

	//----------------------------------------------------------------


	cout << endl << endl << "removing 1, using eraseAt()" << endl;
	arr.eraseAt(2);
	arr.PrintRealArray("Current vector", cout);
	arr.oneLinePrintAdjusted(cout, "Useable order: ");

	//----------------------------------------------------------------

	//arr.insertFront(9);
	
	//----------------------------------------------------------------


	cout << endl << endl << "Inserting 7 after 33 into vector using insertAt()" << endl;
	arr.insertAt(5, 7);
	arr.PrintRealArray("Current vector", cout);
	arr.oneLinePrintAdjusted(cout, "Useable order: ");

	//----------------------------------------------------------------

	cout << endl << endl << "Inserting 44 into vector using insertBack()" << endl;
	arr.insertBack(44);
	arr.PrintRealArray("Current vector", cout);
	arr.oneLinePrintAdjusted(cout, "Useable order: ");



	system("pause");
	return 0;
}
