#include "HashTable.h"
#include <iostream>
#include <cctype>

HashTable::HashTable()
{
  m_linearSize = 11;
  m_linearArr = new Node[m_linearSize];
  m_numElementsLinear = 0;

  m_quadraticSize = 1000003;
  m_quadraticArr = new Node[m_quadraticSize];
  m_numElementsQuadratic = 0;

  m_doubleSize = 1000003;
  m_doubleArr = new Node[m_doubleSize];
  m_numElementsDouble = 0;
}

HashTable::~HashTable()
{
  delete[] m_linearArr;
  delete[] m_quadraticArr;

}

// int HashTable::HashFunctionLinear(std::string password, int bucketSize)
// {
//   // also check for collision
//   // also check for collision
//   // also check for collision
//
//   //CHECK IF NEEDS REHASHED
//
//   int sum = 0;
//   int index = 0;
//   // return password % bucketSize;
//   for(unsigned int i=0;i<password.length();i++)
//   {
//     if(isdigit(password.at(i)))
//     {
//       sum = sum + (password.at(i)-48);
//       // std::cout << "hit: " << password.at(i) << " is " << (password.at(i)-48);
//     }
//     else
//     {
//       sum = sum + password.at(i);
//     }
//   }
//
//   index = sum % bucketSize;
//
//   while(!m_linearArr[index].isEmpty())
//   {
//     sum++;
//     index = sum % bucketSize;
//   }
//
//   return index;
//
// }

int HashTable::HashFunctionQuadratic(std::string password, int bucketSize)
{
  //Quadratic Probing
  //Hi(x) = (h(x) + i^2) % bucketSize

  // also check for collision
  // also check for collision
  // also check for collision

  //CHECK IF NEEDS REHASHED

  int sum = 0;
  int hOfX = 0;
  int index = 0;  //initial h(x) value
  int iterator = 0;
  // return password % bucketSize;
  // for(unsigned int i=0;i<password.length();i++)
  // {
  //   if(isdigit(password.at(i)))
  //   {
  //     sum = sum + (password.at(i)-48);
  //     // std::cout << "hit: " << password.at(i) << " is " << (password.at(i)-48);
  //   }
  //   else
  //   {
  //     sum = sum + password.at(i);
  //   }
  // }
  // std::cout << "password: " << password << " index: " << sum%bucketSize << "\n";
  sum = std::stoi(password);


  index = sum % bucketSize;
  hOfX = index;

  while(!m_quadraticArr[index].isEmpty() )
  {
    index = (hOfX + (iterator*iterator) ) % bucketSize;
    iterator++;

    if(iterator == 25)
    {
      // std::cout << "overflow\n";
      // throw (std::runtime_error("OVERFLOW\n"));
      return bucketSize; //NEED TO ACTUALLY REPORT FAILURE
    }

  }


  return index;
}


int HashTable::HashFunctionDouble(std::string password, int bucketSize)
{
  //Double Probing
  //H+(x) = R - (x mod R)

  //CHECK IF NEEDS REHASHED

  int sum = 0;
  int hOfX = 0;
  int index = 0;  //initial h(x) value
  int iterator = 0;
  // return password % bucketSize;
  // for(unsigned int i=0;i<password.length();i++)
  // {
  //   if(isdigit(password.at(i)))
  //   {
  //     sum = sum + (password.at(i)-48);
  //     // std::cout << "hit: " << password.at(i) << " is " << (password.at(i)-48);
  //   }
  //   else
  //   {
  //     sum = sum + password.at(i);
  //   }
  // }
  // std::cout << "password: " << password << " index: " << sum%bucketSize << "\n";

  sum = std::stoi(password);

  int x = sum;
  index = sum % bucketSize;
  hOfX = index;

  while(!m_doubleArr[index].isEmpty())
  {
    index = (hOfX + iterator*(m_R - (x % m_R))) % bucketSize;
    iterator++;

    if(iterator == 25)
    {
      // std::cout << "Overflow??\n";
      // throw (std::runtime_error("OVERFLOW\n"));
      return bucketSize; //NEED TO ACTUALLY REPORT FAILURE
    }

  }


  return index;
}


bool HashTable::findQuad(std::string number)
{
  int sum = 0;
  int hOfX = 0;
  int index = 0;  //initial h(x) value
  int iterator = 0;

  sum = std::stoi(number);


  index = sum % m_quadraticSize;
  hOfX = index;

  while(m_quadraticArr[index].getPassword() != number)
  {
    index = (hOfX + (iterator*iterator) ) % m_quadraticSize;
    iterator++;

    if(iterator == 25)
    {
      // std::cout << "overflow\n";
      // throw (std::runtime_error("OVERFLOW\n"));
      return false; //NEED TO ACTUALLY REPORT FAILURE
    }

  }
  return true;

}

bool HashTable::findDouble(std::string number)
{
  int sum = 0;
  int hOfX = 0;
  int index = 0;  //initial h(x) value
  int iterator = 0;


  sum = std::stoi(number);

  int x = sum;
  index = sum % m_doubleSize;
  hOfX = index;


  while(m_doubleArr[index].getPassword() != number)
  {
    index = (hOfX + iterator*(m_R - (x % m_R))) % m_doubleSize;
    iterator++;

    if(iterator == 25)
    {
      // std::cout << "Overflow??\n";
      // throw (std::runtime_error("OVERFLOW\n"));
      return false; //NEED TO ACTUALLY REPORT FAILURE
    }
  }
  return true;
}




void HashTable::QuadraticAddUser(std::string password)
{
  // std::cout << "in QuadraticAddUser\n";
  // bool mustRehash = false;
  //check if needs rehashed
  // double loadFactor = m_numElementsQuadratic/(double)m_quadraticSize;
  // if(loadFactor > 0.5)
  // {
  //   std::cout << "REHASH\n";
  //
  //   mustRehash = true;
  // }


  bool noDuplicate = true;
  // for(int i=0;i<m_quadraticSize;i++)
  // {
  //   if(FindNameMatchQuadratic(password))
  //   {
  //     noDuplicate = false;
  //   }
  // }

  if(noDuplicate)
  {
    Node temp(password);
    int index = HashFunctionQuadratic(password, m_quadraticSize);
    if(index == m_doubleSize)
    {
      return;
    }
    m_quadraticArr[index] = temp;
    // m_quadraticArr[index].setWasAlwaysEmpty(false);
    // std::cout << "Quadratic Probing:\n\n";
    // std::cout << userName << " has been successfully added at location " << index << " using Quadratic probing\n\n";
    m_numElementsQuadratic++;

    // if(mustRehash)
    // {
    //   rehashQuadratic();
    //   //if we need to rehash, then we do it after first inserting, so that way
    //   //we know where it was supposed to go
    //   //call rehash(userName, password);
    // }

  }
  else
  {
    std::cout << password << " was already in the table\n";
  }
}

void HashTable::DoubleAddUser(std::string password)
{
  // std::cout << "in QuadraticAddUser\n";
  // bool mustRehash = false;
  //check if needs rehashed
  // double loadFactor = m_numElementsQuadratic/(double)m_quadraticSize;
  // if(loadFactor > 0.5)
  // {
  //   std::cout << "REHASH\n";
  //
  //   mustRehash = true;
  // }


  // bool noDuplicate = true;
  // for(int i=0;i<m_quadraticSize;i++)
  // {
  //   if(FindNameMatchQuadratic(password))
  //   {
  //     noDuplicate = false;
  //   }
  // }

  // if(noDuplicate)
  // {
    Node temp(password);
    int index = HashFunctionDouble(password, m_quadraticSize);
    if(index == m_doubleSize)
    {
      return;
    }
    m_doubleArr[index] = temp;
    // m_doubleArr[index].setWasAlwaysEmpty(false);
    // std::cout << "Quadratic Probing:\n\n";
    // std::cout << userName << " has been successfully added at location " << index << " using Quadratic probing\n\n";
    m_numElementsDouble++;

    // if(mustRehash)
    // {
    //   rehashQuadratic();
    //   //if we need to rehash, then we do it after first inserting, so that way
    //   //we know where it was supposed to go
    //   //call rehash(userName, password);
    // }

  // }
  // else
  // {
  //   std::cout << password << " was already in the table\n";
  // }
}

// void HashTable::LinearAddUser(std::string userName, std::string password)
// {
//   bool mustRehash = false;
//   //check if needs rehashed
//   double loadFactor = m_numElementsLinear/(double)m_linearSize;
//   if(loadFactor > 0.5)
//   {
//     mustRehash = true;
//   }
//
//
//   bool noDuplicate = true;
//   for(int i=0;i<m_linearSize;i++)
//   {
//     if(FindNameMatchLinear(userName, password))
//     {
//       noDuplicate = false;
//     }
//   }
//
//   if(noDuplicate)
//   {
//     Node temp(userName,password);
//     int index = HashFunctionLinear(password, m_linearSize);
//     m_linearArr[index] = temp;
//     m_linearArr[index].setWasAlwaysEmpty(false);
//     std::cout << "\nLinear Probing:\n\n";
//     std::cout << userName << " has been successfully added at location " << index << " using Linear probing\n\n";
//     m_numElementsLinear++;
//
//     if(mustRehash)
//     {
//       rehashLinear();
//
//       //if we need to rehash, then we do it after first inserting, so that way
//       //we know where it was supposed to go
//       //call rehash(userName, password);
//     }
//
//   }
//   else
//   {
//     std::cout << userName << " was already in the table\n";
//   }
//
// }

// void HashTable::rehashLinear()
// {
//   int tempSize = m_linearSize;
//
//   Node* temp = new Node[m_linearSize];
//   for(int i=0;i<m_linearSize;i++)
//   {
//     temp[i].setEntry(m_linearArr[i].getuserName(), m_linearArr[i].getPassword());
//   }
//
//   int newSize = nextPrime(m_linearSize*2);
//
//   delete[] m_linearArr;
//
//   m_linearSize = newSize;
//   m_linearArr = new Node[newSize];
//   m_numElementsLinear = 0;
//
//   for(int i=0;i<tempSize;i++)
//   {
//     if(!temp[i].isEmpty())
//     {
//       LinearAddUser(temp[i].getuserName(),temp[i].getPassword());
//     }
//   }
//
//   delete[] temp;
//
// }

// void HashTable::rehashQuadratic()
// {
//   int tempSize = m_quadraticSize;
//
//   Node* temp = new Node[m_quadraticSize];
//   for(int i=0;i<m_quadraticSize;i++)
//   {
//     temp[i].setEntry(m_quadraticArr[i].getPassword());
//   }
//
//   int newSize = nextPrime(m_quadraticSize*2);
//
//   delete[] m_quadraticArr;
//
//   m_quadraticSize = newSize;
//   m_quadraticArr = new Node[newSize];
//   m_numElementsQuadratic = 0;
//
//   for(int i=0;i<tempSize;i++)
//   {
//     if(!temp[i].isEmpty())
//     {
//       QuadraticAddUser(temp[i].getPassword());
//     }
//   }
//
//   delete[] temp;
// }


// int HashTable::RemoveUserLinearHashIndex(std::string password, int bucketSize, int iterator)
// {
//   int index = 0;
//   int sum = 0;
//
//   for(unsigned int i=0;i<password.length();i++)
//   {
//     if(isdigit(password.at(i)))
//     {
//       sum = sum + (password.at(i)-48);
//       // std::cout << "hit: " << password.at(i) << " is " << (password.at(i)-48);
//     }
//     else
//     {
//       sum = sum + password.at(i);
//     }
//   }
//
//   index = sum % bucketSize;
//
//   index = (sum + iterator ) % bucketSize;
//
//   return index;
// }


// void HashTable::RemoveUserLinear(std::string userName,std::string password)
// {
//   int iterator = 0;
//   int originalIndex = RemoveUserLinearHashIndex(password, m_linearSize, iterator);
//   int index = originalIndex;
//
//
//   if(m_linearArr[originalIndex].getuserName() == userName && m_linearArr[originalIndex].getPassword() == password)
//   {
//     m_linearArr[originalIndex].removeUser();
//     std::cout << "\nLinear Probing:\n\nRecord removed\n";
//     //we found it, so just remove
//   }
//   else
//   {
//     //wasn't where we thought it was, so keep looking
//
//       while(!m_linearArr[index].wasAlwaysEmpty())
//       {
//         //search until finding a spot that has always been empty
//         index = RemoveUserLinearHashIndex(password, m_linearSize, iterator);
//         iterator++;
//
//         if(m_linearArr[index].getuserName() == userName && m_linearArr[index].getPassword() == password)
//         {
//           m_linearArr[index].removeUser();
//           std::cout << "\nLinear Probing:\n\nRecord removed\n\n";
//           return;
//         }
//       }
//       std::cout << "Record does not exist\n";
//
//   }
//
// }


// int HashTable::RemoveUserQuadraticHashIndex(std::string password, int bucketSize, int iterator)
// {
//   int index = 0;
//   int sum = 0;
//   int hOfX = 0;
//
//   for(unsigned int i=0;i<password.length();i++)
//   {
//     if(isdigit(password.at(i)))
//     {
//       sum = sum + (password.at(i)-48);
//       // std::cout << "hit: " << password.at(i) << " is " << (password.at(i)-48);
//     }
//     else
//     {
//       sum = sum + password.at(i);
//     }
//   }
//
//   index = sum % bucketSize;
//   hOfX = index;
//
//   index = (hOfX + (iterator*iterator) ) % bucketSize;
//
//   return index;
// }
//
// void HashTable::PrintListLinear()
// {
//   for(int i=0;i<m_linearSize;i++)
//   {
//     std::cout << "Index[" << i << "]" << ":";
//     m_linearArr[i].print();
//     std::cout << "\n";
//   }
// }



// void HashTable::RemoveUserQuadratic(std::string userName,std::string password)
// {
//   int iterator = 0;
//   int originalIndex = RemoveUserQuadraticHashIndex(password, m_quadraticSize, iterator);
//   int index = originalIndex;
//
//
//   if(m_quadraticArr[originalIndex].getuserName() == userName && m_quadraticArr[originalIndex].getPassword() == password)
//   {
//     m_quadraticArr[originalIndex].removeUser();
//     std::cout << "Quadratic Probing:\n\nRecord removed\n\n";
//     //we found it, so just remove
//   }
//   else
//   {
//     //wasn't where we thought it was, so keep looking
//
//       while(!m_quadraticArr[index].wasAlwaysEmpty())
//       {
//         //search until finding a spot that has always been empty
//         index = RemoveUserQuadraticHashIndex(password, m_quadraticSize, iterator);
//         iterator++;
//
//         if(m_quadraticArr[index].getuserName() == userName && m_quadraticArr[index].getPassword() == password)
//         {
//           m_quadraticArr[index].removeUser();
//           std::cout << "Quadratic Probing:\n\nRecord removed\n";
//           return;
//         }
//
//       }
//       std::cout << "Record does not exist\n";
//
//   }
//
// }


void HashTable::PrintListQuadratic()
{
  for(int i=0;i<m_quadraticSize;i++)
  {
    std::cout << "Index[" << i << "]" << ":";
    m_quadraticArr[i].print();
    std::cout << "\n";
  }
}

// bool HashTable::FindNameMatchLinear(std::string userName, std::string password)
// {
//   for(int i=0;i<m_linearSize;i++)
//   {
//     if(m_linearArr[i].getuserName() == userName)
//     {
//       return true;
//     }
//   }
//   return false;
// }

bool HashTable::FindNameMatchQuadratic(std::string password)
{
  for(int i=0;i<m_quadraticSize;i++)
  {
    if(m_quadraticArr[i].getPassword() == password)
    {
      return true;
    }
  }
  return false;
}

int HashTable::nextPrime(int num)
{

  while(!isPrime(num))
  {
    num++;
  }

  return num;

}

bool HashTable::isPrime(int num)
{
  for(int i=2;i<num;i++)
  {
    if(num%i == 0)
    {
      return false;
    }
  }
  return true;
}



// void HashTable::ForgotPasswordLinear(std::string userName)
// {
//   bool noEntry = true;
//   std::cout << "\nLinear Probing\n\n";
//
//   for(int i=0;i<m_linearSize;i++)
//   {
//     if(!m_linearArr[i].isEmpty())
//     {
//       if(m_linearArr[i].getuserName() == userName)
//       {
//         noEntry = false;
//         std::cout << userName << ":" << m_linearArr[i].getPassword() << "\n";
//       }
//     }
//   }
//   if(noEntry)
//   {
//     std::cout << "Record does not exist\n";
//   }
// }
//
// void HashTable::ForgotUsernameLinear(std::string password)
// {
//   bool noEntry = true;
//   std::cout << "\nLinear Probing\n\n";
//
//   for(int i=0;i<m_linearSize;i++)
//   {
//     if(!m_linearArr[i].isEmpty())
//     {
//       if(m_linearArr[i].getPassword() == password)
//       {
//         noEntry = false;
//         std::cout << m_linearArr[i].getuserName() << ":" << password << "\n";
//       }
//     }
//   }
//   if(noEntry)
//   {
//     std::cout << "Record does not exist\n";
//   }
// }
//
// void HashTable::ForgotPasswordQuadratic(std::string userName)
// {
//   bool noEntry = true;
//
//   std::cout << "\nQuadratic Probing\n\n";
//
//   for(int i=0;i<m_quadraticSize;i++)
//   {
//     if(!m_quadraticArr[i].isEmpty())
//     {
//       if(m_quadraticArr[i].getuserName() == userName)
//       {
//         noEntry = false;
//         std::cout << userName << ":" << m_quadraticArr[i].getPassword() << "\n";
//       }
//     }
//   }
//   if(noEntry)
//   {
//     std::cout << "Record does not exist\n";
//   }
// }
//
// void HashTable::ForgotUsernameQuadratic(std::string password)
// {
//   bool noEntry = true;
//   std::cout << "\nQuadratic Probing\n\n";
//
//   for(int i=0;i<m_quadraticSize;i++)
//   {
//     if(!m_quadraticArr[i].isEmpty())
//     {
//       if(m_quadraticArr[i].getPassword() == password)
//       {
//         noEntry = false;
//         std::cout << m_quadraticArr[i].getuserName() << ":" << password << "\n";
//       }
//     }
//   }
//   if(noEntry)
//   {
//     std::cout << "Record does not exist\n";
//   }
// }
