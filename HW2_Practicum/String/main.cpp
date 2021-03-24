#include <iostream>
#include "String.h"

int main()
{
    String myString;
    myString.setString("Hello");
    std::cout << "String A: ";
    myString.print();
    String myString2;
    myString2.setString("World!");
    std::cout << "String B: ";
    myString2.print();
    String myString3;
    std::cout << "String = (A + B): ";
    myString3 = (myString + myString2);
    myString3.print();
    std::cout << "String A += B: ";
    myString += myString2;
    myString.print();
    std::cout << "String A == B: " << (myString == myString2) << std::endl;
    std::cout << "String A != B: " << (myString != myString2) << std::endl;
    std::cout << "Char c = A[10]: ";
    char c = myString[10];
    std::cout << c << std::endl;
    std::cout << "Adding char c to A: ";
    myString.add(c).print();
    std::cout << "Inserting a space in A: ";
    myString.insertAt(' ', 5);
    myString.print();
    std::cout << "Removing the space in A: ";
    myString.removeAt(5);
    myString.print();
    std::cout << "Removing the first element of A: ";
    myString.trimStart();
    myString.print();
    std::cout << "Removing the last element of A: ";
    myString.trimEnd();
    myString.print();
    std::cout << "Removing the first 4 elements of A: ";
    myString.trimStart(4);
    myString.print();
    std::cout << "Removing the last 5 elements of A: ";
    myString.trimEnd(5);
    myString.print();

    return 0;
}