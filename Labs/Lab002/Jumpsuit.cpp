#include "Jumpsuit.h"


std::string Jumpsuit::getColor() const
{
	return color_;
}

void Jumpsuit::setColor(const std::string& newColor)
{
	std::cout << "Color set to: " << newColor << "\n";
	color_ = newColor;
}