#include <iostream>
#include "Crypto.h"

int main()
{
    Crypto crypto1;
    crypto1.setName("Dogecoin");
    crypto1.setLastPrice(100);
    crypto1.setCurrentPrice(150);

    crypto1.print();
    std::cout << crypto1.priceDifference(crypto1.getLastPrice(), crypto1.getCurrentPrice()) << std::endl;
}