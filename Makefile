lab5: main.o executive.o Node.o HashTable.o
	g++ -std=c++11 -g -Wall main.o executive.o Node.o HashTable.o -o lab5

main.o: main.cpp executive.h
	g++ -std=c++11 -g -Wall -c main.cpp

executive.o: executive.h executive.cpp Node.h
	g++ -std=c++11 -g -Wall -c executive.cpp

Node.o: Node.h Node.cpp
	g++ -std=c++11 -g -Wall -c Node.cpp

HashTable.o: HashTable.h HashTable.cpp
	g++ -std=c++11 -g -Wall -c HashTable.cpp

clean:
	rm *.o lab5
