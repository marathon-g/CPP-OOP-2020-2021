#pragma once
#include <iostream>
#include <cstring>

class String
{
private:
    char* str;

public:
    String();
    String(const char*);
    String& operator=(const String& otherString);
    String(const String& otherString);
    ~String();

    size_t getLength() const;
    void setString(const char* otherName);
    const char* getString() const; 
    void print() const;

    String operator+(const String otherString);
    String& operator+=(const String &otherString);
    char& operator[](const size_t i) const;
    bool operator==(const String& otherString) const;
    bool operator!=(const String& otherString) const;

    String& add(const char c); // adds a char to the end of the string
    void insertAt(const char c, const size_t i); // inserts a char at a given intex
    void removeAt(const size_t i); // removes a char at a given index
    void trimStart(); // removes first element
    void trimEnd(); // removes last element
    void trimStart(const int n); // removes first N elements
    void trimEnd(const int n); // removes last N elements
};