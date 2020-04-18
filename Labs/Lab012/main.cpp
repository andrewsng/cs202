// main.cpp
// Andrew Ng
// Apr 17, 2020
// Lab 12 for cs202


#include <iostream>


class Base
{
public:

    Base() { std::cout << "Base constructed\n"; }

    virtual ~Base() { std::cout << "Base destructed\n"; }

    virtual void isVirtual() {
        std::cout << "Base::isVirtual\n";
    }

    void notVirtual() {
        std::cout << "Base::notVirtual\n";
    }

};


class Derived : public Base
{

    Derived() { std::cout << "Derived constructed\n"; }

    ~Derived() { std::cout << "Derived destructed\n"; }

    void isVirtual() override {
        std::cout << "Derived::isVirtual\n";
    }

    void notVirtual() {
        std::cout << "Derived::notVirtual\n";
    }

};


int main(int argc, char** argv)
{




    return 0;
}