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
    using Base::Base;

    Derived() : word_("howdy")
    {
        std::cout << "Constructing a default derived object\n";
    }

    Derived(int num, std::string word)
    : Base(num), word_(word)
    {
        std::cout << "Constructing a derived object with word: " << word_ << "\n";
    };

    ~Derived()
    {
        std::cout << "Destructing a derived object with word: " << word_ << "\n";
    }


private:
    std::string word_;

};


int main()
{
    std::cout << "---A default base class object---\n";
    { Base myBase; }
    std::cout << "\n";

    std::cout << "---A base class object w/ 1 param---\n";
    { Base myBase(456); }
    std::cout << "\n";

    std::cout << "---A default derived class object---\n";
    { Derived myDerived; }
    std::cout << "\n";

    std::cout << "---A derived class object w/ 2 param---\n";
    { Derived myDerived(789, "hello"); }
    std::cout << "\n";

    std::cout << "---Derived object using inherited base class constructor---\n";
    { Derived myDerived(111); }
    std::cout << "\n";

    return 0;
}