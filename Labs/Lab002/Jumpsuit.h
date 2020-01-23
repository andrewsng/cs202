#pragma once

#ifndef JUMPSUIT_H
#define JUMPSUIT_H


#include <iostream>
#include <string>


class Jumpsuit
{
public:
	Jumpsuit() : color_("blank")
	{
		std::cout << "Blank jumpsuit created\n";
	};

	Jumpsuit(const Jumpsuit& orig) : color_(orig.color_)
	{
		std::cout << "Jumpsuit copied\n";
	};

	Jumpsuit(const std::string& newColor) : color_(newColor)
	{
		std::cout << "Jumpsuit created with color: " << newColor << "\n";
	};

	~Jumpsuit()
	{
		std::cout << "Jumpsuit destroyed\n";
	};


	std::string getColor() const;

	void setJumpsuit(Jumpsuit suit);

	void setColor(const std::string& newColor);

	void clear();


private:
	std::string color_;
};

#endif