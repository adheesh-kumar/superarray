#include <iostream>							//including iostream
#include <string>							//including string
#include <time.h>							//including time
#include "SuperArray.h"						//including our Super Array file

using namespace std;						//using the standard namespace

//CONSTANTS

const int DEFAULT_SIZE = 10;				//the default size of the array

const int MAX_RANGE = 10;					//the max value of the integers
const int MIN_RANGE = 1;					//the min value of the integers

const int TEST_NUM = 0;						//the number used for testing
const int TEST_INDEX = 5;					//the test number index
const int OUT_OF_BOUNDS_INDEX = 25;			//index used for error checking

const string CURRENT = "Current";			//string used for stating the current stats
const string PREVIOUS = "Previous";			//string used for stating the previous stats

//variables

bool finishSwitch = true;					//bool to represent the before and after of a test

/*
this templated function of type A prints statistics of a super array
@param1 the super array
@param2 a bool to represent if its before/after, current/previous
*/
template <typename A>
void printStats(const SuperArray<A>& test, bool& finishSwitch)
{
	//declaring a string to state if the stats are previous or current
	string previousOrCurrent = "";

	//checking if there has been changes to the test
	if (finishSwitch == true)
	{
		//setting it equal to the current
		previousOrCurrent = CURRENT;
	}
	//checking if there has been no changes to the test
	if(finishSwitch == false)
	{
		//setting it equal to previous
		previousOrCurrent = PREVIOUS;
	}

	//printing out stats
	cout << previousOrCurrent << " Statistics:" << endl << endl;
	cout << "-Size: " << test.getSize() << endl;
	cout << "-Print: ";
	test.print();
	cout << endl;

	//checking if changes were true
	if (finishSwitch == true)
	{
		//pausing the system, clearing the screen
		system("pause");
		system("cls");

		//switching it to previous
		finishSwitch = false;
	}
	//incase there were no changes
	else
	{
		//making it so next time this function is called is when changes have occured
		finishSwitch = true;
	}

}

//entry point to the program
int main()
{
	//seeding random number generator
	srand((unsigned int)time(NULL));

	//printing an intro
	cout << "Super Array Class Test Report" << endl;
	cout << "=============================" << endl << endl;

	cout << "The following tests will be conducted on an array of integers" << endl;
	cout << "-------------------------------------------------------------" << endl << endl;

	//pausing the screen, clearing the screen
	system("pause");
	system("cls");

	//declaring a test superarray of type int
	SuperArray<int> test;

	/******************************************
	              OPERATOR [] TEST
	******************************************/
	
	//printing an intro
	cout << "Test #1" << endl;
	cout << "-------" << endl << endl;

	//printing a description
	cout << "Generating an array of integers of size: " << DEFAULT_SIZE << " with numbers from " << MIN_RANGE << "-" << MAX_RANGE << endl;
	cout << "This is done using SuperArray's operator member function([])" << endl << endl;

	//using a for loop to assign random numbers from 1 - 10 to the test array
	for (int i = 0; i < DEFAULT_SIZE; i++)
	{
		//generating a random number
		int randmonNumber = rand() % MAX_RANGE + MIN_RANGE;
		
		//assigning it to an index
		test[i] = randmonNumber;
	}

	//printing stats
	printStats(test, finishSwitch);

	/******************************************
	               INSERT TEST
	******************************************/

	//printing intro
	cout << "Test #2" << endl;
	cout << "-------" << endl << endl;

	//printing description
	cout << "Inserting a test number: " << TEST_NUM << " at index: " << TEST_INDEX << endl;
	cout << "This is done using SuperArray's insert member function(insert(index, value))" << endl << endl;

	//printing previous stats
	printStats(test, finishSwitch);

	//inserting value at index
	test.insert(TEST_INDEX, TEST_NUM);

	//printing new current stats
	printStats(test, finishSwitch);


	/******************************************
	         PUSHFRONT PUSHBACK TEST
	******************************************/
	
	//prinitng intro
	cout << "Test #3" << endl;
	cout << "-------" << endl << endl;

	//printing description
	cout << "Inserting a test number: " << TEST_NUM << " at the first and last index" << endl;
	cout << "This is done using SuperArray's pushFront and pushBack member functions(pushFront(value), pushBack(value))" << endl << endl;

	//printing previous stats
	printStats(test, finishSwitch);

	//inserting value at begining and end
	test.pushFront(TEST_NUM);
	test.pushBack(TEST_NUM);

	//printing3 new current stats
	printStats(test, finishSwitch);

	
	/******************************************
			   POPFRONT POPBACK TEST
	******************************************/

	//printing intro
	cout << "Test #4" << endl;
	cout << "-------" << endl << endl;

	//printing description
	cout << "Removing a value at the first and last index" << endl;
	cout << "This is done using SuperArray's popFront and popBack member functions(popFront(), popBack())" << endl << endl;

	//printing previous stats
	printStats(test, finishSwitch);

	//printing function results
	cout << "Removed: " << test.popFront() << endl;
	cout << "Removed: " << test.popBack() << endl << endl;

	//printing new current stats
	printStats(test, finishSwitch);

	/******************************************
	             REMOVE TEST
	******************************************/
	
	//printing intro
	cout << "Test #5" << endl;
	cout << "-------" << endl << endl;

	//description
	cout << "Removing a value at index: " << TEST_INDEX << endl;
	cout << "This is done using SuperArray's remove member function(remove(index))" << endl << endl;

	//printing previous stats
	printStats(test, finishSwitch);

	//printing results of remove function
	cout << "Removed: " << test.remove(TEST_INDEX) << endl << endl;

	//printing new current stats
	printStats(test, finishSwitch);


	/******************************************
				    SHUFFLE TEST
	******************************************/

	//printing intro
	cout << "Test #6" << endl;
	cout << "-------" << endl << endl;

	//printing description
	cout << "Shuffling the elements of the array" << endl;
	cout << "This is done using SuperArray's shuffle member function(shuffle())" << endl << endl;

	//printing previous stats
	printStats(test, finishSwitch);

	//shuffling the elements of the array
	test.shuffle();

	//printing new current stats
	printStats(test, finishSwitch);


	/******************************************
					SORT TEST
	******************************************/
	
	//printing intro
	cout << "Test #7" << endl;
	cout << "-------" << endl << endl;

	//printing description
	cout << "Sorting the elements of the array in accending order" << endl;
	cout << "This is done using SuperArray's sort member function(sort())" << endl << endl;

	//printing previous stats
	printStats(test, finishSwitch);

	//sorting the elements of the array
	test.sort();

	//printing new current stats
	printStats(test, finishSwitch);


	/******************************************
				PRINT SIZE TEST
	******************************************/

	//printing intro
	cout << "Test #8" << endl;
	cout << "-------" << endl << endl;

	//printing description
	cout << "Print and Size" << endl;
	cout << "This is done using SuperArray's print and getSize member function(print(), getSize())" << endl << endl;

	//printing size and elements of the array
	cout << "-Size: " << test.getSize() << endl;
	cout << "-Print: ";
	test.print();
	cout << endl;
	
	//pausing the screen, clearing the screen
	system("pause");
	system("cls");

	/******************************************
				  ERROR TESTING
	******************************************/

	//printing intro
	cout << "Test #9" << endl;
	cout << "-------" << endl << endl;

	//printing description
	cout << "This test checks for runtime errors that may occur without proper indexes in the insert and remove function" << endl;
	cout << "This is taken care of by SuperArray's insert and remove member function(insert(), remove())" << endl << endl;
	cout << "To test this function use an out of bounds index: " << OUT_OF_BOUNDS_INDEX << endl;

	//pausing the screen, clearing the screen
	system("pause");
	system("cls");

	//printing intro
	cout << "Test #9" << endl;
	cout << "-------" << endl << endl;
	
	//starting with the insert function
	cout << "Insert Function - index used: " << OUT_OF_BOUNDS_INDEX << endl;

	//printing previous stats
	printStats(test, finishSwitch);

	//calling insert at invalid index
	test.insert(OUT_OF_BOUNDS_INDEX, TEST_NUM);
	cout << endl;

	//printing out stats
	printStats(test, finishSwitch);

	//clearing the screen
	system("cls");

	//printing intro
	cout << "Test #9" << endl;
	cout << "-------" << endl << endl;

	//moving on to the remove function
	cout << "Remove Function - index used: " << OUT_OF_BOUNDS_INDEX << endl;

	//printing previous stats
	printStats(test, finishSwitch);

	//calling remove at invalid index
	test.remove(OUT_OF_BOUNDS_INDEX);
	cout << endl;

	//printing new current stats
	printStats(test, finishSwitch);

	/******************************************
	              COPY TESTING
	******************************************/

	//printing intro
	cout << "Test #10" << endl;
	cout << "-------" << endl << endl;

	//printing description
	cout << "This test checks the, constructor, copy constructor, and destructor" << endl;
	cout << "This is done using Super Array's copy constructor by declaring another super array setting it equal to the original" << endl << endl;

	//calling default constructor
	SuperArray<int> defaultConstructorTest;
	
	//printing default stats
	cout << "Stats of default constructor test" << endl;
	cout << "-Size: " << defaultConstructorTest.getSize() << endl;
	cout << "-Print: ";
	defaultConstructorTest.print();

	cout << endl;

	//printing description
	cout << "Setting copy constructor test to the default constructor test inside scope\n which will also destroy the copied test after leaving" << endl << endl;
	
	//using scope to invoke destrouctor after leaving
	{
		//calling cop constructor
		SuperArray<int> copyConstructorTest = defaultConstructorTest;
		
		//printing copied stats
		cout << "Stats of copy constructor test" << endl;
		cout << "-Size: " << defaultConstructorTest.getSize() << endl;
		cout << "-Print: ";
		defaultConstructorTest.print();
	}

	//pausing the screen, clearing the screen
	system("pause");
	system("cls");

	//printing conclusion
	cout << "Those are all the tests, enjoy the SuperArray!!!" << endl;

	//pausing the screen
	system("pause");
	//returning 0
	return 0;
}