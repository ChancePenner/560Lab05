#ifndef NODE_H
#define NODE_H

#include <string>

class Node
{
	private:
	// std::string m_userName; //the player name set to each Node
	std::string m_password;	//the goal value set to each Node
	// Node* m_next;	//a Node pointer that points to the next Node in the list
	bool m_wasAlwaysEmpty;

	public:

	Node();

	 /**
     * @pre Used to create a new Node.
     * @post Takes in entry and creates a new Node of that value
     * @param entry: an int value assigned to each Node
     **/
	Node(std::string m_password);

	 /**
     * @pre Used to return the player at a Node
     * @post Returns the player at a given Node
     **/
	// std::string getuserName()const;

	/**
		* @pre Used to return the password at a Node
		* @post Returns the password at a given Node
		**/
 std::string getPassword()const;


	 /**
     * @pre Sets the entry of a Node
     * @post Sets the value of a Node to the passed in entry
     * @param entry: An int value that is assigned to a Node
     **/
	// void setEntry(std::string userName, std::string password);
	void setEntry(std::string password);


	 /**
     * @pre Used to point to the next Node in a list
     * @post Returns the next node in a list
     **/
	// Node* getNext()const;

	 /**
     * @pre Used to set the next Node in the list. Takes in a Node pointer
     * @post Sets the next Node in a list
     * @param next: A Node pointer that is then assigned as the next Node in a list
     **/
	// void setNext(Node* next);

	void print();

	bool isEmpty();

	void removeUser();

	bool wasAlwaysEmpty();

	void setWasAlwaysEmpty(bool value);

};
#endif
