#include <iostream>

#include "util/mil/roy_system.h"
#include <boost/algorithm/string.hpp>
int main()
{
    std::string rel_pth = "data/abx.out";
    std::cout << "Abs Path:" + roy_c::get_abs_pth(rel_pth) << std::endl;



}