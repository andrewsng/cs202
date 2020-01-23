#include "Jumpsuit.h"


std::string Jumpsuit::getColor() const
{
	return color_;
}

void Jumpsuit::setJumpsuit(Jumpsuit suit)
{
	std::cout << this->color_ << "\n";
	*this = suit;
	std::cout << this->color_ << "\n";
}

void Jumpsuit::setColor(const std::string& newColor)
{
	color_ = newColor;
}

void Jumpsuit::clear()
{
	color_ = "blank";
}