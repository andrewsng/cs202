#include <iostream>
#include <stdexcept>
#include <string>

class MyObject
{
public:
    MyObject() {
        std::cout << "MyObject constructed\n";
    }

    ~MyObject() {
        std::cout << "MyObject destroyed\n";
    }
};

void functionC()
{
    throw std::runtime_error("functionC() threw std::runtime_error");
}

void functionB()
{
    MyObject coolObj;
    std::cout << "Starting functionB()\n";
    functionC();
    std::cout << "Ending functionB()\n";
}

void functionA()
{
    try {
        functionB();
    }
    catch (const std::exception& e) {
        std::cout << "Caught an exception: " << e.what() << std::endl;
    }
}

int main()
{
    std::cout << "Starting main()" << std::endl;
    functionA();
    std::cout << "Ended normally." << std::endl;
    return 0;
}
