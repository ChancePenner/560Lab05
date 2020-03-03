
#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include "Node.h"
#include <string>

class HashTable
{
  private:
  Node* m_linearArr;
  int m_linearSize;
  int m_numElementsLinear;

  Node* m_quadraticArr;
  int m_quadraticSize;
  int m_numElementsQuadratic;

  Node* m_doubleArr;
  int m_doubleSize;
  int m_numElementsDouble;
  int m_R = 773;


  public:

  int HashFunctionLinear(std::string password, int bucketSize);

  int HashFunctionQuadratic(std::string password, int bucketSize);

  int HashFunctionDouble(std::string password, int bucketSize);

  HashTable();

  ~HashTable();

  void LinearAddUser(std::string userName, std::string password);

  // void QuadraticAddUser(std::string userName, std::string password);
  void QuadraticAddUser(std::string password);

  void DoubleAddUser(std::string password);

  int getNumElementsDouble()
  {
    return m_numElementsDouble;
  }

  int getNumElementsQuadratic()
  {
    return m_numElementsQuadratic;
  }

  bool findQuad(std::string number);

  bool findDouble(std::string number);


  // void RemoveUserLinear(std::string userName, std::string password);
  //
  // void RemoveUserQuadratic(std::string userName, std::string password);

  // int RemoveUserLinearHashIndex(std::string password, int bucketSize, int iterator);
  //
  // int RemoveUserQuadraticHashIndex(std::string password, int bucketSize, int iterator);


  // void PlayerWithGoalCountEqualTo(int password);
  //
  // void PlayerWithNumGoalsGreaterThan(int password);
  //
  // void PlayerWithNumGoalsLessThan(int password);

  void PrintListLinear();

  void PrintListQuadratic();

  bool FindNameMatchLinear(std::string userName, std::string password);

  // bool FindNameMatchQuadratic(std::string userName, std::string password);
  bool FindNameMatchQuadratic(std::string password);


  void rehashLinear();

  void rehashQuadratic();

  int nextPrime(int num);

  bool isPrime(int num);

  // void ForgotPasswordLinear(std::string userName);
  //
  // void ForgotUsernameLinear(std::string password);
  //
  // void ForgotPasswordQuadratic(std::string userName);
  //
  // void ForgotUsernameQuadratic(std::string password);


};








#endif
