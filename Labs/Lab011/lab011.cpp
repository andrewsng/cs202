#include <iostream>


class Base
{
public:
    Base() : num_(123)
    {
        std::cout << "Constructing a default base object with value: " << num_ << "\n";
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


int main()
{
    { Base myBase; }
    std::cout << "\n";
    { Base myBase(456); }

    return 0;
}