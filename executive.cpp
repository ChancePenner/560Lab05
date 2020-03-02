#include "executive.h"
#include <string>
#include <iostream>
#include "HashTable.h"
#include <limits>
#include <fstream>
#include <cctype>
#include <stdlib.h> //srand, rand
#include <time.h>

void Executive::run() 																		//handles call to other class and functions
	{
		clock_t startTime;
		clock_t endTime;

		int random_number;
		int tableSize = 1000003;

		int seed1;
		int seed2;
		int seed3;
		int seed4;
		int seed5;

		srand(time(NULL));




		random_number = rand()%10+1;
		HashTable table1;
		HashTable table2;
		HashTable table3;
		HashTable table4;
		HashTable table5;


		startTime = clock();
		std::cout << random_number << "\n";
		endTime = clock() - startTime;
		std::cout << "clock: " << endTime << "\n";

		for(int i=0;i<tableSize*.1;i++)
		{
			random_number = rand()%5000000+1;

			table1.QuadraticAddUser(std::to_string(random_number));
		}


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

	}
