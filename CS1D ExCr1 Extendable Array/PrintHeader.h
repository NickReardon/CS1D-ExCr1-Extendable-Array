/*/*****************************************************************************
 * AUTHOR 	  		: Nick Reardon
 * Extra Credit #1	: Extendable Array
 * CLASS			: CS1D
 * SECTION			: MW - 2:30p
 * DUE DATE			: 02 / 12 / 20
 *****************************************************************************/
#ifndef _PRINTHEADER_H_
#define _PRINTHEADER_H_

#include <iostream>
#include <iomanip>
#include <ostream>
#include <string>
#include <fstream>

 /*****************************************************************************/


const std::string PROGRAMMER = "Nick Reardon";
const std::string SECTION = "MW - 2:30p";
const std::string CLASS = "CS1D";
const int PROGRAM_NUM = 1;
const std::string PROGRAM_NAME = "Extendable Array";
const std::string PROGRAM_TYPE = "Extra Credit";

/*****************************************************************************
* PrintHeader
* ---------------------------------------------------------------------------
* This function will output a class header through the use of ostream.
* It also will output the program description
* Constants must be filled out to specification for each program
* ----------------------------------------------------------------------------
*  Call
* ------
* The function call requires 2 parameters. The following example uses an
* output file in the ostream parameter, and a text file name in the string
* parameter. Ex:
*
* 		PrintHeader (oFile, "input.txt");
*
* --------------------------------------------------------------------------- 
*  Output
* --------
* 	The function will output as follows. 
* 	 - Header on top   
* 	 - Center justified assignment type, program number, title  
* 	 - Prompt text from given filename    
* 	 
* ---------
* 	 Ex.
*
* ********************************************************************
* * PROGRAMMED BY   : Nick Reardon
* * CLASS           : CS1D
* * SECTION         : MW - 2:30p
* * Extra Credit #1 : Extendable Array
* ********************************************************************
*
*                       Extra Credit #1 - Extendable Array
*
*    Implement the vector ADT by means of an extendable array
* (expands dynamically) used in a circular fashion, so that
* insertions and deletions at the beginning and end run in constant
* time. Print the circular array before and after each insertion and
* deletion. Insertions and deletion that are not at the beginning or
* end will run in O(n) time. Test the vector ADT methods (inserts,
* deletes, size, isEmpty, etc.). The initial array size is 4. Print out
* the index (rank) of the array with the corresponding value.
*
* Do not use the <vector> STL.
*     Use the following data:
*
*     Insert 14, 5, 4, 1, 21, 33, 12, 8
*     Delete 14
*     Delete 1
*     Insert 9 at the front of the vector
*     Insert 7 after 33
*     Insert 44 at the end of the vector
*
* Due February 12
*
****************************************************************************
*
* ---------------------------------------------------------------------------
* CONSTANTS
* ---------------------------------------------------------------------------
* OUTPUT - USED FOR CLASS HEADING
* ---------------------------------------------------------------------------
* PROGRAMMER 		: Name(s) of programmer(s) 	- Nick Reardon
* SECTION 	  		: Class times 				- MW - 7:30p
* CLASS 	  		: Class label 				- CS1B
* PROGRAM_NUM		: # of the program
* PROGRAM_NAME		: Title of the program
* PROGRAM_TYPE		: Type of program - Lab, Assignment, etc.
* 
*****************************************************************************/




/**
 * @fn	void PrintHeader(std::ostream &output, std::string inputText)
 * @brief	This function will output a class header through the use of ostream. It also will
 * 			output the program description
 *
 * @param [in,out]	output   	ostream output.
 * @param 		  	inputText	file name of the prompt text file.
 */
void PrintHeader(std::ostream &output, std::string inputText)
{
	std::string typeNum = PROGRAM_TYPE + " #" + std::to_string(PROGRAM_NUM);

	output << std::left
		<< std::string(76, '*')
		<< std::endl
		<< "* PROGRAMMED BY   : " << PROGRAMMER << std::endl
		<< "* " << std::setw(16) << "CLASS" << ": " << CLASS << std::endl
		<< "* " << std::setw(16) << "SECTION" << ": " << SECTION << std::endl
		<< "* " << std::setw(16) << typeNum << ": " << PROGRAM_NAME << std::endl
		<< std::string(76, '*')
		<< std::endl << std::endl
		<< std::string(((76 - typeNum.length() - PROGRAM_NAME.length() ) / 2), ' ')
		<< typeNum + " - " + PROGRAM_NAME
		<< std::endl << std::endl
		<< std::ifstream(inputText).rdbuf()
		<< std::endl
		<< std::string(76, '*')
		<< std::endl << std::endl;

}   

#endif //_PRINTHEADER_H_