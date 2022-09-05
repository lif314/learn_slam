#include "Gun.h"
#include "Soldier.h"

#include <iostream>

void test()
{
    Soldier soldier("llf");
    soldier.addGun(new Gun("AK47"));
    soldier.addBulletToGun(20);
    soldier.fire();
}

int main()
{
    std::cout << "====debug test====" << std::endl;
    test();
    return 0;
}

// g++ main.cpp src/Gun.cpp src/Soldier.cpp -Iinclude -o main.exe