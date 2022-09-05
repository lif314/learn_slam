#pragma once

#include <string>
#include "Gun.h"

class Soldier
{
private:
    std::string _name;
    Gun *_ptr_gun;

public:
    Soldier(std::string name);
    void addBulletToGun(int num);
    void addGun(Gun* ptr_gun);
    bool fire();
    ~Soldier();
};