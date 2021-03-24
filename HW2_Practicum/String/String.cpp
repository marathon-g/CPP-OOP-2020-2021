#include "String.h"

String::String()
{
    str = new char[1];
    str[0] = '\0';
}

String::String(const char* s)
{
    size_t length = strlen(s) + 2;
    str = new char[length];
    strcpy_s(str, length, s);
    str[getLength() + 1] = '\0';
}

String::String(const String& otherString)
{
    size_t length = otherString.getLength() + 1;
    str = new char[length];
    strcpy_s(str, length, otherString.str);
}

String& String::operator=(const String& otherString)
{
    if (this != &otherString)
    {
        delete[] str;
        str = new char[otherString.getLength() + 1];
        strcpy_s(str, otherString.getLength() + 1, otherString.str);
    }
    return *this;
}

String::~String()
{
    delete[] str;
}

void String::setString(const char* otherName)
{
    delete[] this->str;
    str = new char[strlen(otherName) + 1];
    strcpy_s(str, strlen(otherName) + 1, otherName);
}

const char* String::getString() const
{
    return str;
}

size_t String::getLength() const
{
    if (str != nullptr)
    {
        return strlen(str);
    }
}

void String::print() const
{
    std::cout << str << std::endl;
}

String& String::add(const char c)
{
    size_t newLength = getLength() + 2; // 1 for char 1 for 0
    char* temp = new char[newLength];
    for (size_t i = 0; i < newLength; i++)
    {
        temp[i] = str[i];
    }

    temp[this->getLength()] = c;
    temp[this->getLength() + 1] = 0;

    delete[] str;
    str = temp;
    return *this;
}

String String::operator+(const String otherString) 
{
    String result;
    size_t length = strlen(str) + strlen(otherString.str) + 1;
    result.str = new char[length];

    strcpy_s(result.str, length, str);
    strcat_s(result.str, length, otherString.str);
    
    return result;
}

String& String::operator+=(const String &otherString)
{
    char* temp;
    size_t length = strlen(str) + strlen(otherString.str) + 1;
    temp = new char[length];
    
    strcpy_s(temp, length, str);
    strcat_s(temp, length, otherString.str);
    delete[] str;
    str = temp;
    
    return *this;
}

char&  String::operator[](const size_t i) const
{
    return str[i];
}

bool String::operator==(const String& otherString) const
{
    return strcmp(str, otherString.getString()) == 0;
}

bool String::operator!=(const String& otherString) const
{
    return strcmp(str, otherString.getString()) != 0;
}

void String::insertAt(const char c, const size_t i)
{
    size_t length = getLength() + 2;
    char* temp = new char[length];
    bool flag = false;
    for (size_t j = 0; j < length; j++)
    {
        if (j == i)
        {
            flag = true;
            char tempChar = str[j];
            temp[j] = c;
        }
        if (flag)
        {
            temp[j + 1] = str[j];
            continue;
        }
        temp[j] = str[j];
    }
    delete[] str;
    str = temp;
}

void String::removeAt(const size_t i)
{
    size_t length = getLength();
    char* temp = new char[length];
    bool flag = false;
    for (size_t j = 0; j < length; j++)
    {
        if (j == i)
        {
            flag = true;
        }
        if (flag)
        {
            temp[j] = str[j + 1];
            continue;
        }
        temp[j] = str[j];
    }
    delete[] str;
    str = temp;
}

void String::trimStart()
{
    size_t length = getLength();
    char* temp = new char[length];
    for (size_t i = 0; i < length; i++)
    {
        temp[i] = str[i+1];
    }
    delete[] str;
    str = temp;
}

void String::trimEnd()
{
    size_t length = getLength();
    char* temp = new char[length];
    for (size_t i = 0; i < length; i++)
    {
        temp[i] = str[i];
    }
    temp[length - 1] = 0;
    delete[] str;
    str = temp;
}

void String::trimStart(const int n)
{
    size_t length = getLength();
    char* temp = new char[length];
    for (size_t i = 0; i < length; i++)
    {
        temp[i] = str[i + n];
    }
    delete[]str;
    str = temp;
}

void String::trimEnd(const int n)
{
    size_t length = getLength();
    char* temp = new char[length];
    for (size_t i = 0; i < length - n; i++)
    {
        temp[i] = str[i];
    }
    temp[length - 1] = 0;
    delete[]str;
    str = temp;
}