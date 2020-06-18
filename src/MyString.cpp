#include "MyString.h"
#include<cstring>
#include<iostream>
//Constructors
MyString::MyString() : str{nullptr}
{
    std::cout<<"No args constructor"<<std::endl;
    str = new char[1];
    *str = '\0';
}

MyString :: MyString(char *s): str{nullptr}{
    std::cout<<"Overloaded constructor" << std::endl;
   if(s==nullptr){
    str = new char[1];
    *str ='\0';
   }
   else{
   str = new char[std::strlen(s)+1];
    std::strcpy(str,s);
   }
}
MyString :: MyString(const MyString &source):str{nullptr}{
   std::cout<<"copy constructor"<<std::endl;
   str = new char[strlen(source.str) +1];
   std::strcpy(str,source.str);
}
MyString::MyString(MyString &&source): str{source.str}{
    std::cout<<"Move Constructor"<<std::endl;
source.str = nullptr;
}
// Copy assignment operator overloading
MyString &MyString:: operator=(const MyString &rhs){
    std::cout<<"Copy assignment"<<std::endl;
 if(this==&rhs) // checking for self assignment
    return *this;
 delete []str;
 this->str = new char[std::strlen(rhs.str)+1];
 std::strcpy(this->str,rhs.str);
 return *this;   //We are returning to allow chain assignment a=b=c;

}
// Move assignment
MyString &MyString::operator=(MyString &&rhs){
    std::cout<<"Move assignment"<<std::endl;
 if(this==&rhs)
    return *this;
 delete [] str;
 this->str = rhs.str;
 rhs.str=nullptr;
 return *this;
}
//Overloading unary - , which returns a MyString in lower case
MyString MyString::operator-() const{
    std::cout<<"Unary \n";
char *buff = new char[std::strlen(str)+1];
std::strcpy(buff,str);
for(size_t i =0; i<std::strlen(str);i++)
    buff[i]= std::tolower(str[i]);
MyString temp{buff};
delete []buff;
return temp;
}
// Overloading the comparison operator
bool MyString::operator==(const MyString &rhs)
{
   if(std::strcmp(this->str,rhs.str)==0)
      return true;
   else
    return false;
}
//Overloading the addition operator
//MyString MyString::operator=(const MyString &rhs) const{
//char *buff = new char[std::strlen(str) + std::strlen(rhs.str) +1]
//std::strcpy(buff,str);
//std::strcat(buff,rhs.str);
//MyString temp{buff};
//delete [] buff;
//return temp;
//}
//Destructor
MyString::~MyString()
{
    delete []str;
}
//Methods
void MyString::display() const{
//  for(size_t i = 0; i<std::strlen(str);i++)
//    std::cout<<str[i];
//  std::cout<<std::endl;
 std::cout<< str <<std::endl;

 //Both the methods of displaying works with cout
}
int MyString::get_length() const{
 return std::strlen(str);
}
const char* MyString::get_str()const{
  return str;
}
// Global functions
MyString operator+(const MyString &lhs,const MyString &rhs){
    std::cout<<"Plus"<<std::endl;
 char *buff = new char[strlen(lhs.str) + strlen(rhs.str) +1];
  strcpy(buff,lhs.str);
  strcat(buff,rhs.str);
  MyString temp{buff};
  delete [] buff;
  return temp;

}
// Output stream overloaded

std::ostream &operator<<(std::ostream &os, const MyString &obj)
{
  os << obj.str;
  return os;
}

// Input stream extraction operator overloading
std::istream &operator>>(std::istream &in, MyString &obj)
{
    char *buff = new char[1000];
    in >> buff;
    obj = MyString{buff};
    delete []buff;
    return in;
}
