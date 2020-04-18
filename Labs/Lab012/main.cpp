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
public:
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
    Base base;
    Derived derived;
    std::cout << "---------------------\n";

    std::cout << "Base pointer to Base\n";
    Base* bp1 = &base;
    bp1->isVirtual();
    bp1->notVirtual();
    std::cout << "---------------------\n";

    std::cout << "Base pointer to Derived\n";
    Base* bp2 = &derived;
    bp2->isVirtual();
    bp2->notVirtual();
    std::cout << "---------------------\n";

    std::cout << "Derived pointer to Derived\n";
    Derived* dp1 = &derived;
    dp1->isVirtual();
    dp1->notVirtual();
    std::cout << "---------------------\n";

    std::cout << "Base reference to Base\n";
    Base& br1 = base;
    br1.isVirtual();
    br1.notVirtual();
    std::cout << "---------------------\n";

    std::cout << "Base reference to Derived\n";
    Base& br2 = derived;
    br2.isVirtual();
    br2.notVirtual();
    std::cout << "---------------------\n";

    std::cout << "Derived reference to Derived\n";
    Derived& dr = derived;
    dr.isVirtual();
    dr.notVirtual();
    std::cout << "---------------------\n";

    return 0;
}