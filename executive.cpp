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

		float quadTime1 = 0;
		float quadTime2 = 0;
		float quadTime3 = 0;
		float quadTime4 = 0;
		float quadTime5 = 0;

		float doubleTime1 = 0;
		float doubleTime2 = 0;
		float doubleTime3 = 0;
		float doubleTime4 = 0;
		float doubleTime5 = 0;

		int random_number;
		std::string randNumString;
		int tableSize = 1000003;

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

		int notFoundQuad1 = 0;
		int notFoundQuad2 = 0;
		int notFoundQuad3 = 0;
		int notFoundQuad4 = 0;
		int notFoundQuad5 = 0;

		int foundDouble1 = 0;
		int foundDouble2 = 0;
		int foundDouble3 = 0;
		int foundDouble4 = 0;
		int foundDouble5 = 0;

		int notFoundDouble1 = 0;
		int notFoundDouble2 = 0;
		int notFoundDouble3 = 0;
		int notFoundDouble4 = 0;
		int notFoundDouble5 = 0;

		std::cout << "Calculating...\n\n";

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
		quadTime1 = float(QuadEndTime)/CLOCKS_PER_SEC;
		doubleTime1 = float(DoubleEndTime)/CLOCKS_PER_SEC;

		// std::cout << "total Quadratic time: " << float(QuadEndTime)/CLOCKS_PER_SEC << "\n";
		// std::cout << "total Double time: " << float(DoubleEndTime)/CLOCKS_PER_SEC << "\n";
		//
		//
		// std::cout << "success Quadratic: " << table1.getNumElementsQuadratic() << "\n";
		// std::cout << "success double: " << table1.getNumElementsDouble() << "\n";

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

		notFoundQuad1 = floor(tableSize*.01)-foundQuad1;
		notFoundDouble1 = floor(tableSize*.01)-foundDouble1;

		// std::cout << "Quadratic found: " << foundQuad1 << "\n";
		// std::cout << "Quadratic not found: " << floor(tableSize*.01)-foundQuad1 << "\n";
		// std::cout << "Double found: " << foundDouble1 << "\n";
		// std::cout << "Double not found: " << floor(tableSize*.01)-foundDouble1 << "\n\n";

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
		quadTime2 = float(QuadEndTime)/CLOCKS_PER_SEC;
		doubleTime2 = float(DoubleEndTime)/CLOCKS_PER_SEC;
		//
		// std::cout << "total Quadratic time: " << float(QuadEndTime)/CLOCKS_PER_SEC << "\n";
		// std::cout << "total Double time: " << float(DoubleEndTime)/CLOCKS_PER_SEC << "\n";
		//
		// std::cout << "success Quadratic: " << table2.getNumElementsQuadratic() << "\n";
		// std::cout << "success double: " << table2.getNumElementsDouble() << "\n";


		for(int i=0;i<floor(tableSize*.01);i++)
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

		notFoundQuad2 = floor(tableSize*.01)-foundQuad2;
		notFoundDouble2 = floor(tableSize*.01)-foundDouble2;

		// std::cout << "Quadratic found: " << foundQuad2 << "\n";
		// std::cout << "Quadratic not found: " << floor(tableSize*.01)-foundQuad2 << "\n";
		// std::cout << "Double found: " << foundDouble2 << "\n";
		// std::cout << "Quadratic not found: " << floor(tableSize*.01)-foundDouble2 << "\n\n";

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
		quadTime3 = float(QuadEndTime)/CLOCKS_PER_SEC;
		doubleTime3 = float(DoubleEndTime)/CLOCKS_PER_SEC;

		// std::cout << "total Quadratic time: " << float(QuadEndTime)/CLOCKS_PER_SEC << "\n";
		// std::cout << "total Double time: " << float(DoubleEndTime)/CLOCKS_PER_SEC << "\n";
		//
		// std::cout << "success Quadratic: " << table3.getNumElementsQuadratic() << "\n";
		// std::cout << "success double: " << table3.getNumElementsDouble() << "\n";

		for(int i=0;i<floor(tableSize*.01);i++)
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

		notFoundQuad3 = floor(tableSize*.01)-foundQuad3;
		notFoundDouble3 = floor(tableSize*.01)-foundDouble3;
		//
		// std::cout << "Quadratic found: " << foundQuad3 << "\n";
		// std::cout << "Quadratic not found: " << floor(tableSize*.01)-foundQuad3 << "\n";
		// std::cout << "Double found: " << foundDouble3 << "\n";
		// std::cout << "Quadratic not found: " << floor(tableSize*.01)-foundDouble3 << "\n\n";

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
		quadTime4 = float(QuadEndTime)/CLOCKS_PER_SEC;
		doubleTime4 = float(DoubleEndTime)/CLOCKS_PER_SEC;

		// std::cout << "total Quadratic time: " << float(QuadEndTime)/CLOCKS_PER_SEC << "\n";
		// std::cout << "total Double time: " << float(DoubleEndTime)/CLOCKS_PER_SEC << "\n";
		//
		// std::cout << "success Quadratic: " << table4.getNumElementsQuadratic() << "\n";
		// std::cout << "success double: " << table4.getNumElementsDouble() << "\n";

		for(int i=0;i<floor(tableSize*.01);i++)
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

		notFoundQuad4 = floor(tableSize*.01)-foundQuad4;
		notFoundDouble4 = floor(tableSize*.01)-foundDouble4;
		//
		// std::cout << "Quadratic found: " << foundQuad4 << "\n";
		// std::cout << "Quadratic not found: " << floor(tableSize*.01)-foundQuad4 << "\n";
		// std::cout << "Double found: " << foundDouble4 << "\n";
		// std::cout << "Quadratic not found: " << floor(tableSize*.01)-foundDouble4 << "\n\n";

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
		quadTime5 = float(QuadEndTime)/CLOCKS_PER_SEC;
		doubleTime5	= float(DoubleEndTime)/CLOCKS_PER_SEC;

		// std::cout << "total Quadratic time: " << float(QuadEndTime)/CLOCKS_PER_SEC << "\n";
		// std::cout << "total Double time: " << float(DoubleEndTime)/CLOCKS_PER_SEC << "\n";
		//
		// std::cout << "success Quadratic: " << table5.getNumElementsQuadratic() << "\n";
		// std::cout << "success double: " << table5.getNumElementsDouble() << "\n";

		for(int i=0;i<floor(tableSize*.01);i++)
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

		notFoundQuad5 = floor(tableSize*.01)-foundQuad5;
		notFoundDouble5 = floor(tableSize*.01)-foundDouble5;
		//
		// std::cout << "Quadratic found: " << foundQuad5 << "\n";
		// std::cout << "Quadratic not found: " << floor(tableSize*.01)-foundQuad5 << "\n";
		// std::cout << "Double found: " << foundDouble5 << "\n";
		// std::cout << "Quadratic not found: " << floor(tableSize*.01)-foundDouble5 << "\n\n";

		std::cout << "\t\t\t\t\t\t Performance (Quadratic Probing) \n";
		std::cout << "Input Size" << "\t\t\t\t100,000 \t200,000 \t300,000 \t400,000 \t500,000\n";
		std::cout << "Build (s)\t\t\t\t" << quadTime1 << " \t" << quadTime2 << " \t" << quadTime3 << " \t" << quadTime4 << " \t" << quadTime5 << " \n";
		std::cout << "Number of items successfully found\t" << foundQuad1 << " \t\t" << foundQuad2 << " \t\t" << foundQuad3 << " \t\t" << foundQuad4 << " \t\t" << foundQuad5 << "\n";
		std::cout << "Number of items not found\t\t" << notFoundQuad1 << " \t\t" << notFoundQuad2 << " \t\t" << notFoundQuad3 << " \t\t" << notFoundQuad4 << " \t\t" << notFoundQuad5 << "\n";

		std::cout << "\n";

		std::cout << "\t\t\t\t\t Performance (Double Hashing) \n";
		std::cout << "Input Size" << "\t\t\t\t100,000 \t200,000 \t300,000 \t400,000 \t500,000\n";
		std::cout << "Build (s)\t\t\t\t" << doubleTime1 << " \t" << doubleTime2 << " \t" << doubleTime3 << " \t" << doubleTime4 << " \t" << doubleTime5 << " \n";
		std::cout << "Number of items successfully found\t" << foundDouble1 << " \t\t" << foundDouble2 << " \t\t" << foundDouble3 << " \t\t" << foundDouble4 << " \t\t" << foundDouble5 << "\n";
		std::cout << "Number of items not found\t\t" << notFoundDouble1 << " \t\t" << notFoundDouble2 << " \t\t" << notFoundDouble3 << " \t\t" << notFoundDouble4 << " \t\t" << notFoundDouble5 << "\n";

		std::cout << "\n";
		
		return;
	}
