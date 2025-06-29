#include "UtilLib.hpp"

void UtilClass::Init()
{
    std::ranges::fill_n(m_arr.begin(), UtilConst::SZ, UtilConst::VALUE);
}