#include <iostream>
#include <string>


class Base
{
public:
    Base() : num_(123)
    {
        std::cout << "Constructing a default base object\n";
    }

    Base(int num) : num_(num)
    {
        std::cout << "Constructing a base object with param value: " << num_ << "\n";
    }

    ~Base() {
        std::cout << "Destructing a base object with value: " << num_ << "\n";
    }

    
private:
    int num_;

};


class Derived : public Base
{
public:
    Derived() : word_("howdy")
    {
        std::cout << "Constructing a default derived object\n";
    }

    ~Derived()
    {
        std::cout << "Destructing a derived object with word: " << word_ << "\n";
    }


private:
    std::string word_;

};


int main()
{
    { Base myBase; }
    std::cout << "\n";

    { Base myBase(456); }
    std::cout << "\n";

    { Derived myDerived; }
    std::cout << "\n";

    return 0;
}