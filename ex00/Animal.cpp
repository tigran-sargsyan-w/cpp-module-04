#include "Animal.hpp"

Animal::Animal() : type("Animal")
{
	std::cout << "[Animal] default constructor called\n";
}

Animal::Animal(const Animal& other) : type(other.type)
{
	std::cout << "[Animal] copy constructor called\n";
}

Animal& Animal::operator=(const Animal& other)
{
	std::cout << "[Animal] copy assignment operator called\n";
	if (this != &other)
		type = other.type;
	return *this;
}

Animal::~Animal()
{
	std::cout << "[Animal] destructor called\n";
}

std::string Animal::getType() const
{
	return type;
}

void Animal::makeSound() const
{
	std::cout << "* generic animal sound *\n";
}
