#include "swap.h"

int main()
{
    swap mySwap(10, 20);
    mySwap.printInfo();
    mySwap.run();
    std::cout << "======" << std::endl;
    mySwap.printInfo();
    return 0;
}

// 工程构建编译命令：g++ main.cpp src/swap.cpp -Iinclude -o main