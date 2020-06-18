#ifndef MYSTRING_H
#define MYSTRING_H
#include<iostream>

class MyString
{
   friend MyString operator+(const MyString &lhs, const MyString &rhs);
   friend std::ostream &operator<<(std::ostream &os, const MyString &obj);
   friend std::istream &operator>>(std::istream &in,MyString &obj);
   private:
        char *str;
   public:
        MyString();
        MyString(char *s);
        MyString(const MyString &source);
        MyString(MyString &&source);
        MyString &operator=(const MyString &rhs);
        MyString &operator=(MyString &&rhs);
        MyString operator-() const; //Make lower case version of the string
        bool operator==(const MyString &rhs);
//   will implement as a global function      MyString operator+(const MyString &rhs) const; // Concatenate two strings
        ~MyString();
        void display() const;
        int get_length() const;
        const char *get_str() const;

};

#endif // MYSTRING_H
