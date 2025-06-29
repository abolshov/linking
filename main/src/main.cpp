#include <iostream>

#include "UtilLib.hpp"

int main()
{
    UtilClass uc{};
    uc.Init();
    static constexpr size_t UTIL_CLASS_SZ = sizeof(UtilClass);
    std::cout << "UtilClass size: " << UTIL_CLASS_SZ << "\n";
    return 0;
}