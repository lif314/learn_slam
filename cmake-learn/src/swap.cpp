#include "swap.h"

void swap::run()
{
    int temp = this->_a;
    this->_a = this->_b;
    this->_b = temp;
}

void swap::printInfo()
{
    std::cout << "_a=" << this->_a << std::endl;
    std::cout << "_b=" << this->_b << std::endl;
}