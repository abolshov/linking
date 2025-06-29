#ifndef UTIL_LIB_HPP
#define UTIL_LIB_HPP

#include "UtilConst.hpp"

#include <array>
#include <algorithm>
#include <ranges>

class UtilClass
{
    public:
    void Init();

    private:
    std::array<int, UtilConst::SZ> m_arr{};
};

#endif