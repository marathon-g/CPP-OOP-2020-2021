#include "Crypto.h"

void Crypto::copy(const Crypto& otherCrypto)
{
    this->name = new char[strlen(otherCrypto.name) + 1];
    strcpy_s(this->name, strlen(otherCrypto.name) + 1, otherCrypto.name);
    this->lastPrice = otherCrypto.lastPrice;
    this->currentPrice = otherCrypto.currentPrice;
}

void Crypto::erase()
{
    delete [] this->name;
}

Crypto::Crypto()
{
    this->name = new char[6];
    strcpy_s(this->name, 6, "Empty");
    this->lastPrice = 0;
    this->currentPrice = 0;
}

Crypto& Crypto::operator=(const Crypto &otherCrypto)
{
    if(this != &otherCrypto)
    {
        this->erase();
        this->copy(otherCrypto);
    }
    return *this;
}

Crypto::Crypto(const Crypto& otherCrypto)
{
    this->copy(otherCrypto);
}

Crypto::~Crypto()
{
    this->erase();
}

void Crypto::setName(const char* _name)
{
    delete[] this->name;
    this->name = new char[strlen(_name) + 1];
    strcpy_s(this->name, strlen(_name) + 1, _name);
}

void Crypto::setLastPrice(double _lastPrice)
{
    this->lastPrice = _lastPrice;
}

void Crypto::setCurrentPrice(double _currentPrice)
{
    this->currentPrice = _currentPrice;
}

const char* Crypto::getName() const
{
    return this->name;
}

double Crypto::getLastPrice() const
{
    return this->lastPrice;
}

double Crypto::getCurrentPrice() const
{
    return this->currentPrice;
}

void Crypto::print() const
{
    std::cout << name << std::endl;
    std::cout << lastPrice << std::endl;
    std::cout << currentPrice << std::endl;
}

double Crypto::priceDifference(double _lastPrice, double _currentPrice)
{
    return (currentPrice - lastPrice) / lastPrice * 100;
}