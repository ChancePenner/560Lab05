#include "executive.h"
#include <string>
#include <iostream>
#include "HashTable.h"
#include <limits>
#include <fstream>
#include <cctype>
#include <stdlib.h> //srand, rand
#include <time.h>
#include "math.h"

void Executive::run() 																		//handles call to other class and functions
	{
		clock_t QuadStartTime = 0;
		clock_t QuadEndTime = 0;

		clock_t DoubleStartTime = 0;
		clock_t DoubleEndTime = 0;

		int random_number;
		std::string randNumString;
		int tableSize = 1000003;

		int seed1;
		// int seed2;
		// int seed3;
		// int seed4;
		// int seed5;

		srand(time(NULL));

		random_number = rand()%10+1;
		HashTable table1;
		HashTable table2;
		HashTable table3;
		HashTable table4;
		HashTable table5;

		int foundQuad1 = 0;
		int foundQuad2 = 0;
		int foundQuad3 = 0;
		int foundQuad4 = 0;
		int foundQuad5 = 0;

		int foundDouble1 = 0;
		int foundDouble2 = 0;
		int foundDouble3 = 0;
		int foundDouble4 = 0;
		int foundDouble5 = 0;


		QuadStartTime = clock();
		std::cout << "clock: " << QuadEndTime << "\n";

		// for(int i=0;i<tableSize*.1;i++)
		// {
		// 	random_number = rand()%5000000+1;
		//
		// 	// table1.QuadraticAddUser(std::to_string(random_number));
		// }

		for(int i=0;i<floor(tableSize*.1);i++)
		{
			random_number = rand()%5000000+1;

			randNumString = std::to_string(random_number);

			QuadStartTime = clock();
			table1.QuadraticAddUser(randNumString);
			QuadEndTime = QuadEndTime + (clock() - QuadStartTime);

			DoubleStartTime = clock();
			table1.DoubleAddUser(randNumString);
			DoubleEndTime = DoubleEndTime + (clock() - DoubleStartTime);

		}
		std::cout << "total Quadratic time: " << QuadEndTime << "\n";
		std::cout << "total Double time: " << DoubleEndTime << "\n";

		std::cout << "success Quadratic: " << table1.getNumElementsQuadratic() << "\n";
		std::cout << "success double: " << table1.getNumElementsDouble() << "\n";

		for(int i=0;i<floor(tableSize*.01);i++)
		{
			random_number = rand()%5000000+1;
			randNumString = std::to_string(random_number);
			if(table1.findQuad(randNumString))
			{
				foundQuad1++;
			}
			if(table1.findDouble(randNumString))
			{
				foundDouble1++;
			}

		}

		std::cout << "Quadratic found: " << foundQuad1 << "\n";
		std::cout << "Double found: " << foundDouble1 << "\n\n";


		srand(time(NULL));




		for(int i=0;i<floor(tableSize*.2);i++)
		{
			random_number = rand()%5000000+1;

			randNumString = std::to_string(random_number);

			QuadStartTime = clock();
			table2.QuadraticAddUser(randNumString);
			QuadEndTime = QuadEndTime + (clock() - QuadStartTime);

			DoubleStartTime = clock();
			table2.DoubleAddUser(randNumString);
			DoubleEndTime = DoubleEndTime + (clock() - DoubleStartTime);

		}
		std::cout << "total Quadratic time: " << QuadEndTime << "\n";
		std::cout << "total Double time: " << DoubleEndTime << "\n";

		std::cout << "success Quadratic: " << table2.getNumElementsQuadratic() << "\n";
		std::cout << "success double: " << table2.getNumElementsDouble() << "\n";


		for(int i=0;i<floor(tableSize*.02);i++)
		{
			random_number = rand()%5000000+1;
			randNumString = std::to_string(random_number);
			if(table2.findQuad(randNumString))
			{
				foundQuad2++;
			}
			if(table2.findDouble(randNumString))
			{
				foundDouble2++;
			}

		}

		std::cout << "Quadratic found: " << foundQuad2 << "\n";
		std::cout << "Double found: " << foundDouble2 << "\n\n";


		srand(time(NULL));




		for(int i=0;i<floor(tableSize*.3);i++)
		{
			random_number = rand()%5000000+1;

			randNumString = std::to_string(random_number);

			QuadStartTime = clock();
			table3.QuadraticAddUser(randNumString);
			QuadEndTime = QuadEndTime + (clock() - QuadStartTime);

			DoubleStartTime = clock();
			table3.DoubleAddUser(randNumString);
			DoubleEndTime = DoubleEndTime + (clock() - DoubleStartTime);

		}
		std::cout << "total Quadratic time: " << QuadEndTime << "\n";
		std::cout << "total Double time: " << DoubleEndTime << "\n";

		std::cout << "success Quadratic: " << table3.getNumElementsQuadratic() << "\n";
		std::cout << "success double: " << table3.getNumElementsDouble() << "\n";


		for(int i=0;i<floor(tableSize*.03);i++)
		{
			random_number = rand()%5000000+1;
			randNumString = std::to_string(random_number);
			if(table3.findQuad(randNumString))
			{
				foundQuad3++;
			}
			if(table3.findDouble(randNumString))
			{
				foundDouble3++;
			}

		}

		std::cout << "Quadratic found: " << foundQuad3 << "\n";
		std::cout << "Double found: " << foundDouble3 << "\n\n";

		srand(time(NULL));



		for(int i=0;i<floor(tableSize*.4);i++)
		{
			random_number = rand()%5000000+1;

			randNumString = std::to_string(random_number);

			QuadStartTime = clock();
			table4.QuadraticAddUser(randNumString);
			QuadEndTime = QuadEndTime + (clock() - QuadStartTime);

			DoubleStartTime = clock();
			table4.DoubleAddUser(randNumString);
			DoubleEndTime = DoubleEndTime + (clock() - DoubleStartTime);

		}
		std::cout << "total Quadratic time: " << QuadEndTime << "\n";
		std::cout << "total Double time: " << DoubleEndTime << "\n";

		std::cout << "success Quadratic: " << table4.getNumElementsQuadratic() << "\n";
		std::cout << "success double: " << table4.getNumElementsDouble() << "\n";


		for(int i=0;i<floor(tableSize*.04);i++)
		{
			random_number = rand()%5000000+1;
			randNumString = std::to_string(random_number);
			if(table4.findQuad(randNumString))
			{
				foundQuad4++;
			}
			if(table4.findDouble(randNumString))
			{
				foundDouble4++;
			}

		}

		std::cout << "Quadratic found: " << foundQuad4 << "\n";
		std::cout << "Double found: " << foundDouble4 << "\n\n";

		srand(time(NULL));




		for(int i=0;i<floor(tableSize*.5);i++)
		{
			random_number = rand()%5000000+1;

			randNumString = std::to_string(random_number);

			QuadStartTime = clock();
			table5.QuadraticAddUser(randNumString);
			QuadEndTime = QuadEndTime + (clock() - QuadStartTime);

			DoubleStartTime = clock();
			table5.DoubleAddUser(randNumString);
			DoubleEndTime = DoubleEndTime + (clock() - DoubleStartTime);

		}
		std::cout << "total Quadratic time: " << QuadEndTime << "\n";
		std::cout << "total Double time: " << DoubleEndTime << "\n";

		std::cout << "success Quadratic: " << table5.getNumElementsQuadratic() << "\n";
		std::cout << "success double: " << table5.getNumElementsDouble() << "\n";


		for(int i=0;i<floor(tableSize*.05);i++)
		{
			random_number = rand()%5000000+1;
			randNumString = std::to_string(random_number);
			if(table5.findQuad(randNumString))
			{
				foundQuad5++;
			}
			if(table5.findDouble(randNumString))
			{
				foundDouble5++;
			}

		}

		std::cout << "Quadratic found: " << foundQuad5 << "\n";
		std::cout << "Double found: " << foundDouble5 << "\n\n";

		//
		// int userChoice = 0; 																//used to select menu option
		// std::string nodeName = ""; 																	//used to get the node value user wishes to input
		// std::string nodePassword = "";
		// // std::string skip = "";
		//
		// std::ifstream inFile; 															//create a variable of type std::ifstream. It will enable reading from files.
		// inFile.open(m_fileName);														//opens the file
		//
		//
		// if(inFile.is_open())																//Check if file is openn
		// {
		// 	std::cin.clear(); 														// unset failbit
		// 	std::cout.setstate(std::ios_base::failbit);	//to disable cout used by LinearAddUser() and QuadraticAddUser()
		//
		//
		//
		// 		while(inFile >> nodeName)												//inFile's the command and loops until reaching the end of the sample file
		// 		{
		// 				if(nodeName.at(nodeName.length()-1)==',')
		// 				{
		// 					nodeName.pop_back();	//removes the ',' that gets inFiled
		// 				}
		//
		// 				inFile >> nodePassword;
		// 				// inFile >> skip;	//ignore the ','
		//
		// 			myHashTable.LinearAddUser(nodeName, nodePassword);
		// 			try
		// 			{
		// 				myHashTable.QuadraticAddUser(nodeName, nodePassword);
		// 			}
		// 			catch (std::runtime_error & rte)
		// 			{
		// 				std::cout << rte.what();
		// 			}
		// 		}
		// 		inFile.close();
		// 	std::cin.clear();
		// 	std::cout.clear();	//to re-enable cout statements
		// }
		//
		// while(userChoice != 6)
		// {
		// 	std::cout << "\n";
		//
		// 	std::cout << "Choose one operation from the options below:\n\n";
		// 	std::cout << "1.  Add User\n";
		// 	std::cout << "2.  Remove User\n";
		// 	std::cout << "3.  Forgot Password\n";
		// 	std::cout << "4.  Forgot Username\n";
		// 	std::cout << "5.  Print Users\n";
		// 	std::cout << "6.  Exit\n";
		//
		// 	std::cout << ">";
		// 	std::cin >> userChoice;
		//
		//
		// 	while ( std::cin.fail() )
		// 		{
		// 			std::cin.clear(); 														// unset failbit
		// 																					// skip bad input up to the next newline
		// 			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		// 			std::cout << "\n";
		//
		// 			std::cout << "Choose one operation from the options below:\n\n";
		// 			std::cout << "1.  Add User\n";
		// 			std::cout << "2.  Remove User\n";
		// 			std::cout << "3.  Forgot Password\n";
		// 			std::cout << "4.  Forgot Username\n";
		// 			std::cout << "5.  Print Users\n";
		// 			std::cout << "6.  Exit\n";
		//
		// 			std::cout << ">";
		// 			std::cin >> userChoice;
		//
		// 		}
		// 			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		//
		//
		// 	if(userChoice == 1)
		// 	{
		// 		std::cout << "Enter user details to be added:\n";
		// 		std::cin >> nodeName;
		// 		if(nodeName.at(nodeName.length()-1)==':')
		// 		{
		// 			nodeName.pop_back();	//removes the ':' that gets inFiled
		// 		}
		// 		std::cin >> nodePassword;
		//
		// 		while ( std::cin.fail() )
		// 		{
		//
		// 			std::cin.clear(); 													// unset failbit
		// 																				// skip bad input up to the next newline
		// 			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		// 			std::cout << "Please enter a valid record: ";
		//
		// 			std::cin >> nodeName;   										//gets the nodeValue from the user
		// 			std::cin >> nodePassword;
		// 		}
		// 		myHashTable.LinearAddUser(nodeName, nodePassword);
		// 		myHashTable.QuadraticAddUser(nodeName, nodePassword);
		//
		// 	}
		// 	else if(userChoice == 2)
		// 	{
		// 		std::cout << "Enter user and password to be removed:\n";
		//
		// 		std::cin >> nodeName;
		// 		std::cin >> nodePassword;
		//
		// 		while ( std::cin.fail() )
		// 		{
		//
		// 			std::cin.clear(); 													// unset failbit
		// 																				// skip bad input up to the next newline
		// 			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		// 			std::cout << "Please enter a valid record: ";
		//
		// 			std::cin >> nodeName;   										//gets the nodeValue from the user
		// 			std::cin >> nodePassword;
		// 		}
		// 		myHashTable.RemoveUserLinear(nodeName, nodePassword);
		// 		myHashTable.RemoveUserQuadratic(nodeName, nodePassword);
		//
		// 	}
		// 	else if(userChoice == 3)
		// 	{
		// 		std::cout << "Enter username:\n";
		//
		// 		std::cin >> nodeName;
		//
		// 		while ( std::cin.fail() )
		// 		{
		//
		// 			std::cin.clear(); 													// unset failbit
		// 																				// skip bad input up to the next newline
		// 			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		// 			std::cout << "Please enter a valid record: ";
		//
		// 			std::cin >> nodeName;   										//gets the nodeValue from the user
		// 			std::cin >> nodePassword;
		// 		}
		// 		myHashTable.ForgotPasswordLinear(nodeName);
		// 		myHashTable.ForgotPasswordQuadratic(nodeName);
		//
		// 	}
		// 	else if(userChoice == 4)
		// 	{
		// 		std::cout << "Enter Password:\n";
		// 		std::cin >> nodePassword;
		//
		// 			while ( std::cin.fail() )
		// 		{
		// 			std::cin.clear(); 													// unset failbit
		// 																				// skip bad input up to the next newline
		// 			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		// 			std::cout << "Please enter a valid number: ";
		//
		// 			std::cin >> nodePassword;   										//gets the nodeValue from the user
		// 		}
		// 		myHashTable.ForgotUsernameLinear(nodePassword);
		// 		myHashTable.ForgotUsernameQuadratic(nodePassword);
		//
		// 	}
		// 	else if(userChoice == 5)
		// 	{
		// 		std::cout << "\nLinear Probing:\n";
		// 		myHashTable.PrintListLinear();
		// 		std::cout << "\nQuadratic Probing:\n";
		// 		myHashTable.PrintListQuadratic();
		//
		// 		std::cout << "\n";
		// 	}
		// 	else if(userChoice == 6)
		// 	{
		// 		std::cout << "Program execution completed!\n";
		// 	}
		// 	else
		// 	{
		// 		std::cout << "Invalid choice! Please try again.\n";
		// 	}
		//
		// }
		return;
	}
