#include <iostream>

#include "util/mil/roy_system.h"
#include <boost/algorithm/string.hpp>
#include "IO/FileIO.h"

int main()
{
    using namespace std;
    using roy_c::f_write;
    std::string pth = "test_data/test1";
    int stat = 0;

    const int my_con(23);
    string a = roy_c::f_read(pth);
    /*
    std::ofstream myfile(pth, std::ios::app);
            if (myfile.is_open()) {
                myfile << "mike";
            }
    */

    std::cout << a << std::endl;


}