#include "Node.h"
#include <iostream>

Node::Node()
{
	// m_userName = "";
	m_password = "";
	m_wasAlwaysEmpty = true;
}

Node::Node(std::string password) //default constructor the sets m_userName and m_password
{
	m_password = password;
	m_wasAlwaysEmpty = true;
}

// std::string Node::getuserName()const //gets the entry of the Node
// {
// 	return m_userName;
// }

std::string Node::getPassword()const //gets the entry of the Node
{
	return m_password;
}

void Node::setEntry(std::string password) //sets m_userName and m_password equal to the values passed in
{
	m_password = password;
}

// Node* Node::getNext()const //getter function that returns the next node in the linked list
// {
// 	return m_next;
// }

// void Node::setNext(Node* next) //setter function that sets the next node in the list
// {
// 	m_next = next;
// }

void Node::print()
{
	if(isEmpty())
	{

	}
	else
	{
		std::cout << m_password;
		// std::cout << m_userName << ":" << m_password;
	}
}

bool Node::isEmpty()
{
	if(m_password.empty())
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Node::removeUser()
{
	// m_userName = "";
	m_password = "";
}

bool Node::wasAlwaysEmpty()
{
	return m_wasAlwaysEmpty;
}

void Node::setWasAlwaysEmpty(bool value)
{
	m_wasAlwaysEmpty = value;
}
