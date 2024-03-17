/*
 * Name: Seongchan Jung
 * Program : It outputs the size of various data contents.
 * Filename: Lab02_num_obj.cpp
 */

#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{ //numerical
  int int_example = 1;
  float float_example = 2.0;
  double doulbe_example = 2.0;

  //non-numerical
  char char_example = 'a';
  bool bool_example = true;

  //size of returns the number of bytes (8 bits is equiavalent to 1 byte))
  cout << "int_example " << sizeof(int_example) << endl;
  cout << "float_example: " << sizeof(float_example) << endl;
  cout << "doulbe_example: " << sizeof(doulbe_example) << endl;

  cout << "char_example: " << sizeof(char_example) << endl;
  cout << "bool_example: " << sizeof(bool_example) << endl;
}
