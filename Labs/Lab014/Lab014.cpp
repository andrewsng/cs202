#include <iostream>
#include <string>


template <typename T>
T twice(const T& x)
{
    return x + x;
}


int main(int argc, char** argv)
{
    std::cout << twice(2) << std::endl;
    std::cout << twice(2.3) << std::endl;
    std::cout << twice(std::string("Hello")) << std::endl;

    return 0;
}