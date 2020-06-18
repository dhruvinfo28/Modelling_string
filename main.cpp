#include<iostream>
#include "MyString.h"
using namespace std;
int main()
{
   MyString a;
   MyString b{"Hello"};
   a = -b;
   MyString c{a};
   a = "Hello"+c; // Notice first overloaded constructor is called to convert "Hello" to a MyString object, and can only do this because
   // we implemented it as global function.
   a.display();

   // look at this, gives no args , overloaded, unary, overloaded(we create a temp Mystring in - member method), move(not copy because
   // everything not in main is temporary)
   // if it was a=b then copy assignment cause now be is not temp, but in a = -b remember doing -b is an r value.
   cout << (a==a)<<endl;
   cout<< a <<endl;
   cin>>a;
   cout<<a<<endl;
    return 0;
}
