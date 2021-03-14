#pragma once
#include <iostream>
#include <cstring>

class Crypto {
private:
    char* name;
    double lastPrice;
    double currentPrice;

    void copy(const Crypto& otherCrypto);
    void erase();
public:
    Crypto();
    Crypto& operator=(const Crypto& otherCrypto);
    Crypto(const Crypto& otherCrypto);
    ~Crypto();

    void setName(const char* _name);
    void setLastPrice(double _lastPrice);
    void setCurrentPrice(double _currentPrice);

    const char* getName() const;
    double getLastPrice() const;
    double getCurrentPrice() const;

    void print() const;
    double priceDifference(double _lastPrice, double _currentPrice);
};